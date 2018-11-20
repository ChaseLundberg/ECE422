
#include "gpio.h"

void LED_init(void){
    TRISB = 0x1F3F;
    T1CON = 0x00;           //Stops the Timer1 and reset control register
    TMR1 = 0x00;            //Clear contents of the timer register
    PR1 = 7815;             //Load the period register with the value 0xFFFF
    //IPC0bits.T1IP = 5;      //Setup Timer1 interrupt for desired priority level
    IPC0bits.T1IP = 5;
    
    //IFS0 = (IFS0 & 0xFFF7);      //Clear the Timer interrupt status flag
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    
    T1CONbits.TCKPS = 3;    //Prescaler set to 1:256
    T1CONbits.TON = 1;      //Start Timer1 with prescaler settings at 1:1 and 
                            //clock source set to the internal instruction cycle
}

void Button_init(void){
    
    RPINR0bits.INT1R = 0b000101; //pin 14, RP5
    
    INTCON1bits.NSTDIS = 0; //enable nesting
    IPC5bits.INT1IP = 7; //priority
    
    IFS1bits.INT1IF = 0; //flag
    //IFS1 = (IFS1 & 0xFFEF);
    IEC1bits.INT1IE = 1; //enable
    //IEC1 = (IEC1 | 0x0010);
    INTCON2bits.INT1EP = 1;
    
}