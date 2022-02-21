#include "PlayLayer.h"

#include "AppDelegate.h"
#include "GameManager.h"
#include "PlatformToolbox.h"

USING_NS_CC;

PlayLayer::PlayLayer()
{
    
}

PlayLayer::~PlayLayer()
{
    
}

CCScene* PlayLayer::scene(GJGameLevel* level)
{
    // 'scene' is an autorelease object
    CCScene* scene = CCScene::create();

    AppDelegate* pApp = AppDelegate::get();
    pApp->mMenuScene = scene;

    // 'layer' is an autorelease object
    PlayLayer* layer = PlayLayer::create(level);

    // add layer as a child to scene
    scene->addChild(layer);

    // TODO: Implement PlayLayer::scene

    // return the scene
    return scene;
}

PlayLayer* PlayLayer::create(GJGameLevel* level)
{
    PlayLayer* pRet = new PlayLayer();
    if (pRet && pRet->init(level))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool PlayLayer::init(GJGameLevel* level)
{
    if (!GJBaseGameLayer::init())
        return false;

    GameManager* pGameManager = GameManager::sharedState();
    if (!pGameManager->getGameVariable("0024"))
        PlatformToolbox::hideCursor();

    pGameManager->mUnknownBool2 = true;

    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->setForcePrio(-500);

    this->setDamageVerifiedIdx(0);

    // TODO: Implement PlayLayer::init

    if (this->shouldExitHackedLevel())
    {
        this->removeAllObjects();
        this->onQuit();
    }

    return true;
}

void PlayLayer::update(float delta)
{
    // TODO: Implement PlayLayer::update
}

void PlayLayer::removeAllObjects()
{
    // TODO: Implement PlayLayer::removeAllObjects
}

void PlayLayer::onQuit()
{
    // TODO: Implement PlayLayer::onQuit
}

void PlayLayer::setDamageVerifiedIdx(int damage)
{
    // TODO: Implement PlayLayer::setDamageVerifiedIdx
}
