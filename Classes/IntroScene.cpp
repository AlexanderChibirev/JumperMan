#include "IntroScene.h"
#include "GameLevelScene.h"
#include "SimpleAudioEngine.h"
#include "OptionalScene.h"
USING_NS_CC;

bool CIntroScene::init()
{
  
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeLabel = Label::createWithTTF("Exit!", "fonts/Marker Felt.ttf", 24);
	auto closeItem = MenuItemLabel::create(closeLabel, CC_CALLBACK_1(CIntroScene::OnMenuClose, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
		origin.y + closeItem->getContentSize().height/2));
    auto playLabel = Label::createWithTTF("Play Now!", "fonts/Marker Felt.ttf",60);
    auto playItem = MenuItemLabel::create(playLabel, CC_CALLBACK_1(CIntroScene::OnMenuPlay, this));

    playItem->setPosition(Vec2(origin.x + 0.5f * visibleSize.width , origin.y + 0.8f * visibleSize.height));

	auto optionLabel = Label::createWithTTF("optional", "fonts/Marker Felt.ttf", 60);
	auto optionItem = MenuItemLabel::create(optionLabel, CC_CALLBACK_1(CIntroScene::OnOptionsPlay, this));

	optionItem->setPosition(Vec2(origin.x + 0.5f * visibleSize.width, origin.y + 0.8f * visibleSize.height - 100));



    auto menu = Menu::create(closeItem, playItem, optionItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto sprite = Sprite::create("forMenuScene/bgMenu.png");

	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

 
    this->addChild(sprite, 0);
    
    return true;
}


void CIntroScene::OnMenuClose(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void CIntroScene::OnMenuPlay(Ref *pSender)
{
    (void)pSender;
    Director::getInstance()->pushScene(make_scene<CGameLevelScene>());
}

void  CIntroScene::OnOptionsPlay(cocos2d::Ref* pSender)
{
	auto scene = OptionalScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(3.0f, scene));
}