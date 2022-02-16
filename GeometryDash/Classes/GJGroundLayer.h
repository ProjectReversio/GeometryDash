#ifndef __GJGROUNDLAYER_H__
#define __GJGROUNDLAYER_H__

#include "cocos2d.h"

class GJGroundLayer : public cocos2d::CCLayer
{
public:
    GJGroundLayer();
    ~GJGroundLayer();
    
    virtual bool init(int texture, int a2);

    void positionGround(float position);

    static GJGroundLayer* create(int texture, int a2);
};

#endif // __GJGROUNDLAYER_H__
