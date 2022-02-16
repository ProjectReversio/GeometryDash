#ifndef __BOOMSCROLLLAYER_H__
#define __BOOMSCROLLLAYER_H__

#include "cocos2d.h"

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

    void setPagesIndicatorPosition(cocos2d::CCPoint point);
    void instantMoveToPage(int page);

    static BoomScrollLayer* create(cocos2d::CCArray* a1, int a2, bool a3, cocos2d::CCArray* a4, DynamicScrollDelegate* scroll);
    static BoomScrollLayer* create(cocos2d::CCArray* a1, int a2, bool a3);

protected:

};

#endif // __BOOMSCROLLLAYER_H__