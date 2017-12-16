/*
 *
 *
 */

#include <stdint.h>
#include <msp430g2231.h>

#define	LED_R	(0x1 << 0x0)
#define	LED_G	(0x1 << 0x6)

static void sleep(unsigned int c)
{
	volatile unsigned int i;

	for(i = 0; i < c; i++);
}

int main(void)

{
	// Stop watchdog timer
	WDTCTL = WDTPW + WDTHOLD;

	// Set P1.0 and P1.6 to output direction
	P1DIR |= (LED_R | LED_G);

	// Init LED: LED_R is on
	P1OUT = LED_R;

	for (;;)
	{
		P1OUT ^= (LED_R | LED_G);
		sleep(10000);
	}
}
