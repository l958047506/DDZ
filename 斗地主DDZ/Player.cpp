#include "stdafx.h"
#include "Player.h"



Player::~Player(void)
{
}
 vector<unsigned> Player::RestCard;//其他两位玩家手中剩余的牌
 void Player:: GetEachCardNums()//获取每张牌的个数
 {
	 memset(Player::EachCardNums,0,sizeof(int)*15);//每次更新时，现将每张的张数清零
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
 void Player::GetRestCard(vector<unsigned> &RestCard,vector<unsigned> Cards)//“cards”(0~53)其他两家出现过的牌
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