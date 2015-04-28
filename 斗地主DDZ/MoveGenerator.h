#pragma once
#include"DDplayer.h"
#include"Define.h"
#include"Transform.h"
#include"chaipai.h"
#include"algorithm"//调用STL算法sort对容器内的元素排序
#include"movesearch.h"
class MoveGenerator:public Player//方便调用Player里面的方法
{
public:
	MoveGenerator(void);
	~MoveGenerator(void);
	vector<CARDS> GetSingleCard(Player P);                         //获得单牌
	vector<CARDS> GetCoupleCards(Player P);                      //获得对子
	vector<CARDS> GetSantiaoCards(Player P);                     //三条
	vector<CARDS> GetThree_oneCards(Player P);                //三带一
	vector<CARDS> GetThree_twoCards(Player P);                //三带对
	vector<CARDS> GetSinglejunkoCards(Player P,size_t Num);            //顺子
	vector<CARDS> GetDoublejunkoCards(Player P,size_t Num);          //连对
	vector<CARDS> GetThreejunkoCards(Player P,size_t Num);             //飞机
	vector<CARDS> GetThreejunko_oneCards(Player P,size_t Num);    //飞机带单牌
	vector<CARDS> GetThreejunko_twoCards(Player P,size_t Num);    //飞机带对子
	vector<CARDS> GetFour_twoCards(Player P);               //四带二
	vector<CARDS> GetFour_doubletwoCards(Player P);   //四带二对
	vector<CARDS> GetZhadanCards(Player P);                   //炸弹
	CARDS GetCardsDetail(vector<unsigned> cards);//获取套牌的类型.大小（JJJ.3 类型为6 大小为11）
	CARDS TakeMoves(Player P);//获取最基本的走步；  
	void paixu(vector<CARDS> &vec);//对已经组合好的牌 按从大到小排好序
	int cardsvalue(vector<CARDS> vec);
	Transform transform;
};

