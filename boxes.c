#include "boxes.h"


void initBox(int x, int y){

    gotoxy(x,y);
    printf("%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178);
    gotoxy(x,y+1);
    printf("%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178);
    gotoxy(x,y+2);
    printf("%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178);

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
            printf("Use the joystick to move around\nLeft and right move the striker to the left and right\nThe center button on the joystick is the boss key\nThe RESET button takes you to the main menu");
    }

    else if(level[0]==2){
        initBox(10,10);
        initBox(22,10);
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
        initBox(22,10);
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
        initBox(22, 10);
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




void clean_boxes(int *hit, int *hit_confirm, int *score, int *level){
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

