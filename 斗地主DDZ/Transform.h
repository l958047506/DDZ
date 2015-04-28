#pragma once
#include"string"
#include"vector"
#include"sstream"
#include"Player.h"
using namespace std;
class Transform
{
public:
	Transform(void);
	~Transform(void);
	int getInt(string s);//将字符串中的字符转换为int
	string getString(int n);//将整型转换为string
    vector<unsigned> StringTransform(string cInMassage);//从裁判指令中获取牌的信息（0~54）
	vector<unsigned> NumsTransform(vector<unsigned> NumsCards);//将裁判指令转换成（3~15）。
	vector<unsigned> _NumsTransform(vector<unsigned> NumsCard,Player P);//将（0~14）转换为0~54）
	string _StringTransform(vector<unsigned> cards,Player P);//将出牌转换为裁判指令（PLAY B31，32，33，0	)	

};

