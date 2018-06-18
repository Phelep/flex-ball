#ifndef STRIKER_H_INCLUDED
#define STRIKER_H_INCLUDED
#include "stm32f30x_conf.h"
#include "30010_io.h"
#include "hardware.h"

struct striker_t
{
    int32_t p_xs, p_ys, temp_p_xs, temp_p_ys;
    int32_t v_xs, v_ys;
};

void initStriker(struct striker_t * s, int32_t p_xs, int32_t p_ys, int32_t v_xs, int32_t v_ys, int32_t temp_p_xs, int32_t temp_p_ys );
int striker_movement(struct striker_t * s, int x1, int x2, int y1, int y2, int input, int *pow);
void striker_print(struct striker_t * s);

#endif /* STRIKER_H_INCLUDED */
