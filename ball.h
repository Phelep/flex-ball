#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "striker.h"
#include "matematik.h"
#include "vector.h"
#include "boxes.h"

struct ball_t
{
    int32_t p_xb, p_yb, temp_p_xb, temp_p_yb;
    int32_t v_xb, v_yb;
};

void initBall(struct ball_t * v, int32_t p_xb, int32_t p_yb, int32_t v_xb, int32_t v_yb, int32_t temp_p_xb, int32_t temp_p_yb );

int ball_movement(struct ball_t * v, int x1, int x2, int y1, int y2, struct striker_t * s, int *hit, int *level, int *liv_flag, int liv, int *vinkel_bold, int *striker_hit);

void ball_print(struct ball_t * v);





#endif /* BALL_H_INCLUDED */
