#ifndef __LEVELPAGE_H__
#define __LEVELPAGE_H__

#include "cocos2d.h"
#include "GJGameLevel.h"

class GameObject;

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
    void addSecretDoor();

    void onPlay(cocos2d::CCObject* pSender);
    void playStep2();
    void playStep3();

    static LevelPage* create(GJGameLevel* level);
    
    static bool s_didClick;

protected:
    cocos2d::CCSize mUnknownSize1;
    cocos2d::CCArray* mUnknownArray1;
    cocos2d::CCArray* mUnknownArray2;
    cocos2d::CCMenu* mMenu;
    cocos2d::extension::CCScale9Sprite* mLevelInfoBox;
    cocos2d::CCSprite* mProgressBarNormal;
    cocos2d::CCSprite* mProgressBarPractice;
    float mUnknownFloat1;
    cocos2d::CCLabelBMFont* mNormalPercentText;
    cocos2d::CCLabelBMFont* mPracticePercentText;
    cocos2d::CCLabelBMFont* mLevelNameText;
    cocos2d::CCLabelBMFont* mUnknownText4;
    cocos2d::CCSprite* mDifficultySprite;
    cocos2d::CCSprite* mStarSprite;
    cocos2d::CCArray* mCoinArray;
    cocos2d::CCArray* mUnknownArray4;
    GJGameLevel* mLevel;
    bool mUnknown1;
    GameObject* mSecretCoin;
    cocos2d::CCSprite* mSecretDoor;
};

#endif // __LEVELPAGE_H__