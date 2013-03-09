#include <avr/io.h>
#include <util/delay.h>

/* Set Delay in Milisecionds: 12 hours -> 43200000 */
enum {
  BLINK_DELAY_MS = 4320000UL,
};

int main (void) {
    /* set pin 2 of PORTD for output.*/
    DDRD |= _BV(DDD1);

    while(1) {
        /* set pin high to turn light on */
        PORTD |= _BV(PORTD1);
        _delay_ms(BLINK_DELAY_MS);

        /* set pin low to turn light off */
        PORTD &= ~_BV(PORTD1);
        _delay_ms(BLINK_DELAY_MS);
    }

    return 0;
}
