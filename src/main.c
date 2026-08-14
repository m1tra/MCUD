#include <avr/io.h>
#include <util/delay.h>

#include <avr/interrupt.h>


ISR(ADC_vect){}

ISR(TWI_vect){}

int main()
{
    sei();

    DDRA |=
        (1 << PA5);

    PORTA &= ~(1 << PA5);

    ADMUX = (1 << REFS0); // Vэт = 5в, A0

    ADCSRA |=
        (1 << ADIE) |
        (1 << ADEN) |
        (1 << ADPS2) |
        (1 << ADPS1) |
        (1 << ADPS0); 

    ADCSRA |= (1 << ADSC); 

    TWSR = 0;
    TWBR = 72;

    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN) | (1 << TWIE);

    while (1)
    {
    }
}
