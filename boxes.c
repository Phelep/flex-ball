#include "boxes.h"


void initBox(int x, int y){

    gotoxy(x,y);
    printf("%c%c%c%c%c%c", 32, 177, 177, 177, 177, 32);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c", 177, 177, 177, 177, 177, 177);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c", 32, 177, 177, 177, 177, 32);

}
void initPowBox(int x, int y){

    gotoxy(x,y);
    printf("%c%c%c%c%c%c", 32, 178, 178, 178, 178, 32);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c", 32, 178, 178, 178, 178, 32);

}




void byeBox(int x, int y){
    gotoxy(x,y);
    printf("%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32);
}

void all_boxes(int *level){
    if(level[0]==0){ // MENU
        initBox(10,16);
        initBox(34,16);
        gotoxy(10,19);
        printf("Start");
        gotoxy(34,19);
        printf("Help");
        }
    else if(level[0]==1){ // HELP
            clrscr();
            gotoxy(22,10);
            printf("Use the joystick to move around\nLeft and right move the striker to the left and right\nUp on the joystick is the boss key\nThe RESET button takes you to the main menu\nThe power up box is the odd looking one and the \"power up\" inverts the controls");
    }

    else if(level[0]==2){
        initBox(10,10);
        initPowBox(22,10);
        initBox(34,10);
        initBox(10,16);
        initBox(22,16);
        initBox(34,16);
        gotoxy(10,19);
        printf("%c%c%c%c%c", 32,32,32,32,32);
        gotoxy(34,19);
        printf("%c%c%c%c", 32,32,32,32);

    }
    else if(level[0]==3){
        initPowBox(22,10);
        initBox(10,16);
        initBox(34,16);
        initBox(10, 4);
        initBox(34, 4);

    }
    else if(level[0]==4){
        initBox(10, 4);
        initBox(22, 4);
        initBox(34, 4);
        initBox(10, 10);
        initPowBox(22, 10);
        initBox(34, 10);
        initBox(10, 16);
        initBox(22, 16);
        initBox(34, 16);
    }
    else if(level[0]==5){
            clrscr();
            gotoxy(22,10);
                printf("VICTORY\nPress the RESET button to go to the menu");

            }
    }




void clean_boxes(int *hit, int *hit_confirm, int *score, int *level, int *pow){
    if (hit[0]==1 && hit_confirm[0]==0){
            byeBox(10,10);
            hit_confirm[0]=1;
            score[0]++;
            gotoxy(50,40);
            printf("score: %d",score[0]);
}
    else if(hit[1]==1 && hit_confirm[1]==0){
            byeBox(22,10);
            hit_confirm[1]=1;
            score[0]++;
            gotoxy(50,40);
            printf("score: %d",score[0]);
            pow[0]=1;
    }
    else if(hit[2]==1 && hit_confirm[2]==0){
            byeBox(34,10);
            hit_confirm[2]=1;
            score[0]++;
            gotoxy(50,40);
            printf("score: %d",score[0]);
    }
    else if(hit[3]==1 && hit_confirm[3]==0){
            byeBox(10,16);
            hit_confirm[3]=1;

            if(level[0]==0){
                level[0]==2;
            }
            if(level[0]==2 || level[0]==3 || level[0]==4){
                score[0]++;
                gotoxy(50,40);
            printf("score: %d",score[0]);
            }

    }
    else if(hit[4]==1 && hit_confirm[4]==0){
            byeBox(22,16);
            hit_confirm[4]=1;
            score[0]++;
            gotoxy(50,40);
            printf("score: %d",score[0]);
    }
    else if(hit[5]==1 && hit_confirm[5]==0){
            byeBox(34,16);
            hit_confirm[5]=1;
            if(level[0]==0){
                level[0]==1;
            }
            if(level[0]==2 || level[0]==3 || level[0]==4){
                score[0]++;
                gotoxy(50,40);
                printf("score: %d",score[0]);
            }

    }
    else if(hit[6]==1 && hit_confirm[6]==0){
            byeBox(10,4);
            hit_confirm[6]=1;
            score[0]++;
            gotoxy(50,40);
            printf("score: %d",score[0]);
    }
    else if(hit[7]==1 && hit_confirm[7]==0){
            byeBox(22,4);
            hit_confirm[7]=1;
            score[0]++;
            gotoxy(50,40);
            printf("score: %d",score[0]);
    }
    else if(hit[8]==1 && hit_confirm[8]==0){
            byeBox(34,4);
            hit_confirm[8]=1;
            score[0]++;
            gotoxy(50,40);
            printf("score: %d",score[0]);
    }

}

void ball_hit_box(int *hit, int *hit_confirm, int *level, int *liv, int *striker_hit, int *pow, int *score){ // Bekræfter at kasser er blevet ramt, skifter levels når alle kasser er ramt. Printer level, liv og slut score
        if(liv>0)
        {

            if(level[0]==0 && (hit[3]==1 || hit[5]==1))
            {
                if(hit[3]==1)
                {
                    level[0]=2;
                    gotoxy(50,36);
                    printf("level: %d",level[0]-1);
                    liv[0]=3;
                    gotoxy(50,38);
                    printf("lives: %d", liv[0]);

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
                clean_boxes(hit,hit_confirm, score, level,pow);
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

}

}
