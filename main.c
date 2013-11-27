#include "card.h"
#include "play.h"
void newGame(void);
void loadGame(void);
void gameStart(PLAYER players[],PCARD boardNode,PCARD dummyNode,PCARD savetemp);
void screen(PLAYER players[],PCARD board,PCARD dummy,PCARD savetemp);
void playstream(int turn,PLAYER players[],PCARD *board,PCARD *dummy,PCARD *savetemp);
void compare(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy,PCARD *savetemp);
int playercheck(int turn,int what,int playerdeck[][7],int bottom[]);
void goplboard(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy);
void goboard(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy);
void movetemp(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy,PCARD *savetemp); //보드에서 먹은 카드를 임시보관하고 옮긴다

int main(void)
{
	int select=0;
	while(1)
	{
		printf("1. 새로운 게임 시작하기\n");
		printf("2. 저장된 게임 열기\n");
		printf("3. 종료하기\n");
		printf("선택:");
		scanf("%d",&select);
		system("clear");
		switch(select){
		case 1:
			newGame();
			break;
		case 2:
			loadGame();
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
}

void newGame(void)
{
	PLAYER		players[3]={0};
	PCARD		board=0;
	PCARD		dummy=0;
	PCARD		savetemp=0;
	gameStart(players,board,dummy,savetemp);
}

void loadGame(void)
{

}
void gameStart(PLAYER players[],PCARD board,PCARD dummy,PCARD savetemp)
{
	int i,j,k;		
	int a;
	int turn=0;
	cardShuffleStart(players,&board,&dummy);
	while(1)
	{
		screen(players,board,dummy,savetemp);
		
           playstream(turn%3,players,&board,&dummy,&savetemp);
		
          printf("턴 마침\n\n");
		turn++;
	}
	getchar();

}
void screen(PLAYER players[],PCARD board,PCARD dummy,PCARD savetemp)
{
	int i;
	int l=0;
	PCARD k;
	PCARD j;
	for(i=0;i<3;i++)												
	{	//printing player interface
		printf("플레이어 %c ( 점수  %d ) 든패  : ",'A'+i,0);				
		for(j=players[i].playerHead;j!=NULL;j=j->next)
		{
			printf("%s  ",getCard(j,0)->name);
		}
		printf("\n");
		printf("먹은 패 : \n");
		for(j=players[i].playerBoardHead;j!=NULL;j=j->next)
		{
		    printf("%s ", getCard(j,0)->name);
		}
		
		printf("\n\n");
		
	}
	printf("깔린 패 : ");
	for(k=board; k!=NULL; k=k->next) //printing board							
	{	    
		printf("%s  ",getCard(board,l)->name);
		l++;
	}
	printf("\n");
}

