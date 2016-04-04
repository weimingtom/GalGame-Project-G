#include "StartMenuSence.h"
#include "AudioEngine.h"

//
#include "GameSence.h"
//
#include "LoadSence.h"
//
#include "LibSence.h"
//
#include "SetMenuSence.h"
//
#include "cardMainSence.h"

USING_NS_CC;

//record.cpp
extern int load1;
extern int load2;
extern int load3;
extern int load4;
extern int load5;
extern int load6;
extern int load7;
extern int load8;

extern float musicvalue;
extern int musicid;

extern float voicevalue;
extern int voiceid;

Scene* StartMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StartMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartMenu::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	initReadRecord();
	initBackGround();
	initMenu();

    return true;
}

void StartMenu::initReadRecord()
{
	load1 = UserDefault::getInstance()->getIntegerForKey("LOAD1", -1);
	load2 = UserDefault::getInstance()->getIntegerForKey("LOAD2", -1);
	load3 = UserDefault::getInstance()->getIntegerForKey("LOAD3", -1);
	load4 = UserDefault::getInstance()->getIntegerForKey("LOAD4", -1);
	load5 = UserDefault::getInstance()->getIntegerForKey("LOAD5", -1);
	load6 = UserDefault::getInstance()->getIntegerForKey("LOAD6", -1);
	load7 = UserDefault::getInstance()->getIntegerForKey("LOAD7", -1);
	load8 = UserDefault::getInstance()->getIntegerForKey("LOAD8", -1);

	musicvalue = UserDefault::getInstance()->getFloatForKey("MUSICVALUE", 1.0);
	voicevalue = UserDefault::getInstance()->getFloatForKey("VOICEVALUE", 1.0);

	//
	musicid = experimental::AudioEngine::play2d("titleArt/titleMusic.mp3", true, musicvalue);
}

void StartMenu::initBackGround()
{
	//draw background
	auto back = Sprite::create("titleArt/titlePic.png");
	back->setAnchorPoint(Point(0, 0));
	back->setPosition(Point(0, 0));
	this->addChild(back);
}

void StartMenu::initMenu()
{
	//draw menu
	auto startButton = MenuItemImage::create("titleArt/startButton.png", "titleArt/startPush.png", CC_CALLBACK_1(StartMenu::menuCallBack, this));
	auto saveButton = MenuItemImage::create("titleArt/saveButton.png", "titleArt/savePush.png", CC_CALLBACK_1(StartMenu::menuCallBack, this));
	auto libButton = MenuItemImage::create("titleArt/libButton.png", "titleArt/libPush.png", CC_CALLBACK_1(StartMenu::menuCallBack, this));
	auto setButton = MenuItemImage::create("titleArt/setButton.png", "titleArt/setPush.png", CC_CALLBACK_1(StartMenu::menuCallBack, this));
	auto playCardButton = MenuItemImage::create("card/playCard.png", "card/playCardPush.png", CC_CALLBACK_1(StartMenu::menuCallBack, this));

	startButton->setPosition(Point(0, -33));
	saveButton->setPosition(Point(0, -117));
	libButton->setPosition(Point(0, -197));
	setButton->setPosition(Point(0, -279));
	playCardButton->setPosition(Point(520,-250));

	startButton->setTag(TAG_STARTMENU_START);
	saveButton->setTag(TAG_STARTMENU_SAVE);
	libButton->setTag(TAG_STARTMENU_LIB);
	setButton->setTag(TAG_STARTMENU_SET);
	playCardButton->setTag(TAG_STARTMENU_PLAYCARD);

	auto menu = Menu::create(startButton, saveButton, libButton, setButton, playCardButton,NULL);
	this->addChild(menu);
}

void StartMenu::menuCallBack(Ref *sender)
{
	auto itemSelect = (MenuItem*)sender;

	switch (itemSelect->getTag())
	{
	  case TAG_STARTMENU_START:
	  {
		   Director::getInstance()->replaceScene(GameSence::createScene());
		   break;
	  }	

	  case TAG_STARTMENU_SAVE:
	  {
		   Director::getInstance()->pushScene(Load::createScene());
		   break;
      }

	  case TAG_STARTMENU_LIB:
	  {
		  Director::getInstance()->pushScene(Lib::createScene());
		  break;
	  }

	  case TAG_STARTMENU_SET:
	  {
		  Director::getInstance()->pushScene(SetMenu::createScene());
		  break;
	  }

	  case TAG_STARTMENU_PLAYCARD:
	  {
		  Director::getInstance()->pushScene(CardMain::createScene());
		  break;
	  }
	}
}