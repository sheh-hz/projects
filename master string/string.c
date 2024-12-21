#include <lpc214x.h>
#define delay(x) for(i = 0; i < x; i++) //creating a macro delay function 
int main()
{
	int i, j; //i for macro function and j for character iteration
	char str[] = "Quest Innovative Solutions\r";
	PINSEL0 = 0x00001505; //selecting mosi, miso, sck and uart functionalities
	S0SPCCR = 0x08; //selecting clock divider as 8
	S0SPCR = 0x0020; //select as master
	U0LCR = 0x83; //uart configurations
	U0DLL = 97; 
	U0LCR = 0x03;
	while(1)
	{
		for(j = 0; str[j]; j++)
		{
			S0SPDR = str[j]; //writing data to the spi data register
			while(!(S0SPSR & 0x80)); //waiting for the spif bit to set
			delay(100000); //applying delay for synchronization
		}
	}
	return 0;
}