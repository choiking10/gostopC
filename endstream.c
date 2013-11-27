#include<stdio.h>
#include"card.h"

int shake(PLAYER players[])                  //흔들기
{
    int i,j;
    int x=0;
    for(i = 0 ; i <3 ; i++)
    {
	   for(j = 0 ; j<7 ; i++)
	   {
		  if(getCard(players[i].playerHead,i) -> month == getCard(players[i].playerHead,j+1) -> month)
		  {
			 x++;
		  }
	   }
	   if(x == 3)
	   {
		  return 1;
		  break;
	   }
    }
    return 0;
}


int nagari(PCARD *dummy, PLAYER players[])		//나가리
{
    int j = 0;
    int x = 0;
    int y = 0;
    if( *dummy == NULL)
	   x = 1;
    if(x = 1)
    { 
	   while(j<3)
	   {
		  if(players[j].is.go == 0)
		  {
			 y++;
		  }
		  j++;
	   }
	   if(y == 3)
		  return 1;
	   else
		  return 0;
    }
    return 0;
}

int gobak(PLAYER players[])					//고박
{
    int x = 0;
    int j = 0;
    int i = 0;
    while(i < 3)
    {
	   if(players[i].is.stop == 1)
		  break;
	   i++;
    }
    while( j = 3)
    {
	   if(players[j].is.go >0)
	   {
		  if(players[i].is.stop == players[j].is.stop)
		  {
			 return 0;
			 break;
		  }
		  else
			 x++;

	   }
	   j++; 
    }
    if(x == 3)
    {
	   return 1;
    }
}


int pbak(PLAYER players[])					//피박
{
    int i = 0;
    int j = 0;
    int x = 0;
    PCARD k = 0;
    int p = 0;
    int y = 0;
    while(i < 3)
    {
	   if(players[i].is.stop == 1)
		  break;
	   i++;
    }

    for(j = 0 ; j < 3 ; j++)
    {
	   for( k= players[j].playerHead ; k != NULL ; k = k->next)
	   {
		  if(k->kind == P1)
			 p++;
		  else if(k->kind == SP)
			 p += 2;
		  else
			 p += 0;
	   }
	   if(p < 6)
		  players[j].os.pbak = 1;
    }
    return 0;
}

int mokda(PLAYER players[])					//멍따
{
    int i = 0;
    PCARD j = 0;
    int x = 0;
    for(i = 0; i < 3 ; i++ )
    {
	   for(j = players[i].playerBoardHead ; j != NULL ; j = j->next)
	   {
		  if( j -> kind == KU)
			 x++; 
	   }
	   if( x == 7)
		  players[i].os.mokda =1;
	   return 0;
    }
    
}

int gnbak(PLAYER players[])					//광박
{
    int i = 0;
    PCARD j = 0;
    int  x= 0; 
    if(players[0].is.stop == 1 || players[1].is.stop == 1 || players[2].is.stop == 1)
    {
	   for( i = 0 ; i < 3 ; i++)
	   {
		  for(j = players[i].playerBoardHead ; j!= NULL ; j = j -> next)
		  {
			 if(j -> kind = GN)
				x++;
		  }
		  if(x == 0)
			 players[i].os.gnbak = 1;
	   }
	   return 0;
    }
}

int winner(PLAYER players[])
{
    int i = 0;
    while(i<3)
    {
	   players[i].is.stop == 1;
	   break;
	   i++;
    }
}

int money_count(score)
{
    PLAYER players;
    int money,i,last_score;

    for(i = 0 ; i < 3 ; i++)
    {
	   last_score = score(players[i].playerBoardHead);
	   money = last_score * 100;
    }
    return money;
}

int spare_money(PLAYER players[])
{
    if(players[0].is.stop == 1)
    {
	   players[1].money -= money_count(score(players[1].playerBoardHead));
	   players[2].money -= money_count(score(players[2].playerBoardHead));
	   players[0].money += money_count(score(players[1].playerBoardHead)) + money_count(score(players[2].playerBoardHead));
    }

    if(players[1].is.stop == 1)
    {
	   players[0].money -= money_count(score(players[0].playerBoardHead));
	   players[2].money -= money_count(score(players[2].playerBoardHead));
	   players[1].money += money_count(score(players[0].playerBoardHead)) + money_count(score(players[2].playerBoardHead));
    }
    if(players[2].is.stop == 1)
    {
	   players[1].money -= money_count(score(players[1].playerBoardHead));
	   players[0].money -= money_count(score(players[0].playerBoardHead));
	   players[2].money += money_count(score(players[1].playerBoardHead)) + money_count(score(players[0].playerBoardHead));
    }
}


