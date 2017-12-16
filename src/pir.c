/*
 *
 *
 */

#include <stdint.h>
#include <msp430g2231.h>

#define	LED_R	(0x1 << 0x0)
#define	BIT(n)	(0x1 << (n))

static void sleep(unsigned int c)
{
	volatile unsigned int i;

	for(i = 0; i < c; i++);
}

static void led_r_on(void)
{
	P1OUT |= LED_R;
}

static void led_r_off(void)
{
	P1OUT &= ~LED_R;
}

static int get_pin(uint8_t n)
{
	return ((P1IN & BIT(n)) == BIT(n));
}

int main(void)

{

	volatile int val;

	// Stop watchdog timer
	WDTCTL = WDTPW + WDTHOLD;

	// Set P1.0 to output direction
	P1DIR |= LED_R;

	// Set P1.6 to input direction
	P1DIR &= ~BIT(6);

	led_r_off();

	for (;;)
	{
		val = get_pin(6);
		if (val)
		{
			led_r_on();
		}
		else
		{
			led_r_off();
		}


		sleep(10000);
	}
}
