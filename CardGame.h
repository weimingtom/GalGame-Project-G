#ifndef _CARD_GAME_H_
#define _CARD_GAME_H_

#define TAG_CARDPALY_BACK   0
#define TAG_CARDPALY_FAIL   1
#define TAG_CARDPALY_END    2
#define TAG_CARDPALY_YES    3
#define TAG_CARDPALY_NO     4
#define TAG_CARDPALY_YNMENU           5
#define TAG_CARDPALY_YNMENUBUTTON     6
#define TAG_CARDPALY_SKILLUSEBUTTON   7
#define TAG_CARDPLAY_CARDSELECTBUTTON 8
#define TAG_CARDPLAY_SETMENUBUTTON    9

#include "cocos2d.h"

class CardPlayMain : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(CardPlayMain);

	void initBackGround();
    void initGame();
    void initFirstSelectMenu();
    void initSelectMenu();
    
	void menuCallBack(Ref *sender);
    void firstMenuCallBack(Ref *sender);
    
    void YNmenuCallBack(Ref *Sender);
    
    void computerPlayHard();
    
    void computerPlayEasy();
    
    void playerPlay();
    
    void EachPlay();
};

#endif
