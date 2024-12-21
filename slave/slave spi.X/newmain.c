#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 4000000
#include <xc.h>
int main()
{
    char ch;
    TXSTA = 0x24;
    RCSTA = 0x90;
    SPBRG = 25;
    SSPSTAT = 0x00;
    SSPCON = 0x25;
    TRISC = (1 << 3) | (1 << 4);
    while(1)
    {
        while(SSPIF == 0);
        ch = SSPBUF;
        SSPIF = 0;
        TXREG = ch;
        while(TRMT == 0);
        //__delay_ms(10);
    }
}