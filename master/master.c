#include <lpc214x.h>
#define delay(x) for(i = 0; i < x; i++)
int main()
{
	int i;
	char ch;
	PINSEL0 = 0x00001505;
	S0SPCCR = 0x08;
	S0SPCR = 0x0020;
	U0LCR = 0x83;
	U0DLL = 97; 
	U0LCR = 0x03;
	while(1)
	{
		S0SPDR = 'H';
		while(!(S0SPSR & 0x80));
		delay(1000);
		S0SPDR = '\r';
		while(!(S0SPSR & 0x80));
		delay(100000);
	}
	return 0;
}