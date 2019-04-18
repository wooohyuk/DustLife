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

	static cocos2d::Scene* createScene();  //�� ���� >> ��������

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
	int ps = 1; //�÷��̾� �����
	int ep = 0; //���� ���� ��
	int point=0; 
	float pSize=0.15; //�÷��̾� ������
	float pspeed = 600; // �÷��̾� ���ǵ�
	
	


	cocos2d::Sprite * sprite;
	cocos2d::Sprite * sprite3;
	cocos2d::Sprite * sprite2;

	CREATE_FUNC(InGame); 

	clock_t moveOldtime;
};

