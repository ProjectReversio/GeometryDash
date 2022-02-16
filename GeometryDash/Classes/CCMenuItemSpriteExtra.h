#ifndef __CCMENUITEMSPRITEEXTRA_H__
#define __CCMENUITEMSPRITEEXTRA_H__

#include "cocos2d.h"

typedef enum
{
    MENU_ANIM_TYPE_SCALE = 0,
    MENU_ANIM_TYPE_MOVE = 1,
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
    cocos2d::CCPoint mOffsetPosition;
    float mScale;
    std::string mSelectSound;
    std::string mHoverSound;
    float mUnknownSFXValue;
    float mDarkenAmount;
    float mSelectDuration;
    float mUnselectDuration;
    cocos2d::CCPoint mOffsetPositionSelected;
    bool mUseAnimation;
    bool mDarken;
    float mSelectedScale;
};

#endif // __CCMENUITEMSPRITEEXTRA_H__
