#pragma once
#include "cocos2d.h"

class Anime{
public:
	cocos2d::Animation * animation;
	cocos2d::Animate * animate;
	cocos2d::RepeatForever * load(char *a, int b);
};