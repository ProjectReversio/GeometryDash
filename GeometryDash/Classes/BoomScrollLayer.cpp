#include "BoomScrollLayer.h"

USING_NS_CC;

BoomScrollLayer::BoomScrollLayer()
{
    
}

BoomScrollLayer::~BoomScrollLayer()
{
    
}

bool BoomScrollLayer::init(cocos2d::CCArray* a1, int a2, bool a3, cocos2d::CCArray* a4, DynamicScrollDelegate* scroll)
{
    if (!CCLayer::init())
        return false;

    // TODO: Implement BoomScrollLayer::init

    return true;
}

void BoomScrollLayer::setPagesIndicatorPosition(cocos2d::CCPoint point)
{
    // TODO: Implement BoomScrollLayer::setPagesIndicatorPosition
}

void BoomScrollLayer::instantMoveToPage(int page)
{
    // TODO: Implement BoomScrollLayer::instantMoveToPage
}

BoomScrollLayer* BoomScrollLayer::create(cocos2d::CCArray* a1, int a2, bool a3, cocos2d::CCArray* a4, DynamicScrollDelegate* scroll)
{
    BoomScrollLayer* pRet = new BoomScrollLayer();
    if (pRet && pRet->init(a1, a2, a3, a4, scroll))
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

BoomScrollLayer* BoomScrollLayer::create(cocos2d::CCArray* a1, int a2, bool a3)
{
    return BoomScrollLayer::create(a1, a2, a3, nullptr, nullptr);
}
