#pragma once
#include"vector"

using namespace std;
class Player
{
public:
	Player(void)//��ʼ������
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
	char Place;                               //��ҵ�λ�ã�A/B/C��
	int Bid;                                  //������еķ�
	int CardsNums;                           //�����Ƶ�����
	bool IsLandlord;                        //�Ƿ�Ϊ����
	vector<unsigned> NumsCard;              //�����Ƶ���Ϣ��0~53��
	vector<unsigned> HandsCard;             //���е��Ƶ���Ϣ��1~14��
	void  GetEachCardNums();                //��ȡÿ���Ƶ�����
	unsigned EachCardNums[15];              //ÿ���Ƶ�����
	vector<unsigned> PassedCard;           //�ѳ�����
	vector<unsigned> MeetCard;             //����Ҫ�ӵ��ƣ������ϼҳ����ƣ�
	static vector<unsigned> RestCard;      //������λ�������ʣ�����
	void GetRestCard(vector<unsigned> &RestCard,vector<unsigned> Crads);//��ȡʣ����(1~14)

};

