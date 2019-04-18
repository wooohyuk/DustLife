#include "AppDelegate.h"
#include "StartScene.h"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

//static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
//static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
//static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
//static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
#if USE_AUDIO_ENGINE
	AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::end();
#endif
}

void AppDelegate::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}


static int register_all_packages()
{
	return 0; 
}

bool AppDelegate::applicationDidFinishLaunching() {
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("DustLife", cocos2d::Rect(0, 0, 1920, 1080));
		//glview = GLViewImpl::createWithFullScreen("DustLife");  //�̰� �ּ�ó���ϰ� ���� �ּ�Ǯ�� â���
#else
		glview = GLViewImpl::create("DustLife");
#endif
		director->setOpenGLView(glview);
	}
	//auto framesize = glview->getFrameSize();
//	glview->setDesignResolutionSize(framesize.width, framesize.height, kResolutionShowAll);  // ���� ���� �ּ�ó���ϸ� â���
	
	// turn on display FPS ���ϰ��� �Ⱥ��ϰ��� false �� �ٲٸ� �ȶ�
	director->setDisplayStats(false);

	director->setAnimationInterval(1.0f / 60);

	auto scene = Start::createScene();

	director->runWithScene(scene);  //director ���� ����

	return true;
}

void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
	AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
	AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
