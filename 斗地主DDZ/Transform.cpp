#include "stdafx.h"
#include "Transform.h"


Transform::Transform(void)
{
}


Transform::~Transform(void)
{
}
int Transform::getInt(string strText)
{
	int n=0;
	stringstream os;
	os<<strText;
	os>>n;

	return n;
}

string Transform::getString(int n)
{
	string s;
	stringstream os;
	os<<n;
	os>>s;

	return s;
}
//从裁判指令中获取牌的信息（0~54）
vector<unsigned> Transform::StringTransform(string NumsCards)
{
	vector<unsigned> Mediating;
	string tmp_str="";
	istringstream istr(NumsCards);
	while(! istr.eof())
	{
		getline(istr,tmp_str,',');
		Mediating.push_back(getInt(tmp_str));
	}
	return Mediating;
}
//将裁判指令转换成（0~15）。
vector<unsigned> Transform::NumsTransform(vector<unsigned> cInMa)
{
	vector<unsigned> Mediating;
	for(size_t i=0;i<cInMa.size();i++)
	{
		if(cInMa[i]<53)
		{
			Mediating.push_back((cInMa[i])/4);
		}
		else
		{
			Mediating.push_back(14);
		}
	}
	return Mediating;
}
//将出牌指令转换为裁判指令（0~15）转换为（0~53）
vector<unsigned> Transform:: _NumsTransform(vector<unsigned> NumsCard,Player P)
{
	vector<unsigned> vec;
	bool solo;
	for(size_t i=0;i<NumsCard.size();i++)
	{
		if(NumsCard.at(i)==14)
		{
			vec.push_back(53);
		}
		else if(NumsCard.at(i)==13)
		{
			vec.push_back(52);
		}
		else
		{
			for(size_t j=0;j<P.NumsCard.size();j++)
			{
				solo=true;
				if(NumsCard.at(i)==P.NumsCard.at(j)/4)
					{
						for(size_t k=0;k<vec.size();k++)
						{
							if(P.NumsCard.at(j)==vec.at(k))//如果上次取到过这个值，则不再重复转换
								{
									solo=false;
									break;
								}
						}
						if(solo)//如果没有取过该值
						{
							 vec.push_back(P.NumsCard.at(j));
							 break;
						}
					}
			}
		}
	}
	return vec;
}
// /将出牌转换为裁判指令（PLAY B31，32，33，0	)	
string Transform::_StringTransform(vector<unsigned> cards,Player P)//牌的为（0~53）
{
	//vector<unsigned> vec=Transform::_NumsTransform(cards,P);//先将牌的序号转换为0~53
	string str="";
	str+="PLAY ";
	str+=P.Place;
	for(size_t i=0;i<cards.size();i++)
	{
	    if(i==0)
		{
		str+=getString(cards.at(i));
		}
		else
		{
		str+=(","+getString(cards.at(i)));
		}
	}
	return str;
}