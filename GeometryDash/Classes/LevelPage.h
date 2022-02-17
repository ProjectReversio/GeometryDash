#ifndef __LEVELPAGE_H__
#define __LEVELPAGE_H__

#include "cocos2d.h"
#include "GJGameLevel.h"

namespace cocos2d
{
    namespace extension
    {
        class CCScale9Sprite;
    }
}

class LevelPage : public cocos2d::CCLayer
{
public:
    LevelPage();
    ~LevelPage() override;

    bool init(GJGameLevel* level);

    void updateDynamicPage(GJGameLevel* level);

    void onPlay(cocos2d::CCObject* pSender);

    static LevelPage* create(GJGameLevel* level);

protected:
    cocos2d::CCSize mUnknownSize1;
    cocos2d::CCArray* mUnknownArray1;
    cocos2d::CCArray* mUnknownArray2;
    cocos2d::CCMenu* mMenu;
    cocos2d::extension::CCScale9Sprite* mLevelInfoBox;
    cocos2d::CCSprite* mProgressBarNormal;
    cocos2d::CCSprite* mProgressBarPractice;
    float mUnknownFloat1;
    cocos2d::CCLabelBMFont* mUnknownText1;
    cocos2d::CCLabelBMFont* mUnknownText2;
    cocos2d::CCLabelBMFont* mUnknownText3;
    cocos2d::CCLabelBMFont* mUnknownText4;
    cocos2d::CCSprite* mDifficultySprite;
    cocos2d::CCSprite* mStarSprite;
    cocos2d::CCArray* mUnknownArray3;
    cocos2d::CCArray* mUnknownArray4;
};

#endif // __LEVELPAGE_H__