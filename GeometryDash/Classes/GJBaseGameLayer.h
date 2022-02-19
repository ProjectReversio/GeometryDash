#ifndef __GJBASEGAMELAYER_H__
#define __GJBASEGAMELAYER_H__

#include "cocos2d.h"

class GJBaseGameLayer : public cocos2d::CCLayer
{
public:
    GJBaseGameLayer();
    ~GJBaseGameLayer() override;

    bool init() override;
};

#endif // __GJBASEGAMELAYER_H__
