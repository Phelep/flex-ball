#ifndef STRIKER_H_INCLUDED
#define STRIKER_H_INCLUDED
#include "stm32f30x_conf.h"
#include "30010_io.h"

struct striker_t
{
    int32_t p_x, p_y;
    int32_t v_x, v_y;
};

#endif /* STRIKER_H_INCLUDED */
