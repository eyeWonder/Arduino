/**********************************************************************************/
/*    Test program for:															  */
/*	  Board: PIC32-WEB_Rev.A													  */
/*    Manufacture: OLIMEX                                                   	  */
/*	  COPYRIGHT (C) 2009														  */
/*    Designed by: Engineer Penko T. Bozhkov                                      */
/*    Module Name    :  USART			                                          */
/*    File   Name    :  usart.h			                                          */
/*    Revision       :  Rev.A                                                     */
/*    Date           :  27.10.2009                                                */
/**********************************************************************************/
#ifndef __USART_H
#define __USART_H

/***** 1.All functions prototypes *****/
void USART_Init(long Baud_Rate, long USART_Clock_Source);
void USART_Send_Data(unsigned char Data);
void USART_Send_String(char *String_pointer);
void USART_Test_Menu_Begin(void);

/***** 2.All definitions *****/
#define USART_BUSY              (!(U1STAbits.TRMT))
#define USART_TxData_Reg        U1TXREG
#define USART_RxData_Reg        U1RXREG
#define fUSART_Receive_Set      USART_Flags_Register |= 0x01;
#define fUSART_Receive_Clear    USART_Flags_Register &= ~0x01;
#define fUSART_Receive_Check    (USART_Flags_Register & 0x01)

/***** 3.All variables *****/
extern volatile unsigned char USART_Flags_Register;
extern unsigned char USART_Received_Data;

#endif //__USART_H
