#include "GameManager.h"

#include "AppDelegate.h"
#include "GameLevelManager.h"

USING_NS_CC;

GameManager::GameManager()
{
    mCurrentBackground = 0;
    mGroundTexture = 0;
    mUseLowQualityTextures = false;

    mUnknownBool1 = false;
    mUnknownBool4 = false;
    mUnknownBool3 = false;
    mUnknownInt1 = 0;
    mUnknown1 = false;
    mUnknown4 = false;
    mUsedGarageButton = false;
    mShouldLoadLevelSaveData = false;
    mUnknownBool2 = false;
    mUsedCreatorButton = false;
    mCurrentMenu = nullptr;
}

GameManager::~GameManager()
{
    
}

bool GameManager::init()
{
    // TODO: Implement GameManager::init
    // TEMP: firstLoad is not normally called here, but it ends up being called by GManager::setup anyway
    this->firstLoad();
    // TODO: Implement GameManager::init

    return true;
}

void GameManager::firstLoad()
{
    // TODO: Implement GameManager::firstLoad

    GameLevelManager::sharedState()->firstSetup();

    // TODO: Implement GameManager::firstLoad
}

const char* GameManager::getBGTexture(int index)
{
    int num = 1;
    if (index > 0)
    {
        num = index;
        if (index > 22)
            num = 22;
    }
    this->loadBackground(num);

    CCString* s = CCString::createWithFormat("game_bg_%02d_001.png", num);
    return s->getCString();
}

void GameManager::loadBackground(int index)
{
    int num = 1;
    if (index > 0)
    {
        num = index;
        if (index > 22)
            num = 22;
    }

    int currentBG = mCurrentBackground;

    if (num != currentBG)
    {
        CCTextureCache* pTextureCache = CCTextureCache::sharedTextureCache();

        if (currentBG > 0)
        {
            CCString* old = CCString::createWithFormat("game_bg_%02d_001.png", currentBG);
            pTextureCache->removeTextureForKey(old->getCString());
        }

        CCString* s = CCString::createWithFormat("game_bg_%02d_001.png", num);
        
        AppDelegate* pApp = AppDelegate::get();
        bool useLQTextures = true;
        if (!pApp->mLowQualityTextures)
            useLQTextures = mUseLowQualityTextures;

        pTextureCache->addImage(s->getCString(), useLQTextures);

        mCurrentBackground = num;
    }
}

void GameManager::updateMusic()
{
    // TODO: Implement GameManager::updateMusic
}

void GameManager::fadeInMusic(const char* music)
{
    // TODO: Implement GameManager::fadeInMusic
}

void GameManager::setGameVariable(const char* name, bool value)
{
    // TODO: Implement GameManager::setGameVariable
}

bool GameManager::getGameVariable(const char* name)
{
    // TODO: Implement GameManager::getGameVariable
    return false;
}

void GameManager::syncPlatformAchievements()
{
    // TODO: Implement GameManager::syncPlatformAchievements
}

void GameManager::tryCacheAd()
{
    // TODO: Implement GameManager::tryCacheAd - should we even add this anyway?
}

GameManager* GameManager::sharedState()
{
    static GameManager* gGameManager = nullptr;
    if (!gGameManager)
    {
        gGameManager = new GameManager();
        gGameManager->init();
    }

    return gGameManager;
}
