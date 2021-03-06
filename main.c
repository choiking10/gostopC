#include "card.h"
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

void playstream(int turn,PLAYER players[],PCARD *board,PCARD *dummy,PCARD *savetemp)
 {
     int what;
     printf("%d 의 차례\n",turn+1);
     printf("카드내기 : ");
	scanf("%d",&what);
     compare(turn,what,players,board,dummy,savetemp);   //입력하는 번호에 따라 바뀌도록 수정할 것
 }

void compare(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy,PCARD *savetemp)  //현재 든패 바닥패를 배열에 넣음
{
    PCARD i,playertemp,dummytemp,k,l,x;
    int playercheck=0,dummycheck=0,boardcheck=0,check1=0,check2=0,j=0,m=0,counter1=0,counter2=0;
	playertemp = getCard(players[turn].playerHead,what-1);
	dummytemp = getCard(*dummy,0);
	printf("낸 카드 %s\n",playertemp);
	printf("깐 카드 %s\n",dummytemp);
	for(i=*board; i!= NULL ; i=i->next) //포문을 돌릴 횟수를 재어줌
	{
	    counter1++;
	}
	l = *board;
	for(j=0; j<counter1; j++) // 이 포문은 낸카드와 깔린카드를 비교해서 temp로 옮겨줌
	{
	    printf("%d월 ",l->month);
		if(playertemp->month == l->month) //낸카드랑 깔린카드랑 맞으면
		{
		    l = l->next;    //먼저 다음주소를 가리키게 함. 그래야만 문제없이 다음달을 비교할 수 있게됨
		    playercheck++;  //낸카드랑 깔린거를 비교해서 같은게있으면 업 조건따지기용
		    giveCard(board,savetemp,check1); //맞는 카드를 임시공간 temp Linked List에 보냄
		    check1--;		// 링크드리스트의 공간이 1칸 줄어듬으로 가져올 위치도 1칸 줄여줘야한다.
		}
		else
		{
		    l = l->next;  //비교대상이 없다면 다음 카드를 가리키게한다.
		}
		if(dummytemp->month == playertemp->month)
		{
		    dummycheck++;   //낸카드랑 깐카드 비교 조건따지기용
		}
		check1++;
	}
	for(k=*board ; k!=NULL; k=k->next)   //이 포문의 역할도 횟수를 세어주는데 따로하는 이유는 두번비교하기 위함임
	{
	    counter2++;
	}
	x = *board;
	for(m=0; m<counter2; m++)  // 이 포문은 깔린카드와 깐카드를 비교해서 temp로 옮겨줌
	{
	    if(dummytemp->month == x->month) // 깔린카드와 깐카드가 같다면
	    {
		   x = x->next;
		   boardcheck++; //깔린카드랑 깐카드랑 비교 조건따지기용
		   giveCard(board,savetemp,check2); //맞는 카드를 임시공간 temp Linked List에 보냄
		   check2--;
	    }
	    else
	    {
		   x = x->next;
	    }
	    check2++;
	}
	printf("playercheck = %d\n",playercheck);
	printf("dummycheck = %d\n",dummycheck);
	printf("boardcheck = %d\n",boardcheck);
	if(playercheck == 3 || boardcheck == 3) //조건따지기 시작  // 낸카드와 깔린패를 비교했는데 어떤깔린패 3개와 같거나 깐카드도 어떤깔린패 3개와 같을때
	{
	    if(playercheck == 3 && boardcheck == 3) // 그중에서 낸카드와 깔린패를 비교해서 같고 깔린패와 깐패를 비교해서 모두 3이라면 
	    {
		   printf("8개 먹기 피2개내놔");     
		   movetemp(turn,what,players,board,dummy,savetemp);	   //플레이어의 피를 뺏어오는건 아직임 //임시공간에 있는 카드 옮겨주는 함
		   goplboard(turn,what,players,board,dummy); //깐 카드와 낸카드를 모두 먹은패로 보내는 함수
	    }
	    else //하나라도 같다면 4개먹기가 실행된다.
	    {
	    		printf("4개먹기 피내놔\n");
			movetemp(turn,what,players,board,dummy,savetemp);
	    		goplboard(turn,what,players,board,dummy); //깐 카드와 낸카드를 모두 먹은패로 보내는 함수
	    }
	}
	else if(playercheck == 2 && dummycheck > 0) //깔린패가 2장인데 그것과 같은 카드를 냈고 깐카드도 같다면
	{
	    printf("따닥 피내놔\n");
	    movetemp(turn,what,players,board,dummy,savetemp);
	    goplboard(turn,what,players,board,dummy);
	}
	else if(playercheck == 2 && dummycheck == 0) //깔린패가 2장인데 그것과 같은 카드를 냈지만 깐카드가 달랐다면
	{
	    if(boardcheck > 0)
	    {
		   movetemp(turn,what,players,board,dummy,savetemp);
		   goplboard(turn,what,players,board,dummy);  //나중에 이 함수를 대체할것
	    		printf("양자택일\n");
	    }
	    else if(boardcheck == 0)
	    {
		   movetemp(turn,what,players,board,dummy,savetemp);
		   giveCard(&(players[turn].playerHead),&(players[turn].playerBoardHead),what-1);
		   giveCard(dummy,board,0);
		   printf("양자택일\n");
	    }
	}
	else if(playercheck == 1 && dummycheck > 0)
	{
	    //movetemp(turn,what,players,board,dummy,savetemp);
	    giveCard(savetemp,board,0);
	    giveCard(&players[turn].playerHead,board,what-1);
	    giveCard(dummy,board,0);
	    printf("뻑\n");
	}
	else if(playercheck == 1 && dummycheck == 0)  //카드냈는데 깐카드가 낸카드랑 다를 때
	{
	    if(boardcheck > 0)
	    {
		   movetemp(turn,what,players,board,dummy,savetemp);
		   giveCard(dummy,&(players[turn].playerBoardHead),0);
		   giveCard(&players[turn].playerHead,&(players[turn].playerBoardHead),what-1);
	    }
	    if(boardcheck == 0)
	    {
		   movetemp(turn,what,players,board,dummy,savetemp);
		   giveCard(dummy,board,0);
		   giveCard(&players[turn].playerHead,&(players[turn].playerBoardHead),what-1);
    	    }
	}
	else if(playercheck == 0 && dummycheck > 0)
	{
	    printf("쪽 피내놔\n");
	    movetemp(turn,what,players,board,dummy,savetemp);
	    giveCard(&(players[turn].playerHead),&(players[turn].playerBoardHead),what-1);
	    giveCard(dummy,&(players[turn].playerBoardHead),0);
	}
	else if(playercheck == 0 && dummycheck == 0)
	{
	    if(boardcheck == 0)
	    {
			goboard(turn,what,players,board,dummy);
	    }
	    else if(boardcheck > 0)
	    {
		   movetemp(turn,what,players,board,dummy,savetemp);
		   giveCard(&(players[turn].playerHead),board,what-1);
		   giveCard(dummy,&(players[turn].playerBoardHead),0);
	    }
	}


}
void goplboard(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy) //낸카드와 깐카드를 모두 먹은패로 보내주는 함수
{
    PCARD i;
    int j=0;
    	giveCard(dummy,&(players[turn].playerBoardHead),0); //깐 카드를 먹은카드로 보낸다
  	giveCard(&players[turn].playerHead,&(players[turn].playerBoardHead),what-1);// 낸카드를 먹은카드로 보낸다
}
void goboard(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy) //넨거 깐거 모두 꽝일 때
{
    giveCard(&(players[turn].playerHead),board,what-1); // 낸카드를 보드로 보낸다
    giveCard(dummy,board,0); // 깐카드를 보드로 보낸다
}
void movetemp(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy,PCARD *savetemp)
{
    int count=0,j;
    PCARD *i;
    for(i=savetemp; (*i)!=NULL; i=&((*i)->next))
    {
	   count++;  //현재 링크드리스트에 있는 노드들의 개수를 세어줌
    }
    for(j=0; j<count; j++)  //기존의 포문의 단점을 보완. 모든 링크드리스트를 한번씩 다 거침.
    {
    		giveCard(savetemp,&(players[turn].playerBoardHead),0);
    }
}
