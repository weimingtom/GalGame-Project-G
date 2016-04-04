#include "CardGame.h"
#include "cardSetSence.h"
#include <cstdlib>
#include <ctime>

USING_NS_CC;

auto play1st=&CardPlayMain::playerPlay;
auto play2nd=&CardPlayMain::playerPlay;

//***********************data of game*******************************//
//easy hard select
extern bool levelOfCard;

//which is controlled by rand func for decide which one play the card first
int FristHandorSecond=0;
//when player push the end button ,startOne=1;
int startOne=0;
//psd for falishuijing
int psd = 0;

//blood
int playerBlood=30;
int computerBlood=30;

//pointer of button
MenuItemImage *skillbutton=nullptr;

Scene* CardPlayMain::createScene()
{
    auto scene = Scene::create();
    
    auto layer = CardPlayMain::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool CardPlayMain::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    initBackGround();
    initSelectMenu();
    initGame();
    initFirstSelectMenu();
    
    return true;
}

void CardPlayMain::initBackGround()
{
    auto backpage = Sprite::create("card/playBack.png");
    backpage->setAnchorPoint(Point(0, 0));
    backpage->setPosition(Point(0, 0));
    this->addChild(backpage);
}

void CardPlayMain::initSelectMenu()
{
    auto backButton = MenuItemImage::create("card/BackButton.png", "card/BackPush.png", CC_CALLBACK_1(CardPlayMain::menuCallBack, this));
    auto failButton = MenuItemImage::create("card/dead.png", "card/deadPush.png", CC_CALLBACK_1(CardPlayMain::menuCallBack, this));
    auto endButton = MenuItemImage::create("card/endButton.png", "card/endPush.png", CC_CALLBACK_1(CardPlayMain::menuCallBack, this));
    auto cardSeletButton=MenuItemImage::create("card/playerSelectCardButton.png","card/playerSelectCardButton.png",CC_CALLBACK_1(CardPlayMain::menuCallBack, this));
    auto skillUsebutton=MenuItemImage::create("card/skillUseButton.png","card/skillUsePush.png","card/skillUseLock.png",CC_CALLBACK_1(CardPlayMain::menuCallBack, this));
    auto setMenuButton=MenuItemImage::create("card/set.png","card/setPush.png",CC_CALLBACK_1(CardPlayMain::menuCallBack, this));
    
    skillbutton=skillUsebutton;
    
    backButton->setPosition(Point(-600, 330));
    failButton->setPosition(Point(580, 310));
    endButton->setPosition(Point(520,10));
    cardSeletButton->setPosition(Point(360,-270));
    skillUsebutton->setPosition(Point(136,-266));
    setMenuButton->setPosition(Point(-580,-320));
    
    backButton->setTag(TAG_CARDPALY_BACK);
    failButton->setTag(TAG_CARDPALY_FAIL);
    endButton->setTag(TAG_CARDPALY_END);
    cardSeletButton->setTag(TAG_CARDPLAY_CARDSELECTBUTTON);
    skillUsebutton->setTag(TAG_CARDPALY_SKILLUSEBUTTON);
    setMenuButton->setTag(TAG_CARDPLAY_SETMENUBUTTON);
    
    auto menu = Menu::create(backButton, failButton, endButton, cardSeletButton,skillUsebutton,setMenuButton,NULL);
    this->addChild(menu,99);
}

void CardPlayMain::initGame()
{
    //data init
    FristHandorSecond=0;
    startOne=0;
    psd = 0;
    
    playerBlood=30;
    computerBlood=30;
    
    //Mode Select
    srand((unsigned)time(0));
    FristHandorSecond=rand()%2;
    
    if(FristHandorSecond==0)
    {
        play1st=&CardPlayMain::playerPlay;
        
        if(levelOfCard==true)
        {
            play2nd=&CardPlayMain::computerPlayEasy;
        }
        else
        {
            play2nd=&CardPlayMain::computerPlayHard;
        }
    }
    else
    {
        
        play2nd=&CardPlayMain::playerPlay;
        
        if(levelOfCard==true)
        {
            play1st=&CardPlayMain::computerPlayEasy;
        }
        else
        {
            play1st=&CardPlayMain::computerPlayHard;
        }
    }
};

void CardPlayMain::initFirstSelectMenu()
{
    
}

void CardPlayMain::menuCallBack(Ref *sender)
{
    auto itemSelect = (MenuItem*)sender;
    
    switch (itemSelect->getTag())
    {
        case TAG_CARDPALY_FAIL:
        {
            auto rick=Sprite::create("card/YN.png");
            rick->setPosition(Point(640,360));
            rick->setTag(TAG_CARDPALY_YNMENU);
            this->addChild(rick);
            
            auto yesButton = MenuItemImage::create("card/yesButton.png", "card/yesPush.png", CC_CALLBACK_1(CardPlayMain::YNmenuCallBack, this));
            auto noButton = MenuItemImage::create("card/noButton.png", "card/noPush.png", CC_CALLBACK_1(CardPlayMain::YNmenuCallBack, this));
            
            yesButton->setPosition(Point(0, 120));
            noButton->setPosition(Point(0, -120));
            
            yesButton->setTag(TAG_CARDPALY_YES);
            noButton->setTag(TAG_CARDPALY_NO);
            
            auto menu = Menu::create(yesButton, noButton, NULL);
            menu->setTag(TAG_CARDPALY_YNMENUBUTTON);
            this->addChild(menu,100);
        }
        break;
        
            
        case TAG_CARDPALY_BACK:
        {
            Director::getInstance()->popScene();
        }
        break;
            
        case TAG_CARDPALY_END:
        {
            startOne=1;
        }
        break;
            
        case TAG_CARDPLAY_CARDSELECTBUTTON:
        {
           
        }
        break;
            
        case TAG_CARDPALY_SKILLUSEBUTTON:
        {
            skillbutton->setEnabled(false);
        }
        break;
            
        case TAG_CARDPLAY_SETMENUBUTTON:
        {
            Director::getInstance()->pushScene(cardSetMenu::createScene());
        }
        break;
    }
    
}

void CardPlayMain::firstMenuCallBack(Ref *sender)
{
    
}

void CardPlayMain::YNmenuCallBack(Ref *sender)
{
    auto itemSelect = (MenuItem*)sender;
    
    switch (itemSelect->getTag())
    {
        case TAG_CARDPALY_YES:
        {
            Director::getInstance()->popScene();
            Director::getInstance()->pushScene(CardPlayMain::createScene());
        }
            
        case TAG_CARDPALY_NO:
        {
            removeChildByTag(TAG_CARDPALY_YNMENU, true);
            removeChildByTag(TAG_CARDPALY_YNMENUBUTTON, true);
        }
    }
}

void CardPlayMain::computerPlayEasy()
{
    
}

void CardPlayMain::computerPlayHard()
{
    
}

void CardPlayMain::playerPlay()
{
    
}

void CardPlayMain::EachPlay()
{
    skillbutton->setEnabled(true);
    for(;;)
    {
        if(psd<10)
        {
            ++psd;
        }
        
        (this->*play1st)();
        
        (this->*play2nd)();
    }
}
