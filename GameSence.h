#ifndef _GAME_SENCE_H_
#define _GAME_SENCE_H_

#define TAG_GAME_MENU   0
#define TAG_GAME_NEXT   1
#define TAG_GAME_BACK   2
#define TAG_GAME_SAVE   3
#define TAG_GAME_LOAD   4

#define TAG_GAME_TXTS    5
#define TAG_GAME_TXTBACK 6
#define TAG_GAME_FIGURE  7
#define TAG_GAME_BACKS   8

#define TAG_GAME_K1   9
#define TAG_GAME_K2   10

#define TAG_GAME_SELECTMENU   11

#include "cocos2d.h"

class GameSence : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameSence);

	void initMenu();
	void initMainGame();
	void menuCallBack(Ref *sender);
	void kunteBack(Ref *sender);
	void eachPlay(int loadCountBG, int loadCountBGM);
	void NextSence();
	void FirstSencePlay();
	void PrevSence();
};

#endif // !_GAME_SENCE_H_
