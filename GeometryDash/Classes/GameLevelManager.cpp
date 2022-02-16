#include "GameLevelManager.h"

USING_NS_CC;

GameLevelManager::GameLevelManager()
{
    
}

GameLevelManager::~GameLevelManager()
{
    
}

bool GameLevelManager::init()
{
    // TODO: Implement GameLevelManager::init

    return true;
}

void GameLevelManager::getLevelSaveData()
{
    // TODO: Implement GameLevelManager::getLevelSaveData
}

GJGameLevel* GameLevelManager::getMainLevel(int levelId, bool someBool)
{
    // TODO: Implement GameLevelManager::getMainLevel

    return GJGameLevel::create();
}

GameLevelManager* GameLevelManager::sharedState()
{
    static GameLevelManager* gGameLevelManager = nullptr;
    if (!gGameLevelManager)
    {
        gGameLevelManager = new GameLevelManager();
        gGameLevelManager->init();
    }

    return gGameLevelManager;
}