#ifndef _CARD_MAIN_SENCE_H_
#define _CARD_MAIN_SENCE_H_

#define TAG_CARD_EASY   0
#define TAG_CARD_HARD   1
#define TAG_CARD_BACK   2

#include "cocos2d.h"

class CardMain : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(CardMain);

	void initBackGround();
	void initMenu();
	void menuCallBack(Ref *sender);
};

#endif