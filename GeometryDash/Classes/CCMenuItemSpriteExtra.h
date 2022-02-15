#ifndef __CCMENUITEMSPRITEEXTRA_H__
#define __CCMENUITEMSPRITEEXTRA_H__

#include "cocos2d.h"

typedef enum
{
    MENU_ANIM_TYPE_SCALE = 0,
    MENU_ANIM_TYPE_1 = 1,
} MenuAnimationType;

class CCMenuItemSpriteExtra : public cocos2d::CCMenuItemSprite
{
public:
    CCMenuItemSpriteExtra();
    ~CCMenuItemSpriteExtra() override;

    void selected() override;
    void activate() override;
    void unselected() override;
    void useAnimationType(MenuAnimationType type);
    void setSizeMult(float size);
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(cocos2d::CCNode* normalSprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);

    static CCMenuItemSpriteExtra* create(cocos2d::CCNode* normalSprite, cocos2d::CCNode* selectedSprite, cocos2d::CCObject* target, cocos2d::SEL_MenuHandler selector);

protected:
    MenuAnimationType mAnimationType;
    cocos2d::CCPoint mUnknownPoint1;
    float mCurrentScale;
};

#endif // __CCMENUITEMSPRITEEXTRA_H__
