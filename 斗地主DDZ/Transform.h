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
	int getInt(string s);//���ַ����е��ַ�ת��Ϊint
	string getString(int n);//������ת��Ϊstring
    vector<unsigned> StringTransform(string cInMassage);//�Ӳ���ָ���л�ȡ�Ƶ���Ϣ��0~54��
	vector<unsigned> NumsTransform(vector<unsigned> NumsCards);//������ָ��ת���ɣ�3~15����
	vector<unsigned> _NumsTransform(vector<unsigned> NumsCard,Player P);//����0~14��ת��Ϊ0~54��
	string _StringTransform(vector<unsigned> cards,Player P);//������ת��Ϊ����ָ�PLAY B31��32��33��0	)	

};

