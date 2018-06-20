/*
**
**                           Main.c
**
**********************************************************************/
/*
   Last committed:     $Revision: 00 $
   Last changed by:    $Author: Lucas V. Mortensen, Philip H. Karstensen & Jovan A. Todorovic
   Last changed date:  $Date: 20-06-2018 $
   ID:                 $Id: s173942, s173941, s173930 $

**********************************************************************/
#define ESC 0x1B
#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h"// Input/output library for this course
#include "ansi.h"
#include "ball.h"
#include <string.h>
#include "striker.h"
#include "boxes.h"


int main(void)
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////// Varabler og initialiseringer ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    uint8_t buffer[512];
    init_usb_uart(115200);
    init_spi_lcd();
    init_gpio();
    clrscr();
    timer_pp();


    int hit[]= {0,0,0,0,0,0,0,0,0}; // Beskriver om de forskellige kasser er blevet ramt
    int hit_confirm[] = {0,0,0,0,0,0,0,0,0}; // Bekræftelse af ramte kasser
    int vinkel_bold = 64;
    int striker_hit[]={0}; // Antal kollisioner mellem bold og striker
    int k = 1; // Slices på LCD


    wall(0,0,50,30); // Optegning af bane


    int pow[]= {0};   // Power up indikator
    int score[]= {0};
    int level[]= {0}; // Lvl 0 = Menu, Lvl 1 = HELP
    all_boxes(level); // Initialisering af kasser
    struct ball_t b;
    struct striker_t s;
    initBall(&b, 50/2, 25, 1, 1, 0, 0);
    int liv[]={3};
    int liv_flag[]= {0};
    initStriker(&s, 50/2, 30, 1, 0, 0, 0);
    TIM2_IRQHandler(); // Timer håndtering


    // LCD
    memset(buffer, 0x00,512);
    lcd_write_string("Git gud scrub.", k, 1, buffer);
    lcd_write_string("Yes, I work.", k+1, 2, buffer);
    lcd_write_string("I just can't show score", k+2, 3, buffer);
    lcd_push_buffer(buffer);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while(1)
    {
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////// METODER ///////////////////////////////////////////////////////////////////////////
        setLed(liv);
        ball_hit_box(hit, hit_confirm, level, liv, striker_hit, pow, score);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (joyinout()== 0b00001){  /////////////////////////// BOSS KEY ///////////////////////////////////////////////////////////////////////////
                clrscr();
                gotoxy(50,30);
                printf("I SWEAR I'M WORKING, BOSS!");
                break;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(tid.hs==1) //////////////////////////////////////////// OPDATERING AF BOLD, STRIKER OG KASSER ///////////////////////////////////////////
            {
                ball_movement(&b, 1, 50, 1, 30, &s, hit, level, liv_flag, liv, &vinkel_bold, striker_hit);
                striker_movement(&s, 1, 47, 29, 29, joyinout(), pow);

                ball_print(&b);
                striker_print(&s);
                clean_boxes(hit, hit_confirm, score, level,pow);
            }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(liv[0]<=0) /////////////////////////////////////// GAME OVER ///////////////////////////////////////////////////////////////////////////////
        {
            clrscr();
            gotoxy(50,20);
            printf("GAME OVER");
            gotoxy(50,40);
            printf("Press the RESET button to go to menu");
            setLed(liv);
            break;
        }

    }
}

