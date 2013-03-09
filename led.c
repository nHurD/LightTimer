#include <avr/io.h>
#include <util/delay.h>

/* Set Delay in Milisecionds: 8 hours -> 43200000 */
enum {
  BLINK_DELAY_MS = 43200000,
};

int main (void) {
    /* set pin 5 of PORTB for output*/
    DDRC |= _BV(DDC7);
    DDRD |= _BV(DDD1);

    while(1) {
        /* set pin 5 high to turn led on */
        PORTC |= _BV(PORTC7);
        PORTD |= _BV(PORTD1);
        _delay_ms(BLINK_DELAY_MS);

        /* set pin 5 low to turn led off */
        PORTC &= ~_BV(PORTC7);
        PORTD &= ~_BV(PORTD1);
        _delay_ms(BLINK_DELAY_MS);
    }

    return 0;
}
