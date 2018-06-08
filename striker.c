#define ESC 0x1B
#include "striker.h"


void initStriker(struct striker_t * v, int32_t p_x, int32_t p_y, int32_t v_x, int32_t v_y )
{
    v->v_x = v_x << 14;
    v->v_y = v_y << 14;
    v->p_x = p_x << 14;
    v->p_y = p_y << 14;

}

int striker_movement(struct striker_t * v, int x1, int x2, int y1, int y2)
{
  v->p_x = v->p_x + v->v_x;
    v->p_y = v->p_y ;
    if((v->p_x >> 14) ==  x1 || (v->p_x >> 14) ==  x2+1)
    {
        v->v_x = -v->v_x;
        /*
        if((v->v_y > 0 && v->v_x > 0) || (v->v_y < 0 && v->v_x < 0))
        {
            rotato(v,128);
        }
        else if ((v->v_y < 0 && v->v_x < 0) || (v->v_y > 0 && v->v_x > 0))
        {
            rotato(v,-128);
        }*/
    }
    else if((v->p_y >> 14) ==  y1 || (v->p_y >> 14) == y2)
    {
        v->v_y = 0;
        /*if((v->v_y > 0 && v->v_x < 0) || (v->v_y < 0 && v->v_x > 0))
        {
            rotato(v,-128);
        }
        else if ((v->v_y < 0 && v->v_x > 0) || (v->v_y > 0 && v->v_x < 0))
        {
            rotato(v,128);
        }*/
    }
    return 0;
}


void striker_print(struct striker_t * v)
{
    gotoxy(v->p_x >> 14, v -> p_y >> 14);
    printf("PENIS");
}
