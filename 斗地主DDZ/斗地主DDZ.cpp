// 斗地主DDZ.cpp : 定义控制台应用程序的入口点。
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
	Player P;//定义一个玩家实体
	Player Ps,Px;//玩家的上家和下家
L1:
	cin.getline(cInMessage,200);
	for(size_t i=0;i<3;i++)
	{
		cShort[i]=cInMessage[i];
	}
	cShort[3]='\0';
// 收到平台命令：DOUDIZHUVER 1.0 回复：Name cqut		
	if(strcmp(cShort,"DOU")==0)                
	{
		cout<<"NAME MJ"<<endl;
	}
//收到平台命令：INFO 1,4,1,6,9,2100,1  回复：OK INFO
	else if(strcmp(cShort,"INF")==0)      
	{
		cout<<"OK INFO"<<endl;
	}
//收到平台命令：DEAL B0,4,5,7,9,10,17,21,25,	33,34,39,  41,43.... 
	else if(strcmp(cShort,"DEA")==0)        
	{
		player.GameOver(cInMessage,cOutMessage,P,Ps,Px);//用于测试，方面直接点下一局（初始化上一局的信息）
		player.CalDeal(cInMessage,cOutMessage,P, Ps, Px);
		cout<<cOutMessage<<endl;             //  回复：OK DEAL
	}
//收到平台命令：BID A3	/ BID WHAT	
	else if(strcmp(cShort,"BID")==0)      
	{
		player.CalBid(cInMessage,cOutMessage,P,Ps,Px);
		cout<<cOutMessage<<endl;              //回复：OK BID	   /  BID B3[(A/C)(1/2)]
	}
//收到平台命令：LEFTOVER B27,48,53					*/
	else if(strcmp(cShort,"LEF")==0)
	{
		player.CalLef(cInMessage,cOutMessage,P,Ps,Px);
		cout<<cOutMessage<<endl;
	}
//收到平台命令：PLAY A12，13，14，21 /  PLAY WHAT
	else if(strcmp(cShort,"PLA")==0)
	{
		player.CalPlay(cInMessage,cOutMessage,P,Ps,Px);
		cout<<cOutMessage<<endl;
	}
//收到平台命令：GAMEOVER C	
	else if(strcmp(cShort,"GAM")==0)
	{
		player.GameOver(cInMessage,cOutMessage,P,Ps,Px);
		cout<<"OK GAMEOVER"<<endl;
	}
//收到平台命令：ERROR A/B/C
	else if(strcmp(cShort,"ERR")==0)
	{
		cout<<"OK ERROR"<<endl;
	}
//继续接受命令
	                                           //CalOther		利用指令剩余空闲时间完成并行程序段

	goto L1;
	return 0;
}
