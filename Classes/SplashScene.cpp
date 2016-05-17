#include "SplashScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SplashScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SplashScene::create();
    scene->addChild(layer);

    return scene;
}

bool SplashScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
	this->scheduleOnce(schedule_selector(SplashScene::goToIntroScene), 3.0f);
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
    return true;
}

void SplashScene::goToIntroScene(float dt)
{
	auto scene = make_scene<CIntroScene>();
	Director::getInstance()->replaceScene(TransitionFade::create(3.0f, scene));
}