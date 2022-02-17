#ifndef __GJGAMELEVEL_H__
#define __GJGAMELEVEL_H__

#include "cocos2d.h"

class GJGameLevel : public cocos2d::CCNode
{
public:
    GJGameLevel();
    ~GJGameLevel() override;
    
    bool init() override;

    void setLevelID(int id);
    int getLevelID() { return mLevelIDEncrypted - mLevelIDKey; }

    CREATE_FUNC(GJGameLevel);

protected:
    int mLevelIDEncrypted;
    int mLevelIDKey;
    int mLevelID;
};

#endif // __GJGAMELEVEL_H__