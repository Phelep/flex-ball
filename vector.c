#define ESC 0x1B
#include "vector.h"
#define FIX14_SHIFT 14
#define FIX14_MULT(a,b) ((a)*(b) >> FIX14_SHIFT)
#define FIX14_DIV(a,b) (((a) << FIX14_SHIFT) / b)


void initVector(struct vector_t * v, int32_t x, int32_t y)
{
    v->x = x << 14;
    v->y = y << 14;
}


void rotato(struct vector_t * v, int vink)
{
    int32_t x = FIX14_MULT(v->x,cosinus(vink))-FIX14_MULT(v->y,sinus(vink));
    int32_t y = FIX14_MULT(v->x,sinus(vink))+FIX14_MULT(v->y,cosinus(vink));

    v->x = x;
    v->y = y;

    //printFix(expand(x));
    //printf(",");
    //printFix(expand(y));
}

void rotato_ball(struct ball_t * v, int vink)
{
    int32_t v_xb = FIX14_MULT(v->v_xb,cosinus(vink));
    int32_t v_yb = FIX14_MULT(v->v_yb,sinus(vink));

    v->v_xb = v_xb;
    v->v_yb = v_yb;

}

