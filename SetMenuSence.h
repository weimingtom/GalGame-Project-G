#ifndef _SETMENU_SENCE_H_
#define _SETMENU_SENCE_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#define TAG_SETMENU_BACK         0
#define TAG_SETMENU_LIST         1

class SetMenu : public cocos2d::Layer
{
 public:
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(SetMenu);

	void initBackGround();

	void initMenu();

	void menuCallBack(cocos2d::Ref *sender);

	void initSlider();

	void sliderCallback1(Ref *sender, cocos2d::ui::Slider::EventType t);

	void sliderCallback2(Ref *sender, cocos2d::ui::Slider::EventType t);
};

#endif