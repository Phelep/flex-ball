#ifndef HARDWARE_H_INCLUDED
#define HARDWARE_H_INCLUDED

#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "GPIO.h"

typedef struct timer_t {
    uint8_t hs, s, m, h;
};

volatile struct timer_t tid;
volatile uint8_t flag;

int joyinout();

void setLed(int farve);

void timer_pp();

void TIM2_IRQHandler(void);

void lcd_write_string(char *benis, int slice, int line, uint8_t *buffer);

void lcd_update(int *k);

#endif /* HARDWARE_H_INCLUDED */
