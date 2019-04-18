#pragma once
#include "Anime.h"

USING_NS_CC;

RepeatForever * Anime::load(char *a, int b) {
	Animation * animation = Animation::create();
	animation->setDelayPerUnit(0.3f);
	for (int i = 1; i <= b; i++) {
		animation->addSpriteFrameWithFile(StringUtils::format("%s%d.png",a, i));
	}
	Animate * animate = Animate::create(animation);
	RepeatForever * repeatForever = RepeatForever::create(animate);
	return repeatForever;
}
