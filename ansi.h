#ifndef _ANSI_2_H_
#define _ANSI_2_H_

#include "stm32f30x_conf.h"
#include "LUT.h"
#include "30010_io.h"



void inverse(int invert);

void blink(int blinker);

void underline(uint8_t on);

void gotoxy(int x, int y);
void clreol();
void clrscr();
void fgcolor(int foreground);
void bgcolor(int background);
void color(int foreground, int background);
void resetbgcolor();
void window(int x1, int y1, int x2, int y2);
int32_t expand(int32_t i);
void wall(int x1, int y1, int x2, int y2);

#endif
