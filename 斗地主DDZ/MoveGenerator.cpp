#include "stdafx.h"
#include "MoveGenerator.h"


MoveGenerator::MoveGenerator(void)
{
}


MoveGenerator::~MoveGenerator(void)
{
}
CARDS MoveGenerator::GetCardsDetail(vector<unsigned> cards)//�ԣ�0~14�����ƽ�������,���أ�0~14��
{
	CARDS Mediating;
	int size=cards.size();//���Ƶ�����
	sort(cards.begin(),cards.end());//�������򣩡� sort STL�㷨
	for(size_t i=0;i<cards.size();i++)
		{
          	Mediating.cards.push_back(cards.at(i));
		}
	switch(size)
	{
	case 1://����
		Mediating.cardsType=SINGLE;
		Mediating.score=cards.at(0);
		return Mediating;
	case 2://���ӣ����
        if((cards.at(0)==13&&cards.at(1)==14)||(cards.at(0)==14&&cards.at(1)==13))//����Ǵ�С��
		{
			Mediating.cardsType=ZHADAN;
			Mediating.score=100;//�������������һ�����ֵ100
		}
		else
		{
		    Mediating.cardsType=COUPLE;
		    Mediating.score=cards.at(0);
		}
		return Mediating;
	case 3://����
		Mediating.cardsType=SANTIAO;
		Mediating.score=cards.at(0);
		return Mediating;
	case 4://����һ��ը��
		if(cards.at(0)==cards.at(1)&&cards.at(0)==cards.at(2)&&cards.at(0)==cards.at(3))
		{
			Mediating.cardsType=ZHADAN;
			Mediating.score=cards.at(0)+20;
		}
		else
		{
			Mediating.cardsType=THREE_ONE;
			for(size_t i=0;i<cards.size()-1;i++)
			{
				if(cards.at(i)==cards.at(i+1))//���������������ȵģ�������ƴ�С���Ǹ�ֵ
				{
					Mediating.score=cards.at(i);
					break;
				}

			}    
		}
		return Mediating;
	case 5://5���ӣ�������
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score=cards.at(0);
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))//����������ȵ�
			{
				Mediating.cardsType=THREE_TWO ;//���������ͺʹ�С
				Mediating.score=cards.at(i);
				break;
			}
		}
		return Mediating;

	case 6://6���ӣ��Ĵ�������3���ӣ��ɻ�
		for(size_t i=0;i<cards.size()-3;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2)&&cards.at(i)==cards.at(i+3))
			{
				Mediating.cardsType =FOUR_TWO ;
				Mediating.score=cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-1;i++)
		{
			if(cards.at(i)==cards.at(i+1))
			{
				Mediating.cardsType=DOUBLEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 7://7����
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 8://8���ӣ�4���ӣ��ɻ����������Ĵ�����
		for(size_t i=0;i<cards.size()-3;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2)&&cards.at(i)==cards.at(i+3))
			{
				Mediating.cardsType =FOUR_TWO ;
				Mediating.score=cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_ONE;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-1;i++)
		{
			if(cards.at(i)==cards.at(i+1))
			{
				Mediating.cardsType=DOUBLEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 9://9���ӣ��ɻ�
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 10://10���ӣ�5���ԣ��ɻ�������
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_TWO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size()-1;i++)
		{
			if(cards.at(i)==cards.at(i+1))
			{
				Mediating.cardsType=DOUBLEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 11://11����
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 12://12���ӣ�6���ԣ�3�ɻ���������4�ɻ�(͵����������4�ɻ��Ŀ��ܷǳ�С�����ķɻ������Ƶļ��ʸ�С�����Ժ���4�ɻ�)
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_ONE;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		for(size_t i=0;i<cards.size();i++)
		{
			if(cards.at(i)==cards.at(i+1))
			{
				Mediating.cardsType=DOUBLEJUNKO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=SINGLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 14://7����
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 15://5�ɻ���3�ɻ�������
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_TWO;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
    case 16://8���ԣ�4�ɻ�����
		for(size_t i=0;i<cards.size()-2;i++)
		{
			if(cards.at(i)==cards.at(i+1)&&cards.at(i)==cards.at(i+2))
			{
				Mediating.cardsType=THREEJUNKO_ONE;
				Mediating.score =cards.at(i);
				return Mediating;
			}
		}
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 18://9����
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	case 20://10����
		Mediating.cardsType=DOUBLEJUNKO;
		Mediating.score =cards.at(0);
		return Mediating;
	default:
			break;
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetSingleCard(Player P)    //���أ�0~14��                   //��õ���
{
	vector<CARDS> Mediating;//��¼���е���
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=1)
		{
			for(size_t j=0;j<P.EachCardNums[i];j++)
			{
			solo.cards.push_back(i);
			solo.cardsType=SINGLE;
			solo.score=i;
		    Mediating.push_back(solo);
		    solo.cards.clear();//������������գ�������һ�μ�¼��
			}
		}
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetCoupleCards(Player P)                  //��ö���
{
	vector<CARDS> Mediating;//��¼���ж���
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=2)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cardsType=COUPLE;
			solo.score=i;
			Mediating.push_back(solo);
		    solo.cards.clear();//������������գ�������һ�μ�¼
		}
		
	}
	if(Mediating.empty())//���û�ж��ӡ���
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetSantiaoCards(Player P)                     //����
{
	vector<CARDS> Mediating;//��¼��������
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=3)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cardsType=SANTIAO;
			solo.score=i;
			Mediating.push_back(solo);
		    solo.cards.clear();//������������գ�������һ�μ�¼
		}
	}
	if(Mediating .empty())//���û����������
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetThree_oneCards(Player P)                //����һ
{
	vector<CARDS> Mediating;//��¼��������һ
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=3)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			for(size_t j=0;j<15;j++)
			{
				if(P.EachCardNums[j]>=1&&j!=i)
				{
					solo.cards.push_back(j);
					solo.cardsType=THREE_ONE;
			        solo.score=i;
			        Mediating.push_back(solo);
					solo.cards.pop_back();
				}
			}
			solo.cards.clear();//������������գ�������һ�μ�¼
		}	
	}
	if(Mediating .empty())//���û������һ����
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;

}
vector<CARDS> MoveGenerator::GetThree_twoCards(Player P)                //������
{
	vector<CARDS> Mediating;//��¼���ж���
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]>=3)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			for(size_t j=0;j<15;j++)
			{
				if(P.EachCardNums[j]>=2&&j!=i)
				{
					solo.cards.push_back(j);
					solo.cards.push_back(j);
					solo.cardsType=THREE_TWO;
			        solo.score=i;
			        Mediating.push_back(solo);
					solo.cards.pop_back();
					solo.cards.pop_back();
				}
			}
			solo.cards.clear();//������������գ�������һ�μ�¼
		}	
	}
	if(Mediating .empty())//���û�������ԡ���
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetSinglejunkoCards(Player P,size_t Num)            //˳��
{
	vector<CARDS> Mediating;//��¼����˳��
	CARDS solo;
	bool kill;
	for(size_t i=0;i<13-Num;i++)//��num=5ʱ��i��ֵ���Ϊ10�γ����ӣ�10,J,Q,K,A��
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<1)
		   {
			   kill=false;
		   }
		}
		if(kill)
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				
				
			}
			solo.cardsType=SINGLEJUNKO;
			solo.score=i;
			Mediating.push_back(solo);
			solo.cards.clear();//������������գ�������һ�μ�¼
		}
	}
	if(Mediating .empty())//���û�����ӡ���
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetDoublejunkoCards(Player P,size_t Num)          //����
{
	vector<CARDS> Mediating;//��¼��������
	CARDS solo;
	bool kill;
	for(size_t i=0;i<13-Num;i++)//��num=3ʱ��i��ֵ���ΪQ�γ����ԣ�QQ,KK,AA��
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<2)//��С������
		   {
			   kill=false;
			   break;
		   }
		}
		if(kill)
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				solo.cards.push_back(j);	
			}
			solo.cardsType=DOUBLEJUNKO;	
			solo.score=i;
			Mediating.push_back(solo);
			solo.cards.clear();//������������գ�������һ�μ�¼
		}
	}
	if(Mediating .empty())//���û�����ԡ���
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetThreejunkoCards(Player P,size_t Num)             //�ɻ�
{
	vector<CARDS> Mediating;//��¼��������
	CARDS solo;
	bool kill;
	for(size_t i=0;i<13-Num;i++)//��num=2ʱ��i��ֵ���Ϊk�γɷɻ�(KKK,AAA��
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<3)//��С������
		   {
			   kill=false;
			   break;
		   }
		}
		if(kill)
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				solo.cards.push_back(j);	
				solo.cards.push_back(j);
			}
			solo.cardsType=THREEJUNKO;	
			solo.score=i;
			Mediating.push_back(solo);
			solo.cards.clear();//������������գ�������һ�μ�¼
		}
	}
	if(Mediating .empty())//���û�зɻ�����
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetThreejunko_oneCards(Player P,size_t Num)    //�ɻ�������
{
	vector<CARDS> Mediating;//��¼��������
	CARDS solo;
	bool kill,bill,mill;
	for(size_t i=0;i<13-Num;i++)//��num=2ʱ��i��ֵ���Ϊk�γɷɻ�(KKK,AAA��
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<3)//��С������
		   {
			   kill=false;
			   break;
		   }
		}
		if(kill)//������������������
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				solo.cards.push_back(j);	
				solo.cards.push_back(j);
			}
			for(size_t j=0;j<15;j++)//��ʼ�ҷɻ���Ҫ���ĵ�������
		    {	
		     	bill=true;
				for(size_t k=0;k<Num;k++)
				{
				   if(j==i+k)
				   {
					   bill=false;
				   }
				}
				if(bill)//���ϲ���ɻ���ֵ��ȵ���
				{
					if(P.EachCardNums[j]>0)
					{
						solo.cards.push_back(j);
						for(size_t t=j+1;t<15;t++)//��ʼ�ҷɻ���Ҫ������һ�ŵ���
		                {
							mill=true;
			             	for(size_t k=0;k<Num;k++)
			            	{
				              if(t==i+k)
				              {
				           	   mill=false;
				              }
			             	}
			            	if(mill)//���ϲ���ɻ���ֵ��ȵ���
			            	{
			     		       if(P.EachCardNums[t]>0&&t!=j)
				             	{
									solo.cards.push_back(t);
					         	    solo.cardsType=THREEJUNKO_ONE;
					        	    solo.score=i;
			                        Mediating.push_back(solo);
					        	    solo.cards.pop_back();
							   }
							}
						}
					 solo.cards.pop_back();
					}
				}
			}	
			solo.cards.clear();//������������գ�������һ�μ�¼
		}
	}
	if(Mediating .empty())//���û�зɻ���������
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetThreejunko_twoCards(Player P,size_t Num)    //�ɻ�������
{
	vector<CARDS> Mediating;//��¼��������
	CARDS solo;
	bool kill,bill,mill;
	for(size_t i=0;i<13-Num;i++)//��num=2ʱ��i��ֵ���Ϊk�γɷɻ�(KKK,AAA��
	{
		kill=true;
		for(size_t j=i;j<Num+i;j++)
		{
		   if(P.EachCardNums[j]<3)//��С������
		   {
			   kill=false;
			   break;
		   }
		}
		if(kill)//������������������
		{
			for(size_t j=i;j<Num+i;j++)
		    {
				solo.cards.push_back(j);
				solo.cards.push_back(j);	
				solo.cards.push_back(j);
			}
			for(size_t j=0;j<15;j++)//��ʼ�ҷɻ���Ҫ���ĵ�������
		    {	
		     	bill=true;
				for(size_t k=0;k<Num;k++)
				{
				   if(j==i+k)
				   {
					   bill=false;
				   }
				}
				if(bill)//���ϲ���ɻ���ֵ��ȵ���
				{
					if(P.EachCardNums[j]>1)
					{
						solo.cards.push_back(j);
						solo.cards.push_back(j);
						for(size_t t=j+1;t<15;t++)//��ʼ�ҷɻ���Ҫ������һ�ŵ���
		                {
							mill=true;
			             	for(size_t k=0;k<Num;k++)
			            	{
				              if(t==i+k)
				              {
				           	   mill=false;
				              }
			             	}
			            	if(mill)//���ϲ���ɻ���ֵ��ȵ���
			            	{
			     		       if(P.EachCardNums[t]>1&&t!=j)
				             	{
									solo.cards.push_back(t);
									solo.cards.push_back(t);
					         	    solo.cardsType=THREEJUNKO_TWO;
					        	    solo.score=i;
			                        Mediating.push_back(solo);
					        	    solo.cards.pop_back();
								    solo.cards.pop_back();
							   }
							}
						}
					 solo.cards.pop_back();
					 solo.cards.pop_back();
					}
				}
			}	
			solo.cards.clear();//������������գ�������һ�μ�¼
		}
	}
	if(Mediating .empty())//���û�зɻ���������
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetFour_twoCards(Player P)               //�Ĵ���
{
	vector<CARDS> Mediating;//��¼���ж���
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]=4)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			for(size_t j=0;j<15;j++)
			{
				if(j!=j&&P.EachCardNums[j]>0)
				{
			        solo.cards.push_back(j);
					solo.cardsType=FOUR_TWO;
			        solo.score=i;
			        Mediating.push_back(solo);
					solo.cards.pop_back();
				}
			}
			solo.cards.clear();//������������գ�������һ�μ�¼
		}
	}
	if(Mediating .empty())//���û���Ĵ�������
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetFour_doubletwoCards(Player P)   //�Ĵ�����
{
	vector<CARDS> Mediating;//��¼���ж���
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]=4)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			for(size_t j=0;j<15;j++)
			{
				if(j!=j&&P.EachCardNums[j]>1)
				{
					solo.cards.push_back(j);
			        solo.cards.push_back(j);
					solo.cardsType=FOUR_TWO;
			        solo.score=i;
			        Mediating.push_back(solo);
					solo.cards.pop_back();
					solo.cards.pop_back();
				}
			}
			solo.cards.clear();//������������գ�������һ�μ�¼
		}
	}
	if(Mediating .empty())//���û���Ĵ����ԡ���
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
vector<CARDS> MoveGenerator::GetZhadanCards(Player P)                   //ը��
{
	vector<CARDS> Mediating;//��¼���ж���
	CARDS solo;
	for(size_t i=0;i<15;i++)
	{
		if(P.EachCardNums[i]==4)
		{
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cards.push_back(i);
			solo.cardsType=ZHADAN;
			solo.score=i+20;
			Mediating.push_back(solo);
		    solo.cards.clear();//������������գ�������һ�μ�¼
		}
	}
	if(P.EachCardNums[13]==1&&P.EachCardNums[14]==1)
	{
		solo.cards.push_back(13);
	    solo.cards.push_back(14);
		solo.cardsType=ZHADAN;
		solo.score=100;
		Mediating.push_back(solo);
	}
	if(Mediating .empty())//���û��ը������
	{
		solo.cardsType=INVAILD;
		Mediating.push_back(solo);
	}
	return Mediating;
}
CARDS MoveGenerator::TakeMoves(Player P)
{
	movesearch movesearch;
	if(P.MeetCard.empty())           //�����Ҫ��Ե���Ϊ�գ�˵������������   
	{
		chaipai Chaipai;		
		vector<CARDS> vec,vec1;
		CARDS cards;
		int N=-100;
		vec=Chaipai.GetCombination_1(P);//��ȡ�߲����ٵ��������
		CARDS Mediating;
		CARDS card=movesearch.duiyi_1(P,Mediating,vec);
		if(!card.cards.empty())
		{
			return card;
		}
		/*if(vec.size()<10)
		{
			vec1=movesearch.search_1(P);
		    if(!vec1.empty())
		   {
			return vec1.at(0);
		   }
		}*/
		for(size_t i=0;i<vec.size();i++)
		{
			vector<CARDS> vec1=vec;
			CARDS card;
			card=vec1.at(i);
			vector<CARDS>::iterator it=vec1.begin()+i;
			vec1.erase(it);
			if(cardsvalue(vec1)>N)
			{
				cards=card;
				N=cardsvalue(vec1);
			}
		}
		return cards;		
	}
	else                            //��������
	{
		chaipai Chaipai;
		bool OK=true;
		vector<unsigned> vec=transform.NumsTransform(P.MeetCard);
		CARDS Mediating=MoveGenerator::GetCardsDetail(vec);
		vector<CARDS> VEC1,vec1;
		CARDS VEC;
		VEC.cardsType=INVAILD;//����޷����� �ͷ������VEC
		VEC1=Chaipai.GetCombination_1(P);//��ȡ�߲����ٵ��������
		CARDS card=movesearch.duiyi_1(P,Mediating,VEC1);
		if(!card.cards.empty())
		{
			return card;
		}
		if(Mediating.cardsType==SINGLE)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==SINGLE&&VEC1.at(i).score!=13&&VEC1.at(i).score!=14&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==COUPLE)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==COUPLE&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==SINGLEJUNKO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==SINGLEJUNKO&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==SANTIAO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==SANTIAO&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==THREE_ONE)
		{for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREE_ONE&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==THREE_TWO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREE_TWO&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==DOUBLEJUNKO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==DOUBLEJUNKO&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==THREEJUNKO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREEJUNKO&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==THREEJUNKO_ONE)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREEJUNKO_ONE&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==THREEJUNKO_TWO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==THREEJUNKO_TWO&&VEC1.at(i).score>Mediating.score&&VEC1.at(i).cards.size()==Mediating.cards.size())
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==FOUR_TWO)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==FOUR_TWO&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		if(Mediating.cardsType==FOUR_TWO_COUPLE)
		{
			for(size_t i=0;i<VEC1.size();i++)
			{
				if(VEC1.at(i).cardsType==FOUR_TWO_COUPLE&&VEC1.at(i).score>Mediating.score)
				{
					return VEC1.at(i);
				}
			}
			//return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
		}
		/*if(VEC1.size()<10)
		{
			vec1=movesearch.search_1(P);
		    if(!vec1.empty())
		   {
			 for(size_t i=0;i<vec1.size();i++)
			 {
				 if(vec1.at(i).cardsType==Mediating.cardsType&&vec1.at(i).cards.size()==Mediating.cards .size()&&vec1.at(i).score>Mediating.score)
				 {
					 return vec1.at(i);
				 }
				 else if(vec1.at(i).cardsType==ZHADAN&&vec1.at(i).score>Mediating.score)
				 {
					return vec1.at(i);
				 }
			 }
		   }
		}*/
		return VEC;//���û���ҵ����ϼҳ����ƴ�˵����pass
	}
	CARDS VEC;
    VEC.cardsType=INVAILD;//����޷����� �ͷ������VEC
    return VEC;
}
void MoveGenerator::paixu(vector<CARDS> &vec)
{
	    for(int i=2;i<=14;i++)
		{
			for(size_t j=0;j<vec.size();j++)
			{
					CARDS V;
				if(vec.at(j).cardsType==i)
				{
					for(size_t k=0;k<vec.size()-1;k++)
					{
						if(vec.at(k).score>vec.at(k+1).score)
						{
							V=vec.at(k);
							vec.at(k)=vec.at(k+1);
							vec.at(k+1)=V;
						}

					}
				}
			}
		}
}
int MoveGenerator::cardsvalue(vector<CARDS> vec)
{
	int sum=0;
	for(size_t i=0;i<vec.size();i++)
	{
		sum+=vec.at(i).score;
		for(size_t j=0;j<vec.size();j++)
	    {
			if(vec.at(j).cardsType==vec.at(i).cardsType&&vec.at(j).score>vec.at(i).score)
			{
				sum--;
			}
		}
		if(vec.at(i).cardsType==ZHADAN)
		{
			sum+=10+vec.at(i).score;
		}
	}
	return sum;
}