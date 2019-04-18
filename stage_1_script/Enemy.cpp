#pragma once
#include "Enemy.h"

USING_NS_CC;

void Enemy::aa()
{
	int ex = rand() % 8192;
	int ey = rand() % 4608;
	if (number == 1) {
		spriteE = Sprite::create("cell/Pcell/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.18);
		es = 5;
		spriteE->runAction(EA->load("cell/Pcell/", 4));
		Espeed = 320;
		ag = 90;

	}
	else if (number == 2) {
		spriteE = Sprite::create("cell/Acell/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.22);
		es = 6;
		spriteE->runAction(EA->load("cell/Acell/", 4));
		Espeed = 300;
		ag = 90;
	}
	else if (number == 3) {
		spriteE = Sprite::create("cell/Ameba/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.15);
		es = 2;
		spriteE->runAction(EA->load("cell/Ameba/", 4));
		Espeed = 380;
		ag = 180;
	}
	else if (number == 4) {
		spriteE = Sprite::create("cell/Cold/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.28);
		es = 7;
		spriteE->runAction(EA->load("cell/Cold/", 4));
		Espeed = 280;
		ag = 90;
	}
	else if (number == 5) {
		spriteE = Sprite::create("cell/Nanja/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.26);
		es = 8;
		spriteE->runAction(EA->load("cell/Nanja/", 4));
		Espeed = 260;
		ag = 90;
	}
	else if (number == 6) {
		spriteE = Sprite::create("cell/Red/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.14);
		es = 3;
		spriteE->runAction(EA->load("cell/Red/", 4));
		Espeed = 360;
		ag = 90;
	}
	else if (number == 7) {
		spriteE = Sprite::create("cell/White/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.18);
		es = 4;
		spriteE->runAction(EA->load("cell/White/", 4));
		Espeed = 340;
		ag = 90;
	}
	else if (number == 8) {
		spriteE = Sprite::create("cell/Sperm/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.2);
		es = 1;
		spriteE->runAction(EA->load("cell/Sperm/", 4));
		Espeed = 400;
		ag = 0;
	}
	else if (number == 9) {
		spriteE = Sprite::create("cell/Tcell/1.png");
		spriteE->setAnchorPoint(Point(0.5, 0.5));
		spriteE->setPosition(Point(ex, ey));
		spriteE->setScale(0.32);
		es = 9;
		spriteE->runAction(EA->load("cell/Tcell/", 4));
		Espeed = 240;
		ag = 90;
	} //수정난자추가하기 정자만 따로 spriteE2같은 곳에 받아서 플레이어처럼 충돌처리해주기
	ii();
}

void Enemy::ii() {
	int ia = random() % 7800 + 200;
	int ib = random() % 3800 + 200;
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