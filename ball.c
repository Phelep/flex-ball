#define ESC 0x1B
#include "ball.h"

void initBall(struct ball_t * v, int32_t p_x, int32_t p_y, int32_t v_x, int32_t v_y )
{
    v->v_x = v_x << 14;
    v->v_y = v_y << 14;
    v->p_x = p_x << 14;
    v->p_y = p_y << 14;

}

int ball_movement(struct ball_t * v, int x1, int x2, int y1, int y2)
{
    //int bounce_count=0;


    //bounce_count=0;
    /*v->p_x = v->p_x + v->v_x;
    v->p_y = v->p_y + v->v_y;
    //return(p_x);

    if(v->p_x ==  x1 || v->p_x ==  x2){
            v->v_x = -v->v_x;
            *bounce_count++;
    }
    else if(v->p_y ==  y1 || v->p_y ==  y2){
            v-> v_y = -v -> v_y;
            }*/

    //*bounce_count++;

    //else if(p_x=x1 |){

    /*v->p_x = v->p_x + v->v_x;
           v->p_y = v->p_y + v->v_y;
           //return(p_x);

           if(v->p_x >> 14 <=  x1 || v->p_x >> 14 >=  x2){
                   v->v_x == -v->v_x;
                   //*bounce_count++;
           }
           else if(v->p_y >> 14 <=  y1 || v->p_y >> 14 >=  y2){
                   v-> v_y == -v -> v_y;
                   //*bounce_count++;
           }
           } */

    v->p_x = v->p_x + v->v_x;
    v->p_y = v->p_y + v->v_y;
    if((v->p_x >> 14) ==  x1 || (v->p_x >> 14) ==  x2)
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
        v->v_y = -v->v_y;
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


void ball_print(struct ball_t * v)
{
    gotoxy(v->p_x >> 14, v -> p_y >> 14);
    printf("o");
}
