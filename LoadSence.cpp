#include "LoadSence.h"
#include "GameSence.h"
#include <vector>
#include <string>

using namespace std;

USING_NS_CC;

extern vector<string> recordBackGround;

extern vector<string> recordFigure;

extern vector<string> recordTxt;

extern int RecordFrom;

extern int load1;
extern int load2;
extern int load3;
extern int load4;
extern int load5;
extern int load6;
extern int load7;
extern int load8;

Scene* Load::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Load::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool Load::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initBackGround();
	initMenu();

	return true;
}

void Load::initBackGround()
{
	auto backpage = Sprite::create("libArt/LibBack.png");
	backpage->setAnchorPoint(Point(0, 0));
	backpage->setPosition(Point(0, 0));
	this->addChild(backpage);

	initEach9(load1, 1);
	initEach9(load2, 2);
	initEach9(load3, 3);
	initEach9(load4, 4);
	initEach9(load5, 5);
	initEach9(load6, 6);
	initEach9(load7, 7);
	initEach9(load8, 8);
}

void Load::initEach9(int load, int number)
{
	int x = 0, y = 0;

	switch (number)
	{
	case 1:
		x = 0, y = 480;
		break;
	case 2:
		x = 427, y = 480;
		break;
	case 3:
		x = 854, y = 480;
		break;
	case 4:
		x = 0, y = 240;
		break;
	case 5:
		x = 427, y = 240;
		break;
	case 6:
		x = 854, y = 240;
		break;
	case 7:
		x = 0, y = 0;
		break;
	case 8:
		x = 427, y = 0;
		break;
	}

	if (load == -1)
	{
		auto B = Sprite::create("SaveLoad/slNull.png");
		B->setAnchorPoint(Point(0, 0));
		B->setPosition(Point(x, y));
		this->addChild(B);
	}
	else
	{
		loadPicforEach9(load,x,y);
	}
}

void Load::loadPicforEach9(int load,int x,int y)
{
	int loadCount = load;

	while (recordBackGround[loadCount] == "N" || recordBackGround[loadCount] == "S" || recordBackGround[loadCount] == "K")
	{
		--loadCount;
	}

	auto BG = Sprite::create(recordBackGround[loadCount]);
	BG->setAnchorPoint(Point(0, 0));
	BG->setPosition(Point(x, y));
	BG->setScale(0.33);
	this->addChild(BG);

	if (recordFigure[load] != "N")
	{
		auto FG = Sprite::create(recordFigure[load]);
		FG->setAnchorPoint(Point(0, 0));
		FG->setPosition(Point(x, y));
		FG->setScale(0.33);
		this->addChild(FG);
	}

	if (recordTxt[load] != "N")
	{
		auto txtb = Sprite::create("InGame/talk.png");
		txtb->setAnchorPoint(Point(0, 0));
		txtb->setPosition(Point(x, y));
		txtb->setScale(0.33);
		this->addChild(txtb);

		auto txtss = Label::createWithTTF(recordTxt[load], "fonts/normal.ttf", 43, Size(1260, 200));
		txtss->setAnchorPoint(Point(0, 0));
		txtss->setPosition(Point(x + 10, y));
		txtss->setColor(Color3B(0, 0, 0));
		txtss->setScale(0.33);
		this->addChild(txtss);
	}

	if (recordBackGround[load] == "S")
	{

	}

	if (recordBackGround[load] == "K")
	{
		auto S1 = Sprite::create("InGame/select1.png");
		S1->setAnchorPoint(Point(0, 0));
		S1->setPosition(Point(x+125, y+180));
		S1->setScale(0.33);
		this->addChild(S1);

		auto S2 = Sprite::create("InGame/select2.png");
		S2->setAnchorPoint(Point(0, 0));
		S2->setPosition(Point(x + 125, y + 120));
		S2->setScale(0.33);
		this->addChild(S2);
	}
}

void Load::initMenu()
{
	//draw menu
	auto Load1Button = MenuItemImage::create("SaveLoad/sl.png", "SaveLoad/slPush.png", CC_CALLBACK_1(Load::menuCallBack, this));
	Load1Button->setPosition(Point(-426, 240));
	Load1Button->setTag(TAG_LOAD_LOAD1);

	auto Load2Button = MenuItemImage::create("SaveLoad/sl.png", "SaveLoad/slPush.png", CC_CALLBACK_1(Load::menuCallBack, this));
	Load2Button->setPosition(Point(0, 240));
	Load2Button->setTag(TAG_LOAD_LOAD2);

	auto Load3Button = MenuItemImage::create("SaveLoad/sl.png", "SaveLoad/slPush.png", CC_CALLBACK_1(Load::menuCallBack, this));
	Load3Button->setPosition(Point(426, 240));
	Load3Button->setTag(TAG_LOAD_LOAD3);

	auto Load4Button = MenuItemImage::create("SaveLoad/sl.png", "SaveLoad/slPush.png", CC_CALLBACK_1(Load::menuCallBack, this));
	Load4Button->setPosition(Point(-426, 0));
	Load4Button->setTag(TAG_LOAD_LOAD4);

	auto Load5Button = MenuItemImage::create("SaveLoad/sl.png", "SaveLoad/slPush.png", CC_CALLBACK_1(Load::menuCallBack, this));
	Load5Button->setPosition(Point(0, 0));
	Load5Button->setTag(TAG_LOAD_LOAD5);

	auto Load6Button = MenuItemImage::create("SaveLoad/sl.png", "SaveLoad/slPush.png", CC_CALLBACK_1(Load::menuCallBack, this));
	Load6Button->setPosition(Point(426, 0));
	Load6Button->setTag(TAG_LOAD_LOAD6);

	auto Load7Button = MenuItemImage::create("SaveLoad/sl.png", "SaveLoad/slPush.png", CC_CALLBACK_1(Load::menuCallBack, this));
	Load7Button->setPosition(Point(-426, -240));
	Load7Button->setTag(TAG_LOAD_LOAD7);

	auto Load8Button = MenuItemImage::create("SaveLoad/sl.png", "SaveLoad/slPush.png", CC_CALLBACK_1(Load::menuCallBack, this));
	Load8Button->setPosition(Point(0, -240));
	Load8Button->setTag(TAG_LOAD_LOAD8);

	auto BackButton = MenuItemImage::create("setArt/BackButton.png", "setArt/BackPush.png", CC_CALLBACK_1(Load::menuCallBack, this));
	BackButton->setPosition(Point(540, -300));
	BackButton->setTag(TAG_LOAD_BACK);

	auto menu = Menu::create(Load1Button, Load2Button, Load3Button, Load4Button, Load5Button, Load6Button, Load7Button, Load8Button, BackButton, NULL);

	this->addChild(menu, 99);
}

void Load::menuCallBack(Ref *sender)
{
	auto itemSelect = (MenuItem*)sender;

	switch (itemSelect->getTag())
	{
	case TAG_LOAD_BACK:
	{
		Director::getInstance()->popScene();
		break;
	}
	case TAG_LOAD_LOAD1:
	{
		if (load1 != -1)
		{
			RecordFrom = load1;
			Director::getInstance()->replaceScene(GameSence::createScene());
		}
		break;
	}
	case TAG_LOAD_LOAD2:
	{
		if (load2 != -1)
		{
			RecordFrom = load2;
			Director::getInstance()->replaceScene(GameSence::createScene());
		}
		break;
	}
	case TAG_LOAD_LOAD3:
	{
		if (load3 != -1)
		{
			RecordFrom = load3;
			Director::getInstance()->replaceScene(GameSence::createScene());
		}
		break;
	}
	case TAG_LOAD_LOAD4:
	{
		if (load4 != -1)
		{
			RecordFrom = load4;
			Director::getInstance()->replaceScene(GameSence::createScene());
		}
		break;
	}
	case TAG_LOAD_LOAD5:
	{
		if (load5 != -1)
		{
			RecordFrom = load5;
			Director::getInstance()->replaceScene(GameSence::createScene());
		}
		break;
	}
	case TAG_LOAD_LOAD6:
	{
		if (load6 != -1)
		{
			RecordFrom = load6;
			Director::getInstance()->replaceScene(GameSence::createScene());
		}
		break;
	}
	case TAG_LOAD_LOAD7:
	{
		if (load7 != -1)
		{
			RecordFrom = load7;
			Director::getInstance()->replaceScene(GameSence::createScene());
		}
		break;
	}
	case TAG_LOAD_LOAD8:
	{
		if (load8 != -1)
		{
			RecordFrom = load8;
			Director::getInstance()->replaceScene(GameSence::createScene());
		}
		break;
	}

	}
}