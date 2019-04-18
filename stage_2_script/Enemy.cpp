#pragma once
#include "Enemy.h"

USING_NS_CC;

void Enemy::aa()
{
	int ex = rand() % 6880;
	int ey = rand() % 3440;
	if (number == 1) {
		spriteE = Sprite::create("sea/lucky/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.18);
		es = 15;
		spriteE->runAction(EA->load("sea/lucky/", 10));
		Espeed = 320;
		ag = 180;

	}
	else if (number == 2) {
		spriteE = Sprite::create("sea/blob/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.22);
		es = 16;
		spriteE->runAction(EA->load("sea/blob/", 2));
		Espeed = 50;
		ag = 270;
	}
	else if (number == 3) {
		spriteE = Sprite::create("sea/shrimp/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.10);
		es = 12;
		spriteE->runAction(EA->load("sea/shrimp/", 2));
		Espeed = 150;
		ag = 180;
	}
	else if (number == 4) {
		spriteE = Sprite::create("sea/blue/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.28);
		es = 17;
		spriteE->runAction(EA->load("sea/blue/", 2));
		Espeed = 1000;
		ag = 180;
	}
	else if (number == 5) {
		spriteE = Sprite::create("sea/turtle/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.3);
		es = 18;
		spriteE->runAction(EA->load("sea/turtle/", 2));
		Espeed = 300;
		ag = 180;
	}
	else if (number == 6) {
		spriteE = Sprite::create("sea/mdz/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.14);
		es = 13;
		spriteE->runAction(EA->load("sea/mdz/", 2));
		Espeed = 100;
		ag = 270;
	}
	else if (number == 7) {
		spriteE = Sprite::create("sea/fish/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.16);
		es = 14;
		spriteE->runAction(EA->load("sea/fish/", 2));
		Espeed = 250;
		ag = 180;
	}
	else if (number == 8) {
		spriteE = Sprite::create("sea/srabbit/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.08);
		es = 11;
		spriteE->runAction(EA->load("sea/srabbit/", 2));
		Espeed = 200;
		ag = 180;
	}
	else if (number == 9) {
		spriteE = Sprite::create("sea/dog.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.32);
		es = 19;
		Espeed = 240;
		ag = 180;
	} 
	else if (number == 10) {
		spriteE = Sprite::create("sea/shark/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.36);
		es = 20;
		spriteE->runAction(EA->load("sea/shark/", 2));
		Espeed = 240;
		ag = 180;
	}
	ii();
}

void Enemy::ii() {
	int ia = random() % 6880 + 200;
	int ib = random() % 3440 + 200;
	Point iStart = Point(ia, ib);
	CCPoint aVector = ccpSub(iStart, spriteE->getPosition());
	float radAngle = ccpToAngle(aVector);
	float degreeAngle = CC_RADIANS_TO_DEGREES(-1 * radAngle);

	float speed = 180 / 0.1;

	float duration = fabsf(degreeAngle / speed);

	CCActionInterval* actRotate = CCRotateTo::create(0.000001, degreeAngle - ag);
	spriteE->runAction(actRotate);

	float xx = spriteE->getPositionX() - iStart.x;
	float yy = spriteE->getPositionY() - iStart.y;

	auto act1 = MoveTo::create(sqrt(((xx*xx) + (yy*yy))) / Espeed, iStart);
	act1->setTag(1);
	spriteE->runAction(act1);
}