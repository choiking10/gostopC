#ifndef _ENDSTREAM_H_
#define _ENDSTREAM_H_
#include<stdio.h>
#include"card.h"

int shake(PLAYER players[]);
//player announce shake situation. If this player win, score will be doubled
int nagari(PCARD *dummy, PLAYER players[]);
//players announce nagari situation. Next game's score will be doubled
int gobak(PLAYER players[]);
//player announce gobak situation. This player's score will be doubled
int pbak(PLAYER players[]);
//player announce pbak situation. This player's score will be doubled
int mokda(PLAYER players[]);
//player announce mokda situation. This player's score will be doubled
int gnbak(PLAYER players[]);
//player announce gnbak situation. This player's score will be doubled
int winner(PLAYER player[]);
//define who's winner
int money_count(score);
//money will be counted based on player's score
int spare_money(PLAYER players[]);
//money will be spare to other players

#endif
