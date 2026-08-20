#ifndef SERVO_TESTER_H
#define SERVO_TESTER_H

void servo_pin_action(void);
void servo_angle_action(void);
void servo_pulse_action(void);
void servo_freq_action(void);
void servo_confirm_action(void);

void servo_draw_pin(void);
void servo_draw_angle(void);
void servo_draw_pulse(void);
void servo_draw_freq(void);

void servo_tester(void);
void servo_tester_run(void);

#endif