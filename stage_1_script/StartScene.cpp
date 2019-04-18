#include "StartScene.h"
#include "InGameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* Start::createScene()
{
	auto scene = Scene::create();

	auto layer = Start::create();

	scene->addChild(layer);

	return scene;
}

bool Start::init()
{
	if (!Layer::init())
	{
		return false;
	}
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("start.mp3");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("start.mp3", true);

	auto visibleSize = Director::getInstance()->getVisibleSize();

	sprite = Sprite::create("/BackScreen/start.png");
	sprite->setAnchorPoint(Point(0, 0));
	
	sprite2 = Sprite::create("/BackScreen/text.png");
	sprite2->setAnchorPoint(Point(0.5, 0.5));
	sprite2->setPosition(Point(visibleSize.width / 2, visibleSize.height / 4.5));


	this->addChild(sprite);
	this->addChild(sprite2);

	auto action = Blink::create(3.0, 5);
	RepeatForever * repeatForever = RepeatForever::create(action);
	sprite2->runAction(repeatForever);

	listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(Start::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(Start::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(Start::onTouchesEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
	
	return true;
}

void Start::onTouchesBegan(const std::vector<Touch*>&touches, Event* unused_event)
{

}
void Start::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * unused_event)
{
}
void Start::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event * unused_event)
{
	//auto scene = InGame::createScene(); //auto scene = TransitionPageTurn::create(1.0, InGame::createScene(),0);전환하고 잠시동안 안움직이는 현상 수정 화면넘김효과 먼지들어가는장면에서는살짝다름
	Director::getInstance()->replaceScene(InGame::createScene());
	Director::getInstance()->getEventDispatcher()->removeEventListener(listener);
	
}
