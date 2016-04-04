#include "SetMenuSence.h"
#include "DevListSence.h"

#include "AudioEngine.h"

USING_NS_CC;
using namespace ui;

extern float musicvalue;
extern int   musicid;
extern float voicevalue;

Scene* SetMenu::createScene()
{
	auto scene = Scene::create();

	auto layer = SetMenu::create();

	scene->addChild(layer);

	return scene;
}

bool SetMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	initBackGround();
	initMenu();
	initSlider();

	return true;
}

void SetMenu::initBackGround()
{
	//draw background
	auto menu = Sprite::create("setArt/setPic.png");
	menu->setAnchorPoint(Point(0, 0));
	menu->setPosition(Point(0, 0));
	this->addChild(menu);
}

void SetMenu::initMenu()
{
	//draw menu
	auto ListButton = MenuItemImage::create("setArt/ListButton.png", "setArt/ListPush.png", CC_CALLBACK_1(SetMenu::menuCallBack, this));
	auto BackButton = MenuItemImage::create("setArt/BackButton.png", "setArt/BackPush.png", CC_CALLBACK_1(SetMenu::menuCallBack, this));

	ListButton->setPosition(Point(0, -50));
	BackButton->setPosition(Point(0, -150));

	ListButton->setTag(TAG_SETMENU_LIST);
	BackButton->setTag(TAG_SETMENU_BACK);

	auto menu = Menu::create(ListButton, BackButton, NULL);
	this->addChild(menu);
}

//When touch button
void SetMenu::menuCallBack(Ref * sender)
{
	auto itemSelect = (MenuItem*)sender;

	switch (itemSelect->getTag())
	{
	    case TAG_SETMENU_BACK:
	    {
		     Director::getInstance()->popScene();
		     break;
	    }

	    case TAG_SETMENU_LIST:
	    {
	       	Director::getInstance()->pushScene(DevList::createScene());
		    break;
     	}
	}
}

void SetMenu::initSlider()
{
	auto slider = Slider::create();
	slider->loadBarTexture("setArt/VoiceBase.png");
	slider->loadProgressBarTexture("setArt/VoiceUpon.png");
	slider->loadSlidBallTextureNormal("setArt/SliderButton.png");
	slider->setPercent(musicvalue*100);
	slider->addEventListener(CC_CALLBACK_2(SetMenu::sliderCallback1, this));
	slider->setAnchorPoint(Point(0, 0));
	slider->setPosition(Point(480, 485));
	this->addChild(slider);

	auto slider2 = Slider::create();
	slider2->loadBarTexture("setArt/VoiceBase.png");
	slider2->loadProgressBarTexture("setArt/VoiceUpon.png");
	slider2->loadSlidBallTextureNormal("setArt/SliderButton.png");
	slider2->setPercent(voicevalue * 100);
	slider2->addEventListener(CC_CALLBACK_2(SetMenu::sliderCallback2, this));
	slider2->setAnchorPoint(Point(0, 0));
	slider2->setPosition(Point(480, 378));
	this->addChild(slider2);
}

void SetMenu::sliderCallback1(Ref *sender, Slider::EventType t)
{
	float BGMvalue = 100.0;
	float Base = 100.0;
	auto slider = (Slider*) sender;

	switch (t)
	{
	  	case Slider::EventType::ON_PERCENTAGE_CHANGED:
        {
		BGMvalue=slider->getPercent();
		
		experimental::AudioEngine::setVolume(musicid, (BGMvalue/Base));
		musicvalue = BGMvalue / Base;
        }
        break;

		case Slider::EventType::ON_SLIDEBALL_UP:
        {
		UserDefault::getInstance()->setFloatForKey("MUSICVALUE",musicvalue);
		UserDefault::getInstance()->flush();
        }
        break;
	}
}

void SetMenu::sliderCallback2(Ref *sender, Slider::EventType t)
{
	float VOICEvalue = 100.0;
	float Base = 100.0;
	auto slider = (Slider*)sender;

	switch (t)
	{
	case Slider::EventType::ON_PERCENTAGE_CHANGED:
    {
		VOICEvalue = slider->getPercent();

		voicevalue = VOICEvalue / Base;
    }
    break;

	case Slider::EventType::ON_SLIDEBALL_UP:
    {
        UserDefault::getInstance()->setFloatForKey("VOICEVALUE", voicevalue);
		UserDefault::getInstance()->flush();
	}
    break;
    }
}