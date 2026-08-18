#ifndef PWM_GENERATOR_H
#define PWM_GENERATOR_H

void pin_action(void);
void duty_action(void);
void freq_action(void);
void confirm_action(void);

void draw_pin(void);
void draw_freq(void);
void draw_duty(void);

void pwm_generator(void);
void pwm_generator_run(void);

#endif