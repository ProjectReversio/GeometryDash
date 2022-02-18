#include "GameLevelManager.h"

#include "LevelTools.h"

USING_NS_CC;

GameLevelManager::GameLevelManager()
{
    mUnknownDictionary = nullptr;
}

GameLevelManager::~GameLevelManager()
{
    
}

bool GameLevelManager::init()
{
    mUnknownStr = CCString::createWithFormat("%i", 1);
    mUnknownStr->retain();

    // TODO: Implement GameLevelManager::init

    return true;
}

void GameLevelManager::getLevelSaveData()
{
    // TODO: Implement GameLevelManager::getLevelSaveData
}

void GameLevelManager::firstSetup()
{
    this->setMainLevels(CCDictionary::create());

    // TODO: Implement GameLevelManager::firstSetup
}

void GameLevelManager::setMainLevels(cocos2d::CCDictionary* dictionary)
{
    if (mUnknownDictionary != dictionary)
    {
        if (dictionary)
            dictionary->retain();

        if (mUnknownDictionary)
            mUnknownDictionary->release();

        mUnknownDictionary = dictionary;
    }
}

GJGameLevel* GameLevelManager::getMainLevel(int levelId, bool someBool)
{
    GJGameLevel* lvlRet = (GJGameLevel*)mUnknownDictionary->objectForKey(this->getLevelKey(levelId));

    GJGameLevel* newLvl = LevelTools::getLevel(levelId, someBool);

    if (lvlRet)
    {
        // TODO: Implement GameLevelManager::getMainLevel

        lvlRet->setStars(newLvl->getStars());

        // TODO: Implement GameLevelManager::getMainLevel

        lvlRet->setCoinsRequired(newLvl->getCoinsRequired());
        lvlRet->setLevelName(newLvl->getLevelName());
        lvlRet->setSongID(newLvl->getSongID());

        // TODO: Implement GameLevelManager::getMainLevel

        lvlRet->setDemon(newLvl->getDemon());
        lvlRet->setDifficulty(newLvl->getDifficulty());
        lvlRet->setCapacityString(newLvl->getCapacityString());

        lvlRet->setLevelID(levelId);
    } else
    {
        lvlRet = LevelTools::getLevel(levelId, false);
        mUnknownDictionary->setObject(lvlRet, this->getLevelKey(levelId));
    }

    return lvlRet;
}

const char* GameLevelManager::getLevelKey(int levelId)
{
    const CCString* str = CCString::createWithFormat("%i", levelId);
    return str->getCString();
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