#include "CCMenuItemSpriteExtra.h"

USING_NS_CC;

CCMenuItemSpriteExtra::CCMenuItemSpriteExtra()
{
    mCurrentScale = 0.0f;
    mAnimationType = MENU_ANIM_TYPE_SCALE;
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

    this->mCurrentScale = 1.0f;
    normalSprite->setAnchorPoint(CCPoint(0.5f, 0.5f));

    // TODO: Implement CCMenuItemSpriteExtra::init

    normalSprite->setPosition(normalSprite->getParent()->convertToNodeSpace(CCPoint(0.0f, 0.0f)));

    // TODO: Implement CCMenuItemSpriteExtra::init

    return true;
}

void CCMenuItemSpriteExtra::activate()
{
    if (!this->isEnabled())
        return;

    this->stopAllActions();
    if (this->mAnimationType == MENU_ANIM_TYPE_SCALE)
        this->setScale(mCurrentScale);

    // TODO: Implement CCMenuItemSpriteExtra::activate

    CCMenuItem::activate();
}

void CCMenuItemSpriteExtra::selected()
{
    if (!this->isEnabled())
        return;

    CCMenuItemSprite::selected();

    // TODO: Implement CCMenuItemSpriteExtra::selected
}

void CCMenuItemSpriteExtra::unselected()
{
    if (!this->isEnabled())
        return;

    CCMenuItemSprite::unselected();

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
