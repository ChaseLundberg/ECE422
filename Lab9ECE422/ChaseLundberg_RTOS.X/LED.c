
#include "LED.h"
#include "../mcc_generated_files/pin_manager.h"


//used for UART indicator (RED LED))
void LED_toggleOne(void){
    IO_RB15_Toggle();
}

//used for functions 'c' (YELLOW LED))
void LED_toggleTwo(void){
    IO_RB14_Toggle();
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