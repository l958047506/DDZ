#ifndef define_h_
#define define_h_
#include<vector>

using namespace std;

#define MAX_Depth 120     //���ؿ������
#define AlphaBeta_Depth 3 // ��-��ģ�����
#define RANDTIME 15		   // ���ģ�����

#define PASS -1				// pass
#define INVAILD 0 			//��Ч����
#define ROCKET 1			// ���
#define ZHADAN 2			// ը��
#define SINGLE 3			// ����
#define COUPLE 4			// ����
#define SANTIAO 5			// ����
#define THREE_ONE 6			// ������
#define THREE_TWO 7			// ����˫
#define SINGLEJUNKO 8		// ��˳
#define DOUBLEJUNKO 9			// ˫˳
#define THREEJUNKO 10		// ��˳
#define THREEJUNKO_ONE 11   // ��˳����
#define THREEJUNKO_TWO 12   // ��˳��˫
#define FOUR_TWO 13         // �Ĵ���
#define FOUR_TWO_COUPLE 14  // �Ĵ�����
typedef struct _cardsmoves
{
	vector<unsigned> cards;
	int cardsType;
	int score;
}CARDS;
#endif