#ifndef __SPLASHSCENE_SCENE_H__
#define __SPLASHSCENE_SCENE_H__

#include "cocos2d.h"
#include "IntroScene.h"
#include "cocos_custom.h"

class SplashScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	void goToIntroScene(float dt);
    CREATE_FUNC(SplashScene);
};

#endif // __SPLASHSCENE_SCENE_H__
