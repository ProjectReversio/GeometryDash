#include "GameManager.h"

#include "AppDelegate.h"

USING_NS_CC;

GameManager::GameManager()
{
    mUseLowQualityTextures = false;
}

GameManager::~GameManager()
{
    
}

bool GameManager::init()
{
    // TODO: Implement

    return true;
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

void GameManager::fadeInMusic(const char* music)
{
    // TODO: Implement GameManager::fadeInMusic
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
        gGameManager = GameManager::create();
        gGameManager->init();
    }

    return gGameManager;
}
