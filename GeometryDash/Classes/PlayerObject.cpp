#include "PlayerObject.h"

USING_NS_CC;

PlayerObject::PlayerObject()
{
    
}

PlayerObject::~PlayerObject()
{
    
}

bool PlayerObject::init(int a2, int a3, cocos2d::CCLayer* layer)
{
    // TODO: Implement PlayerObject::init

    return true;
}

PlayerObject* PlayerObject::create(int a2, int a3, cocos2d::CCLayer* layer)
{
    PlayerObject* pRet = new PlayerObject();
    if (pRet && pRet->init(a2, a3, layer))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}
