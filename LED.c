#include <stdint.h>
#include "..//inc//tm4c123gh6pm.h" 
#include "LED.h"



void LED_Init(void){ 
	volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x04;           // 1) activate clock for Port C
  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
  GPIO_PORTC_PCTL_R &= ~0x000F0000; // 3) regular GPIO. was ~0x00000F00
  GPIO_PORTC_AMSEL_R &= ~0x10;      // 4) disable analog function on PC4
  GPIO_PORTC_DIR_R |= 0x10;         // 5) set direction to output
  GPIO_PORTC_AFSEL_R &= ~0x10;      // 6) regular port function
  GPIO_PORTC_DEN_R |= 0x10;         // 7) enable digital port
}

void LED_On(void){
	GPIO_PORTC_DATA_R |= 0x10;
}

void LED_Off(void){
	GPIO_PORTC_DATA_R &= ~0x10;
}


