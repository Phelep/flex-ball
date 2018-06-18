#define ESC 0x1B
#include "striker.h"

void initStriker(struct striker_t * s, int32_t p_xs, int32_t p_ys, int32_t v_xs, int32_t v_ys, int32_t temp_p_xs, int32_t temp_p_ys)
{
    s->v_xs = v_xs << 14;
    s->v_ys = v_ys << 14;
    s->p_xs = p_xs << 14;
    s->p_ys = p_ys << 14;
    s->temp_p_xs = temp_p_xs << 14;
    s->temp_p_ys = temp_p_ys << 14;


}

int striker_movement(struct striker_t * s, int x1, int x2, int y1, int y2, int input, int *pow)
{
    s->p_xs = s->p_xs + s->v_xs;
    s->p_ys = s->p_ys;
    s->temp_p_xs = s->p_xs-s->v_xs;
    s->temp_p_ys = s->p_ys-s->v_ys;

if(pow[0]==0){
    if(( input == 16  && (s->p_xs >> 14) < x2)){
            s->v_xs = 1 << 11;
    }
    else if(( input == 8  && (s->p_xs >> 14) > x1)){
            s->v_xs = -1 << 11;
    }
    else if(input == 0b00000 || s->p_xs >> 14 == x1 || s->p_xs >> 14 == x2){
            s->v_xs = 0;
    }
}
else if(pow[0]==1){
        if(( input == 8  && (s->p_xs >> 14) < x2)){
            s->v_xs = 1 << 11;
    }
    else if(( input == 16  && (s->p_xs >> 14) > x1)){
            s->v_xs = -1 << 11;
    }
    else if(input == 0b00000 || s->p_xs >> 14 == x1 || s->p_xs >> 14 == x2){
            s->v_xs = 0;
    }
}

   /* if((v->p_x >> 14) ==  x1 || (v->p_x >> 14) ==  x2+1)
    {
        v->v_x = -v->v_x;

        if((v->v_y > 0 && v->v_x > 0) || (v->v_y < 0 && v->v_x < 0))
        {
            rotato(v,128);
        }
        else if ((v->v_y < 0 && v->v_x < 0) || (v->v_y > 0 && v->v_x > 0))
        {
            rotato(v,-128);
        }*/

    else if((s->p_ys >> 14) ==  y1 || (s->p_ys >> 14) == y2)
    {
        s->v_ys = 0;
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


void striker_print(struct striker_t * s)
{

    if(s->v_xs > 0){
        gotoxy(s->temp_p_xs >> 14, s->temp_p_ys >> 14);
        printf("%c", 32);
        gotoxy(s->p_xs >> 14, s -> p_ys >> 14);
        printf("=====");
    }
    else if (s->v_xs < 0){
        gotoxy(((s->temp_p_xs >> 14)+5), s->temp_p_ys >> 14);
        printf("%c", 32);
        gotoxy(s->p_xs >> 14, s -> p_ys >> 14);
        printf("=====");
    }

}
