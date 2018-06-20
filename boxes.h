#ifndef BOXES_H_INCLUDED
#define BOXES_H_INCLUDED
#include "ball.h"


void initBox(int x, int y);
void initPowBox(int x, int y);
void byeBox(int x, int y);
void all_boxes(int *level);
void clean_boxes(int *hit, int *hit_confirm,int *score, int *level, int *pow);
void ball_hit_box(int *hit, int *hit_confirm, int *level, int *liv, int *striker_hit, int *pow, int *score);


#endif /* BOXES_H_INCLUDED */
