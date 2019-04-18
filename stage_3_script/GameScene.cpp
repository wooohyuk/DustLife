#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace CocosDenshion;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}


bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("godd.mp3");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("godd.mp3", true);

	auto visibleSize = Director::getInstance()->getVisibleSize();

	sprite = Sprite::create("cell/dust/1.png");
	sprite->setAnchorPoint(Point(0.5, 0.5));
	sprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	sprite->setScale(0.15);

	sprite2 = Sprite::create("gods.png");
	sprite2->setAnchorPoint(Point(0.5, 0.5));
	sprite2->setPosition(Point(0, visibleSize.height -250));
	sprite2->setScale(0.15);

	sprite3 = Sprite::create("god.png");
	sprite3->setAnchorPoint(Point(0, 0));

	srand(time(NULL));

	this->addChild(sprite3, 0);
	this->addChild(sprite, 2);
	this->addChild(sprite2, 2);


	listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(GameScene::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(GameScene::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GameScene::onTouchesEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	scheduleUpdate();

	sprite->runAction(AG->load("cell/dust/", 4));
	this->schedule(schedule_selector(GameScene::setMissile), 0.3);
	GameScene::setgods();
	return true;
}

void GameScene::onTouchesBegan(const std::vector<Touch*>&touches, Event* unused_event)
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


		MoveBy* move = MoveBy::create(sqrt(((x*x) + (y*y))) / 600.f, Point(-x, -y));
		move->setTag(1);
		sprite->runAction(move);

	}
	moveOldtime = clock();

}

void GameScene::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * unused_event)
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
			MoveBy* move = MoveBy::create(sqrt(((x*x) + (y*y))) /600.f, Point(-x, -y));
			move->setTag(1);
			sprite->runAction(move);

		}
		moveOldtime = clock();
	}
}

void GameScene::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * unused_event)
{
}

void GameScene::setMissile(float delta) {
	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto sprMissile = Sprite::create("3.png");
	sprMissile->setScale(0.15);
	sprMissile->setRotation(180);
	sprMissile->setPosition(sprite2->getPosition() + Point(-1, -100));
	this->addChild(sprMissile);

	auto action = Sequence::create(MoveBy::create (1.0, Point(0, -1080)), MoveBy::create(1.0, Point(0, -1080)), NULL);
	sprMissile->runAction(action);
}

void GameScene::resetMissile(Ref *sender) {
	auto sprMissile = (Sprite*)sender;
	this->removeChild(sprMissile);
}


void GameScene::setgods() {
	auto action2= Sequence::create(MoveBy::create(5.0, Point(1920, 0)), MoveBy::create(5.0, Point(-1920, 0)), NULL);
	auto action3 = RepeatForever::create(action2);
	sprite2->runAction(action3);
}
void GameScene::update(float dt)
{
	if (sprite->getPositionY() >= 1000) {
		unschedule(schedule_selector(GameScene::setMissile));
		this->removeChild(sprite);
		this->removeChild(sprite2);
		sprite4 = Sprite::create("4.png");
		sprite4->setAnchorPoint(Point(0, 0));
		this->addChild(sprite4);
	}
	else {
		sprite4 = Sprite::create("4.png");
	}
	
}