// ������DDZ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"iostream"
#include"string"
#include"DDplayer.h"

using namespace std;
int main()
{
	char cInMessage[200]={};
	char cOutMessage[200]={};
	char cShort[4];
	DDplayer player;
	Player P;//����һ�����ʵ��
	Player Ps,Px;//��ҵ��ϼҺ��¼�
L1:
	cin.getline(cInMessage,200);
	for(size_t i=0;i<3;i++)
	{
		cShort[i]=cInMessage[i];
	}
	cShort[3]='\0';
// �յ�ƽ̨���DOUDIZHUVER 1.0 �ظ���Name cqut		
	if(strcmp(cShort,"DOU")==0)                
	{
		cout<<"NAME MJ"<<endl;
	}
//�յ�ƽ̨���INFO 1,4,1,6,9,2100,1  �ظ���OK INFO
	else if(strcmp(cShort,"INF")==0)      
	{
		cout<<"OK INFO"<<endl;
	}
//�յ�ƽ̨���DEAL B0,4,5,7,9,10,17,21,25,	33,34,39,  41,43.... 
	else if(strcmp(cShort,"DEA")==0)        
	{
		player.GameOver(cInMessage,cOutMessage,P,Ps,Px);//���ڲ��ԣ�����ֱ�ӵ���һ�֣���ʼ����һ�ֵ���Ϣ��
		player.CalDeal(cInMessage,cOutMessage,P, Ps, Px);
		cout<<cOutMessage<<endl;             //  �ظ���OK DEAL
	}
//�յ�ƽ̨���BID A3	/ BID WHAT	
	else if(strcmp(cShort,"BID")==0)      
	{
		player.CalBid(cInMessage,cOutMessage,P,Ps,Px);
		cout<<cOutMessage<<endl;              //�ظ���OK BID	   /  BID B3[(A/C)(1/2)]
	}
//�յ�ƽ̨���LEFTOVER B27,48,53					*/
	else if(strcmp(cShort,"LEF")==0)
	{
		player.CalLef(cInMessage,cOutMessage,P,Ps,Px);
		cout<<cOutMessage<<endl;
	}
//�յ�ƽ̨���PLAY A12��13��14��21 /  PLAY WHAT
	else if(strcmp(cShort,"PLA")==0)
	{
		player.CalPlay(cInMessage,cOutMessage,P,Ps,Px);
		cout<<cOutMessage<<endl;
	}
//�յ�ƽ̨���GAMEOVER C	
	else if(strcmp(cShort,"GAM")==0)
	{
		player.GameOver(cInMessage,cOutMessage,P,Ps,Px);
		cout<<"OK GAMEOVER"<<endl;
	}
//�յ�ƽ̨���ERROR A/B/C
	else if(strcmp(cShort,"ERR")==0)
	{
		cout<<"OK ERROR"<<endl;
	}
//������������
	                                           //CalOther		����ָ��ʣ�����ʱ����ɲ��г����

	goto L1;
	return 0;
}
