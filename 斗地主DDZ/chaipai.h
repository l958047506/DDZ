#pragma once
#include"MoveGenerator.h"
#include"time.h"
class chaipai//拆牌
{
public:
	chaipai(void);
	~chaipai(void);
//	vector<CARDS> GetSingleCard(Player &P,int &N);                         //获得单牌
//	vector<CARDS> GetCoupleCards(Player &P,int &N);                      //获得对子
//	vector<CARDS> GetSantiaoCards(Player &P,int &N);                     //三条
//	vector<CARDS> GetThree_oneCards(Player &P,int &N);                //三带一
//	vector<CARDS> GetThree_twoCards(Player &P,int &N);                //三带对
	vector<CARDS> GetSinglejunkoCards(Player P);            //顺子
	vector<CARDS> GetDoublejunkoCards(Player P);          //连对
	vector<CARDS> GetThreejunkoCards(Player P);             //飞机
	vector<CARDS> GetThreejunko_oneCards(Player P);    //飞机带单牌
	vector<CARDS> GetThreejunko_twoCards(Player P);    //飞机带对子
//	vector<CARDS> GetFour_twoCards(Player &P,int &N);               //四带二
//	vector<CARDS> GetFour_doubletwoCards(Player &P,int &N);   //四带二对
//	vector<CARDS> GetZhadanCards(Player &P,int &N);                   //炸弹
	vector<CARDS> GetCombination(Player P);//获取最少走步的牌型组合
	vector<CARDS> GetCombination_1(Player P);//获取最少走步的牌型组合
	void gencing(Player &P,CARDS vec);//跟新牌
	void huifu(Player &P,CARDS vec);//恢复牌
	vector<CARDS> fib(Player &P);
	Transform transform;
	
};

