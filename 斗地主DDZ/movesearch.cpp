#include "stdafx.h"
#include "movesearch.h"

Player Pex;
movesearch::movesearch(void)
{
	
}


movesearch::~movesearch(void)
{
}
vector<CARDS> movesearch::newplayer(Player P,Player &Pex)
{
	Transform * transform=new Transform();
	chaipai *cha=new chaipai();
	vector<CARDS> vec;
	Pex.NumsCard=P.RestCard;
	Pex.GetEachCardNums();
	Pex.HandsCard=transform->NumsTransform(Pex.NumsCard);
	Pex.CardsNums=0;//牌的数量的初始值
	Pex.CardsNums+=Pex.NumsCard.size();
	vec=cha->GetCombination_1(Pex);
	delete(transform);
	delete(cha);
	return vec;
}
void movesearch::newplayer_1(Player P,Player &Pex)
{
	Transform * transform=new Transform();
	chaipai *cha=new chaipai();
	vector<CARDS> vec;
	Pex.NumsCard=P.RestCard;
	Pex.GetEachCardNums();
	Pex.HandsCard=transform->NumsTransform(Pex.NumsCard);
	Pex.CardsNums=0;//牌的数量的初始值
	Pex.CardsNums+=Pex.NumsCard.size();
	delete(transform);
	delete(cha);
}
vector<CARDS> movesearch::search(Player &P,Player &Pex)
{
	chaipai *cha=new chaipai();
	vector<CARDS> vec1=cha->GetCombination_1(P);
	vector<CARDS> vec2=movesearch::newplayer(P,Pex);
	vector<CARDS> VEC;
	for(size_t i=0;i<vec1.size();i++)
	{
		bool ok=true;
		for(size_t j=0;j<vec2.size();j++)
		{
			if(vec2.at(j).cardsType==vec1.at(i).cardsType&&vec2.at(j).score>vec1.at(i).score&&vec2.at(j).cards.size()==vec1.at(i).cards.size())
			{
				ok=false;
			}
			else if(vec2.at(j).cardsType==ZHADAN&&vec2.at(j).score>vec1.at(i).score)
			{
			    ok=false;
			}
		}
		if(ok)
		{
			VEC.push_back(vec1.at(i));
		}
	}
	if(VEC.size()<vec1.size()-1)
	{
		vector<CARDS> empety;
		return empety;
	}
	else
		return VEC;
}
vector<CARDS> movesearch::search_1(Player P)
{
	if(P.RestCard.size()>20)
	{
		vector<CARDS> vec;
		return vec;
	}
	vector<CARDS> vec=movesearch::search(P,Pex);
	return vec;
}
CARDS movesearch::congge(Player &Pex,CARDS cards)
{
	MoveGenerator *move=new MoveGenerator();
	Transform * transform=new Transform();
	vector<CARDS> vec;
	switch (cards.cardsType)
	{
	case 2:vec=move->GetZhadanCards(Pex);break;
	case 3:vec=move->GetSingleCard(Pex);break;
	case 4:vec=move->GetCoupleCards(Pex);break;
	case 5:vec=move->GetSantiaoCards(Pex);break;
	case 6:vec=move->GetThree_oneCards(Pex);break;
	case 7:vec=move->GetThree_twoCards(Pex);break;
	case 8:vec=move->GetSinglejunkoCards(Pex,cards.cards.size());break;
	case 9:vec=move->GetDoublejunkoCards(Pex,cards.cards.size()/2);break;
	case 10:vec=move->GetThreejunkoCards(Pex,cards.cards.size()/3);break;
	case 11:vec=move->GetThreejunko_oneCards(Pex,2);break;
	case 12:vec=move->GetThreejunko_twoCards(Pex,2);break;
	case 13:vec=move->GetFour_twoCards(Pex);break;
	case 14:vec=move->GetFour_doubletwoCards(Pex);break;
	default:
		break;
	}
	int i=vec.size()-1;
	while(i>-1)
	{
        if(vec.at(i).score>cards.score)
		{
			chaipai *cha=new chaipai();
			cha->gencing(Pex,vec.at(i));
			delete(cha);
			return vec.at(i);
		}
		i--;
	}
	vec=move->GetZhadanCards(Pex);
	if(!vec.empty())
	{
		for(size_t i=0;i<vec.size();i++)
		{
		  if(vec.at(i).score>cards.score)
		  {
			  srand(time(NULL));
			  int n = rand()%10;
			  if(n>5)
			  {
				  chaipai *cha=new chaipai();
				  cha->gencing(Pex,vec.at(i));
				  delete(cha);
				  return vec.at(0);
			  }
		  }
		}
	}
    CARDS cards0;
	return cards0;
}
CARDS static card;
int movesearch::duiyi(Player &Pex,vector<CARDS> vec,CARDS cards)
{
	vector<CARDS> VEC=vec;
	CARDS cards1,cards2;
	if(cards.cards.empty())
	{
		for(size_t i=0;i<vec.size();i++)
		{
			cards1=vec.at(i);
			vector<CARDS>::iterator it=vec.begin();
			vec.erase(it+i);
			if(vec.empty())
	        {
				card=cards1;
				return 1;
			}
			cards2=movesearch::congge(Pex,cards1);
			if(duiyi(Pex,vec,cards2))
			{
                card=cards1;
				return 1;
			}
			chaipai *cha=new chaipai();
			cha->huifu(Pex,cards2);
			vec=VEC;
			delete(cha);
		}
	}
	else
	{
		for(size_t i=0;i<vec.size();i++)
		{		
			if(vec.at(i).cardsType==cards.cardsType&&vec.at(i).score>cards.score&&vec.at(i).cards.size()==cards.cards.size())
			{
				cards1=vec.at(i);
				vector<CARDS>::iterator it=vec.begin();
			    vec.erase(it+i);
			    if(vec.empty())
	            {
				  card=cards1;
				  return 1;
			    }
			    cards2=movesearch::congge(Pex,cards1);
			    if(duiyi(Pex,vec,cards2))
			    {
                  card=cards1;
				  return 1;
			    }
				chaipai *cha=new chaipai();
				cha->huifu(Pex,cards2);
				vec=VEC;
				delete(cha);
			}
			else if(vec.at(i).cardsType==ZHADAN&&vec.at(i).score>cards.score)
			{
			    cards1=vec.at(i);
				vector<CARDS>::iterator it=vec.begin();
			    vec.erase(it+i);
			    if(vec.empty())
	            {
				card=cards1;
				return 1;
			    }
			    cards2=movesearch::congge(Pex,cards1);
			    if(duiyi(Pex,vec,cards2))
			    {
                  card=cards1;
				  return 1;
			    }
				chaipai *cha=new chaipai();
				cha->huifu(Pex,cards2);
				vec=VEC;
				delete(cha);
			}
		}
		
	}
	return 0;
}
CARDS movesearch::duiyi_1(Player P,CARDS cards,vector<CARDS> vec)
{
	if(vec.size()>6)
	{
		CARDS cards1;
		return cards1;
	}
	MoveGenerator *move=new MoveGenerator();
	move->paixu(vec);
	delete(move);
	movesearch::newplayer_1(P,Pex);
	if(movesearch::duiyi(Pex,vec,cards))
		return card;
	else
	{
		CARDS cards1;
		return cards1;
	}
}