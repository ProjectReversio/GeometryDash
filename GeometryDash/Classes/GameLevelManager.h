#ifndef __GAMELEVELMANAGER_H__
#define __GAMELEVELMANAGER_H__

#include "cocos2d.h"
#include "GJGameLevel.h"

class GameLevelManager : public cocos2d::CCNode
{
public:
    GameLevelManager();
    ~GameLevelManager() override;

    bool init() override;

    void getLevelSaveData();
    GJGameLevel* getMainLevel(int levelId, bool someBool);

    static GameLevelManager* sharedState();

protected:

};

#endif // __GAMELEVELMANAGER_H__
