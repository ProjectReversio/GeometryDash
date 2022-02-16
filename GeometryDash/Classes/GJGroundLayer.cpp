#include "GJGroundLayer.h"

USING_NS_CC;

GJGroundLayer::GJGroundLayer()
{
    
}

GJGroundLayer::~GJGroundLayer()
{
    
}

GJGroundLayer* GJGroundLayer::create(int texture, int a2)
{
    GJGroundLayer* pRet = new GJGroundLayer();
    if (pRet && pRet->init(texture, a2))
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

bool GJGroundLayer::init(int texture, int a2)
{
    if (!CCLayer::init())
        return false;

    // TODO: Implement GJGroundLayer::init

    return true;
}

void GJGroundLayer::positionGround(float position)
{
    // TODO: Implement GJGroundLayer::positionGround
}
