#ifndef __GJBASEGAMELAYER_H__
#define __GJBASEGAMELAYER_H__

#include "cocos2d.h"

class GJBaseGameLayer : public cocos2d::CCLayer
{
public:
    GJBaseGameLayer();
    ~GJBaseGameLayer() override;

    bool init() override;

    bool shouldExitHackedLevel();

protected:
    cocos2d::CCArray* mUnknownArray6;
    cocos2d::CCArray* mUnknownArray8;
    cocos2d::CCArray* mUnknownArray1;
    cocos2d::CCArray* mUnknownArray2;
    cocos2d::CCArray* mUnknownArray3;
    cocos2d::CCArray* mUnknownArray4;
    cocos2d::CCArray* mUnknownArray5;
    cocos2d::CCArray* mUnknownArray7;
    cocos2d::CCDictionary* mUnknownDictionary1;
    cocos2d::CCDictionary* mUnknownDictionary2;
    cocos2d::CCDictionary* mUnknownDictionary3;
    cocos2d::CCDictionary* mUnknownDictionary4;
    cocos2d::CCDictionary* mUnknownDictionary5;
    cocos2d::CCNode* mUnknownNode;
    std::vector<cocos2d::CCArray*> mArrVec1;
    std::vector<cocos2d::CCArray*> mArrVec2;
    std::vector<cocos2d::CCArray*> mArrVec3;
    int mUnknown34;
    bool mUnknownBool7;
};

#endif // __GJBASEGAMELAYER_H__
