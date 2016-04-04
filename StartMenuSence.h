#ifndef __STRATMENU_SCENE_H__
#define __STRATMENU_SCENE_H__

#include "cocos2d.h"

#define TAG_STARTMENU_START  0
#define TAG_STARTMENU_SAVE   1
#define TAG_STARTMENU_LIB    2
#define TAG_STARTMENU_SET    3

#define TAG_STARTMENU_PLAYCARD    4

class StartMenu : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(StartMenu);

	void initReadRecord();
	
	void initBackGround();

	void initMenu();

	void menuCallBack(Ref *sender);
};

#endif // __STRATMENU_SCENE_H__
