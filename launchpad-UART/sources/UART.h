#ifndef __UART_H__
#define __UART_H__

void Transmit(void);
void initUART(void);
void UART_echo_mode(void);
void UART_tx_string (unsigned char * str);


#endif //__UART_H__