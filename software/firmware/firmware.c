#include "stdlib.h"
#include "system.h"
#include "periphs.h"
#include "iob-uart.h"
#include "printf.h"

int main()
{
unsigned long long elapsed;
unsigned int elapsedu;

//timer_reset(TIMER_BASE);
timer_reset(TIMER_BASE);


//init uart 
uart_init(UART_BASE,FREQ/BAUD);   
uart_printf("\nHello world!\n");
uart_txwait();

//read current timer count, compute elapsed time
elapsed = timer_get_count(TIMER_BASE);
elapsedu = timer_time_us(TIMER_BASE);

uart_printf("\nExecution time: %d clocks in %dus @%dMHz\n\n",
  		(unsigned int)elapsed, elapsedu, FREQ/1000000);
  		
uart_txwait();
return 0;
 ////init uart 
 //uart_init(UART_BASE,FREQ/BAUD);   
 //uart_printf("\n\n\nHello world number %d!\n\n\n", 1);
 //
 //printf_("Value of Pi = %f\n\n", 3.1415);
 //
 //uart_finish();
 //
}
