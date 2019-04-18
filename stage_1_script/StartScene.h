#pragma once

#include "cocos2d.h"



class Start : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);

	cocos2d::Sprite * sprite;
	cocos2d::Sprite * sprite2;

	CREATE_FUNC(Start);

	cocos2d::EventListenerTouchAllAtOnce * listener;
};
