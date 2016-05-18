#include "HeroPuppet.h"
#include "Resources.h"

USING_NS_CC;

bool CHeroPuppet::init(IMapPhysics & mapPhysics)
{
    if (!CPuppet::init(mapPhysics))
    {
        return false;
    }
	m_body = Sprite::create(res::C_SPRITE_HERO);
	return true;
}

void CHeroPuppet::onEnter()
{
    CPuppet::onEnter();
    addChild(m_body);
	auto physicsBody = PhysicsBody::createBox(Size(65.0f, 81.0f), PhysicsMaterial(0.1f, 1.0f, 0.0f));
	physicsBody->setDynamic(false);
	m_body->setPhysicsBody(physicsBody);
	
}

void CHeroPuppet::onExit()
{
    m_body->removeFromParentAndCleanup(true);
    CPuppet::onExit();
}

void CHeroPuppet::update(float delta)
{
    CPuppet::update(delta);
    if (m_afterUpdate)
    {
        m_afterUpdate();
    }
}

void CHeroPuppet::DoAfterUpdate(const std::function<void()> &func)
{
    m_afterUpdate = func;
}
