#ifndef HARDWARE_H_INCLUDED
#define HARDWARE_H_INCLUDED

#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "GPIO.h"
#include <string.h>

struct timer_t {
    uint8_t hs, s, m, h;
};

volatile struct timer_t tid;
volatile uint8_t flag;

int joyinout();

void setLed(int *liv);

void timer_pp();
void timer_pp1(uint32_t timer_speed);

void TIM2_IRQHandler(void);

void lcd_write_string(char *string_ting, int slice, int line, uint8_t *buffer);

void lcd_update(int *k);

#endif /* HARDWARE_H_INCLUDED */
