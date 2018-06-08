#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include "stm32f30x_conf.h"
#include "30010_io.h"

struct ball_t
{
    int32_t p_x, p_y;
    int32_t v_x, v_y;
};

void initBall(struct ball_t * v, int32_t p_x, int32_t p_y, int32_t v_x, int32_t v_y );

int ball_movement(struct ball_t * v, int x1, int x2, int y1, int y2);

void ball_print(struct ball_t * v);

#endif /* BALL_H_INCLUDED */
