
#include "UART.h"


char Read(void)
{
    while(!(U1STAbits.URXDA == 1))
    {
        
    }

    if ((U1STAbits.OERR == 1))
    {
        U1STAbits.OERR = 0;
    }

    return U1RXREG;
}

void Write(char txData)
{
    while(U1STAbits.UTXBF == 1)
    {
        
    }

    U1TXREG = txData;    // Write the data byte to the USART.
}

void UART_init(void){
    
    RPINR18bits.U1RXR = 4;        //pin 11, RP4
    RPOR1bits.RP2R = 3;           //pin 6, RP2
            
    //BaudRate = 38400; Frequency = 4MHz Hz; U1BRG 100;
    U1BRG = 25; //create calculation function or just precalc the number
    
    U1STA = 0; //couldn't you use 0x0400 to double enable UTXEN bit and save line of code?
    
    U1MODE = 0;
    U1MODEbits.UARTEN = 1;
    
    U1STAbits.UTXEN = 1;
    U1STAbits.UTXISEL0 = 0; 
    U1STAbits.UTXISEL1 = 1;
    
    //IFS0 = (IFS0 & 0xF7FF); //flag 
    IFS0bits.U1RXIF = 0; // flag
    //IEC0 = (IEC0 | 0x0800); //enable interrupt for receiver
    IEC0bits.U1RXIE = 1; // enable interrupt for receiver
    IPC2bits.U1RXIP = 6; //interrupt priority lower than the button
    
}

