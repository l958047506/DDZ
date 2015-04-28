#include "stdafx.h"
#include "chaipai.h"


chaipai::chaipai(void)
{
}


chaipai::~chaipai(void)
{
}

vector<CARDS> chaipai::GetSinglejunkoCards(Player P)           //顺子
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
	for(size_t i=5;i<11;i++)
	{
		vec1=move->GetSinglejunkoCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetDoublejunkoCards(Player P)          //连对
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
		for(size_t i=3;i<=8;i++)
	{
		vec1=move->GetDoublejunkoCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetThreejunkoCards(Player P)             //飞机
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
		for(size_t i=2;i<=4;i++)
	{
		vec1=move->GetThreejunkoCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetThreejunko_oneCards(Player P)    //飞机带单牌
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
	for(size_t i=2;i<=4;i++)
	{
		vec1=move->GetThreejunko_oneCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetThreejunko_twoCards(Player P)    //飞机带对子
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
		for(size_t i=2;i<=3;i++)
	{
		vec1=move->GetThreejunko_twoCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetCombination(Player P)//获取最少走步的牌型组合
{
	int N=0;//记录最少出多少次能把手中的牌出牌；
	if(P.CardsNums==0)
	{
		vector<CARDS> VEC; 
		return VEC;//返回一个空的
	}
	else
	{
		vector<CARDS> vec,VEC,VEC1;	//vec用来获取一种牌型的所有走步。VEC作为返回。VEC1过渡。
		CARDS vec1;//获取一种牌型的一种走步
		int min=20,n=0,value=0;//min记录最小走步,n用于提高某种组合的权值。
		size_t k=0;//用于遍历完一种牌型所有走步
		MoveGenerator *move=new MoveGenerator();
		vector<unsigned> me=transform.NumsTransform(P.MeetCard);
		CARDS Mediating=move->GetCardsDetail(me);
		for(size_t i=1;i<=11;i++)
		{
			switch (i)
			{
			case 1:vec=move->GetZhadanCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}//如果没有该牌型，就不执行该case语句，直接跳到下一个case；
				else
				{
						vec1=vec.at(k);//获取一种情况，记录；
						k++;
						i--;//使得下次遍历该switch语句是，继续执行该case；（该牌型还没有取完的时候）
						n-=2;//是炸弹的权值变高
						if(k==vec.size())//如果这是该牌型的最后一种组合，下次switch时就不需要执行该case，所以i++；初始化k的值；
						{k=0;i++;}
						break;
					}
			case 2:vec=chaipai::GetThreejunko_oneCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREEJUNKO_ONE)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 3:vec=chaipai::GetThreejunko_twoCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREEJUNKO_TWO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 4:vec=chaipai::GetThreejunkoCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREEJUNKO)
					{n-=2;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 5:vec=chaipai::GetDoublejunkoCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==DOUBLEJUNKO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 6:vec=chaipai::GetSinglejunkoCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==SINGLEJUNKO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 7:vec=move->GetThree_twoCards(P) ;
				vec.at(0).cardsType=INVAILD;
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREE_TWO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 8:vec=move->GetThree_oneCards(P) ;
				vec.at(0).cardsType=INVAILD;
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREE_ONE)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 9:vec=move->GetSantiaoCards(P) ;
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==SANTIAO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 10:vec=move->GetCoupleCards(P);//为了提高速度，将对子和单牌，当做一种牌型
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					VEC1=vec;
					N+=vec.size();	
					for(size_t l=0;l<vec.size();l++)
					{
						gencing(P,vec.at(l));//还原上次对eachcardsnum的更新
					}
					if(P.CardsNums==0)//如果取对子能将剩余的牌取完，就没有必要再去取单牌，所以就直接返 回，跳过取单牌
					{
						for(size_t l=0;l<vec.size();l++)
						{
						huifu(P,vec.at(l));//还原上次对eachcardsnum的更新
						}
						delete(move);
						if(N<min)
						{
						return VEC1;
						}
						else
						{
							return VEC;
						}
					}
				}
			case 11:vec=move->GetSingleCard(P);
				if(vec.empty())
				{break;}
				else
				{
					for(size_t l=0;l<vec.size();l++)
					{
					vec1=vec.at(l);
					VEC1.push_back(vec1);
					gencing(P,vec1);
					}
					N+=vec.size();	
					delete(move);
					for(size_t l=0;l<vec.size();l++)
					{
						huifu(P,VEC1.at(l));//还原上次对eachcardsnum的更新
					}
					if(N<min)
					{
						return VEC1;
					}
					else
					{
					    return VEC;
					}
				}
			default:
				break;
			}//switch
    		gencing(P,vec1);//更新剩下每张牌的张数
			VEC1=chaipai::GetCombination(P);//再次调用
			N=n+VEC1.size();//走步数
			if(N==min)
			{
				if(move->cardsvalue(VEC1)>value)
				{
					VEC=VEC1;
				    VEC.push_back(vec1);
				    value=move->cardsvalue(VEC1);
				}
			}
			if(N<min)
			{
				min=N;
				VEC=VEC1;
				VEC.push_back(vec1);
				value=move->cardsvalue(VEC1);
			}
			n=0;
			N=0;
			huifu(P,vec1);//还原上次对eachcardsnum的更新
		 }//for
	 }//else
	 vector<CARDS> VEC; 
	 return VEC;//返回一个空的
}
vector<CARDS> chaipai::GetCombination_1(Player P)
{
	vector<CARDS> vec=chaipai::GetCombination(P);
	MoveGenerator *move=new MoveGenerator();
	vector<unsigned> me=transform.NumsTransform(P.MeetCard);
	CARDS Mediating=move->GetCardsDetail(me);
	vector<CARDS>::iterator it=vec.begin();
	CARDS cards;
	int value=-10,k,N1=0,N2=0;//value剩余牌的估值，K记录所带牌的位置，N1记录单牌的个数；N2对子的个数
	for(size_t i=0;i<vec.size();i++)
	{
		if(vec.at(i).cardsType==SANTIAO)
		{
			if(vec.at(i).score==12)//如果三条为三个2；根据情况考虑是否有必要三个2 ；
			{
				CARDS cards;
				cards.cards.push_back(12);
				cards.cards.push_back(12);
				cards.cardsType=COUPLE;
				cards.score=12;
				vec.push_back(cards);
				cards.cards.pop_back();
				cards.cardsType=SINGLE;
				cards.score=12;
				vec.push_back(cards);
				vector<CARDS>::iterator it=vec.begin();
				vec.erase(it+i);
			}
			else
			{
			for(size_t j=0;j<vec.size();j++)
	        {
				vector<CARDS>	VEC=vec;
				int v=0;
				if(vec.at(j).cardsType==SINGLE||vec.at(j).cardsType==COUPLE)
				{
					if(Mediating.cardsType==THREE_ONE)
					{
						if(VEC.at(j).cardsType==COUPLE)
						{
							CARDS c;
						   c.cards.push_back(j);
						   c.cardsType=SINGLE;
						   c.score=VEC.at(j).score;
						   VEC.push_back(c);
						}
					}
					else if(Mediating.cardsType==THREE_TWO)
					{
						if(VEC.at(j).cardsType==COUPLE)
						{
					     v+=5;
						}
					}
					vector<CARDS>::iterator it1=VEC.begin();
					VEC.erase(it1+j);
					v+=move->cardsvalue(VEC);
					if(v>value)
					{
						cards=vec.at(j);
						k=j;
						value=v;
					}				 	
				}
			}			
			if(cards.cardsType==SINGLE)
			{
			vec.at(i).cards.push_back(cards.cards.at(0));	
			vec.at(i).cardsType=THREE_ONE;
			}
			else if(cards.cardsType==COUPLE)
			{
				vec.at(i).cards.push_back(cards.cards.at(0));	
				vec.at(i).cards.push_back(cards.cards.at(0));	
				vec.at(i).cardsType=THREE_TWO;
            }
			else
			{
				continue;
			}
			vec.erase(it+k);
			if(k<(int)i)
			i--;
		}
		}//三带一
		if(vec.at(i).cardsType==SINGLE)
		{
		    N1++;
		}
		if(vec.at(i).cardsType==COUPLE)
		{
		    N2++;
		}
	}
	for(size_t i=0;i<vec.size();i++)
	{
		if(vec.at(i).cardsType==COUPLE&&vec.at(i).score==12)
		{
			if(N1>N2+1)//如果单牌张数大于对牌 就把一对2拆成单牌
		   {
			CARDS c;
			c.cards.push_back(vec.at(i).cards.at(0));
			c.cardsType=SINGLE;
			c.score=vec.at(i).score;
			vec.push_back(c);
			vec.push_back(c);
			vector<CARDS>::iterator it=vec.begin();
			vec.erase(it+i);
			break;
		    }
		}
	}
	return vec;
}
void chaipai::gencing(Player &P,CARDS vec)//跟新剩下的牌
{
	//由于在获取炸弹、连子....的时候没有用到 NumsCards和HandsCards  为减少工作量不对其进行操作；
	//P.GetRestCard(P.NumsCard,transform._NumsTransform(vec.cards,P));//将玩家手中剩余的牌跟新(0~53)
	//P.HandsCard=transform.NumsTransform(P.NumsCard);//将玩家手中牌跟新（0~14）	
	//P.GetEachCardNums();//更新每张牌的数量
	for(size_t i=0;i<vec.cards.size();i++)
	{
		for(size_t j=0;j<15;j++)
		{
			if(vec.cards.at(i)==j)
			{
			P.EachCardNums[j]--;
			break;
			}
		}
	}
	P.CardsNums-=vec.cards.size();//手牌数量减少
}
void chaipai::huifu(Player &P,CARDS vec)//恢复上一步跟新的牌
{
	for(size_t i=0;i<vec.cards.size();i++)
	{
		for(size_t j=0;j<15;j++)
		{
			if(vec.cards.at(i)==j)
			{
			P.EachCardNums[j]++;
			break;
			}
		}
	}
	P.CardsNums+=vec.cards.size();//手牌数量减少
}