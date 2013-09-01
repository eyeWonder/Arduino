/**********************************************************************************/
/*    Test program for:															  */
/*	  Board: PIC32-WEB_Rev.A													  */
/*    Manufacture: OLIMEX                                                   	  */
/*	  COPYRIGHT (C) 2009														  */
/*    Designed by: Engineer Penko T. Bozhkov                                      */
/*    Module Name    :  USART	                                                  */
/*    File   Name    :  usart.c			                                          */
/*    Revision       :  Rev.A                                                     */
/*    Date           :  27.10.2009                                                */
/**********************************************************************************/
#include "Compiler.h"
#include "usart-olimex.h"

//Global Variables initialization:
volatile unsigned char USART_Flags_Register = 0;
unsigned char USART_Received_Data = 0;


/**********************************************************************************/
/*  Function name: USART_Init		                                              */
/*  	Parameters                                                                */
/*          Input   :  Baud_Rate		                                          */
/*          Output  :  No		                                                  */
/*	Action: Initialize USART.													  */
/**********************************************************************************/
void USART_Init(long Baud_Rate, long USART_Clock_Source){
  // Init UART1:
	TRISFbits.TRISF8 = 0;		// Set UART1TX like output
	TRISFbits.TRISF2 = 1;		// Set UART1RX like input
	U1MODE = 0x00008000;		// Set UARTEN.  Note: this must be done before setting UTXEN
	U1STA = 0x00001400;			// RXEN set, TXEN set
	U1BRG = ((USART_Clock_Source)/16/Baud_Rate-1); // See PIC32MX Family Reference Manual, page 720, Equation 21-1:
	// As was defined before: GetPeripheralClock() = 80000000, BAUD_RATE = 19200
	// Calculate error if required. In current case it is: 0.0016%
	
	// Configure UART1 RX Interrupt
	ConfigIntUART1(UART_INT_PR2 | UART_RX_INT_EN);
	
}


/**********************************************************************************/
/*  Function name: USART_Send_Data                                                */
/*  	Parameters                                                                */
/*          Input   :  Data				                                          */
/*          Output  :  No		                                                  */
/*	Action: Send one data byte to HyperTerminal via USART.						  */
/**********************************************************************************/
void USART_Send_Data(unsigned char Data){
  while(USART_BUSY);	// Check USCI busy flag
  USART_TxData_Reg = Data;
}


/**********************************************************************************/
/*  Function name: USART_Read_Data                                                */
/*  	Parameters                                                                */
/*          Input   :  No				                                          */
/*          Output  :  Data		                                                  */
/*	Action: Send one data byte to HyperTerminal via USART.						  */
/**********************************************************************************/
char USART_Read_Data(void){
	while(!(U1STAbits.URXDA));	// Check RXDA: Receive Buffer Data Available bit (read-only)
	if(U1MODEbits.PDSEL == 3)
        return ((char)U1RXREG);
    else
        return ((char)(U1RXREG & 0xFF));
}


/**********************************************************************************/
/*  Function name: USART_Send_String                                              */
/*  	Parameters                                                                */
/*          Input   :  *String_pointer                                            */
/*          Output  :  No		                                                  */
/*	Action: Send string to HyperTerminal via USART.						  		  */
/**********************************************************************************/
void USART_Send_String(char *String_pointer){
  while(*String_pointer){
    USART_Send_Data(*String_pointer);
    String_pointer++;	
  }	
}


/**********************************************************************************/
/*  Function name: USART_Test_Menu_Begin                                          */
/*  	Parameters                                                                */
/*          Input   :  No						                                  */
/*          Output  :  No		                                                  */
/*	Action: First TEST Menu sending to HyperTerminal.			        		  */
/**********************************************************************************/
void USART_Test_Menu_Begin(void){
  // Write TEST Menu to HyperTerminal:
  USART_Send_String("\a\f\r***************************************************");
  USART_Send_String("\n\r**** Welcom to OLIMEX PIC32-WEB Demo program! *****");
  USART_Send_String("\n\r***************************************************");
  USART_Send_String("\n\r         ------ -------- ---------- ");
  USART_Send_String("\n\r        | LED  | Status | Emoticon |");
  USART_Send_String("\n\r         ------ -------- ---------- ");
}

