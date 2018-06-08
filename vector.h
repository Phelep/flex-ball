#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include "stm32f30x_conf.h"
#include "30010_io.h"

struct vector_t
{
    int32_t x,y;
};
void initVector(struct vector_t * v, int32_t x, int32_t y);

void rotato(struct vector_t * v, int vink);




#endif /* VECTOR_H_INCLUDED */
