#include "stdafx.h"
#include "MoveGenerator.h"


MoveGenerator::MoveGenerator(void)
{
}


MoveGenerator::~MoveGenerator(void)
{
}
CARDS MoveGenerator::GetCardsDetail(vector<unsigned> cards)//对（0~14）的牌进行整理,返回（0~14）
{
	CARDS Mediating;
	int size=cards.size();//套牌的张数
	sort(cards.begin(),cards.end());//排序（升序）。 sort STL算法
	for(size_t i=0;i<cards.size();i++)
		{
          	Mediating.cards.push_back(cards.at(i));
		}
	switch(size)
	{
	case 1://单牌
		Mediating.cardsType=SINGLE;
		Mediating.score=cards.at(0);
		return Mediating;
	case 2://对子，火箭
        if((cards.at(0)==13&&cards.at(1)==14)||(cards.at(0)==14&&cards.at(1)==13))//如果是大小王
		{
			Mediating.cardsType=ZHADAN;
			Mediating.score=100;//火箭最大随意设的一个最大值100
		}
		else
		{
		    Mediating.cardsType=COUPLE;
		    Mediating.score=cards.at(0);
		}
		return Mediating;
	case 3://三条
		Mediating.cardsType=SANTIAO;
		Mediating.score=cards.at(0);
		return Mediating;
	case 4://三带一，炸弹
		if(cards.at(0)==cards.at(1)&&cards.at(0)==cards.at(2)&&cards.at(0)==cards.at(3))
		{
			Mediating.cardsType=ZHADAN;
			Mediating.score=cards.at(0)+20;
		}
		else
		{
			Mediating.cardsType=THREE_ONE;
			for(size_t i=0;i<cards.size()-1;i++)
			{
				if(cards.at(i)==cards.at(i+1))//如果其中有两个相等的，则此套牌大小就是该值
				{
					Mediating.score=cards.at(i);
					break;
				}

			}    
		}
		return Mediating;
	case 5://5连子，三带对
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score=cards.at(0);
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))//若有三个相等的
			{
				Mediating.cardsType=THREE_TWO ;//更换其牌型和大小
				Mediating.score=cards.at(i);
				break;
			}
		}
		return Mediating;

	case 6://6连子，四带二单，3连队，飞机
		for(size_t i=0;i<cards.size()-3;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2)&&cards.at(i)==cards.at(i+3))
			{
				Mediating.cardsType =FOUR_TWO ;
				Mediating.score=cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-1;i++)
		{
			if(cards.at(i)==cards.at(i+1))
			{
				Mediating.cardsType=DOUBLEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 7://7连子
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 8://8连子，4连队，飞机带两单，四带两对
		for(size_t i=0;i<cards.size()-3;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2)&&cards.at(i)==cards.at(i+3))
			{
				Mediating.cardsType =FOUR_TWO ;
				Mediating.score=cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_ONE;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-1;i++)
		{
			if(cards.at(i)==cards.at(i+1))
			{
				Mediating.cardsType=DOUBLEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 9://9连子，飞机
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 10://10连子，5连对，飞机带两对
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_TWO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-1;i++)
		{
			if(cards.at(i)==cards.at(i+1))
			{
				Mediating.cardsType=DOUBLEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 11://11连子
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 12://12连子，6连对，3飞机带三单，4飞机(偷懒，由于有4飞机的可能非常小，且四飞机不带牌的几率更小，所以忽略4飞机)
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_ONE;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size();i++)
		{
			if(cards.at(i)==cards.at(i+1))
			{
				Mediating.cardsType=DOUBLEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 14://7连对
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 15://5飞机，3飞机带三队
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_TWO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
    case 16://8连对，4飞机带单
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_ONE;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 18://9连对
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 20://10连对
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	default:
			break;
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetSingleCard(Player P)    //返回（0~14）                   //获得单牌
{
	vector<CARDS> Mediating;//记录所有单牌
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=1)
		{
			for(size_t j=0;j<P.EachCardNums[i];j++)
			{
			solo.cards.push_back(i);
			solo.cardsType=SINGLE;
			solo.score=i;
		    Mediating.push_back(solo);
		    solo.cards.clear();//对容器进行清空，方便下一次记录；
			}
		}
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetCoupleCards(Player P)                  //获得对子
{
	vector<CARDS> Mediating;//记录所有对牌
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=2)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cardsType=COUPLE;
			solo.score=i;
			Mediating.push_back(solo);
		    solo.cards.clear();//对容器进行清空，方便下一次记录
		}
		
	}
	if(Mediating.empty())//如果没有对子。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetSantiaoCards(Player P)                     //三条
{
	vector<CARDS> Mediating;//记录所有三条
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=3)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cardsType=SANTIAO;
			solo.score=i;
			Mediating.push_back(solo);
		    solo.cards.clear();//对容器进行清空，方便下一次记录
		}
	}
	if(Mediating .empty())//如果没有三条。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetThree_oneCards(Player P)                //三带一
{
	vector<CARDS> Mediating;//记录所有三带一
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=3)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			for(size_t j=0;j<15;j++)
			{
				if(P.EachCardNums[j]>=1&&j!=i)
				{
					solo.cards.push_back(j);
					solo.cardsType=THREE_ONE;
			        solo.score=i;
			        Mediating.push_back(solo);
					solo.cards.pop_back();
				}
			}
			solo.cards.clear();//对容器进行清空，方便下一次记录
		}	
	}
	if(Mediating .empty())//如果没有三带一。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;

}
vector<CARDS> MoveGenerator::GetThree_twoCards(Player P)                //三带对
{
	vector<CARDS> Mediating;//记录所有对牌
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=3)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			for(size_t j=0;j<15;j++)
			{
				if(P.EachCardNums[j]>=2&&j!=i)
				{
					solo.cards.push_back(j);
					solo.cards.push_back(j);
					solo.cardsType=THREE_TWO;
			        solo.score=i;
			        Mediating.push_back(solo);
					solo.cards.pop_back();
					solo.cards.pop_back();
				}
			}
			solo.cards.clear();//对容器进行清空，方便下一次记录
		}	
	}
	if(Mediating .empty())//如果没有三带对。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetSinglejunkoCards(Player P,size_t Num)            //顺子
{
	vector<CARDS> Mediating;//记录所有顺子
	CARDS solo;
	bool kill;
	for(size_t i=0;i<13-Num;i++)//当num=5时，i的值最多为10形成连子（10,J,Q,K,A）
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<1)
		   {
			   kill=false;
		   }
		}
		if(kill)
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				
				
			}
			solo.cardsType=SINGLEJUNKO;
			solo.score=i;
			Mediating.push_back(solo);
			solo.cards.clear();//对容器进行清空，方便下一次记录
		}
	}
	if(Mediating .empty())//如果没有连子。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetDoublejunkoCards(Player P,size_t Num)          //连对
{
	vector<CARDS> Mediating;//记录所有连对
	CARDS solo;
	bool kill;
	for(size_t i=0;i<13-Num;i++)//当num=3时，i的值最多为Q形成连对（QQ,KK,AA）
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<2)//若小于两张
		   {
			   kill=false;
			   break;
		   }
		}
		if(kill)
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				solo.cards.push_back(j);	
			}
			solo.cardsType=DOUBLEJUNKO;	
			solo.score=i;
			Mediating.push_back(solo);
			solo.cards.clear();//对容器进行清空，方便下一次记录
		}
	}
	if(Mediating .empty())//如果没有连对。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetThreejunkoCards(Player P,size_t Num)             //飞机
{
	vector<CARDS> Mediating;//记录所有连对
	CARDS solo;
	bool kill;
	for(size_t i=0;i<13-Num;i++)//当num=2时，i的值最多为k形成飞机(KKK,AAA）
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<3)//若小于两张
		   {
			   kill=false;
			   break;
		   }
		}
		if(kill)
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				solo.cards.push_back(j);	
				solo.cards.push_back(j);
			}
			solo.cardsType=THREEJUNKO;	
			solo.score=i;
			Mediating.push_back(solo);
			solo.cards.clear();//对容器进行清空，方便下一次记录
		}
	}
	if(Mediating .empty())//如果没有飞机。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetThreejunko_oneCards(Player P,size_t Num)    //飞机带单牌
{
	vector<CARDS> Mediating;//记录所有连对
	CARDS solo;
	bool kill,bill,mill;
	for(size_t i=0;i<13-Num;i++)//当num=2时，i的值最多为k形成飞机(KKK,AAA）
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<3)//若小于两张
		   {
			   kill=false;
			   break;
		   }
		}
		if(kill)//符合两个相邻起三条
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				solo.cards.push_back(j);	
				solo.cards.push_back(j);
			}
			for(size_t j=0;j<15;j++)//开始找飞机需要带的单牌两张
		    {	
		     	bill=true;
				for(size_t k=0;k<Num;k++)
				{
				   if(j==i+k)
				   {
					   bill=false;
				   }
				}
				if(bill)//符合不与飞机牌值相等单牌
				{
					if(P.EachCardNums[j]>0)
					{
						solo.cards.push_back(j);
						for(size_t t=j+1;t<15;t++)//开始找飞机需要带的另一张单牌
		                {
							mill=true;
			             	for(size_t k=0;k<Num;k++)
			            	{
				              if(t==i+k)
				              {
				           	   mill=false;
				              }
			             	}
			            	if(mill)//符合不与飞机牌值相等单牌
			            	{
			     		       if(P.EachCardNums[t]>0&&t!=j)
				             	{
									solo.cards.push_back(t);
					         	    solo.cardsType=THREEJUNKO_ONE;
					        	    solo.score=i;
			                        Mediating.push_back(solo);
					        	    solo.cards.pop_back();
							   }
							}
						}
					 solo.cards.pop_back();
					}
				}
			}	
			solo.cards.clear();//对容器进行清空，方便下一次记录
		}
	}
	if(Mediating .empty())//如果没有飞机带单。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetThreejunko_twoCards(Player P,size_t Num)    //飞机带对子
{
	vector<CARDS> Mediating;//记录所有连对
	CARDS solo;
	bool kill,bill,mill;
	for(size_t i=0;i<13-Num;i++)//当num=2时，i的值最多为k形成飞机(KKK,AAA）
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<3)//若小于两张
		   {
			   kill=false;
			   break;
		   }
		}
		if(kill)//符合两个相邻起三条
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				solo.cards.push_back(j);	
				solo.cards.push_back(j);
			}
			for(size_t j=0;j<15;j++)//开始找飞机需要带的单牌两张
		    {	
		     	bill=true;
				for(size_t k=0;k<Num;k++)
				{
				   if(j==i+k)
				   {
					   bill=false;
				   }
				}
				if(bill)//符合不与飞机牌值相等单牌
				{
					if(P.EachCardNums[j]>1)
					{
						solo.cards.push_back(j);
						solo.cards.push_back(j);
						for(size_t t=j+1;t<15;t++)//开始找飞机需要带的另一张单牌
		                {
							mill=true;
			             	for(size_t k=0;k<Num;k++)
			            	{
				              if(t==i+k)
				              {
				           	   mill=false;
				              }
			             	}
			            	if(mill)//符合不与飞机牌值相等单牌
			            	{
			     		       if(P.EachCardNums[t]>1&&t!=j)
				             	{
									solo.cards.push_back(t);
									solo.cards.push_back(t);
					         	    solo.cardsType=THREEJUNKO_TWO;
					        	    solo.score=i;
			                        Mediating.push_back(solo);
					        	    solo.cards.pop_back();
								    solo.cards.pop_back();
							   }
							}
						}
					 solo.cards.pop_back();
					 solo.cards.pop_back();
					}
				}
			}	
			solo.cards.clear();//对容器进行清空，方便下一次记录
		}
	}
	if(Mediating .empty())//如果没有飞机带单。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetFour_twoCards(Player P)               //四带二
{
	vector<CARDS> Mediating;//记录所有对牌
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]=4)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			for(size_t j=0;j<15;j++)
			{
				if(j!=j&&P.EachCardNums[j]>0)
				{
			        solo.cards.push_back(j);
					solo.cardsType=FOUR_TWO;
			        solo.score=i;
			        Mediating.push_back(solo);
					solo.cards.pop_back();
				}
			}
			solo.cards.clear();//对容器进行清空，方便下一次记录
		}
	}
	if(Mediating .empty())//如果没有四带二。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetFour_doubletwoCards(Player P)   //四带二对
{
	vector<CARDS> Mediating;//记录所有对牌
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]=4)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			for(size_t j=0;j<15;j++)
			{
				if(j!=j&&P.EachCardNums[j]>1)
				{
					solo.cards.push_back(j);
			        solo.cards.push_back(j);
					solo.cardsType=FOUR_TWO;
			        solo.score=i;
			        Mediating.push_back(solo);
					solo.cards.pop_back();
					solo.cards.pop_back();
				}
			}
			solo.cards.clear();//对容器进行清空，方便下一次记录
		}
	}
	if(Mediating .empty())//如果没有四带二对。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetZhadanCards(Player P)                   //炸弹
{
	vector<CARDS> Mediating;//记录所有对牌
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]==4)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cardsType=ZHADAN;
			solo.score=i+20;
			Mediating.push_back(solo);
		    solo.cards.clear();//对容器进行清空，方便下一次记录
		}
	}
	if(P.EachCardNums[13]==1&&P.EachCardNums[14]==1)
	{
		solo.cards.push_back(13);
	    solo.cards.push_back(14);
		solo.cardsType=ZHADAN;
		solo.score=100;
		Mediating.push_back(solo);
	}
	if(Mediating .empty())//如果没有炸弹。。
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
CARDS MoveGenerator::TakeMoves(Player P)
{
	movesearch movesearch;
	if(P.MeetCard.empty())           //如果将要面对的牌为空，说明该主动出牌   
	{
		chaipai Chaipai;		
		vector<CARDS> vec,vec1;
		CARDS cards;
		int N=-100;
		vec=Chaipai.GetCombination_1(P);//获取走步最少的牌型组合
		CARDS Mediating;
		CARDS card=movesearch.duiyi_1(P,Mediating,vec);
		if(!card.cards.empty())
		{
			return card;
		}
		/*if(vec.size()<10)
		{
			vec1=movesearch.search_1(P);
		    if(!vec1.empty())
		   {
			return vec1.at(0);
		   }
		}*/
		for(size_t i=0;i<vec.size();i++)
		{
			vector<CARDS> vec1=vec;
			CARDS card;
			card=vec1.at(i);
			vector<CARDS>::iterator it=vec1.begin()+i;
			vec1.erase(it);
			if(cardsvalue(vec1)>N)
			{
				cards=card;
				N=cardsvalue(vec1);
			}
		}
		return cards;		
	}
	else                            //被动出牌
	{
		chaipai Chaipai;
		bool OK=true;
		vector<unsigned> vec=transform.NumsTransform(P.MeetCard);
		CARDS Mediating=MoveGenerator::GetCardsDetail(vec);
		vector<CARDS> VEC1,vec1;
		CARDS VEC;
		VEC.cardsType=INVAILD;//如果无法接牌 就返回这个VEC
		VEC1=Chaipai.GetCombination_1(P);//获取走步最少的牌型组合
		CARDS card=movesearch.duiyi_1(P,Mediating,VEC1);
		if(!card.cards.empty())
		{
			return card;
		}
		if(Mediating.cardsType==SINGLE)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==SINGLE&&VEC1.at(i).score!=13&&VEC1.at(i).score!=14&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==COUPLE)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==COUPLE&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==SINGLEJUNKO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==SINGLEJUNKO&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==SANTIAO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==SANTIAO&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==THREE_ONE)
		{for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREE_ONE&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==THREE_TWO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREE_TWO&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==DOUBLEJUNKO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==DOUBLEJUNKO&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==THREEJUNKO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREEJUNKO&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==THREEJUNKO_ONE)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREEJUNKO_ONE&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==THREEJUNKO_TWO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREEJUNKO_TWO&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==FOUR_TWO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==FOUR_TWO&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		if(Mediating.cardsType==FOUR_TWO_COUPLE)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==FOUR_TWO_COUPLE&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//如果没有找到比上家出的牌大，说明就pass
		}
		/*if(VEC1.size()<10)
		{
			vec1=movesearch.search_1(P);
		    if(!vec1.empty())
		   {
			 for(size_t i=0;i<vec1.size();i++)
			 {
				 if(vec1.at(i).cardsType==Mediating.cardsType&&vec1.at(i).cards.size()==Mediating.cards .size()&&vec1.at(i).score>Mediating.score)
				 {
					 return vec1.at(i);
				 }
				 else if(vec1.at(i).cardsType==ZHADAN&&vec1.at(i).score>Mediating.score)
				 {
					return vec1.at(i);
				 }
			 }
		   }
		}*/
		return VEC;//如果没有找到比上家出的牌大，说明就pass
	}
	CARDS VEC;
    VEC.cardsType=INVAILD;//如果无法接牌 就返回这个VEC
    return VEC;
}
void MoveGenerator::paixu(vector<CARDS> &vec)
{
	    for(int i=2;i<=14;i++)
		{
			for(size_t j=0;j<vec.size();j++)
			{
					CARDS V;
				if(vec.at(j).cardsType==i)
				{
					for(size_t k=0;k<vec.size()-1;k++)
					{
						if(vec.at(k).score>vec.at(k+1).score)
						{
							V=vec.at(k);
							vec.at(k)=vec.at(k+1);
							vec.at(k+1)=V;
						}

					}
				}
			}
		}
}
int MoveGenerator::cardsvalue(vector<CARDS> vec)
{
	int sum=0;
	for(size_t i=0;i<vec.size();i++)
	{
		sum+=vec.at(i).score;
		for(size_t j=0;j<vec.size();j++)
	    {
			if(vec.at(j).cardsType==vec.at(i).cardsType&&vec.at(j).score>vec.at(i).score)
			{
				sum--;
			}
		}
		if(vec.at(i).cardsType==ZHADAN)
		{
			sum+=10+vec.at(i).score;
		}
	}
	return sum;
}