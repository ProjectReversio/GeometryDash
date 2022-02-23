#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "cocos2d.h"
#include "GManager.h"

class GameManager : public cocos2d::CCNode, GManager
{
    friend class AppDelegate;
public:
    GameManager();
    virtual ~GameManager();

    bool init() override;

    void firstLoad();

    const char* getBGTexture(int index);
    void loadBackground(int index);

    void updateMusic();
    void fadeInMusic(const char* music);

    void setGameVariable(const char* name, bool value);
    bool getGameVariable(const char* name);

    void syncPlatformAchievements();
    void tryCacheAd();

    static GameManager* sharedState();

private:
    int mCurrentBackground;
    bool mUseLowQualityTextures;

public:
    bool mUnknownBool1;
    bool mUnknownBool4;
    bool mUnknownBool3;
    int mUnknownInt1;
    bool mUnknown1;
    bool mUnknown4;
    bool mUsedGarageButton;
    bool mShouldLoadLevelSaveData;
    bool mUnknownBool2;
    bool mUnknownBool5;
    bool mUnknownBool6;
    bool mUsedCreatorButton;
    cocos2d::CCLayer* mCurrentMenu;
    int mGroundTexture;
};

#endif // __GAMEMANAGER_H__
