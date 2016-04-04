#include "LibSence.h"

USING_NS_CC;

Scene* Lib::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Lib::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool Lib::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initBackGround();
	initMenu();

	return true;
}

void Lib::initBackGround()
{
	auto backpage = Sprite::create("libArt/LibBack.png");
	backpage->setAnchorPoint(Point(0, 0));
	backpage->setPosition(Point(0, 0));
	this->addChild(backpage);
}

void Lib::initMenu()
{
	//draw menu
	auto BackButton = MenuItemImage::create("setArt/BackButton.png", "setArt/BackPush.png", CC_CALLBACK_1(Lib::menuCallBack, this));
	BackButton->setPosition(Point(540, -300));
	BackButton->setTag(TAG_LIB_BACK);

	auto menu = Menu::create(BackButton, NULL);

	this->addChild(menu);
}

void Lib::menuCallBack(Ref *sender)
{
	auto itemSelect = (MenuItem*)sender;

	switch (itemSelect->getTag())
	{
	    case TAG_LIB_BACK:
	   {
	     	Director::getInstance()->popScene();
	     	break;
	   }
	}
}