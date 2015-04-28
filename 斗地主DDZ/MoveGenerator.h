#pragma once
#include"DDplayer.h"
#include"Define.h"
#include"Transform.h"
#include"chaipai.h"
#include"algorithm"//����STL�㷨sort�������ڵ�Ԫ������
#include"movesearch.h"
class MoveGenerator:public Player//�������Player����ķ���
{
public:
	MoveGenerator(void);
	~MoveGenerator(void);
	vector<CARDS> GetSingleCard(Player P);                         //��õ���
	vector<CARDS> GetCoupleCards(Player P);                      //��ö���
	vector<CARDS> GetSantiaoCards(Player P);                     //����
	vector<CARDS> GetThree_oneCards(Player P);                //����һ
	vector<CARDS> GetThree_twoCards(Player P);                //������
	vector<CARDS> GetSinglejunkoCards(Player P,size_t Num);            //˳��
	vector<CARDS> GetDoublejunkoCards(Player P,size_t Num);          //����
	vector<CARDS> GetThreejunkoCards(Player P,size_t Num);             //�ɻ�
	vector<CARDS> GetThreejunko_oneCards(Player P,size_t Num);    //�ɻ�������
	vector<CARDS> GetThreejunko_twoCards(Player P,size_t Num);    //�ɻ�������
	vector<CARDS> GetFour_twoCards(Player P);               //�Ĵ���
	vector<CARDS> GetFour_doubletwoCards(Player P);   //�Ĵ�����
	vector<CARDS> GetZhadanCards(Player P);                   //ը��
	CARDS GetCardsDetail(vector<unsigned> cards);//��ȡ���Ƶ�����.��С��JJJ.3 ����Ϊ6 ��СΪ11��
	CARDS TakeMoves(Player P);//��ȡ��������߲���  
	void paixu(vector<CARDS> &vec);//���Ѿ���Ϻõ��� ���Ӵ�С�ź���
	int cardsvalue(vector<CARDS> vec);
	Transform transform;
};

