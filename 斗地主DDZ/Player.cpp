#include "stdafx.h"
#include "Player.h"



Player::~Player(void)
{
}
 vector<unsigned> Player::RestCard;//������λ�������ʣ�����
 void Player:: GetEachCardNums()//��ȡÿ���Ƶĸ���
 {
	 memset(Player::EachCardNums,0,sizeof(int)*15);//ÿ�θ���ʱ���ֽ�ÿ�ŵ���������
	 for(size_t i=0;i<Player::NumsCard.size();i++)
	 {
		 for(size_t j=0;j<15;j++)
		 {
			 if(Player::NumsCard.at(i)<53)
			 {
				 if(Player::NumsCard.at(i)/4==j)
				 {
					 Player::EachCardNums[j]++;
				 }
			 }
			 else
			 {
				 Player::EachCardNums[14]=1;
			 }
		 }
	 }
 }
 void Player::GetRestCard(vector<unsigned> &RestCard,vector<unsigned> Cards)//��cards��(0~53)�������ҳ��ֹ�����
 {
	vector<unsigned>::iterator it=RestCard.begin();
	 for(size_t i=0;i<Cards.size();i++) 
	 {
		 for(size_t j=0;j<RestCard.size();j++)
		 {
			 if(Cards[i]==RestCard[j])
			 {
				 RestCard.erase(it+j);
				 it=RestCard.begin();
				 break;
			 }
		 } 
	 }
 }