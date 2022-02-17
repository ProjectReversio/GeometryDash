#ifndef __BOOMSCROLLLAYER_H__
#define __BOOMSCROLLLAYER_H__

#include "cocos2d.h"

class ExtendedLayer;

struct DynamicScrollDelegate
{
public:
    virtual void updatePageWithObject(cocos2d::CCObject* obj1, cocos2d::CCObject* obj2) = 0;
};

class BoomScrollLayer : public cocos2d::CCLayer
{
public:
    BoomScrollLayer();
    ~BoomScrollLayer() override;

    virtual bool init(cocos2d::CCArray* a1, int a2, bool a3, cocos2d::CCArray* a4, DynamicScrollDelegate* scroll);

    int pageNumberForPosition(cocos2d::CCPoint point);
    int getRelativePageForNum(int num);
    void setPagesIndicatorPosition(cocos2d::CCPoint point);
    void instantMoveToPage(int page);
    void updatePages();
    void repositionPagesLooped();
    void setupDynamicScrolling(cocos2d::CCArray* arr, DynamicScrollDelegate* scroll);
    int getTotalPages();
    void updateDots(float f);

    static BoomScrollLayer* create(cocos2d::CCArray* a1, int a2, bool a3, cocos2d::CCArray* a4, DynamicScrollDelegate* scroll);
    static BoomScrollLayer* create(cocos2d::CCArray* a1, int a2, bool a3);

public:
    ExtendedLayer* mUnknown1;

protected:
    bool mUnknown2;
    float mUnknownFloat1;
    float mUnknownFloat2;
    float mUnknownFloat3;
    bool mUnknown3;
    unsigned char mUnknownByte5;
    unsigned char mUnknownByte6;
    unsigned char mUnknownByte7;
    unsigned char mUnknownByte8;
    unsigned char mUnknownByte1;
    unsigned char mUnknownByte2;
    unsigned char mUnknownByte3;
    unsigned char mUnknownByte4;
    cocos2d::CCRect mUnknownRect1;
    int mUnknown4;
    float mUnknownFloat4;
    float mUnknownFloat6;
    float mUnknownFloat5;
    float mUnknown5;
    cocos2d::CCArray* mUnknownArray0;
    cocos2d::CCArray* mUnknownArray1;
    cocos2d::CCArray* mUnknownArray2;
    bool mUnknownBool1;
    bool mUnknown6;
    cocos2d::CCPoint mUnknownPoint1;
    cocos2d::CCPoint mUnknownPoint2;
    cocos2d::CCRect mUnknownRect2;
    DynamicScrollDelegate* mUnknown555;
};

#endif // __BOOMSCROLLLAYER_H__