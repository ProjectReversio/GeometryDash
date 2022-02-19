#include "PlayLayer.h"

#include "AppDelegate.h"

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

    // TODO: Implement PlayLayer::init

    return true;
}
