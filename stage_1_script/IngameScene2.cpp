#include "InGameScene2.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

Scene* InGame2::createScene()
{
	auto scene = Scene::create();

	auto layer = InGame2::create();

	scene->addChild(layer);

	return scene;
}


bool InGame2::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//SimpleAudioEngine::getInstance()->preloadBackgroundMusic("ocean.mp3");
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("ocean.mp3", true);

	auto visibleSize = Director::getInstance()->getVisibleSize();

	sprite = Sprite::create("cell/dust/1.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	sprite->setScale(0.15);


	sprite3 = Sprite::create("BackScreen/ocean.jpg");
	sprite3->setAnchorPoint(Point(0, 0));
	sprite3->setScale(2);

	Eadd(1);
	srand(time(NULL));

	this->addChild(sprite3, 0);
	this->addChild(sprite, 2);

	initScore();

	listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(InGame2::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(InGame2::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(InGame2::onTouchesEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	scheduleUpdate();

	sprite->runAction(AG->load("cell/dust/", 4));

	return true;
}

void InGame2::initScore() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto labelScore = Label::createWithSystemFont("Eat Point : 50", "fonts/a몬스터.ttf", 35);
	labelScore->setAnchorPoint(Point(0, 1));
	labelScore->setPosition(Point(10, visibleSize.height - 10));
	labelScore->setColor(Color3B::WHITE);
	labelScore->setTag(TAG_LABEL_SCORE);
	this->addChild(labelScore, 100);

	auto labelSize = Label::createWithSystemFont("Dust Size Level : 11", "fonts/a몬스터.ttf", 35);
	labelSize->setAnchorPoint(Point(1, 1));
	labelSize->setPosition(Point(visibleSize.width - 15, visibleSize.height - 10));
	labelSize->setColor(Color3B::WHITE);
	labelSize->setTag(TAG_LABEL_SIZE);
	this->addChild(labelSize, 100);
}

void InGame2::addScore(int add, int add2) {
	ep += add;
	auto labelScore = (Label*)this->getChildByTag(TAG_LABEL_SCORE);
	labelScore->setString(StringUtils::format("Eat Point : %d", ep));
	ps += add2;
	auto labelSize = (Label*)this->getChildByTag(TAG_LABEL_SIZE);
	labelSize->setString(StringUtils::format("Dust Size Level : %d", ps));
}

void InGame2::onTouchesBegan(const std::vector<Touch*>&touches, Event* unused_event)
{
	sprite->stopActionByTag(1);
	for (auto iter = touches.begin(); iter != touches.end(); iter++)
	{
		Touch* touch = (Touch*)*iter;
		Point touchStart = touch->getLocation();

		CCPoint aVector = ccpSub(touchStart, sprite->getPosition());
		float radAngle = ccpToAngle(aVector);
		float degreeAngle = CC_RADIANS_TO_DEGREES(-1 * radAngle);

		float speed = 180 / 0.1;

		float duration = fabsf(degreeAngle / speed);

		CCActionInterval* actRotate = CCRotateTo::create(0.000001f, degreeAngle - 90);
		sprite->runAction(actRotate);

		float x = sprite->getPositionX() - touchStart.x;
		float y = sprite->getPositionY() - touchStart.y;


		MoveBy* move = MoveBy::create(sqrt(((x*x) + (y*y))) / pspeed, Point(-x, -y));
		move->setTag(1);
		sprite->runAction(move);

	}
	moveOldtime = clock();

}

void InGame2::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * unused_event)
{
	clock_t curtime = clock();
	if (curtime - moveOldtime >= 100) {
		sprite->stopActionByTag(1);
		for (auto iter = touches.begin(); iter != touches.end(); iter++)
		{
			Touch* touch = (Touch*)*iter;
			Point touchStart = touch->getLocation();

			CCPoint aVector = ccpSub(touchStart, sprite->getPosition());
			float radAngle = ccpToAngle(aVector);
			float degreeAngle = CC_RADIANS_TO_DEGREES(-1 * radAngle);

			float speed = 180 / 0.5;

			float duration = fabsf(degreeAngle / speed);

			CCActionInterval* actRotate = CCRotateTo::create(0.000001f, degreeAngle - 90);
			sprite->runAction(actRotate);

			float x = sprite->getPositionX() - touchStart.x;
			float y = sprite->getPositionY() - touchStart.y;
			MoveBy* move = MoveBy::create(sqrt(((x*x) + (y*y))) / 600.f, Point(-x, -y));
			move->setTag(1);
			sprite->runAction(move);

		}
		moveOldtime = clock();
	}
}

void InGame2::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * unused_event)
{
}

void InGame2::Eadd(float dt) {
	g = g + 1;
	Enemy2 enemy;
	srand(time(NULL));
	int ab = rand() % 10 + 1;
	enemy.number = ab;
	enemy.aa();
	this->addChild(enemy.spriteE, 1);
	enemyVec.push_back(enemy);
}




void InGame2::update(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	if (sprite->getPositionX() >= 1260 && sprite3->getPositionX()>-6880 + 1920) {
		float x = sprite->getPositionX() - 1260;
		sprite3->setPositionX(sprite3->getPositionX() - x);
		sprite->setPositionX(1260);
		for (std::vector<Enemy2>::iterator iter = enemyVec.begin(); iter != enemyVec.end(); iter++) {
			(*iter).spriteE->setPositionX((*iter).spriteE->getPositionX() - x);
		}
	}
	if (sprite->getPositionX() <= 660 && sprite3->getPositionX() < 0) {
		float x = sprite->getPositionX() - 660;
		sprite3->setPositionX(sprite3->getPositionX() - x);
		sprite->setPositionX(660);
		for (std::vector<Enemy2>::iterator iter = enemyVec.begin(); iter != enemyVec.end(); iter++) {
			(*iter).spriteE->setPositionX((*iter).spriteE->getPositionX() - x);
		}
	}
	if (sprite->getPositionY() >= 690 && sprite3->getPositionY() > -3440 + 1080) {
		float y = sprite->getPositionY() - 690;
		sprite3->setPositionY(sprite3->getPositionY() - y);
		sprite->setPositionY(690);
		for (std::vector<Enemy2>::iterator iter = enemyVec.begin(); iter != enemyVec.end(); iter++) {
			(*iter).spriteE->setPositionY((*iter).spriteE->getPositionY() - y);
		}
	}
	if (sprite->getPositionY() <= 480 && sprite3->getPositionY() < 0) {
		float y = sprite->getPositionY() - 480;
		sprite3->setPositionY(sprite3->getPositionY() - y);
		sprite->setPositionY(480);
		for (std::vector<Enemy2>::iterator iter = enemyVec.begin(); iter != enemyVec.end(); iter++) {
			(*iter).spriteE->setPositionY((*iter).spriteE->getPositionY() - y);
		}
	}
	if (g < 200)
		schedule(schedule_selector(InGame2::Eadd), 0.6);
	if (g == 200)
		unschedule(schedule_selector(InGame2::Eadd));


	for (std::vector<Enemy2>::iterator iter = enemyVec.begin(); iter != enemyVec.end(); iter++) {
		if ((*iter).spriteE->getActionManager()->getNumberOfRunningActionsInTarget((*iter).spriteE) == 1)
			(*iter).ii();
	}
	for (std::vector<Enemy2>::iterator iter = enemyVec.begin(); iter != enemyVec.end();) {
		if ((*iter).spriteE != NULL) {
			Rect playerRect = sprite->getBoundingBox();
			Rect enemyRect = (*iter).spriteE->getBoundingBox();
			playerRect.setRect(playerRect.origin.x + 40, playerRect.origin.y + 40, playerRect.size.width - 80, playerRect.size.height - 80);
			if (playerRect.intersectsRect(enemyRect)) {

				if ((*iter).es > ps) {
					sprite2 = Sprite::create("death.png");
					sprite2->setAnchorPoint(Point(0.5, 0.5));
					sprite2->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
					this->addChild(sprite2, 4);
					SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
					(*iter).spriteE = NULL;
					iter = enemyVec.erase(iter);
				}
				else {
					removeChild((*iter).spriteE, true);
					g = g - 1;
					addScore(1, 0);
					(*iter).spriteE = NULL;
					iter = enemyVec.erase(iter);
					if (ep == 55 || ep == 60 || ep == 75 || ep == 80 || ep == 85 || ep == 90 || ep == 95 || ep == 105 || ep == 110) {
						addScore(0, 1);
						pSize = pSize + 0.03;
						sprite->setScale(pSize);
						pspeed = pspeed + 50;
					}
				} 
			}
			else {
				++iter;
			}
		}
		else {
			++iter;
		}
	}
}