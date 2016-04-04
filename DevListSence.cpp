#include "DevListSence.h"

USING_NS_CC;

Scene* DevList::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = DevList::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool DevList::init()
{
	if (!Layer::init())
	{
		return false;
	}

	initBackGround();
	initMenu();

	return true;
}

void DevList::initBackGround()
{
	auto backpage = Sprite::create("ListArt/DevList.png");
	backpage->setAnchorPoint(Point(0, 0));
	backpage->setPosition(Point(0, 0));
	this->addChild(backpage);
}

void DevList::initMenu()
{
	//draw menu
	auto BackButton = MenuItemImage::create("setArt/BackButton.png", "setArt/BackPush.png", CC_CALLBACK_1(DevList::menuCallBack, this));

	BackButton->setPosition(Point(540, -300));

	BackButton->setTag(TAG_DEV_BACK);

	auto menu = Menu::create(BackButton, NULL);

	this->addChild(menu);
}

void DevList::menuCallBack(Ref *sender)
{
	auto itemSelect = (MenuItem*)sender;

	switch (itemSelect->getTag())
	{
	  case TAG_DEV_BACK:
	  {
		  Director::getInstance()->popScene();
		  break;
	  }
	}
}