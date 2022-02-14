#include "CCMenuItemSpriteExtra.h"

USING_NS_CC;

CCMenuItemSpriteExtra::CCMenuItemSpriteExtra()
{
    mAnimationType = MENU_ANIM_TYPE_0;
    mUnknownPoint1 = CCPoint();
}

CCMenuItemSpriteExtra::~CCMenuItemSpriteExtra()
{
    
}

CCMenuItemSpriteExtra* CCMenuItemSpriteExtra::create(cocos2d::CCNode* normalSprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector)
{
    CCMenuItemSpriteExtra* pRet = new CCMenuItemSpriteExtra();
    if (pRet && pRet->init(normalSprite, selectedSprite, target, selector))
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

bool CCMenuItemSpriteExtra::init(cocos2d::CCNode* normalSprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector)
{
    if (!CCMenuItemSprite::initWithNormalSprite(normalSprite, selectedSprite, nullptr, target, selector))
        return false;

    // TODO: Implement CCMenuItemSpriteExtra::init

    return true;
}

void CCMenuItemSpriteExtra::activate()
{
    // TODO: Implement CCMenuItemSpriteExtra::activate
}

void CCMenuItemSpriteExtra::selected()
{
    // TODO: Implement CCMenuItemSpriteExtra::selected
}

void CCMenuItemSpriteExtra::unselected()
{
    // TODO: Implement CCMenuItemSpriteExtra::unselected
}

void CCMenuItemSpriteExtra::setSizeMult(float size)
{
    // TODO: Implement CCMenuItemSpriteExtra::setSizeMult
}

void CCMenuItemSpriteExtra::useAnimationType(MenuAnimationType type)
{
    // TODO: Implement CCMenuItemSpriteExtra::useAnimationType
}
