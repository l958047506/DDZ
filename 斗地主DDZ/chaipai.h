#pragma once
#include"MoveGenerator.h"
#include"time.h"
class chaipai//����
{
public:
	chaipai(void);
	~chaipai(void);
//	vector<CARDS> GetSingleCard(Player &P,int &N);                         //��õ���
//	vector<CARDS> GetCoupleCards(Player &P,int &N);                      //��ö���
//	vector<CARDS> GetSantiaoCards(Player &P,int &N);                     //����
//	vector<CARDS> GetThree_oneCards(Player &P,int &N);                //����һ
//	vector<CARDS> GetThree_twoCards(Player &P,int &N);                //������
	vector<CARDS> GetSinglejunkoCards(Player P);            //˳��
	vector<CARDS> GetDoublejunkoCards(Player P);          //����
	vector<CARDS> GetThreejunkoCards(Player P);             //�ɻ�
	vector<CARDS> GetThreejunko_oneCards(Player P);    //�ɻ�������
	vector<CARDS> GetThreejunko_twoCards(Player P);    //�ɻ�������
//	vector<CARDS> GetFour_twoCards(Player &P,int &N);               //�Ĵ���
//	vector<CARDS> GetFour_doubletwoCards(Player &P,int &N);   //�Ĵ�����
//	vector<CARDS> GetZhadanCards(Player &P,int &N);                   //ը��
	vector<CARDS> GetCombination(Player P);//��ȡ�����߲����������
	vector<CARDS> GetCombination_1(Player P);//��ȡ�����߲����������
	void gencing(Player &P,CARDS vec);//������
	void huifu(Player &P,CARDS vec);//�ָ���
	vector<CARDS> fib(Player &P);
	Transform transform;
	
};

