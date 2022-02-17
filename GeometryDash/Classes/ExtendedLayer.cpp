#include "ExtendedLayer.h"

USING_NS_CC;

ExtendedLayer::ExtendedLayer()
{
    mUnknown3 = nullptr;
}

ExtendedLayer::~ExtendedLayer()
{
    
}

bool ExtendedLayer::init()
{
    if (!CCLayer::init())
        return false;

    return true;
}

void ExtendedLayer::setPosition(const cocos2d::CCPoint& position)
{
    CCLayer::setPosition(position);

    // TODO: We don't know what type mUnknown3 should be, so we can't do the following code, setPosition is assumed.
    //if (mUnknown3)
    //    mUnknown3->setPosition(position);
}
