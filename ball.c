#define ESC 0x1B
#include "ball.h"
#define FIX14_SHIFT 14
#define FIX14_MULT(a,b) ((a)*(b) >> FIX14_SHIFT)
#define FIX14_DIV(a,b) (((a) << FIX14_SHIFT) / b)


// Hastighedsvektor, position og temp position
void initBall(struct ball_t * v, int32_t p_xb, int32_t p_yb, int32_t v_xb, int32_t v_yb, int32_t temp_p_xb, int32_t temp_p_yb )
{

    v->v_xb = v_xb << 11;
    v->v_yb = v_yb << 11;
    v->p_xb = p_xb << 14;
    v->p_yb = p_yb << 14;
    v->temp_p_xb = temp_p_xb << 14;
    v->temp_p_yb = temp_p_yb << 14;


}



int ball_movement(struct ball_t * v, int x1, int x2, int y1, int y2, struct striker_t * s, int *hit, int *level, int *liv_flag, int liv, int *vinkel_bold)
{


    /* if(level[0]==2){
     v->v_xb = (v->v_xb * (3 << 13) >> 11);
     v->v_yb = (v->v_yb * (3 << 13) >> 11);
     }
     else if(level[0]==3){
     v->v_xb = (v->v_xb * (3 << 13)) >> 12;
     v->v_yb = (v->v_yb * (3 << 13)) >> 12;
     }*/


    v->p_xb = v->p_xb + v->v_xb;
    v->p_yb = v->p_yb + v->v_yb;
    v->temp_p_xb = v->p_xb-v->v_xb;
    v->temp_p_yb = v->p_yb-v->v_yb;




    if((v->p_xb >> 14) ==  x1+1 || (v->p_xb >> 14) ==  x2+1)  //Bounce på lodrette væge
    {

        v->v_xb = -v->v_xb;
        (*vinkel_bold)=(256-(*vinkel_bold)) & 0x1FF;
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
    else if((v->p_yb >> 14) ==  y1) //Bounce på øverste væg
    {
        v->v_yb = -v->v_yb;
        (*vinkel_bold)=(512-(*vinkel_bold)) & 0x1FF;
        /*if((v->v_y > 0 && v->v_x < 0) || (v->v_y < 0 && v->v_x > 0))
        {
            rotato(v,-128);
        }
        else if ((v->v_y < 0 && v->v_x > 0) || (v->v_y > 0 && v->v_x < 0))
        {
            rotato(v,128);
        }*/
    }

    else if(((v->p_yb >> 14) ==  y2+1) && level[0]==0) //Bounce på øverste væg
    {
        v->v_yb = -v->v_yb;
    }

    else if((v->p_yb >> 14) > y2+5)
    {
        liv_flag[0]=1;
        v->p_yb = (y2-2) << 14;
        v->p_xb = 25 << 14;

        if(level==2)
        {
            v->v_yb = -1 << 11;
            v->v_xb = -1 << 11;


        }
        else if(level==3)
        {
            v->v_yb = (-4 << 9);
            v->v_xb = (-4 << 9);


        }
        else if(level==4)
        {
            v->v_yb = (-2 << 10);
            v->v_xb = (-2 << 10);


        }


    }

    // BOX 0 bounce
    else if(((((v->p_yb >> 14)==10) && (((v->p_xb >> 14)>10) && (v->p_xb >> 14) < 15)) && (1 > hit[0]))  && (level[0]==2 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[0]=1;

    }
    else if(((((v->p_yb >> 14)==12) && (((v->p_xb >> 14)>10) && (v->p_xb >> 14) < 15)) && (1 > hit[0]))  && (level[0]==2 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[0]=1;
    }
    else if(((((v->p_xb >> 14)==10) && (((v->p_yb >> 14)>10) && (v->p_yb >> 14) < 12)) && (1 > hit[0]))  && (level[0]==2 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[0]=1;
    }
    else if(((((v->p_xb >> 14)==15) && (((v->p_yb >> 14)>10) && (v->p_yb >> 14) < 12)) && (1 > hit[0]))  && (level[0]==2 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[0]=1;
    }


    // BOX 1 bounce
    else if(((((v->p_yb >> 14)==10) && (((v->p_xb >> 14)>22) && (v->p_xb >> 14) < 27)) && (1 > hit[1])) && (level[0]==2 || level[0]==3 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[1]=1;
    }
    else if(((((v->p_yb >> 14)==12) && (((v->p_xb >> 14)>22) && (v->p_xb >> 14) < 27)) && (1 > hit[1])) && (level[0]==2 || level[0]==3 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[1]=1;
    }
    else if(((((v->p_xb >> 14)==22) && (((v->p_yb >> 14)>10) && (v->p_yb >> 14) < 12)) && (1 > hit[1])) && (level[0]==2 || level[0]==3 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[1]=1;
    }
    else if(((((v->p_xb >> 14)==27) && (((v->p_yb >> 14)>10) && (v->p_yb >> 14) < 12)) && (1 > hit[1])) && (level[0]==2 || level[0]==3 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[1]=1;
    }


    // BOX 2 bounce
    else if(((((v->p_yb >> 14)==10) && (((v->p_xb >> 14)>34) && (v->p_xb >> 14) < 39)) && (1 > hit[2])) && (level[0]==2 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[2]=1;
    }
    else if(((((v->p_yb >> 14)==12) && (((v->p_xb >> 14)>34) && (v->p_xb >> 14) < 39)) && (1 > hit[2])) && (level[0]==2 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[2]=1;
    }
    else if(((((v->p_xb >> 14)==34) && (((v->p_yb >> 14)>10) && (v->p_yb >> 14) < 12)) && (1 > hit[2])) && (level[0]==2 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[2]=1;
    }
    else if(((((v->p_xb >> 14)==39) && (((v->p_yb >> 14)>10) && (v->p_yb >> 14) < 12)) && (1 > hit[2])) && (level[0]==2 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[2]=1;
    }


    // BOX 3 bounce
    else if((((v->p_yb >> 14)==16) && (((v->p_xb >> 14)>10) && (v->p_xb >> 14) < 15)) && (1 > hit[3]))
    {
        v->v_yb=-v->v_yb;
        hit[3]=1;
    }
    else if((((v->p_yb >> 14)==18) && (((v->p_xb >> 14)>10) && (v->p_xb >> 14) < 15)) && (1 > hit[3]))
    {
        v->v_yb=-v->v_yb;
        hit[3]=1;
    }
    else if((((v->p_xb >> 14)==10) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[3]))
    {
        v->v_xb=-v->v_xb;
        hit[3]=1;
    }
    else if((((v->p_xb >> 14)==15) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[3]))
    {
        v->v_xb=-v->v_xb;
        hit[3]=1;
    }


    // BOX 4 bounce
    else if(((((v->p_yb >> 14)==16) && (((v->p_xb >> 14)>22) && (v->p_xb >> 14) < 27)) && (1 > hit[4])) && (level[0]==2 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[4]=1;
    }
    else if(((((v->p_yb >> 14)==18) && (((v->p_xb >> 14)>22) && (v->p_xb >> 14) < 27)) && (1 > hit[4])) && (level[0]==2 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[4]=1;
    }
    else if(((((v->p_xb >> 14)==22) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[4])) && (level[0]==2 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[4]=1;
    }
    else if(((((v->p_xb >> 14)==27) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[4])) && (level[0]==2 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[4]=1;
    }


    // BOX 5 bounce
    else if((((v->p_yb >> 14)==16) && (((v->p_xb >> 14)>34) && (v->p_xb >> 14) < 39)) && (1 > hit[5]))
    {
        v->v_yb=-v->v_yb;
        hit[5]=1;
    }
    else if((((v->p_yb >> 14)==18) && (((v->p_xb >> 14)>34) && (v->p_xb >> 14) < 39)) && (1 > hit[5]))
    {
        v->v_yb=-v->v_yb;
        hit[5]=1;
    }
    else if((((v->p_xb >> 14)==34) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[5]))
    {
        v->v_xb=-v->v_xb;
        hit[5]=1;
    }
    else if((((v->p_xb >> 14)==39) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[5]))
    {
        v->v_xb=-v->v_xb;
        hit[5]=1;
    }
    // BOX 6 bounce
    else if(((((v->p_yb >> 14)==4) && (((v->p_xb >> 14)>10) && (v->p_xb >> 14) < 15)) && (1 > hit[6])) && (level[0]==3 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[6]=1;

    }
    else if(((((v->p_yb >> 14)==6) && (((v->p_xb >> 14)>10) && (v->p_xb >> 14) < 15)) && (1 > hit[6])) && (level[0]==3 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[6]=1;
    }
    else if(((((v->p_xb >> 14)==10) && (((v->p_yb >> 14)>10) && (v->p_yb >> 14) < 6)) && (1 > hit[6])) && (level[0]==3 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[6]=1;
    }
    else if(((((v->p_xb >> 14)==15) && (((v->p_yb >> 14)>10) && (v->p_yb >> 14) < 6)) && (1 > hit[6])) && (level[0]==3 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[6]=1;
    }

    //BOX 7 bounce
    else if(((((v->p_yb >> 14)==4) && (((v->p_xb >> 14)>22) && (v->p_xb >> 14) < 27)) && (1 > hit[7])) && (level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[7]=1;
    }
    else if(((((v->p_yb >> 14)==6) && (((v->p_xb >> 14)>22) && (v->p_xb >> 14) < 27)) && (1 > hit[7])) && (level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[7]=1;
    }
    else if(((((v->p_xb >> 14)==22) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 6)) && (1 > hit[7])) && (level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[7]=1;
    }
    else if(((((v->p_xb >> 14)==27) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 6)) && (1 > hit[7])) && (level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[7]=1;
    }

    //BOX 8 bounce
    else if(((((v->p_yb >> 14)==4) && (((v->p_xb >> 14)>34) && (v->p_xb >> 14) < 39)) && (1 > hit[8])) && (level[0]==3 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[8]=1;
    }
    else if(((((v->p_yb >> 14)==6) && (((v->p_xb >> 14)>34) && (v->p_xb >> 14) < 39)) && (1 > hit[8])) && (level[0]==3 || level[0]==4))
    {
        v->v_yb=-v->v_yb;
        hit[8]=1;
    }
    else if(((((v->p_xb >> 14)==34) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 6)) && (1 > hit[8])) && (level[0]==3 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[8]=1;
    }
    else if(((((v->p_xb >> 14)==39) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 6)) && (1 > hit[8])) && (level[0]==3 || level[0]==4))
    {
        v->v_xb=-v->v_xb;
        hit[8]=1;
    }

    // MENU START BOX
    else if((((v->p_yb >> 14)==16) && (((v->p_xb >> 14)>10) && (v->p_xb >> 14) < 15)) && (1 > hit[3]) && level[0]==0)
    {
        v->v_yb=-v->v_yb;
        hit[3]=1;
    }
    else if((((v->p_yb >> 14)==18) && (((v->p_xb >> 14)>10) && (v->p_xb >> 14) < 15)) && (1 > hit[3]) && level[0]==0)
    {
        v->v_yb=-v->v_yb;
        hit[3]=1;
    }
    else if((((v->p_xb >> 14)==10) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[3]) && level[0]==0)
    {
        v->v_xb=-v->v_xb;
        hit[3]=1;
    }
    else if((((v->p_xb >> 14)==15) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[3]) && level[0]==0)
    {
        v->v_xb=-v->v_xb;
        hit[3]=1;
    }
    //  HELP BOX IN MENU
    else if((((v->p_yb >> 14)==16) && (((v->p_xb >> 14)>34) && (v->p_xb >> 14) < 39)) && (1 > hit[5]) && level[0]==0)
    {
        v->v_yb=-v->v_yb;
        hit[5]=1;
    }
    else if((((v->p_yb >> 14)==18) && (((v->p_xb >> 14)>34) && (v->p_xb >> 14) < 39)) && (1 > hit[5]) && level[0]==0)
    {
        v->v_yb=-v->v_yb;
        hit[5]=1;
    }
    else if((((v->p_xb >> 14)==34) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[5]) && level[0]==0)
    {
        v->v_xb=-v->v_xb;
        hit[5]=1;
    }
    else if((((v->p_xb >> 14)==39) && (((v->p_yb >> 14)>16) && (v->p_yb >> 14) < 18)) && (1 > hit[5]) && level[0]==0)
    {
        v->v_xb=-v->v_xb;
        hit[5]=1;
    }


    //Bounce på striker
    else if((
                v->p_xb == s->p_xs ||
                (v->p_xb >> 14) == (s->p_xs >> 14)-1 ||
                (v->p_xb >> 14) == (s->p_xs >> 14)+1 ||
                (v->p_xb >> 14) == (s->p_xs >> 14) + 2 ||
                (v->p_xb >> 14)== (s->p_xs >> 14) + 3 ||
                (v->p_xb >> 14)== (s->p_xs >> 14) +4 ) &&
            v->p_yb >> 14 == y2
           )
    {
        //v->v_yb = -v->v_yb;

        //if(v->v_xb<0)

            if((v->p_xb == s->p_xs) || ((s->p_xs >> 14)-1))
            {
                /* v->v_xb=FIX14_MULT(v->v_xb,cosinus(vinkel_bold*4));

                 vinkel_bold=(vinkel_bold*4+vinkel_bold); */
                (*vinkel_bold)=(-300-(*vinkel_bold)) & 0x1FF;
                v->v_xb=cosinus((*vinkel_bold)) >> 3;
                v->v_yb=sinus((*vinkel_bold)) >> 3;



            }

             else if((v->p_xb >> 14) == ((s->p_xs >> 14)+1))
            {
                /* v->v_xb=FIX14_MULT(v->v_xb, cosinus(vinkel_bold*2));

                  vinkel_bold=(vinkel_bold*2+vinkel_bold); */
                (*vinkel_bold)=(-300-(*vinkel_bold)) & 0x1FF;

                v->v_xb=cosinus((*vinkel_bold)) >> 3;
                v->v_yb=sinus((*vinkel_bold)) >> 3;


            }
            else if((v->p_xb >> 14) == (s->p_xs >> 14)+2)
            {
                /*  v->v_xb=FIX14_MULT(v->v_xb, cosinus(vinkel_bold)); */
                (*vinkel_bold)=(-300-(*vinkel_bold)) & 0x1FF;
                v->v_xb=cosinus((*vinkel_bold)) >> 3;
                v->v_yb=sinus((*vinkel_bold)) >> 3;



            }
            else if((v->p_xb >> 14) == (s->p_xs >> 14)+3)
            {
                /*  v->v_xb=FIX14_MULT(v->v_xb, cosinus(vinkel_bold/2));

                  vinkel_bold=(vinkel_bold/2+vinkel_bold); */
                (*vinkel_bold)=(-300-(*vinkel_bold)) & 0x1FF;
                v->v_xb=cosinus((*vinkel_bold)) >> 3;
                v->v_yb=sinus((*vinkel_bold)) >> 3;



            }
            else if((v->p_xb >> 14) == ((s->p_xs >> 14)+4 || (s->p_xs >> 14)+5))
            {
                /*  v->v_xb=FIX14_MULT(v->v_xb, cosinus(vinkel_bold/4));

                  vinkel_bold=(vinkel_bold/4+vinkel_bold); */
                (*vinkel_bold)=(-300-(*vinkel_bold)) & 0x1FF;
                v->v_xb=cosinus((*vinkel_bold)) >> 3;
                v->v_yb=sinus((*vinkel_bold)) >> 3;
            }
        }
//          /* else if(v->v_xb>0){
//                    if(v->p_xb == s->p_xs){
//                           /* v->v_xb=FIX14_MULT(v->v_xb,cosinus(vinkel_bold/4)); */
//
//                            vinkel_bold=512-vinkel_bold;
//                            v->v_xb=-cosinus(vinkel_bold >> 6);
//                            v->v_yb=sinus(vinkel_bold >> 6);
//
//                    }
//                    else if((v->p_xb >> 14) == (s->p_xs >> 14)+1){
//                           /* v->v_xb=FIX14_MULT(v->v_xb, cosinus(vinkel_bold/2)); */
//
//                            vinkel_bold=(-vinkel_bold/2-vinkel_bold);
//
//                            v->v_xb=-cosinus(vinkel_bold >> 6);
//                            v->v_yb=sinus(vinkel_bold >> 6);
//                            vinkel_bold=-vinkel_bold;
//
//                    }
//                    else if((v->p_xb >> 14) == (s->p_xs >> 14)+2){
//                           /* v->v_xb=FIX14_MULT(v->v_xb, cosinus(vinkel_bold)); */
//
//                            v->v_xb=-cosinus(vinkel_bold >> 6);
//                            v->v_yb=sinus(vinkel_bold >> 6);
//                            vinkel_bold=-vinkel_bold;
//                    }
//                    else if((v->p_xb >> 14) == (s->p_xs >> 14)+3){
//                            /*v->v_xb=FIX14_MULT(v->v_xb, cosinus(vinkel_bold*2));
//
//                            vinkel_bold=(-vinkel_bold*2-vinkel_bold);
//
//                            v->v_xb=-cosinus(vinkel_bold >> 6);
//                            v->v_yb=sinus(vinkel_bold >> 6);
//                            vinkel_bold=-vinkel_bold;
//                    }
//                    else if((v->p_xb >> 14) == (s->p_xs >> 14)+4){
//                           /*v->v_xb=FIX14_MULT(v->v_xb, cosinus(vinkel_bold*4));
//
//                            vinkel_bold=(-vinkel_bold*4-vinkel_bold);
//
//                            v->v_xb=-cosinus(vinkel_bold >> 6);
//                            v->v_yb=sinus(vinkel_bold >> 6);
//                            vinkel_bold=-vinkel_bold;
//                    }
//           }*/
//        else
//        {
//            v->v_xb=1;
//        }



        return 0;
    }




void ball_print(struct ball_t * v)
{

    gotoxy(v->temp_p_xb >> 14, v->temp_p_yb >> 14);
    printf("%c", 32);
    gotoxy(v->p_xb >> 14, v -> p_yb >> 14);
    printf("o");
}



