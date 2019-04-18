#include "cocos2d.h"
#include "Anime.h"

#define TAG_SPRITE_PLAYER 1000

class GameScene : public cocos2d::Layer
{
public:
	void update(float dt);

	static cocos2d::Scene* createScene();  //æ¿ ∏∏µÍ >> ∏Æ≈œ«ÿ¡‹

	virtual bool init();
	virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
	cocos2d::EventListenerTouchAllAtOnce * listener;

	void setMissile(float delta);
	void resetMissile(Ref *sender);
	void setgods();

	Anime*AG;

	cocos2d::Sprite * sprite;
	cocos2d::Sprite * sprite3;
	cocos2d::Sprite * sprite2;
	cocos2d::Sprite * sprite4;
	CREATE_FUNC(GameScene);

	clock_t moveOldtime;
};