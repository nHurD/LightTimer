#include <avr/io.h>
#include <util/delay.h>

#ifdef DEBUG
#define DEBUG_LED_PORT_DDR DDRC
#define DEBUG_LED_PORT PORTC
#define DEBUG_LED_PIN PC7
#endif

#define LED_PORT_DDR DDRD
#define LED_PORT PORTD
#define LED_PIN PD1

/* Setup delays and compare constants */
enum {
    BLINK_DELAY_MS = 1000,
    TWELVE_HOURS_SEC = 43200
};

int main (void) {
    
    /* Set the pin for output */
    LED_PORT_DDR = (1 << LED_PIN);

#ifdef DEBUG
    /* Set the debug pin (led) for output */
    DEBUG_LED_PORT_DDR = (1 << DEBUG_LED_PIN);
#endif
    
    
    /* Second counter */
    static long counter = 0;
    
    /* Enable the port */
    LED_PORT ^= (1 << LED_PIN);
    
#ifdef DEBUG
    /* Enable the debug port */
    DEBUG_LED_PORT ^= (1 << DEBUG_LED_PIN);
#endif
    
    /* Main loop */
    while(1) {
        
        /* If the counter makes it to 12 hours, reset and change the pin */
        if (counter == TWELVE_HOURS_SEC) {
            counter = 0;
            LED_PORT ^= (1 << LED_PIN);
#ifdef DEBUG
            DEBUG_LED_PORT ^= (1 << DEBUG_LED_PIN);
#endif
        }
        
        /* Increment */
        counter++;
        
        /* Sleep for 1 second */
        _delay_ms(BLINK_DELAY_MS);

    }

    return 0;
}
