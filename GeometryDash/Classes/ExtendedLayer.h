#ifndef __EXTENDEDLAYER_H__
#define __EXTENDEDLAYER_H__

#include "cocos2d.h"

class ExtendedLayer : public cocos2d::CCLayer
{
public:
    ExtendedLayer();
    ~ExtendedLayer() override;

    bool init() override;

    void setPosition(const cocos2d::CCPoint& position) override;

    CREATE_FUNC(ExtendedLayer);

protected:
    void* mUnknown3;
};

#endif // __EXTENDEDLAYER_H__
