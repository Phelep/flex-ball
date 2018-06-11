#define ESC 0x1B
#include "ball.h"

void initBall(struct ball_t * v, int32_t p_xb, int32_t p_yb, int32_t v_xb, int32_t v_yb, int32_t temp_p_xb, int32_t temp_p_yb )
{
    // Hastighedsvektor, position og temp position
    v->v_xb = v_xb << 11;
    v->v_yb = v_yb << 11;
    v->p_xb = p_xb << 14;
    v->p_yb = p_yb << 14;
    v->temp_p_xb = temp_p_xb << 14;
    v->temp_p_yb = temp_p_yb << 14;


}



int ball_movement(struct ball_t * v, int x1, int x2, int y1, int y2, struct striker_t * s)
{

    v->p_xb = v->p_xb + v->v_xb;
    v->p_yb = v->p_yb + v->v_yb;
    v->temp_p_xb = v->p_xb-v->v_xb;
    v->temp_p_yb = v->p_yb-v->v_yb;
    if((v->p_xb >> 14) ==  x1+1 || (v->p_xb >> 14) ==  x2)  //Bounce på lodrette væge
    {

        v->v_xb = -v->v_xb;
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
    else if((v->p_yb >> 14) ==  y1+1) //Bounce på øverste væg
    {
        v->v_yb = -v->v_yb;
        /*if((v->v_y > 0 && v->v_x < 0) || (v->v_y < 0 && v->v_x > 0))
        {
            rotato(v,-128);
        }
        else if ((v->v_y < 0 && v->v_x > 0) || (v->v_y > 0 && v->v_x < 0))
        {
            rotato(v,128);
        }*/
    }
    //Bounce på striker
    else if((v->p_xb == s->p_xs ||(v->p_xb >> 14) == (s->p_xs >> 14)+1 ||(v->p_xb >> 14) == (s->p_xs >> 14) + 2  ||(v->p_xb >> 14)== (s->p_xs >> 14) + 3 ||(v->p_xb >> 14)== (s->p_xs >> 14) +4 ) && v->p_yb >> 14 == y2){
            v->v_yb=-v->v_yb;
    }
    return 0;
}


void ball_print(struct ball_t * v)
{

    gotoxy(v->temp_p_xb >> 14, v->temp_p_yb >> 14);
    printf("%c", 32);
    gotoxy(v->p_xb >> 14, v -> p_yb >> 14);
    printf("o");
}


