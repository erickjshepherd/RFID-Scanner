// EdgeInterrupt.c
// Runs on LM4F120 or TM4C123
// Request an interrupt on the falling edge of PF4 (when the user
// button is pressed) and increment a counter in the interrupt.  Note
// that button bouncing is not addressed.
// Daniel Valvano
// May 3, 2015

/* This example accompanies the book
   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers"
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2015
   Volume 1, Program 9.4
   
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2014
   Volume 2, Program 5.6, Section 5.5

 Copyright 2015 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

// user button connected to PF4 (increment counter on falling edge)

#include <stdint.h>
#include <stdbool.h>
#include "../inc/tm4c123gh6pm.h"
#include "trf79x0.h"
#include "iso14443a.h"
#include "iso14443b.h"
#include "nfc_p2p.h"
#include "nfc.h"
#include "PLL.h"
#include "trf79x0_hw.h"
#include "SysCtl.h"
#include "Switch.h"
#include "LED.h"
#include "ST7735.h"
#include "Cart.h"
#include "String.h"


#define PF2             (*((volatile uint32_t *)0x40025010))
#define PF1             (*((volatile uint32_t *)0x40025008))
#define Cart_Size 14

volatile extern int g_irq_flag;

unsigned char IRQReg;
unsigned char ChipStatus;
unsigned char ISO_Control;
unsigned char FIFO_Status;
unsigned char FIFO;
unsigned char NFC_ID;

tTRF79x0TRFMode eCurrentTRF79x0Mode = P2P_INITATIOR_MODE;//P2P_PASSIVE_TARGET_MODE;//P2P_INITATIOR_MODE;
tTRF79x0IRQFlag IRQflag;
sNFCP2PRxStatus g_sTRFRecieveStatus;
sNDEFMessageData        g_sMessageHeader;
sNDEFTextRecord         g_sTextRecord;
sNDEFURIRecord          g_sURIRecord;
sNDEFSmartPosterRecord  g_sSPRecord;
uint8_t g_ui8NFCP2PRawTagBuffer[SNEP_MAX_BUFFER];

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

uint8_t *flag = 0;

void TimerSet(uint16_t timeout_ms, uint8_t * timeout_flag){
	flag = timeout_flag;
	*flag = 0;
	SYSCTL_RCGCTIMER_R |= 0x01;   // 0) activate TIMER0
  TIMER0_CTL_R = 0x00000000;    // 1) disable TIMER0A during setup
  TIMER0_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER0_TAMR_R = 0x00000002;   // 3) configure for periodic mode, default down-count settings
  TIMER0_TAILR_R = timeout_ms * 4000;    // 4) reload value
  TIMER0_TAPR_R = 0;            // 5) bus clock resolution
  TIMER0_ICR_R = 0x00000001;    // 6) clear TIMER0A timeout flag
  TIMER0_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x00000000; // 8) priority 4
	// interrupts enabled in the main program after all devices initialized
	// vector number 35, interrupt number 19
  NVIC_EN0_R = 1<<19;           // 9) enable IRQ 19 in NVIC
  TIMER0_CTL_R = 0x00000001;    // 10) enable TIMER0A
	EnableInterrupts();           // (i) Clears the I bit
}

void Timer0Dis(void){
	
	if((SYSCTL_RCGCTIMER_R & 0x01) == 1){
			TIMER0_CTL_R = 0x00000000;
	}
}

void Timer0A_Handler(void){
	TIMER0_ICR_R = TIMER_ICR_TATOCINT;// acknowledge timer0A timeout
	*flag = 1;
	//TIMER0_CTL_R = 0x00000000;
}

tTRF79x0IRQFlag IRQ_Status;
void GPIOPortE_Handler(void){
	
	uint8_t irq_status;
	
	// set global flag and clear interrupts 
	TRF79x0IRQPinInterruptHandler();
	if(irq_status == 0xA0){
			
	}
	else{
		
		IRQ_Status = TRF79x0IRQHandler(495);
	}
}


unsigned char pucUID[5];
unsigned int puiUIDSize = 5;
unsigned char pucSAK = 0;

StoreItem UIDArray[Cart_Size];
int Total_Cost;
char hexArray[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

//debug code
int main(void){
	
	PLL_Init(Bus4MHz);                  // set system clock to 80 MHz
	Total_Cost = 0;
	//initialize other modules
	Switch1_Init();
	Switch2_Init();
	LED_Init();
	LED_On();
	ST7735_InitR(INITR_REDTAB);
	Data_Init();
	EnableInterrupts();           // (i) Clears the I bit
	
	// Set booster pack type variable
	g_eRFDaughterType = RF_DAUGHTER_TRF7970ABP;
	
	// Initialize transceiver
	TRF79x0Init();
	ISO14443ASetupRegisters();
	int card_flag = 0;
	int uid_index = 0;
	int lcdX, lcdY;
	
	// initialize port F for LEDs
	SYSCTL_RCGCGPIO_R |= 0x20;            // activate port F
  GPIO_PORTF_DIR_R |= 0x06;             // make PF2, PF1 out (built-in LED)
  GPIO_PORTF_AFSEL_R &= ~0x06;          // disable alt funct on PF2, PF1
  GPIO_PORTF_DEN_R |= 0x06;             // enable digital I/O on PF2, PF1                                  // configure PF2 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF00F)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;  
	
	SysCtlDelay(16000);
	
	ST7735_OutString("Cart");
	ST7735_SetCursor(0,15);
	ST7735_OutString("Total: "); // 0 - 6
	ST7735_OutUDec(Total_Cost);
	ST7735_SetCursor(0,1);
	lcdX = 0;
	lcdY = 1;
	
	while(1) {
		// set up the scanner
		ISO14443ASetupRegisters();
		ISO14443APowerOn();
			// search for a tag
			if(ISO14443ASelectFirst(ISO14443A_WUPA, pucUID, &puiUIDSize, &pucSAK)) {
				
				PF1 = 0x02;
				LED_On();
				// if this is the first read of the card add it to the cart
				if(card_flag == 0){
					// put UID in the cart
					UIDArray[uid_index].uid[0] = pucUID[0];
					UIDArray[uid_index].uid[1] = pucUID[1];
					UIDArray[uid_index].uid[2] = pucUID[2];
					UIDArray[uid_index].uid[3] = pucUID[3];
					UIDArray[uid_index].uid[4] = '\0';
					
					// add its price to the total cost
					Total_Cost += Get_Price(UIDArray[uid_index].uid);
					
					//output the name
					ST7735_OutString(Get_Name(UIDArray[uid_index].uid));
					lcdY++;
					ST7735_SetCursor(7, 15);
					
					// output the total price
					ST7735_OutUDec(Total_Cost);
					ST7735_SetCursor(lcdX, lcdY);
					
					// set the card flag and increment uid_index
					card_flag = 1;
					uid_index = (uid_index + 1) % Cart_Size;

					// de-select the tag
					ISO14443AHalt();
				}
			}
		else{
				
			PF1 = 0;
			LED_Off();
			if(card_flag == 1){
				//Output_Clear();
				//ST7735_SetCursor(0,0);
				//ST7735_OutString("No Tag");	
			}

			card_flag = 0;
		}		
		
		if(Get_ClearFlag()){
			Set_ClearFlag(0);
			Output_Clear();
			ST7735_SetCursor(0,0);
			ST7735_OutString("Cart");
			ST7735_SetCursor(0,15);
			ST7735_OutString("Total: "); // 0 - 6
			Total_Cost = 0;
			ST7735_OutUDec(Total_Cost);
			ST7735_SetCursor(0,1);
			lcdX = 0;
			lcdY = 1;
			uid_index = 0;
		}
		
	  // power off the scanner
		TRF79x0ResetFifoCommand();
	  ISO14443APowerOff();
	}
}
