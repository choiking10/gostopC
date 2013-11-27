
#ifdef _PLAY_H_
#define _PLAY_H_

#include"card.h"
#include<stdio.h>
void playstream(int turn,PLAYER players[],PCARD *board,PCARD *dummy);
void compare(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy,PCARD *savetemp);
void goplboard(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy);
void goboard(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy);
void movetemp(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy,PCARD *savetemp);

#endif