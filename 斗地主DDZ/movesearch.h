#pragma once
#include"MoveGenerator.h"
#include"Player.h"
#include"time.h"

class movesearch
{
public:
	
	movesearch(void);
	~movesearch(void);
	vector<CARDS> newplayer(Player P,Player &Pex);
	void newplayer_1(Player P,Player &Pex);
	vector<CARDS> search(Player &P,Player &Pex);
	vector<CARDS> search_1(Player P);
	CARDS congge(Player &P,CARDS cards);
	int duiyi(Player &Pex,vector<CARDS> vec,CARDS cards);
	CARDS duiyi_1(Player P,CARDS cards,vector<CARDS> vec);
};

