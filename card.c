#include			"card.h"
#include			<stdlib.h>
#include			<time.h>

void connectLink(PCARD *dummy,CARD newCard[],int random[]);
void initializeDummy(PCARD * dummy);

int giveCard(PCARD* give,PCARD* take, int index)
{
	if( index < 0 || 8 <= index )
	{
		printf("card.c/giveCard error! checking index");
		return -1;
	}
	else if(index==0)
	{
		PCARD temp=NULL;
		temp	= *take;
		*take	= *give;
		if((*give)!=NULL)
			(*give)=(*give)->next;
		(*take)->next=temp;
		return 0;
	}
	else
		giveCard(&((*give)->next),take,index-1);
}
void sorting(PCARD *cardlist)  	
//sorting card list
{
	PCARD *i,*j,*temp1,temp2;
	int a;
	for(i=cardlist; (*i)->next !=NULL; i=&((*i)->next))
	{
		temp1=i;

		for(j=i ; (*j) ; j=&((*j)->next))
		{
			if((*temp1) -> month > (*j) -> month)
			{
				temp1=j;

			}
		}
		if(i!=temp1)
		{

				temp2	=	(*i);
				*i		=	*temp1;
				*temp1	=	temp2;

				temp2			=	(*i)->next;
				(*i)->next		=	(*temp1)->next;
				(*temp1)->next	=	temp2;
		}
		
	}
}
void cardShuffleStart(PLAYER player[],PCARD *board,PCARD* dummy)	
//initialize card deck and give card from deck to player and board
{
	int i,j;
	
	
	initializeDummy(dummy);		

	for( i = 0 ; i < 3 ; i++ )						
		for( j = 0 ; j < 7 ; j++ )
		{
			giveCard(dummy,&(player[i].playerHead),0);
			sorting(&(player[i].playerHead));
		}

	for( i = 0 ; i < 6 ; i++ )						
	{
		giveCard(dummy,board,0);
		sorting(board);
	}
	
	return;
}
void initializeDummy(PCARD* dummy)
//initialize deck	
{

		CARD newCard[48] = {
			{"1피1",1,P1,NULL},		{"1피2",1,P2,NULL},		{"1광",1,GN,NULL},		{"1띠",1,DI,NULL},
			{"2끗",2,KU,NULL},		{"2띠",2,DI,NULL},		{"2피1",2,P1,NULL},		{"2피2",2,P2,NULL},
			{"3광",3,GN,NULL},		{"3띠",3,DI,NULL},		{"3피1",3,P1,NULL},		{"3피2",3,P2,NULL},
			{"4광",4,KU,NULL},		{"4띠",4,DI,NULL},		{"4피1",4,P1,NULL},		{"4피2",4,P2,NULL},
			{"5끗",5,KU,NULL},		{"5띠",5,DI,NULL},		{"5피1",5,P1,NULL},		{"5피2",5,P2,NULL},
			{"6끗",6,KU,NULL},		{"6띠",6,DI,NULL},		{"6피1",6,P1,NULL},		{"6피2",6,P2,NULL},
			{"7끗",7,KU,NULL},		{"7띠",7,DI,NULL},		{"7피1",7,P1,NULL},		{"7피2",7,P2,NULL},
			{"8광",8,GN,NULL},		{"8끗",8,KU,NULL},		{"8피1",8,P1,NULL},		{"8피2",8,P2,NULL},
			{"9끗",9,KU,NULL},		{"9띠",9,DI,NULL},		{"9피1",9,P1,NULL},		{"9피2",9,P2,NULL},
			{"10끗",10,KU,NULL},	{"10띠",10,DI,NULL},	{"10피1",10,P1,NULL},	{"10피2",10,P2,NULL},
			{"11광",11,GN,NULL},	{"11끗",11,KU,NULL},	{"11피1",11,P1,NULL},	{"11피2",11,P2,NULL},
			{"12광",12,GN,NULL},	{"12끗",12,KU,NULL},	{"12띠",12,DI,NULL},	{"12쌍피",12,SP,NULL}};
		int i, j;
		int random[48];
		srand(time(NULL));
		for( i = 0 ; i < 48 ; i++ )
		{
			random[i]=rand()%48;
			for( j = 0 ; j < i ; j++ )
			{
				if( random[i] == random[j] )
				{
					i--;
					break;
				}
			}
		}
		connectLink(dummy,newCard,random);
}
void connectLink(PCARD *dummy,CARD newCard[],int random[])
//reculcive function for linked list
{
	static int index=47;
	static int i=0;

	*dummy=	(PCARD)malloc(sizeof(CARD));
	**dummy=newCard[random[index]];
	
	if( index != 0 )
	{
		index--;
		connectLink(&((*dummy)->next),newCard,random);
	}
	else
	{
		index=47;
		(*dummy)->next=NULL;
		return;
	}
}

PCARD getCard(PCARD card,int index)										
//get card without modifying the card list
{
	if( index < 0)
	{
		printf("card.c/getCard error! checking index");

		return NULL;
	}
	else if(index==0)
	{
			return card;
	}
	else
		getCard(card->next,index-1);
}
