#include "stdafx.h"
#include "ThinkTable.h"


CThinkTable::CThinkTable(void)
{
}


CThinkTable::~CThinkTable(void)
{
}

int CThinkTable::Thinktable(Player P)
{
	int CardsPoints=2,Piont=0;
	CardsPoints+=(int)0.5*P.EachCardNums[12];
	chaipai CH;
	vector<CARDS> VEC=CH.GetCombination_1(P);
	if(VEC.size()<=5)
		CardsPoints+=6;
	if(VEC.size()>5&&VEC.size()<8)
		CardsPoints+=2;
	for(size_t i=0;i<VEC.size();i++)
	{
		if(VEC.at(i).cardsType==ZHADAN)
		{
			CardsPoints+=4;
			if(VEC.size()<=5)
		    CardsPoints+=2;
		}
		else if(VEC.at(i).score==13)
	    {
		CardsPoints+=1;
	    }
		else if(VEC.at(i).score==14)
	    {
		CardsPoints+=2;
	    }

	}
	if(CardsPoints>10)Piont=3;
	else if(CardsPoints>=6&&CardsPoints<=10)Piont=2;
	else if(CardsPoints>=3&&CardsPoints<6)Piont=1;
	else Piont=0;
	return Piont;
}