#include "cardMainSence.h"
#include "AudioEngine.h"
#include "CardGame.h"

USING_NS_CC;

extern int musicid;
extern float musicvalue;
extern bool levelOfCard;
extern int CARDmusicid;

Scene* CardMain::createScene()
{
	auto scene = Scene::create();

	auto layer = CardMain::create();

	scene->addChild(layer);

	return scene;
}

bool CardMain::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initBackGround();
	initMenu();

	return true;
}

void CardMain::initBackGround()
{
	experimental::AudioEngine::pause(musicid);
	CARDmusicid=experimental::AudioEngine::play2d("card/cardBGM.mp3", true, musicvalue);

	auto backpage = Sprite::create("card/cardBack.png");
	backpage->setAnchorPoint(Point(0, 0));
	backpage->setPosition(Point(0, 0));
	this->addChild(backpage);
}

void CardMain::initMenu()
{
	//draw menu
	auto EasyButton = MenuItemImage::create("card/EasyButton.png", "card/EasyPush.png", CC_CALLBACK_1(CardMain::menuCallBack, this));
	auto HardButton = MenuItemImage::create("card/HardButton.png", "card/HardPush.png", CC_CALLBACK_1(CardMain::menuCallBack, this));
	auto BackButton = MenuItemImage::create("card/BackButton.png", "card/BackPush.png", CC_CALLBACK_1(CardMain::menuCallBack, this));

	EasyButton->setPosition(Point(-250, 0));
	HardButton->setPosition(Point(250, 0));
	BackButton->setPosition(Point(-580, -300));

	EasyButton->setTag(TAG_CARD_EASY);
	HardButton->setTag(TAG_CARD_HARD);
	BackButton->setTag(TAG_CARD_BACK);

	auto menu = Menu::create(EasyButton, HardButton, BackButton, NULL);

	this->addChild(menu);
}

void CardMain::menuCallBack(Ref *sender)
{
	auto itemSelect = (MenuItem*)sender;

	switch (itemSelect->getTag())
	{
	    case TAG_CARD_EASY:
	   {
		    levelOfCard = true;
            Director::getInstance()->pushScene(CardPlayMain::createScene());
	    	break;
       }

		case TAG_CARD_HARD:
		{
			levelOfCard = false;
            Director::getInstance()->pushScene(CardPlayMain::createScene());
			break;
		}

		case TAG_CARD_BACK:
		{
			experimental::AudioEngine::stop(CARDmusicid);

			experimental::AudioEngine::resume(musicid);

			Director::getInstance()->popScene();
			break;
		}
	}
}