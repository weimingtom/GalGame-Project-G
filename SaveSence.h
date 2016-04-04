#ifndef _SAVE_SENCE_H_
#define _SAVE_SENCE_H_

#define TAG_SAVE_BACK        0
#define TAG_SAVE_LOAD1       1
#define TAG_SAVE_LOAD2       2
#define TAG_SAVE_LOAD3       3
#define TAG_SAVE_LOAD4       4
#define TAG_SAVE_LOAD5       5
#define TAG_SAVE_LOAD6       6
#define TAG_SAVE_LOAD7       7
#define TAG_SAVE_LOAD8       8

#include "cocos2d.h"

class Save : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Save);

	void initBackGround();

	void initEach9(int load,int number);

	void initMenu();

	void menuCallBack(cocos2d::Ref *sender);

	void loadPicforEach9(int load, int x, int y);

};

#endif