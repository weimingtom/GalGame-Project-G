#ifndef _CARD_SET_SENCE_H_
#define _CARD_SET_SENCE_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#define TAG_CARDSETMENU_BACK         0
#define TAG_CARDSETMENU_LIST         1

class cardSetMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(cardSetMenu);
    
    void initBackGround();
    
    void initMenu();
    
    void menuCallBack(cocos2d::Ref *sender);
    
    void initSlider();
    
    void sliderCallback1(Ref *sender, cocos2d::ui::Slider::EventType t);
    
    void sliderCallback2(Ref *sender, cocos2d::ui::Slider::EventType t);
};

#endif