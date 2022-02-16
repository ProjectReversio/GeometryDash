#ifndef __GJGAMELEVEL_H__
#define __GJGAMELEVEL_H__

#include "cocos2d.h"

class GJGameLevel : public cocos2d::CCNode
{
public:
    GJGameLevel();
    ~GJGameLevel() override;
    
    bool init() override;

    CREATE_FUNC(GJGameLevel);
};

#endif // __GJGAMELEVEL_H__