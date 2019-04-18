#pragma once
#include "Anime.h"
#include "cocos2d.h"
#include "Enemy.h"

#define TAG_LABEL_SCORE  1001
#define TAG_LABEL_SIZE  1002
#define TAG_LABEL_GG  1003

class InGame : public cocos2d::Layer
{
public:
	void update(float dt);

	static cocos2d::Scene* createScene();  //씬 만듦 >> 리턴해줌

	virtual bool init();  
	virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	cocos2d::EventListenerTouchAllAtOnce * listener;
	void initScore();
	void addScore(int add,int add2);

	void InGame::Eadd(float dt);

	std::vector<Enemy> enemyVec;

	Anime*AG;
	Enemy*EE;

	int g=0;
	int ps = 1; //플레이어 사이즈값
	int ep = 0; //적을 먹은 수
	int point=0; 
	float pSize=0.15; //플레이어 사이즈
	float pspeed = 600; // 플레이어 스피드
	
	


	cocos2d::Sprite * sprite;
	cocos2d::Sprite * sprite3;
	cocos2d::Sprite * sprite2;

	CREATE_FUNC(InGame); 

	clock_t moveOldtime;
};

