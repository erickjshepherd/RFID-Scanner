
#include <stdint.h>
#include "..//inc//tm4c123gh6pm.h" 
#include "Switch.h"
#include "LED.h"

#define PF2             (*((volatile uint32_t *)0x40025010))
#define PF1             (*((volatile uint32_t *)0x40025008))

static void GPIOArm(void){					//enable interrupts for the buttons again
  GPIO_PORTB_ICR_R = 0x03;      // (e) clear flag4
  GPIO_PORTB_IM_R |= 0x03;      // (f) arm interrupt on PB4 *** No IME bit as mentioned in Book ***
  NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFF1FFF)|0x00004000;
	NVIC_EN0_R = 0x02;
}

void Timer2Arm(void){
	SYSCTL_RCGCTIMER_R |= 0x04;   // 0) activate TIMER2
  TIMER2_CTL_R = 0x00000000;    // 1) disable timer2A during setup
  TIMER2_CFG_R = 0x00000000;    // 2) configure for 32-bit mode
  TIMER2_TAMR_R = 0x00000001;   // 3) configure for periodic mode, default down-count settings
  TIMER2_TAILR_R = 160000;    // 4) reload value
  TIMER2_TAPR_R = 0;            // 5) bus clock resolution
  TIMER2_ICR_R = 0x00000001;    // 6) clear timer2A timeout flag
  TIMER2_IMR_R = 0x00000001;    // 7) arm timeout interrupt
  NVIC_PRI4_R = (NVIC_PRI4_R&0x00FFFFFF)|0x80000000; // 8) priority 4
// interrupts enabled in the main program after all devices initialized
// vector number 39, interrupt number 23
  NVIC_EN0_R = 1<<23;           // 9) enable IRQ 23 in NVIC
  TIMER2_CTL_R = 0x00000001;    // 10) enable timer2A
}

void Timer2A_Handler(void){
	TIMER2_IMR_R = 0x00000000;    // disarm timeout interrupt
  GPIOArm();   // start GPIO
}

// Initialize switch 1 to PB0

void Switch1_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x02;
	GPIO_PORTB_DIR_R &= ~0x01;
	GPIO_PORTB_DEN_R |= 0x01;
	GPIO_PORTB_AFSEL_R &= ~0x01;
	GPIO_PORTB_AMSEL_R &= ~0x1;
	GPIO_PORTB_PCTL_R &= ~0x0000000F;
	GPIO_PORTB_IS_R &= ~0x01;
	GPIO_PORTB_IBE_R &= ~0x01;
	GPIO_PORTB_ICR_R = 0x01;
	GPIO_PORTB_IEV_R |= 0x01;
	GPIO_PORTB_IM_R |= 0x01;
	NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFF1FFF)|0x00004000;
	NVIC_EN0_R = 0x02;
}

// Initialize switch 2 to PB1

void Switch2_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x02;
	GPIO_PORTB_DIR_R &= ~0x02;
	GPIO_PORTB_DEN_R |= 0x02;
	GPIO_PORTB_AFSEL_R &= ~0x02;
	GPIO_PORTB_PCTL_R &= ~0x000000F0;
	GPIO_PORTB_AMSEL_R &= ~0x02;
	GPIO_PORTB_IS_R &= ~0x02;
	GPIO_PORTB_IBE_R &= ~0x02;
	GPIO_PORTB_ICR_R = 0x02;
	GPIO_PORTB_IEV_R |= 0x02;
	GPIO_PORTB_IM_R |= 0x02;
	NVIC_PRI0_R = (NVIC_PRI0_R&0xFFFF1FFF)|0x00004000;
	NVIC_EN0_R = 0x02;
}

int clear_flag = 0, push_flag = 0;

void GPIOPortB_Handler(void){
		
	NVIC_ST_CURRENT_R = 0;
	
	GPIO_PORTB_IM_R &= ~0x03;
	
	// get the pin identification
	int pin_id = GPIO_PORTB_RIS_R & 0x03;
	
		// acknowledge the interrupt
	if(pin_id == 1){
		GPIO_PORTB_ICR_R = 0x01;
		//GPIO_PORTB_IM_R &= ~0x01;
	}
	else if(pin_id == 2){
			GPIO_PORTB_ICR_R = 0x02;
			//GPIO_PORTB_IM_R &= ~0x02;
	}
	
	// reset the cart
	if(pin_id == 1){
		LED_On();
		clear_flag = 1;
	}
	// push cart to server
	else if(pin_id == 2){
		push_flag = 1;
		LED_Off();
	}
	Timer2Arm();
}


int Get_ClearFlag(void){
	
	return clear_flag;
}

void Set_ClearFlag(int flag){
	clear_flag = flag;
}


void DelayWait10ms(int n){
	uint32_t volatile time;
  while(n){
    time = 727240*2/91;  // 10msec
    while(time){
	  	time--;
    }
    n--;
  }
}
