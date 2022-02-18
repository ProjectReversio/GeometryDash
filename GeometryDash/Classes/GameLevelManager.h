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
    void firstSetup();
    void setMainLevels(cocos2d::CCDictionary* dictionary);
    GJGameLevel* getMainLevel(int levelId, bool someBool);

    const char* getLevelKey(int levelId);

    static GameLevelManager* sharedState();

protected:
    cocos2d::CCDictionary* mUnknownDictionary;
    cocos2d::CCString* mUnknownStr;
};

#endif // __GAMELEVELMANAGER_H__
