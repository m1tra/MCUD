#include <avr/io.h>
#include <stdint.h>
#include "gpio.h"
#include "pwm.h"

// pin
// mode
// com
// duty
// prescaler

void pwm_init(PWM_settings pwm_settings)
{

    //MODE 14 todo: выбор юзером мода прескейлера и top значения
    TCCR4A = (1 << WGM41);

    TCCR4B = (1 << WGM43) |
             (1 << WGM42);


    
    // 1. OC4A сделать OUTPUT

    // 2. WGM: выбрать режим PWM

    // 3. COM: настроить поведение OC4A

    // 4. OCR: установить duty

    // 5. CS: выбрать prescaler и запустить Timer4
}