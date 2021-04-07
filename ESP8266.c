// U0Rx (VCP receive) connected to PA0
// U0Tx (VCP transmit) connected to PA1
#include <stdint.h>
#include "ESP8266.h"
#include "../inc/tm4c123gh6pm.h"


#define UART_FR_TXFF            0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE            0x00000010  // UART Receive FIFO Empty
#define UART_LCRH_WLEN_8        0x00000060  // 8 bit word length
#define UART_LCRH_FEN           0x00000010  // UART Enable FIFOs
#define UART_CTL_UARTEN         0x00000001  // UART Enable


//------------UART_Init------------
// Initialize the UART for 115,200 baud rate (assuming 50 MHz UART clock),
// 8 bit word length, no parity bits, one stop bit, FIFOs enabled
// Input: none
// Output: none
void UART_Init(void){
  SYSCTL_RCGCUART_R |= 0x08;            // activate UART3
  SYSCTL_RCGCGPIO_R |= 0x04;            // activate port C
  while((SYSCTL_PRGPIO_R&0x01) == 0){};
  UART3_CTL_R &= ~UART_CTL_UARTEN;      // disable UART
  UART3_IBRD_R = 27;                    // IBRD = int(50,000,000 / (16 * 115,200)) = int(27.1267)
  UART3_FBRD_R = 8;                     // FBRD = int(0.1267 * 64 + 0.5) = 8
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART3_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
  UART3_CTL_R |= 0x01;                 // enable UART
  GPIO_PORTC_AFSEL_R |= 0x000000C0;           // enable alt funct on PA1-0
  GPIO_PORTC_DEN_R |= 0x000000C0;             // enable digital I/O on PA1-0
                                        // configure PA1-0 as UART
  GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0x00FFFFFF)+0x11000000;
  GPIO_PORTC_AMSEL_R &= ~0x000000C0;          // disable analog functionality on PA
}
