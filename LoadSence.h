#ifndef _LOAD_SENCE_H_
#define _LOAD_SENCE_H_

#define TAG_LOAD_BACK        0
#define TAG_LOAD_LOAD1       1
#define TAG_LOAD_LOAD2       2
#define TAG_LOAD_LOAD3       3
#define TAG_LOAD_LOAD4       4
#define TAG_LOAD_LOAD5       5
#define TAG_LOAD_LOAD6       6
#define TAG_LOAD_LOAD7       7
#define TAG_LOAD_LOAD8       8

#include "cocos2d.h"

class Load : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Load);

	void initBackGround();

	void initEach9(int load, int number);

	void loadPicforEach9(int load,int x,int y);

	void initMenu();

	void menuCallBack(cocos2d::Ref *sender);

};

#endif