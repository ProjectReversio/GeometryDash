#ifndef __LEVELPAGE_H__
#define __LEVELPAGE_H__

#include "cocos2d.h"
#include "GJGameLevel.h"

class LevelPage : public cocos2d::CCLayer
{
public:
    LevelPage();
    ~LevelPage() override;

    bool init(GJGameLevel* level);

    static LevelPage* create(GJGameLevel* level);
};

#endif // __LEVELPAGE_H__