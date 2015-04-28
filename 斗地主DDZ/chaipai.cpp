#include "stdafx.h"
#include "chaipai.h"


chaipai::chaipai(void)
{
}


chaipai::~chaipai(void)
{
}

vector<CARDS> chaipai::GetSinglejunkoCards(Player P)           //˳��
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
	for(size_t i=5;i<11;i++)
	{
		vec1=move->GetSinglejunkoCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetDoublejunkoCards(Player P)          //����
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
		for(size_t i=3;i<=8;i++)
	{
		vec1=move->GetDoublejunkoCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetThreejunkoCards(Player P)             //�ɻ�
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
		for(size_t i=2;i<=4;i++)
	{
		vec1=move->GetThreejunkoCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetThreejunko_oneCards(Player P)    //�ɻ�������
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
	for(size_t i=2;i<=4;i++)
	{
		vec1=move->GetThreejunko_oneCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetThreejunko_twoCards(Player P)    //�ɻ�������
{
	vector<CARDS> vec,vec1;
	MoveGenerator *move=new MoveGenerator();
		for(size_t i=2;i<=3;i++)
	{
		vec1=move->GetThreejunko_twoCards(P,i);
		if(vec1.at(0).cardsType==INVAILD)
		{
			if(vec.empty())
			vec.push_back(vec1.at(0));
			break;
		}
		for(size_t j=0;j<vec1.size();j++)
		{
			vec.push_back(vec1.at(j));
		}
	}
		delete(move);
		return vec;
}
vector<CARDS> chaipai::GetCombination(Player P)//��ȡ�����߲����������
{
	int N=0;//��¼���ٳ����ٴ��ܰ����е��Ƴ��ƣ�
	if(P.CardsNums==0)
	{
		vector<CARDS> VEC; 
		return VEC;//����һ���յ�
	}
	else
	{
		vector<CARDS> vec,VEC,VEC1;	//vec������ȡһ�����͵������߲���VEC��Ϊ���ء�VEC1���ɡ�
		CARDS vec1;//��ȡһ�����͵�һ���߲�
		int min=20,n=0,value=0;//min��¼��С�߲�,n�������ĳ����ϵ�Ȩֵ��
		size_t k=0;//���ڱ�����һ�����������߲�
		MoveGenerator *move=new MoveGenerator();
		vector<unsigned> me=transform.NumsTransform(P.MeetCard);
		CARDS Mediating=move->GetCardsDetail(me);
		for(size_t i=1;i<=11;i++)
		{
			switch (i)
			{
			case 1:vec=move->GetZhadanCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}//���û�и����ͣ��Ͳ�ִ�и�case��䣬ֱ��������һ��case��
				else
				{
						vec1=vec.at(k);//��ȡһ���������¼��
						k++;
						i--;//ʹ���´α�����switch����ǣ�����ִ�и�case���������ͻ�û��ȡ���ʱ��
						n-=2;//��ը����Ȩֵ���
						if(k==vec.size())//������Ǹ����͵����һ����ϣ��´�switchʱ�Ͳ���Ҫִ�и�case������i++����ʼ��k��ֵ��
						{k=0;i++;}
						break;
					}
			case 2:vec=chaipai::GetThreejunko_oneCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREEJUNKO_ONE)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 3:vec=chaipai::GetThreejunko_twoCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREEJUNKO_TWO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 4:vec=chaipai::GetThreejunkoCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREEJUNKO)
					{n-=2;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 5:vec=chaipai::GetDoublejunkoCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==DOUBLEJUNKO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 6:vec=chaipai::GetSinglejunkoCards(P);
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==SINGLEJUNKO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 7:vec=move->GetThree_twoCards(P) ;
				vec.at(0).cardsType=INVAILD;
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREE_TWO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 8:vec=move->GetThree_oneCards(P) ;
				vec.at(0).cardsType=INVAILD;
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==THREE_ONE)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 9:vec=move->GetSantiaoCards(P) ;
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					if(Mediating.cardsType==SANTIAO)
					{n--;}
						vec1=vec.at(k);
						k++;
						i--;
						if(k==vec.size())
						{k=0;i++;}
						break;
					}
			case 10:vec=move->GetCoupleCards(P);//Ϊ������ٶȣ������Ӻ͵��ƣ�����һ������
				if(vec.at(0).cardsType==INVAILD)
				{i++;}
				else
				{
					VEC1=vec;
					N+=vec.size();	
					for(size_t l=0;l<vec.size();l++)
					{
						gencing(P,vec.at(l));//��ԭ�ϴζ�eachcardsnum�ĸ���
					}
					if(P.CardsNums==0)//���ȡ�����ܽ�ʣ�����ȡ�꣬��û�б�Ҫ��ȥȡ���ƣ����Ծ�ֱ�ӷ� �أ�����ȡ����
					{
						for(size_t l=0;l<vec.size();l++)
						{
						huifu(P,vec.at(l));//��ԭ�ϴζ�eachcardsnum�ĸ���
						}
						delete(move);
						if(N<min)
						{
						return VEC1;
						}
						else
						{
							return VEC;
						}
					}
				}
			case 11:vec=move->GetSingleCard(P);
				if(vec.empty())
				{break;}
				else
				{
					for(size_t l=0;l<vec.size();l++)
					{
					vec1=vec.at(l);
					VEC1.push_back(vec1);
					gencing(P,vec1);
					}
					N+=vec.size();	
					delete(move);
					for(size_t l=0;l<vec.size();l++)
					{
						huifu(P,VEC1.at(l));//��ԭ�ϴζ�eachcardsnum�ĸ���
					}
					if(N<min)
					{
						return VEC1;
					}
					else
					{
					    return VEC;
					}
				}
			default:
				break;
			}//switch
    		gencing(P,vec1);//����ʣ��ÿ���Ƶ�����
			VEC1=chaipai::GetCombination(P);//�ٴε���
			N=n+VEC1.size();//�߲���
			if(N==min)
			{
				if(move->cardsvalue(VEC1)>value)
				{
					VEC=VEC1;
				    VEC.push_back(vec1);
				    value=move->cardsvalue(VEC1);
				}
			}
			if(N<min)
			{
				min=N;
				VEC=VEC1;
				VEC.push_back(vec1);
				value=move->cardsvalue(VEC1);
			}
			n=0;
			N=0;
			huifu(P,vec1);//��ԭ�ϴζ�eachcardsnum�ĸ���
		 }//for
	 }//else
	 vector<CARDS> VEC; 
	 return VEC;//����һ���յ�
}
vector<CARDS> chaipai::GetCombination_1(Player P)
{
	vector<CARDS> vec=chaipai::GetCombination(P);
	MoveGenerator *move=new MoveGenerator();
	vector<unsigned> me=transform.NumsTransform(P.MeetCard);
	CARDS Mediating=move->GetCardsDetail(me);
	vector<CARDS>::iterator it=vec.begin();
	CARDS cards;
	int value=-10,k,N1=0,N2=0;//valueʣ���ƵĹ�ֵ��K��¼�����Ƶ�λ�ã�N1��¼���Ƶĸ�����N2���ӵĸ���
	for(size_t i=0;i<vec.size();i++)
	{
		if(vec.at(i).cardsType==SANTIAO)
		{
			if(vec.at(i).score==12)//�������Ϊ����2��������������Ƿ��б�Ҫ����2 ��
			{
				CARDS cards;
				cards.cards.push_back(12);
				cards.cards.push_back(12);
				cards.cardsType=COUPLE;
				cards.score=12;
				vec.push_back(cards);
				cards.cards.pop_back();
				cards.cardsType=SINGLE;
				cards.score=12;
				vec.push_back(cards);
				vector<CARDS>::iterator it=vec.begin();
				vec.erase(it+i);
			}
			else
			{
			for(size_t j=0;j<vec.size();j++)
	        {
				vector<CARDS>	VEC=vec;
				int v=0;
				if(vec.at(j).cardsType==SINGLE||vec.at(j).cardsType==COUPLE)
				{
					if(Mediating.cardsType==THREE_ONE)
					{
						if(VEC.at(j).cardsType==COUPLE)
						{
							CARDS c;
						   c.cards.push_back(j);
						   c.cardsType=SINGLE;
						   c.score=VEC.at(j).score;
						   VEC.push_back(c);
						}
					}
					else if(Mediating.cardsType==THREE_TWO)
					{
						if(VEC.at(j).cardsType==COUPLE)
						{
					     v+=5;
						}
					}
					vector<CARDS>::iterator it1=VEC.begin();
					VEC.erase(it1+j);
					v+=move->cardsvalue(VEC);
					if(v>value)
					{
						cards=vec.at(j);
						k=j;
						value=v;
					}				 	
				}
			}			
			if(cards.cardsType==SINGLE)
			{
			vec.at(i).cards.push_back(cards.cards.at(0));	
			vec.at(i).cardsType=THREE_ONE;
			}
			else if(cards.cardsType==COUPLE)
			{
				vec.at(i).cards.push_back(cards.cards.at(0));	
				vec.at(i).cards.push_back(cards.cards.at(0));	
				vec.at(i).cardsType=THREE_TWO;
            }
			else
			{
				continue;
			}
			vec.erase(it+k);
			if(k<(int)i)
			i--;
		}
		}//����һ
		if(vec.at(i).cardsType==SINGLE)
		{
		    N1++;
		}
		if(vec.at(i).cardsType==COUPLE)
		{
		    N2++;
		}
	}
	for(size_t i=0;i<vec.size();i++)
	{
		if(vec.at(i).cardsType==COUPLE&&vec.at(i).score==12)
		{
			if(N1>N2+1)//��������������ڶ��� �Ͱ�һ��2��ɵ���
		   {
			CARDS c;
			c.cards.push_back(vec.at(i).cards.at(0));
			c.cardsType=SINGLE;
			c.score=vec.at(i).score;
			vec.push_back(c);
			vec.push_back(c);
			vector<CARDS>::iterator it=vec.begin();
			vec.erase(it+i);
			break;
		    }
		}
	}
	return vec;
}
void chaipai::gencing(Player &P,CARDS vec)//����ʣ�µ���
{
	//�����ڻ�ȡը��������....��ʱ��û���õ� NumsCards��HandsCards  Ϊ���ٹ�������������в�����
	//P.GetRestCard(P.NumsCard,transform._NumsTransform(vec.cards,P));//���������ʣ����Ƹ���(0~53)
	//P.HandsCard=transform.NumsTransform(P.NumsCard);//����������Ƹ��£�0~14��	
	//P.GetEachCardNums();//����ÿ���Ƶ�����
	for(size_t i=0;i<vec.cards.size();i++)
	{
		for(size_t j=0;j<15;j++)
		{
			if(vec.cards.at(i)==j)
			{
			P.EachCardNums[j]--;
			break;
			}
		}
	}
	P.CardsNums-=vec.cards.size();//������������
}
void chaipai::huifu(Player &P,CARDS vec)//�ָ���һ�����µ���
{
	for(size_t i=0;i<vec.cards.size();i++)
	{
		for(size_t j=0;j<15;j++)
		{
			if(vec.cards.at(i)==j)
			{
			P.EachCardNums[j]++;
			break;
			}
		}
	}
	P.CardsNums+=vec.cards.size();//������������
}