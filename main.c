/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: $
   Last changed date:  $Date:  $
   ID:                 $Id:  $

**********************************************************************/
#define ESC 0x1B
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h"// Input/output library for this course
#include "ansi.h"
#include "ball.h"
#include "hardware.h"
#include "matematik.h"
#include "vector.h"
#include <string.h>
#include "striker.h"
#include "GPIO.h"
#include "boxes.h"






int main(void)
{
    uint8_t buffer[512];
    init_usb_uart(115200);
    init_spi_lcd();
    init_gpio();
    clrscr();
    timer_pp();


    int hit[]= {0,0,0,0,0,0,0,0,0};
    int hit_confirm[] = {0,0,0,0,0,0,0,0,0};
    int vinkel_bold = 64;
    int boss = 0;
    int striker_hit[]={0};
    int k = 1;


    wall(0,0,50,30);


    int pow[]= {0};
    int score[]= {0};
    int level[]= {0}; // Lvl 0 = Menu, Lvl 1 = HELP
    all_boxes(level);
    struct vector_t v;
    initVector(&v, -4, -4);
    rotato(&v, 1280);
    struct ball_t b;
    struct striker_t s;
    initBall(&b, 50/2, 25, 1, 1, 0, 0);
    int liv=3;
    int liv_flag[]= {0};
    initStriker(&s, 50/2, 30, 1, 0, 0, 0);
    TIM2_IRQHandler();


    // LCD
    memset(buffer, 0x00,512);
    lcd_write_string("Git gud scrub.", k, 1, buffer);
    lcd_write_string("Yes, the LCD works.", k+1, 2, buffer);
    lcd_write_string("Move on.", k+2, 3, buffer);
    lcd_push_buffer(buffer);

    while(1)
    {

        setLed(liv);


        if (joyinout()== 0b00001){
                clrscr();
                gotoxy(50,30);
                printf("I SWEAR I'M WORKING, BOSS!");
                break;

        }

        if(liv>0 && boss == 0)
        {

            if(level[0]==0 && (hit[3]==1 || hit[5]==1))
            {
                if(hit[3]==1)
                {
                    level[0]=2;
                    gotoxy(50,36);
                    printf("level: %d",level[0]-1);
                    liv=3;
                    gotoxy(50,38);
                    printf("lives: %d", liv);

                }
                else if(hit[5]==1)
                {
                    level[0]=1;
                }
                hit[0]=0;
                hit[1]=0;
                hit[2]=0;
                hit[3]=0;
                hit[4]=0;
                hit[5]=0;
                hit[6]=0;
                hit[7]=0;
                hit[8]=0;
                hit_confirm[0]=0;
                hit_confirm[1]=0;
                hit_confirm[2]=0;
                hit_confirm[3]=0;
                hit_confirm[4]=0;
                hit_confirm[5]=0;
                hit_confirm[6]=0;
                hit_confirm[7]=0;
                hit_confirm[8]=0;
                clean_boxes(hit,hit_confirm,score, level,pow);
                all_boxes(level);

            }
            else if(hit[0]==1 && hit[1]==1 && hit[2]==1 && hit[3]==1 && hit[4]==1 && hit[5]==1 && level[0]==2)
            {
                level[0]++;
                hit[0]=0;
                hit[1]=0;
                hit[2]=0;
                hit[3]=0;
                hit[4]=0;
                hit[5]=0;
                hit[6]=0;
                hit[7]=0;
                hit[8]=0;
                hit_confirm[0]=0;
                hit_confirm[1]=0;
                hit_confirm[2]=0;
                hit_confirm[3]=0;
                hit_confirm[4]=0;
                hit_confirm[5]=0;
                hit_confirm[6]=0;
                hit_confirm[7]=0;
                hit_confirm[8]=0;
                clean_boxes(hit,hit_confirm,score, level,pow);
                all_boxes(level);
                gotoxy(50,36);
                printf("level: %d",level[0]-1);
                pow[0]=0;
                timer_pp1(5999);

            }
            else if(hit[1]==1 && hit[3]==1 && hit[5]==1 && hit[6]==1 && hit[8]==1 && level[0]==3)
            {
                level[0]++;
                hit[0]=0;
                hit[1]=0;
                hit[2]=0;
                hit[3]=0;
                hit[4]=0;
                hit[5]=0;
                hit[6]=0;
                hit[7]=0;
                hit[8]=0;
                hit_confirm[0]=0;
                hit_confirm[1]=0;
                hit_confirm[2]=0;
                hit_confirm[3]=0;
                hit_confirm[4]=0;
                hit_confirm[5]=0;
                hit_confirm[6]=0;
                hit_confirm[7]=0;
                hit_confirm[8]=0;
                clean_boxes(hit,hit_confirm,score, level,pow);
                all_boxes(level);
                gotoxy(50,36);
                printf("level: %d",level[0]-1);
                pow[0]=0;
                timer_pp1(5599);

            }
            else if(hit[0]==1 && hit[1]==1 && hit[2]==1 && hit[3]==1 && hit[4]==1 && hit[5]==1 && hit[6]==1 && hit[7]==1 && hit[8]==1 && level[0]==4)
            {

                hit[0]=0;
                hit[1]=0;
                hit[2]=0;
                hit[3]=0;
                hit[4]=0;
                hit[5]=0;
                hit[6]=0;
                hit[7]=0;
                hit[8]=0;
                hit_confirm[0]=0;
                hit_confirm[1]=0;
                hit_confirm[2]=0;
                hit_confirm[3]=0;
                hit_confirm[4]=0;
                hit_confirm[5]=0;
                hit_confirm[6]=0;
                hit_confirm[7]=0;
                hit_confirm[8]=0;
                clean_boxes(hit,hit_confirm,score, level,pow);
                all_boxes(level);
                clrscr();

                gotoxy(10, 20);
                printf("Press the RESET button to go to the menu");
                for (int i=0; i<=10; i++){

                gotoxy(50+i, 10+i);
                printf("VICTORY!");
                    if(i==10){
                            i=0;
                    }
                gotoxy(10, 10);
                printf("Your score is %d/%d", score[0], striker_hit[0]);
                }
            }
            if(liv_flag[0]==1 && (level[0]==2 || level[0]==3 || level[0]==4))
            {
                liv--;
                gotoxy(50,38);
                printf("lives: %d", liv);
                liv_flag[0]=0;
            }



            ;

            if(tid.hs==1)
            {
                ball_movement(&b, 1, 50, 1, 30, &s, hit, level, liv_flag, liv, &vinkel_bold, striker_hit);
                striker_movement(&s, 1, 47, 29, 29, joyinout(), pow);

                ball_print(&b);
                striker_print(&s);
                clean_boxes(hit, hit_confirm, score, level,pow);
            }







    }

            /*setLed(joyinout());*/

//            gotoxy(10,60);
//            printf("%d:%d:%d.%d\n",tid.h, tid.m, tid.s, tid.hs);
//            if(joyinout()==0b10000){
//                    movey(1);
//                    printf("Split time 1: %d:%d:%d.%d\n",tid.h, tid.m, tid.s, tid.hs);
//            }
//            else if(joyinout()==0b01000){
//                    movey(2);
//                    printf("Split time 2: %d:%d:%d.%d\n",tid.h, tid.m, tid.s, tid.hs);
//            }
//            else if(joyinout()==0b00010){
//                    gotoxy(0,0);
//                    printf("0:0:0.00\n");
//            }
//            }*/




        else if(liv<=0)
        {
            clrscr();
            gotoxy(50,20);
            printf("GAME OVER");
            gotoxy(50,40);
            printf("Press the RESET button to go to menu");
            break;
        }

    }

    }















