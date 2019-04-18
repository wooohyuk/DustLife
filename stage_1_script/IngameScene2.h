#pragma once
#include "Anime.h"
#include "cocos2d.h"
#include "Enemy2.h"

#define TAG_LABEL_SCORE  1001
#define TAG_LABEL_SIZE  1002




class InGame2 : public cocos2d::Layer
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
	void addScore(int add, int add2);

	void InGame2::Eadd(float dt);

	std::vector<Enemy2> enemyVec;

	Anime*AG;
	Enemy2*EE;

	int g = 0;
	int ps = 11; //플레이어 사이즈값
	int ep = 50; //적을 먹은 수
	int point = 0;
	float pSize = 0.15; //플레이어 사이즈
	float pspeed = 600; // 플레이어 스피드

	cocos2d::Sprite * sprite;
	cocos2d::Sprite * sprite3;
	cocos2d::Sprite * sprite2;

	CREATE_FUNC(InGame2);

	clock_t moveOldtime;
};