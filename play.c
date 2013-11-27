#include			"play.h"
#include			"card.h"
void playstream(int turn,PLAYER players[],PCARD *board,PCARD *dummy)
{
    int what;
    printf("%d 의 차례\n",turn+1);
    printf("카드내기 : ");
    scanf("%d",&what);

    compare(turn,what,players,board,dummy);
}
void compare(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy)
{
    PCARD i,playertemp,dummytemp,k;
    int playercheck=0,dummycheck=0,boardcheck=0,check1=0,check2=0,j=0;

    playertemp = getCard(players[turn].playerHead,what-1);^M
	   dummytemp = getCard(*dummy,0);
    printf("낸 카드 %s\n",playertemp);
    printf("깐 카드 %s\n",dummytemp);

    for(i=*board; i!= NULL ; i=i->next)
    {
	   if(playertemp->month == i->month && dummytemp->month != i->month) //낸카드랑 깔린카드랑 맞으면서 깔린카드와 깐카드랑 다르면
	   {
		  playercheck++;  //낸카드랑 깔린거를 비교해서 같은게있으면 업 조건따지기용
		  giveCard(board,&(players[turn].playerBoardHead),check1); //깔린카드중 맞는것만 "먼저" 냠냠한다.
	   }
	   if(dummytemp->month == playertemp->month)
	   {
		  dummycheck++;   //낸카드랑 깐카드 비교 조건따지기용
	   }
	   check1++; // 포문을 돌면 하나 증가
    }
    for(k=*board ; k!=NULL; k=k->next)
    {
	   if(playertemp->month != k->month && dummytemp->month == k->month) //낸카드가 깔린카드랑 다르지만 깔린카드와 깐카드가 같다면
	   {
		  boardcheck++; //깔린카드랑 깐카드랑 비교 조건따지기용
		  giveCard(board,&(players[turn].playerBoardHead),check2); //깔린카드중 맞는것만 "먼저" 냠냠한다.
	   }
	   check2++;
    }
    printf("playercheck = %d\n",playercheck);
    printf("dummycheck = %d\n",dummycheck);
    printf("boardcheck = %d\n",boardcheck);
    //for(j=0; j<12; j++)
    //  printf("(%d \\ %d)",where1[j],where2[j]);
    if(playercheck == 3 || boardcheck == 3) //조건따지기 시작  // 낸카드와 깔린패를 비교했는데 어떤깔린패 3개와 같거나 깐카드도 어떤깔린패 3개와     같을때
    {
	   if(playercheck == 3 && boardcheck == 3) // 그중에서 낸카드와 깔린패를 비교해서 같고 깔린패와 깐패를 비교해서 모두 3이라면
	   {
		  printf("8개 먹기 피2개내놔");        //플레이어의 피를 뺏어오는건 아직임
		  goplboard(turn,what,players,board,dummy); //깐 카드와 낸카드를 모두 먹은패로 보내는 함수
	   }
	   else //하나라도 같다면 4개먹기가 실행된다.
	   {
		  printf("4개먹기 피내놔\n");
		  goplboard(turn,what,players,board,dummy); //깐 카드와 낸카드를 모두 먹은패로 보내는 함수
	   }
    }
    else if(playercheck == 2 && dumycheck > 0)
    {
	   printf("따닥 피내놔\n");
	   goplboard(turn,what,players,board,dummy); //깐 카드와 낸카드를 모두 먹은패로 보내는 함수
    }
}
else if(playercheck == 2 && dummycheck > 0) //깔린패가 2장인데 그것과 같은 카드를 냈고 깐카드도 같다면
{
    printf("따닥 피내놔\n");
    goplboard(turn,what,players,board,dummy);
}
else if(playercheck == 2 && dummycheck == 0) //깔린패가 2장인데 그것과 같은 카드를 냈지만 깐카드가 달랐다면
{
    if(boardcheck > 0)
    {
	   //plboardeat(boardcheck,where1,where2,turn,what,players,board,dummy);
	   goplboard(turn,what,players,board,dummy);  //나중에 이 함수를 대체할것
	   printf("양자택일\n");
    }
    else if(boardcheck == 0)
    {
	   //plboardeat(boardcheck,where1,where2,turn,what,players,board,dummy);
	   giveCard(&(players[turn].playerHead),&(players[turn].playerBoardHead),what-1);
	   giveCard(dummy,board,0);
	   printf("양자택일\n");
    }
}
else if(playercheck == 1 && dummycheck > 0)
{
    giveCard(&players[turn].playerHead,&(players[turn].playerBoardHead),what-1);
    giveCard(dummy,board,0);
    printf("뻑\n");
}
else if(playercheck == 1 && dummycheck == 0)  //카드냈는데 깐카드가 낸카드랑 다를 때
{
    if(boardcheck > 0)
    {
	   //plboardeat(boardcheck,where1,where2,turn,what,players,board,dummy);
	   giveCard(dummy,&(players[turn].playerBoardHead),0);
	   giveCard(&players[turn].playerHead,&(players[turn].playerBoardHead),what-1);
    }
    if(boardcheck == 0)
    {
	   //plboardeat(boardcheck,where1,where2,turn,what,players,board,dummy);
	   giveCard(dummy,board,0);
	   giveCard(&players[turn].playerHead,&(players[turn].playerBoardHead),what-1);
    }
}
else if(playercheck == 0 && dummycheck > 0)
{
    printf("쪽 피내놔\n");
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
	   giveCard(&(players[turn].playerHead),board,what-1);
	   giveCard(dummy,&(players[turn].playerBoardHead),0);
    }
}
}
void goplboard(/*int boardcheck,int where1[],int where2[],*/int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy) //낸카드와 깐카드를 모두 먹은패로 보내주는 함수
{
    PCARD i;
    int j=0;
    //plboardeat(boardcheck,where1,where2,turn,what,players,board,dummy);
    giveCard(dummy,&(players[turn].playerBoardHead),0); //깐 카드를 먹은카드로 보낸다
    giveCard(&players[turn].playerHead,&(players[turn].playerBoardHead),what-1);// 낸카드를 먹은카드로 보낸다
}
void goboard(int turn,int what,PLAYER players[],PCARD *board,PCARD *dummy) //낸카드와 깐카드를 모두 판으로 보내주는 함수
{
    giveCard(&(players[turn].playerHead),board,what-1); // 낸카드를 보드로 보낸다
    giveCard(dummy,board,0); // 깐카드를 보드로 보낸다
}

