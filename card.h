//writing the header file and implement function : 최윤호
#ifndef _CARD_H_
#define _CARD_H_
#include <stdio.h>
//define card ID
#define		P1						10				//피
#define		P2						11				//피2
#define		SP						12				//쌍피
#define		KU						2				//끗
#define		DI						3				//띠
#define		GN						4				//광



typedef struct card {								//card struct
	char			name[8];
	int				month;
	int				kind;							
	struct card*	next;
}CARD;
typedef		CARD					*PCARD;

typedef struct in_special {								//in sepcial struct
	_Bool			stop; 	// 스탑
	int				go;   	// 고
}INSPECIAL;

typedef struct out_special {								//out speical struct
    _Bool			shake;	//흔들기
    _Bool			nagari;	//나가리
    _Bool			gnbak;	//광박
    _Bool 			pbak;	//피박
    _Bool			gobak;	//고박
    _Bool			mokda;	//멍따
}OUTSPECIAL;

typedef struct player{								//player struct
	PCARD			playerHead;
	PCARD			playerBoardHead;
	int				money;
	INSPECIAL 		is;
	OUTSPECIAL 		os;


}PLAYER;

int giveCard(PCARD* give,PCARD* take, int index);					 
//move the index-th card form 'give' to 'take' 
void sorting(PCARD *x);	
//sorting the card list(don`t use dummy)
void cardShuffleStart(PLAYER player[],PCARD *board,PCARD* dummy);	
//initialize dummy, set player`s and dummy`s card list

PCARD getCard(PCARD card,int index);
//get a index-th card without modifying card list

int score(PCARD cardlist);

#endif
