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







int main(void)
{
    //uint8_t buffer[512];
    init_usb_uart(115200); // Initialize USB serial at 9600 baud
    init_gpio();
    clrscr();
    timer_pp();




    //init_spi_lcd();
    //memset(buffer, 0x00,512);


   /* lcd_update(&k);
    lcd_write_string("Schlong", k, 1, &buffer);
    lcd_push_buffer(buffer);

    //clrscr();

    //timer_pp();
*/



    wall(0,0,50,30);


        struct vector_t v;
        initVector(&v, -4, -4);
        rotato(&v, 1280);
        struct ball_t b;
        struct striker_t s;
        initBall(&b, 50/2, 30/2, 1, 1, 0, 0);

        initStriker(&s, 50/2, 30, 1, 0, 0, 0);
        TIM2_IRQHandler();

     while(1){


        if(tid.hs==0){
        ball_movement(&b, 1, 50, 1, 30, &s);
        striker_movement(&s, 1, 46, 29, 29, joyinout());

        //wall(0,0,50,30);
        ball_print(&b);
        striker_print(&s);
        }

   // while (1){
        //lcd_update(&k);
        //memset(buffer, 0x00,512);
        //lcd_write_string("Looooooooong penis", k, 1, buffer);
        //lcd_push_buffer(buffer);
        /*setLed(joyinout());*/

        /*gotoxy(0,0);
        printf("%d:%d:%d.%d\n",tid.h, tid.m, tid.s, tid.hs);
        if(joyinout()==0b10000){
                movey(1);
                printf("Split time 1: %d:%d:%d.%d\n",tid.h, tid.m, tid.s, tid.hs);
        }
        else if(joyinout()==0b01000){
                movey(2);
                printf("Split time 2: %d:%d:%d.%d\n",tid.h, tid.m, tid.s, tid.hs);
        }
        else if(joyinout()==0b00010){
                gotoxy(0,0);
                printf("0:0:0.00\n");
        }
    }*/


     }
}











