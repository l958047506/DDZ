#pragma once
#include"vector"

using namespace std;
class Player
{
public:
	Player(void)//初始化变量
	{	
		 Bid=0;
		CardsNums=0;
		 IsLandlord=false;
		 for(size_t i=0;i<15;i++)
		 {
		  EachCardNums[i]=0; 
		 }
	};
	~Player(void);
	char Place;                               //玩家的位置（A/B/C）
	int Bid;                                  //玩家所叫的分
	int CardsNums;                           //手中牌的数量
	bool IsLandlord;                        //是否为地主
	vector<unsigned> NumsCard;              //手中牌的信息（0~53）
	vector<unsigned> HandsCard;             //手中的牌的信息（1~14）
	void  GetEachCardNums();                //获取每张牌的数量
	unsigned EachCardNums[15];              //每张牌的数量
	vector<unsigned> PassedCard;           //已出的牌
	vector<unsigned> MeetCard;             //所需要接的牌（比如上家出的牌）
	static vector<unsigned> RestCard;      //其他两位玩家手中剩余的牌
	void GetRestCard(vector<unsigned> &RestCard,vector<unsigned> Crads);//获取剩余牌(1~14)

};

