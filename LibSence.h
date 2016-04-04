#ifndef _LIB_SENCE_H_
#define _LIB_SENCE_H_

#define TAG_LIB_BACK        0

#include "cocos2d.h"

class Lib : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Lib);

	void initBackGround();

	void initMenu();

	void menuCallBack(cocos2d::Ref *sender);

};

#endif
