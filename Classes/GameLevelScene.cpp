#include "GameLevelScene.h"
#include "SimpleAudioEngine.h"
#include "EnemyPuppet.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool CGameLevelScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    m_customMap = make_node<CCustomMap>("tmx/layer_1.tmx");
    addChild(m_customMap);
    m_customMap->setScale(2.0f);
    SpawnHero();
    SpawnEnemies();
    
    return true;
}

Vec2 CGameLevelScene::GetHeroPosition() const
{
    return m_hero->GetCenterInWorld();
}

IMapPhysics &CGameLevelScene::GetMap()
{
    return *m_customMap;
}

void CGameLevelScene::SpawnHero()
{
    m_hero = make_node<CHeroPuppet>(*m_customMap);
    m_hero->DoAfterUpdate([this]() {;
        Vec2 pos = m_hero->getPosition();
        setPosition(-pos + 0.5f * Vec2(getContentSize()));
    });
    m_hero->setPosition(convertToNodeSpace(m_customMap->GetHeroWorldPosition()));
    m_heroPuppeteer = std::make_unique<CHeroPuppeteer>();
    m_heroPuppeteer->SetPuppet(m_hero);
	;
	for (auto &it : m_customMap->GetObcaslePosition())
	{
		auto physicsBody = PhysicsBody::createBox(Size(it.size.width + 32, it.size.height + 32), PhysicsMaterial(0.1f, 1.0f, 0.0f));
		physicsBody->setDynamic(false);
		cocos2d::Sprite* _mySprite = cocos2d::Sprite::create();
		_mySprite->setPhysicsBody(physicsBody);
		_mySprite->setPosition(it.origin.x+ 300, it.origin.y + 400);
		addChild(_mySprite);
	}
    addChild(m_hero);
}

void CGameLevelScene::SpawnEnemies()
{
    for (const Vec2 &pos : m_customMap->GetEnemyWorldPositions())
    {
        auto enemy = make_node<CEnemyPuppet>(*m_customMap);
        enemy->setPosition(convertToNodeSpace(pos));
        auto puppeteer = std::make_unique<CEnemyPuppeteer>(*this);
        puppeteer->SetPuppet(enemy);
        addChild(enemy);
        m_enemyPuppeteers.emplace_back(std::move(puppeteer));
    }
}
