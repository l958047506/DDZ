#ifndef define_h_
#define define_h_
#include<vector>

using namespace std;

#define MAX_Depth 120     //蒙特卡罗深度
#define AlphaBeta_Depth 3 // α-β模拟深度
#define RANDTIME 15		   // 随机模拟次数

#define PASS -1				// pass
#define INVAILD 0 			//无效牌型
#define ROCKET 1			// 火箭
#define ZHADAN 2			// 炸弹
#define SINGLE 3			// 单牌
#define COUPLE 4			// 对牌
#define SANTIAO 5			// 三条
#define THREE_ONE 6			// 三带单
#define THREE_TWO 7			// 三带双
#define SINGLEJUNKO 8		// 单顺
#define DOUBLEJUNKO 9			// 双顺
#define THREEJUNKO 10		// 三顺
#define THREEJUNKO_ONE 11   // 三顺带单
#define THREEJUNKO_TWO 12   // 三顺带双
#define FOUR_TWO 13         // 四带二
#define FOUR_TWO_COUPLE 14  // 四带两对
typedef struct _cardsmoves
{
	vector<unsigned> cards;
	int cardsType;
	int score;
}CARDS;
#endif