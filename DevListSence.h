#ifndef _DEV_LIST_SENCE_H_
#define _DEV_LIST_SENCE_H_

#define TAG_DEV_BACK   0

#include "cocos2d.h"

class DevList : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(DevList);

	void initBackGround();
	void initMenu();
	void menuCallBack(Ref *sender);
};

#endif
