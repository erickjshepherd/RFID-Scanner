//*****************************************************************************
//
// trf79x0_hw_example.h - Hardware Pin configuration for TRF79x0 ATB on
// Tiva C Series Snowflake Class silicon. Tailored for DK-tm4c129x, but will
// work for any board with a Snowflake chip with RF Headers.
//
// Copyright (c) 2014-2017 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.4.178 of the Tiva Firmware Development Package.
//
//*****************************************************************************

#define GPIO_PA0_U0RX           0x00000001
#define GPIO_PA0_CAN1RX         0x00000008

#define GPIO_PA1_U0TX           0x00000401
#define GPIO_PA1_CAN1TX         0x00000408

#define GPIO_PA2_SSI0CLK        0x00000802

#define GPIO_PA3_SSI0FSS        0x00000C02

#define GPIO_PA4_SSI0RX         0x00001002

#define GPIO_PA5_SSI0TX         0x00001402

#define GPIO_PA6_I2C1SCL        0x00001803
#define GPIO_PA6_M1PWM2         0x00001805

#define GPIO_PA7_I2C1SDA        0x00001C03
#define GPIO_PA7_M1PWM3         0x00001C05

#define GPIO_PB0_U1RX           0x00010001
#define GPIO_PB0_T2CCP0         0x00010007

#define GPIO_PB1_U1TX           0x00010401
#define GPIO_PB1_T2CCP1         0x00010407

#define GPIO_PB2_I2C0SCL        0x00010803
#define GPIO_PB2_T3CCP0         0x00010807

#define GPIO_PB3_I2C0SDA        0x00010C03
#define GPIO_PB3_T3CCP1         0x00010C07

#define GPIO_PB4_SSI2CLK        0x00011002
#define GPIO_PB4_M0PWM2         0x00011004
#define GPIO_PB4_T1CCP0         0x00011007
#define GPIO_PB4_CAN0RX         0x00011008

#define GPIO_PB5_SSI2FSS        0x00011402
#define GPIO_PB5_M0PWM3         0x00011404
#define GPIO_PB5_T1CCP1         0x00011407
#define GPIO_PB5_CAN0TX         0x00011408

#define GPIO_PB6_SSI2RX         0x00011802
#define GPIO_PB6_M0PWM0         0x00011804
#define GPIO_PB6_T0CCP0         0x00011807

#define GPIO_PB7_SSI2TX         0x00011C02
#define GPIO_PB7_M0PWM1         0x00011C04
#define GPIO_PB7_T0CCP1         0x00011C07

#define GPIO_PC0_TCK            0x00020001
#define GPIO_PC0_SWCLK          0x00020001
#define GPIO_PC0_T4CCP0         0x00020007

#define GPIO_PC1_TMS            0x00020401
#define GPIO_PC1_SWDIO          0x00020401
#define GPIO_PC1_T4CCP1         0x00020407

#define GPIO_PC2_TDI            0x00020801
#define GPIO_PC2_T5CCP0         0x00020807

#define GPIO_PC3_SWO            0x00020C01
#define GPIO_PC3_TDO            0x00020C01
#define GPIO_PC3_T5CCP1         0x00020C07

#define GPIO_PC4_U4RX           0x00021001
#define GPIO_PC4_U1RX           0x00021002
#define GPIO_PC4_M0PWM6         0x00021004
#define GPIO_PC4_IDX1           0x00021006
#define GPIO_PC4_WT0CCP0        0x00021007
#define GPIO_PC4_U1RTS          0x00021008

#define GPIO_PC5_U4TX           0x00021401
#define GPIO_PC5_U1TX           0x00021402
#define GPIO_PC5_M0PWM7         0x00021404
#define GPIO_PC5_PHA1           0x00021406
#define GPIO_PC5_WT0CCP1        0x00021407
#define GPIO_PC5_U1CTS          0x00021408

#define GPIO_PC6_U3RX           0x00021801
#define GPIO_PC6_PHB1           0x00021806
#define GPIO_PC6_WT1CCP0        0x00021807
#define GPIO_PC6_USB0EPEN       0x00021808

#define GPIO_PC7_U3TX           0x00021C01
#define GPIO_PC7_WT1CCP1        0x00021C07
#define GPIO_PC7_USB0PFLT       0x00021C08

#define GPIO_PD0_SSI3CLK        0x00030001
#define GPIO_PD0_SSI1CLK        0x00030002
#define GPIO_PD0_I2C3SCL        0x00030003
#define GPIO_PD0_M0PWM6         0x00030004
#define GPIO_PD0_M1PWM0         0x00030005
#define GPIO_PD0_WT2CCP0        0x00030007

#define GPIO_PD1_SSI3FSS        0x00030401
#define GPIO_PD1_SSI1FSS        0x00030402
#define GPIO_PD1_I2C3SDA        0x00030403
#define GPIO_PD1_M0PWM7         0x00030404
#define GPIO_PD1_M1PWM1         0x00030405
#define GPIO_PD1_WT2CCP1        0x00030407

#define GPIO_PD2_SSI3RX         0x00030801
#define GPIO_PD2_SSI1RX         0x00030802
#define GPIO_PD2_M0FAULT0       0x00030804
#define GPIO_PD2_WT3CCP0        0x00030807
#define GPIO_PD2_USB0EPEN       0x00030808

#define GPIO_PD3_SSI3TX         0x00030C01
#define GPIO_PD3_SSI1TX         0x00030C02
#define GPIO_PD3_IDX0           0x00030C06
#define GPIO_PD3_WT3CCP1        0x00030C07
#define GPIO_PD3_USB0PFLT       0x00030C08

#define GPIO_PD4_U6RX           0x00031001
#define GPIO_PD4_WT4CCP0        0x00031007

#define GPIO_PD5_U6TX           0x00031401
#define GPIO_PD5_WT4CCP1        0x00031407

#define GPIO_PD6_U2RX           0x00031801
#define GPIO_PD6_M0FAULT0       0x00031804
#define GPIO_PD6_PHA0           0x00031806
#define GPIO_PD6_WT5CCP0        0x00031807

#define GPIO_PD7_U2TX           0x00031C01
#define GPIO_PD7_PHB0           0x00031C06
#define GPIO_PD7_WT5CCP1        0x00031C07
#define GPIO_PD7_NMI            0x00031C08

#define GPIO_PE0_U7RX           0x00040001

#define GPIO_PE1_U7TX           0x00040401

#define GPIO_PE4_U5RX           0x00041001
#define GPIO_PE4_I2C2SCL        0x00041003
#define GPIO_PE4_M0PWM4         0x00041004
#define GPIO_PE4_M1PWM2         0x00041005
#define GPIO_PE4_CAN0RX         0x00041008

#define GPIO_PE5_U5TX           0x00041401
#define GPIO_PE5_I2C2SDA        0x00041403
#define GPIO_PE5_M0PWM5         0x00041404
#define GPIO_PE5_M1PWM3         0x00041405
#define GPIO_PE5_CAN0TX         0x00041408

#define GPIO_PF0_U1RTS          0x00050001
#define GPIO_PF0_SSI1RX         0x00050002
#define GPIO_PF0_CAN0RX         0x00050003
#define GPIO_PF0_M1PWM4         0x00050005
#define GPIO_PF0_PHA0           0x00050006
#define GPIO_PF0_T0CCP0         0x00050007
#define GPIO_PF0_NMI            0x00050008
#define GPIO_PF0_C0O            0x00050009

#define GPIO_PF1_U1CTS          0x00050401
#define GPIO_PF1_SSI1TX         0x00050402
#define GPIO_PF1_M1PWM5         0x00050405
#define GPIO_PF1_PHB0           0x00050406
#define GPIO_PF1_T0CCP1         0x00050407
#define GPIO_PF1_C1O            0x00050409
#define GPIO_PF1_TRD1           0x0005040E

#define GPIO_PF2_SSI1CLK        0x00050802
#define GPIO_PF2_M0FAULT0       0x00050804
#define GPIO_PF2_M1PWM6         0x00050805
#define GPIO_PF2_T1CCP0         0x00050807
#define GPIO_PF2_TRD0           0x0005080E

#define GPIO_PF3_SSI1FSS        0x00050C02
#define GPIO_PF3_CAN0TX         0x00050C03
#define GPIO_PF3_M1PWM7         0x00050C05
#define GPIO_PF3_T1CCP1         0x00050C07
#define GPIO_PF3_TRCLK          0x00050C0E

#define GPIO_PF4_M1FAULT0       0x00051005
#define GPIO_PF4_IDX0           0x00051006
#define GPIO_PF4_T2CCP0         0x00051007
#define GPIO_PF4_USB0EPEN       0x00051008

#ifndef __TRF79X0_HW_H__
#define __TRF79X0_HW_H__
#define PART_TM4C123GH6PM
//*****************************************************************************
//
// Enable the TRF79x0 that will be used with the TM4C129X board
// Enabled = 1, Disabled = 0
//
//*****************************************************************************
#define RF_DAUGHTER_TRF7960         0
#define RF_DAUGHTER_TRF7970         1

//*****************************************************************************
//
// Check for correct definition of RF_DAUGTHER_TRF79X0
//
//*****************************************************************************
#if (RF_DAUGHTER_TRF7960 && RF_DAUGHTER_TRF7970)
#error "Only one TRF79X0 can be defined at the same time."
#elif (!(RF_DAUGHTER_TRF7960 || RF_DAUGHTER_TRF7970))
#error "Define the TRF79X0 to be used, none currently defined."
#endif

//*****************************************************************************
//
// Pin definitions for the DK-TM4C129X development board connections to the
// BoosterPack board.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup nfc_hw NFC Hardware Definitions
//! @{
//! This section covers the definitions that control which hardware is used to
//! communicate with the TRF79x0 EM module.  These defines configure which SSI
//! peripheral is used as well as which pins are assigned to the other
//! connections to the TRF79x0 EM module.  The \b TRF79X0_SSI_* defines are
//! used to specify the SSI peripheral that is used by the application.  The
//! remaining defines specify the pins used by the NFC APIs.  The TRF79x0
//! EM module requires the following signal connections: CLK, RX, TX, CS, ASKOK,
//! EN, EN2, IRQ, MOD.  To configure these signals, three defines must be set
//! for each. For example, for the CS signal, the \ref TRF79X0_CS_BASE,
//! \ref TRF79X0_CS_PERIPH and \ref TRF79X0_CS_PIN defines must be set.
//!
//! \b Example:  CS pin is on GPIO port E pin 1.
//! \verbatim
//!
//! #define TRF79X0_CS_BASE         GPIO_PORTA_BASE
//! #define TRF79X0_CS_PERIPH       SYSCTL_PERIPH_GPIOA
//! #define TRF79X0_CS_PIN          GPIO_PIN_4
//! \endverbatim
//!
//*****************************************************************************

//*****************************************************************************
//
//! The clock rate of the SSI clock specified in Hz.
//!
//! \b Example: 2-MHz SSI data clock.
//!
//! <tt>\#define SSI_CLK_RATE        2000000</tt>
//!
//*****************************************************************************
#define SSI_CLK_RATE            4000000
#define SSI_CLKS_PER_MS         (SSI_CLK_RATE / 1000)
#define STATUS_READS_PER_MS     (SSI_CLKS_PER_MS / 16)
#define SSI_NO_DATA              0

//*****************************************************************************
//
//! Specifies the SSI peripheral for the SSI port that is connected to the
//! TRF79x0 EM board.  The value should be set to SYSCTL_PERIPH_SSIn, where n is
//! the number of the SSI port being used.
//!
//! \b Example: Uses SSI0 peripheral
//!
//! <tt>\#define TRF79X0_SSI_PERIPH      SYSCTL_PERIPH_SSI0</tt>
//!
//*****************************************************************************
#define TRF79X0_SSI_PERIPH      SYSCTL_PERIPH_SSI2

//*****************************************************************************
//
//! Specifies the SSI @a base address for the SSI port that is connected to the
//! TRF79x0 EM board.  The value should be set to SYSCTL_PERIPH_SSIn, where n is
//! the number of the SSI port being used.
//!
//! \b Example: Uses SSI0 peripheral
//!
//! <tt>\#define TRF79X0_SSI_BASE        SSI0_BASE</tt>
//!
//*****************************************************************************
#define TRF79X0_SSI_BASE        SSI2_BASE

//*****************************************************************************
//
// GPIO pin deffinitions for TRF79x0 SSI signals
//
//*****************************************************************************

//
//! Specifies the @a base address of the GPIO port that is connected to the SSI
//! Clock signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral CLK signal is on GPIO port A.
//!
//! <tt>\#define TRF79X0_CLK_BASE        GPIO_PORTA_BASE</tt>
//
#define TRF79X0_CLK_BASE        GPIO_PORTB_BASE

//
//! Specifies the @a peripheral for the GPIO port that is connected to the SSI
//! Clock signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral CLK signal is on GPIO port A.
//!
//! <tt>\#define TRF79X0_CLK_PERIPH      SYSCTL_PERIPH_GPIOA</tt>
//
#define TRF79X0_CLK_PERIPH      SYSCTL_PERIPH_GPIOB

//
//! Specifies the GPIO pin that is connected to the SSI
//! Clock signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral CLK signal is on GPIO pin 2.
//!
//! <tt>\#define TRF79X0_CLK_PIN         GPIO_PIN_2</tt>
//
#define TRF79X0_CLK_PIN         GPIO_PIN_4

//
//! Specifies the GPIO pin that is connected to
//! the SSI Clock signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI Clock signal is on GPIO port A pin 2.
//!
//! <tt>\#define TRF79X0_CLK_CONFIG      GPIO_PA2_SSI0CLK</tt>
//
#define TRF79X0_CLK_CONFIG      GPIO_PB4_SSI2CLK

//
//! Specifies the @a base address of the GPIO port that is connected to the SSI
//! TX signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral TX signal is on GPIO port A.
//!
//! <tt>\#define TRF79X0_TX_BASE         GPIO_PORTA_BASE</tt>
//
#define TRF79X0_TX_BASE         GPIO_PORTB_BASE

//
//! Specifies the @a peripheral for the GPIO port that is connected to the SSI
//! TX signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral TX signal is on GPIO port A.
//!
//! <tt>\#define TRF79X0_TX_PERIPH       SYSCTL_PERIPH_GPIOA</tt>
//
#define TRF79X0_TX_PERIPH       SYSCTL_PERIPH_GPIOB

//
//! Specifies the GPIO pin that is connected to the SSI
//! TX signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral TX signal is on GPIO pin 4.
//!
//! <tt>\#define TRF79X0_TX_PIN          GPIO_PIN_4</tt>
//
#define TRF79X0_TX_PIN          GPIO_PIN_7

//
//! Specifies the GPIO pin that is connected to
//! the SSITX (DAT0) signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI 1 TX signal is on GPIO port A pin 4.
//!
//! <tt>\#define TRF79X0_TX_CONFIG       GPIO_PA4_SSI0XDAT0</tt>
//
#define TRF79X0_TX_CONFIG       GPIO_PB7_SSI2TX 

//
//! Specifies the @a base address of the GPIO port that is connected to the SSI
//! RX signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral RX signal is on GPIO port A.
//!
//! <tt>\#define TRF79X0_RX_BASE         GPIO_PORTA_BASE</tt>
//
#define TRF79X0_RX_BASE         GPIO_PORTB_BASE

//
//! Specifies the @a peripheral for the GPIO port that is connected to the SSI
//! RX signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral RX signal is on GPIO port A.
//!
//! <tt>\#define TRF79X0_RX_PERIPH       SYSCTL_PERIPH_GPIOA</tt>
//
#define TRF79X0_RX_PERIPH       SYSCTL_PERIPH_GPIOB

//
//! Specifies the GPIO pin that is connected to the SSI
//! RX signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral RX signal is on GPIO pin 5.
//!
//! <tt>\#define TRF79X0_RX_PIN          GPIO_PIN_5</tt>
//
#define TRF79X0_RX_PIN          GPIO_PIN_6

//
//! Specifies the GPIO pin that is connected to
//! the SSIRX (DAT1) signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI 1 RX signal is on GPIO port A pin 5.
//!
//! <tt>\#define TRF79X0_RX_CONFIG       GPIO_PA5_SSI0XDAT1</tt>
//
#define TRF79X0_RX_CONFIG       GPIO_PB6_SSI2RX        

//*****************************************************************************
//
// Hardware connection definitions for the TRF79x0 board.
//
//*****************************************************************************

//
//! Specifies the @a base address of the GPIO port that is connected to the SSI
//! CS signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI CS signal is on GPIO port A.
//!
//! <tt>\#define TRF79X0_CS_BASE         GPIO_PORTA_BASE</tt>
//
#define TRF79X0_CS_BASE         GPIO_PORTB_BASE

//
//! Specifies the @a peripheral for the GPIO port that is connected to the SSI
//! CS signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI CS signal is on GPIO port A.
//!
//! <tt>\#define TRF79X0_CS_PERIPH       SYSCTL_PERIPH_GPIOA</tt>
//
#define TRF79X0_CS_PERIPH       SYSCTL_PERIPH_GPIOB

//
//! Specifies the GPIO pin that is connected to the SSI
//! CS signal on the TRF79x0 EM board.
//!
//! \b Example: The SSI peripheral CS signal is on GPIO pin 4.
//!
//! <tt>\#define TRF79X0_CS_PIN          GPIO_PIN_4</tt>
//
#define TRF79X0_CS_PIN          GPIO_PIN_5

//
//! Specifies the @a base address of the GPIO port that is connected to the EN
//! signal on the TRF79x0 EM board.
//!
//! \b Example: The EN signal is on GPIO port D.
//!
//! <tt>\#define TRF79X0_EN_BASE         GPIO_PORTD_BASE</tt>
//
#define TRF79X0_EN_BASE         GPIO_PORTA_BASE

//
//! Specifies the @a peripheral for the GPIO port that is connected to the EN
//! signal on the TRF79x0 EM board.
//!
//! \b Example: The EN signal is on GPIO port D.
//!
//! <tt>\#define TRF79X0_EN_PERIPH       SYSCTL_PERIPH_GPIOD</tt>
//
#define TRF79X0_EN_PERIPH       SYSCTL_PERIPH_GPIOA

//
//! Specifies the GPIO pin that is connected to the EN pin on the
//! TRF79x0 EM board.
//!
//! \b Example: The EN signal is on GPIO pin 2.
//!
//! <tt>\#define TRF79X0_EN_PIN          GPIO_PIN_2</tt>
//
#define TRF79X0_EN_PIN          GPIO_PIN_7

//
//! Specifies the @a base address of the GPIO port that is connected to the EN2
//! signal on the TRF79x0 EM board.
//!
//! \b Example: The EN2 signal is on GPIO port D.
//!
//! <tt>\#define TRF79X0_EN2_BASE        GPIO_PORTD_BASE</tt>
//
#define TRF79X0_EN2_BASE        GPIO_PORTB_BASE

//
//! Specifies the @a peripheral for the GPIO port that is connected to the EN2
//! signal on the TRF79x0 EM board.
//!
//! \b Example: The EN2 signal is on GPIO port D.
//!
//! <tt>\#define TRF79X0_EN2_PERIPH      SYSCTL_PERIPH_GPIOD</tt>
//
#define TRF79X0_EN2_PERIPH      SYSCTL_PERIPH_GPIOB

//
//! Specifies the GPIO pin that is connected to the EN2 signal on the
//! TRF79x0 EM board.
//!
//! \b Example: The EN2 signal is on GPIO pin 3.
//!
//! <tt>\#define TRF79X0_EN2_PIN         GPIO_PIN_3</tt>
//
#define TRF79X0_EN2_PIN         GPIO_PIN_1

//
//! Specifies the @a base address of the GPIO port that is connected to the
//! ASKOK signal on the TRF79x0 EM board.
//!
//! \b Example: The ASKOK signal is on GPIO port J.
//!
//! <tt>\#define TRF79X0_ASKOK_BASE      GPIO_PORTJ_BASE</tt>
//
#define TRF79X0_ASKOK_BASE      GPIO_PORTE_BASE

//
//! Specifies the @a peripheral for the GPIO port that is connected to the ASKOK
//! signal on the TRF79x0 EM board.
//!
//! \b Example: The ASKOK signal is on GPIO port J.
//!
//! <tt>\#define TRF79X0_ASKOK_PERIPH    SYSCTL_PERIPH_GPIOJ</tt>
//
#define TRF79X0_ASKOK_PERIPH    SYSCTL_PERIPH_GPIOE

//
//! Specifies the GPIO pin that is connected to the ASKOK signal on
//! the TRF79x0 EM board.
//!
//! \b Example: The ASKOK signal is on GPIO pin 5.
//!
//! <tt>\#define TRF79X0_ASKOK_PIN       GPIO_PIN_5</tt>
//
#define TRF79X0_ASKOK_PIN       GPIO_PIN_4

//
//! Specifies the @a base address of the GPIO port that is connected to the MOD
//! signal on the TRF79x0 EM board.
//!
//! \b Example: The MOD signal is on GPIO port J.
//!
//! <tt>\#define TRF79X0_MOD_BASE        GPIO_PORTJ_BASE</tt>
//
#define TRF79X0_MOD_BASE        GPIO_PORTE_BASE

//
//! Specifies the @a peripheral for the GPIO port that is connected to the MOD
//! signal on the TRF79x0 EM board.
//!
//! \b Example: The MOD signal is on GPIO port J.
//!
//! <tt>\#define TRF79X0_MOD_PERIPH      SYSCTL_PERIPH_GPIOJ</tt>
//
#define TRF79X0_MOD_PERIPH      SYSCTL_PERIPH_GPIOE

//
//! Specifies the GPIO pin that is connected to the MOD signal on the
//! TRF79x0 EM board.
//!
//! \b Example: The MOD signal is on GPIO pin 4.
//!
//! <tt>\#define TRF79X0_MOD_PIN         GPIO_PIN_4</tt>
//
#define TRF79X0_MOD_PIN         GPIO_PIN_5

//
//! Specifies the @a base address of the GPIO port that is connected to the IRQ
//! signal on the TRF79x0 EM board.
//!
//! \b Example: The IRQ signal is on GPIO port D.
//!
//! <tt>\#define TRF79X0_IRQ_BASE        GPIO_PORTJ_BASE</tt>
//
#define TRF79X0_IRQ_BASE        GPIO_PORTE_BASE

//
//! Specifies the @a peripheral for the GPIO port that is connected to the IRQ
//! signal on the TRF79x0 EM board.
//!
//! \b Example: The IRQ signal is on GPIO port J.
//!
//! <tt>\#define TRF79X0_IRQ_PERIPH      SYSCTL_PERIPH_GPIOJ</tt>
//
#define TRF79X0_IRQ_PERIPH      SYSCTL_PERIPH_GPIOE

//
//! Specifies the GPIO pin that is connected to the IRQ signal on the
//! TRF79x0 EM board.
//!
//! \b Example: The IRQ signal is on GPIO pin 1.
//!
//! <tt>\#define TRF79X0_IRQ_PIN         GPIO_PIN_1</tt>
//
#define TRF79X0_IRQ_PIN         GPIO_PIN_0

//
//! Specifies GPIO interrupt that is tied to the GPIO port that the IRQ signal
//! is connected to TRF79x0 EM board.
//!
//! \b Example: SSI GPIO interrupt is on GPIO port C.
//!
//! <tt>\#define TRF79X0_IRQ_INT         INT_GPIOC</tt>
//
#define TRF79X0_IRQ_INT         INT_GPIOE_TM4C123

//
//  Uses Blue LED part of RGB tricolor LED (arbitrary color choice)
//
#define ENABLE_LED_PERIPHERAL SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOQ);
#define SET_LED_DIRECTION GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_4 );
#define TURN_ON_LED  GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_4, GPIO_PIN_4);
#define TURN_OFF_LED GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_4, 0);

//*****************************************************************************
//
// Optional LED Defines, useful for boards that have tricolor LED's
//
//*****************************************************************************
#define BOARD_HAS_TRICOLOR_LED              1

#define ENABLE_LED_TRICOLOR_RED_PERIPH      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
#define SET_LED_TRICOLOR_RED_DIRECTION      GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_5 );
#define TURN_ON_LED_TRICOLOR_RED            GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_5, GPIO_PIN_5);
#define TURN_OFF_LED_TRICOLOR_RED           GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_5, 0);

#define ENABLE_LED_TRICOLOR_BLUE_PERIPH     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOQ);
#define SET_LED_TRICOLOR_BLUE_DIRECTION     GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_4 );
#define TURN_ON_LED_TRICOLOR_BLUE           GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_4, GPIO_PIN_4);
#define TURN_OFF_LED_TRICOLOR_BLUE          GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_4, 0);

#define ENABLE_LED_TRICOLOR_GREEN_PERIPH    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOQ);
#define SET_LED_TRICOLOR_GREEN_DIRECTION    GPIOPinTypeGPIOOutput(GPIO_PORTQ_BASE, GPIO_PIN_7 );
#define TURN_ON_LED_TRICOLOR_GREEN          GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_7, GPIO_PIN_7);
#define TURN_OFF_LED_TRICOLOR_GREEN         GPIOPinWrite(GPIO_PORTQ_BASE, GPIO_PIN_7, 0);

//*****************************************************************************
//
// Macro for IRQ signal from TRF79x0 -> Board
// left in this format for cross platform compatibility.
//
//*****************************************************************************
#define IRQ_IS_SET()        GPIOPinRead(TRF79X0_IRQ_BASE, TRF79X0_IRQ_PIN)

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

#endif // __TRF79X0_HW_H__
