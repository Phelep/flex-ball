#define ESC 0x1B
#include "ansi.h"


void fgcolor(int foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(int background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(int foreground, int background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);
}

void clrscr(){
printf("%c[2J", ESC);
}

void clreol(){
printf("%c[K", ESC);
}

void gotoxy(int y, int x){

printf("%c[%d;%dH", ESC,x,y);
}

void underline(uint8_t on){

    if (on==0){
            printf("%c[04m",ESC);
    }
    else if (on==1){
    printf("%c[24m", ESC);
    }
}

void blink(int blinker){
    if (blinker==0){
            printf("%c[5m",ESC);
    }
    else if (blinker==1){
            printf("%c[25m",ESC);
    }
}

void  inverse(int invert){
    if (invert==0){
            printf("%c[7m",ESC);
        }
    else if(invert==1){
            printf("%c[27m",ESC);
    }
}

void movex(int move_x){
        printf("%c[%dC",ESC,move_x);

    }
void movey(int move_y){
        printf("%c[%dB",ESC,move_y);
}

void window(int x1, int y1, int x2, int y2){
    int x= x2-x1;
    int y= y2-y1;
        gotoxy(x1,y1);
        printf("%c%c",197,180);
        inverse(0);
        printf("Window 1");
        inverse(1);
        printf("%c", 195);
        for (int i2=0; i2<=x-11; i2++){
                printf("%c",196);
        }
        printf("%c\n",197);
    for(int l=0; l<=y-2; l++){
        movex(x1-1);
        printf("%c",179);
        for(int j=0; j<=x-1; j++){
            printf("%c",32);
    }
    printf("%c\n",179);
    }
    movex(x1-1);
    printf("%c",197);
    for (int k=0; k<=x-1; k++){
        printf("%c",196);
    }
    printf("%c",197);
    }
    void printFix(int32_t i) {
 // Prints a signed 16.16 fixed point number
 if ((i & 0x80000000) != 0) { // Handle negative numbers
 printf("-");
 i = ~i + 1;
 }
 printf("%ld.%04ld", i >> 16, 10000 * (uint32_t)(i & 0xFFFF) >> 16);
 // Print a maximum of 4 decimal digits to avoid overflow
 }

int32_t expand(int32_t i) {
 // Converts an 18.14 fixed point number to 16.16
 return i << 2;
 }



void wall(int x1, int y1, int x2, int y2){

    int x= x2-x1;
    int y= y2-y1;
        gotoxy(x1,y1);
        printf("%c",197);
        for (int k=0; k<=x-1; k++){
        printf("%c",196);
    }
        printf("%c\n",197);
    for(int l=0; l<=y-2; l++){
        movex(x1-1);
        printf("%c",179);
        for(int j=0; j<=x-1; j++){
            printf("%c",32);
    }
    printf("%c\n",179);
    }
    movex(x1-1);
    printf("%c",197);
    for (int k=0; k<=x-1; k++){
        printf("%c",196);
    }
    printf("%c",197);
    }
