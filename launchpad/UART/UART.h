#ifndef __UART_H__
#define __UART_H__

// Set the baudrate here:
#define BAUDRATE        9600

//Set this to 1 to have LEDs visual feedback for TX and RX activity.
#define USE_LEDS_TXRX   1


/*----------------------------------------------------------------------------*/
// Don't edit below this.

#if USE_LEDS_TXRX
/*
#define LED_TX_PIN  0
#define LED_RX_PIN  6
#define LEDS_PORT   1
*/
//Is it possible to substitute numbers below with the definitions above???

#define LED_TX            OUT_BIT(1, 0)
#define LED_TX_DIR        DIR_BIT(1, 0)
#define LED_RX            OUT_BIT(1, 6)
#define LED_RX_DIR        DIR_BIT(1, 6)
  
#define SETUP_UART_LEDS()  \
  LED_TX = 0; \
  LED_RX = 0; \
  LED_TX_DIR = 1; \
  LED_RX_DIR = 1

#define DIR_BIT(PORT,PIN)  \
        (P ## PORT ## DIR_bit.P ## PORT ## DIR_ ## PIN)

#define OUT_BIT(PORT,PIN)  \
        (P ## PORT ## OUT_bit.P ## PORT ## OUT_ ## PIN)

#else

#define SETUP_UART_LEDS()
#define LED_TX
#define LED_RX

#endif


void initUART(void);
void UART_echo_mode(void);
void UART_tx_string (char * str);
void start_UART_rx(void);
unsigned char UART_get_char(void);

#endif //__UART_H__