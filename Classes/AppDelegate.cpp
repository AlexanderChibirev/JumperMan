#include "AppDelegate.h"
#include "SplashScene.h"
#include "GameLevelScene.h"
USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate() 
{
}
void AppDelegate::initGLContextAttrs()
{
	GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview)
	{
        glview = GLViewImpl::createWithRect("LittlePrince", Rect(0, 0, 1280, 720));
        director->setOpenGLView(glview);
    }

    director->getOpenGLView()->setDesignResolutionSize(1280, 720, ResolutionPolicy::SHOW_ALL);
    director->setDisplayStats(true);
    director->setAnimationInterval(float(1.0) / 60);

    FileUtils::getInstance()->addSearchPath("res");

	auto scene = (make_scene<CGameLevelScene>());
    //auto scene = SplashScene::createScene();

    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() 
{
    Director::getInstance()->stopAnimation();
}


void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
}
