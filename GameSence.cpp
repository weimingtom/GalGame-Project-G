#include "GameSence.h"
#include "AudioEngine.h"

#include "SetMenuSence.h"

#include "SaveSence.h"
#include "LoadSence.h"
#include "cardMainSence.h"
#include <vector>
#include <string>

USING_NS_CC;
using namespace std;

extern vector<string> recordBackGround;

extern vector<string> recordBGM;

extern vector<string> recordFigure;

extern vector<string> recordVoice;

extern vector<string> recordTxt;

extern int RecordFrom;

extern int musicid;

extern float musicvalue;

extern int voiceid;

extern float voicevalue;

extern int HaveFigure;

extern int HaveTxts;

extern int HaveMenu;

MenuItemImage *nextB = nullptr;

Scene* GameSence::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameSence::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameSence::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initMenu();
	initMainGame();

	return true;
}

void GameSence::kunteBack(Ref *sender)
{
	auto itemSelect = (MenuItem*)sender;

	switch (itemSelect->getTag())
	{
	   case TAG_GAME_K1:
	   {
		   Director::getInstance()->pushScene(CardMain::createScene());
		   break;
	   }

	   case TAG_GAME_K2:
	   {
		   if (recordBackGround[RecordFrom + 1] != "END")
		   {
			   ++RecordFrom;
			   NextSence();
		   }
		   break;
	   }
	}
}

void GameSence::initMenu()
{
	auto MenuButton = MenuItemImage::create("InGame/MsetButton.png", "InGame/MsetButtonPush.png", CC_CALLBACK_1(GameSence::menuCallBack, this));
	auto NextButton = MenuItemImage::create("InGame/nextBar.png", "InGame/nextBarPush.png","InGame/nextBarLock.png", CC_CALLBACK_1(GameSence::menuCallBack, this));
	auto BackaButton = MenuItemImage::create("InGame/backBar.png", "InGame/backBarPush.png", CC_CALLBACK_1(GameSence::menuCallBack, this));
	auto SaveButton = MenuItemImage::create("InGame/saveBar.png", "InGame/saveBarPush.png", CC_CALLBACK_1(GameSence::menuCallBack, this));
	auto LoadButton = MenuItemImage::create("InGame/loadBar.png", "InGame/loadBarPush.png", CC_CALLBACK_1(GameSence::menuCallBack, this));

	MenuButton->setAnchorPoint(Point(0, 0));
	NextButton->setAnchorPoint(Point(0, 0));
	BackaButton->setAnchorPoint(Point(0, 0));
	SaveButton->setAnchorPoint(Point(0, 0));
	LoadButton->setAnchorPoint(Point(0, 0));

	MenuButton->setPosition(Point(1180, 620));
	NextButton->setPosition(Point(960, 0));
	BackaButton->setPosition(Point(0, 0));
	SaveButton->setPosition(Point(320, 0));
	LoadButton->setPosition(Point(640, 0));

	MenuButton->setTag(TAG_GAME_MENU);
	NextButton->setTag(TAG_GAME_NEXT);
	BackaButton->setTag(TAG_GAME_BACK);
	SaveButton->setTag(TAG_GAME_SAVE);
	LoadButton->setTag(TAG_GAME_LOAD);

	nextB = NextButton;

	auto menu = Menu::create(MenuButton, NextButton, BackaButton, SaveButton, LoadButton, NULL);

	menu->setAnchorPoint(Point(0, 0));
	menu->setPosition(Point(0, 0));

	this->addChild(menu,50);
}

void GameSence::menuCallBack(Ref *sender)
{
	auto itemSelect = (MenuItem*)sender;

	switch (itemSelect->getTag())
	{
	    case TAG_GAME_MENU:
		{
			Director::getInstance()->pushScene(SetMenu::createScene());
			break;
		}

		case TAG_GAME_NEXT:
		{
			if (recordBackGround[RecordFrom+1] != "END")
			{
				++RecordFrom;
				NextSence();
			}
			break;
		}

		case TAG_GAME_BACK:
		{
			if (RecordFrom != 0)
			{
				--RecordFrom;
				PrevSence();
			}
			break;
		}

		case TAG_GAME_SAVE:
		{
			Director::getInstance()->pushScene(Save::createScene());
			break;
		}

		case TAG_GAME_LOAD:
		{
			Director::getInstance()->pushScene(Load::createScene());
			break;
		}
	}
}

void GameSence::initMainGame()
{	
	FirstSencePlay();
}

void GameSence::eachPlay(int loadCountBG,int loadCountBGM)
{
	if (loadCountBG != -1)
	{
		//背景
		auto back = Sprite::create(recordBackGround[loadCountBG]);
		back->setAnchorPoint(Point(0, 0));
		back->setPosition(Point(0, 0));
		back->setTag(TAG_GAME_BACKS);
		this->addChild(back);
	}

	if (loadCountBGM != -1)
	{
		//BGM
		musicid = experimental::AudioEngine::play2d(recordBGM[loadCountBGM], true, musicvalue);
	}

	if (HaveFigure == 1)
	{
		removeChildByTag(TAG_GAME_FIGURE, true);
		HaveFigure = 0;
	}

	//立绘
	if (recordFigure[RecordFrom] != "N")
	{
		auto Figure = Sprite::create(recordFigure[RecordFrom]);
		Figure->setAnchorPoint(Point(0, 0));
		Figure->setPosition(Point(0, 0));
		Figure->setTag(TAG_GAME_FIGURE);
		this->addChild(Figure);

		HaveFigure = 1;
	}

	//语音
	//	if (recordVoice[RecordFrom] != "N")
	//	{
	//      experimental::AudioEngine::stop(voiceid);
	//		voiceid = experimental::AudioEngine::play2d(recordVoice[RecordFrom], false, voicevalue);
	//	}

	if (HaveTxts == 1)
	{
		removeChildByTag(TAG_GAME_TXTS, true);
		removeChildByTag(TAG_GAME_TXTBACK, true);
		HaveTxts = 0;
	}

	//对话框和文本初始化
	if (recordTxt[RecordFrom] != "N")
	{
		auto txtback = Sprite::create("InGame/talk.png");
		txtback->setAnchorPoint(Point(0, 0));
		txtback->setPosition(Point(0, 0));
		txtback->setTag(TAG_GAME_TXTBACK);
		this->addChild(txtback);

		auto txts = Label::createWithTTF(recordTxt[RecordFrom], "fonts/normal.ttf", 43, Size(1260, 200));
		txts->setAnchorPoint(Point(0, 0));
		txts->setPosition(Point(10, 0));
		txts->setColor(Color3B(0, 0, 0));
		txts->setTag(TAG_GAME_TXTS);
		this->addChild(txts);

		HaveTxts = 1;
	}

	if(HaveMenu == 1)
	{
		removeChildByTag(TAG_GAME_SELECTMENU);
		nextB->setEnabled(true);
		HaveMenu = 0;
	}

	if (recordBackGround[RecordFrom] == "S")
	{
		
	}
	
	if (recordBackGround[RecordFrom] == "K")
	{
		auto K1Button = MenuItemImage::create("InGame/select1.png", "InGame/select1Push.png", CC_CALLBACK_1(GameSence::kunteBack, this));
		auto K2Button = MenuItemImage::create("InGame/select2.png", "InGame/select2Push.png", CC_CALLBACK_1(GameSence::kunteBack, this));

		K1Button->setAnchorPoint(Point(0, 0));
		K2Button->setAnchorPoint(Point(0, 0));

		K1Button->setPosition(Point(400, 540));
		K2Button->setPosition(Point(400, 360));

		K1Button->setTag(TAG_GAME_K1);
		K2Button->setTag(TAG_GAME_K2);

		auto kunteMenu = Menu::create(K1Button, K2Button, NULL);

		kunteMenu->setAnchorPoint(Point(0, 0));
		kunteMenu->setPosition(Point(0, 0));

		kunteMenu->setTag(TAG_GAME_SELECTMENU);

		this->addChild(kunteMenu, 90);

		nextB->setEnabled(false);

		HaveMenu = 1;
	}
}

void GameSence::FirstSencePlay()
{
	experimental::AudioEngine::stop(musicid);
	int loadCountBG = RecordFrom,loadCountBGM = RecordFrom;
	while (recordBackGround[loadCountBG] == "N" || recordBackGround[loadCountBG] == "S" || recordBackGround[loadCountBG] == "K")
	{
		--loadCountBG;
	}
	while (recordBGM[loadCountBGM] == "N")
	{
		--loadCountBGM;
	}

	eachPlay(loadCountBG, loadCountBGM);
}

void GameSence::NextSence()
{
	int loadCountBG = RecordFrom, loadCountBGM = RecordFrom;
	if (recordBackGround[loadCountBG] == "N" || recordBackGround[loadCountBG] == "S" || recordBackGround[loadCountBG] == "K")
	{
		loadCountBG = -1;
	}
	else
	{
		removeChildByTag(TAG_GAME_BACKS, true);
	}

	if (recordBGM[loadCountBGM] == "N")
	{
		loadCountBGM = -1;
	}
	else
	{
		experimental::AudioEngine::stop(musicid);
	}

	eachPlay(loadCountBG, loadCountBGM);
}

void GameSence::PrevSence()
{
	int loadCountBG = RecordFrom, loadCountBGM = RecordFrom;

	if (recordBackGround[++loadCountBG] != "N"&&recordBackGround[loadCountBG] != "S"&&recordBackGround[loadCountBG] != "K")
	{
		--loadCountBG;
		while (recordBackGround[loadCountBG] == "N" || recordBackGround[loadCountBG] == "S" || recordBackGround[loadCountBG] == "K")
		{
			--loadCountBG;
		}
		removeChildByTag(TAG_GAME_BACKS, true);
	}
	else
	{
		loadCountBG = -1;
	}

	if (recordBGM[++loadCountBGM] != "N")
	{
		--loadCountBGM;
		while (recordBGM[loadCountBGM] == "N")
		{
			--loadCountBGM;
		}
		experimental::AudioEngine::stop(musicid);
	}
	else
	{
		loadCountBGM = -1;
	}

	eachPlay(loadCountBG, loadCountBGM);
}