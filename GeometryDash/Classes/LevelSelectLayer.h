#ifndef __LEVELSELECTLAYER_H__
#define __LEVELSELECTLAYER_H__

#include "cocos2d.h"
#include "BoomScrollLayer.h"

static bool s_didClick = false;

class GJGroundLayer;

class LevelSelectLayer : public cocos2d::CCLayer, public DynamicScrollDelegate
{
public:
    LevelSelectLayer();
    ~LevelSelectLayer() override;

    void keyBackClicked() override;
    void onBack(cocos2d::CCObject* pSender);
    void onPrev(cocos2d::CCObject* pSender);
    void onNext(cocos2d::CCObject* pSender);
    void onInfo(cocos2d::CCObject* pSender);
    void onDownload(cocos2d::CCObject* pSender);

    void scrollLayerMoved(const cocos2d::CCPoint& point);

    void updatePageWithObject(cocos2d::CCObject* obj1, cocos2d::CCObject* obj2) override;

    virtual bool init(int page);
    
    static cocos2d::CCScene* scene(int page);
    
    static LevelSelectLayer* create(int page);

protected:
    bool mEarnedAchievement;
    cocos2d::CCSprite* mBackgroundSprite;
    GJGroundLayer* mGroundLayer;
    float mUnknown1;
    BoomScrollLayer* mBoomScrollLayer;
};

#endif // __LEVELSELECTLAYER_H__
