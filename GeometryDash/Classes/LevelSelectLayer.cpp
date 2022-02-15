#include "LevelSelectLayer.h"

#include "AppDelegate.h"

USING_NS_CC;

LevelSelectLayer::LevelSelectLayer()
{
    
}

LevelSelectLayer::~LevelSelectLayer()
{
    
}

CCScene* LevelSelectLayer::scene(int page)
{
    // 'scene' is an autorelease object
    CCScene* scene = CCScene::create();

    AppDelegate* pApp = AppDelegate::get();
    pApp->mMenuScene = scene;

    // 'layer' is an autorelease object
    LevelSelectLayer* layer = LevelSelectLayer::create(page);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

LevelSelectLayer* LevelSelectLayer::create(int page)
{
    LevelSelectLayer* pRet = new LevelSelectLayer();
    if (pRet && pRet->init(page))
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

bool LevelSelectLayer::init(int page)
{
    if (!CCLayer::init())
        return false;

    // TODO: Implement LevelSelectLayer::init

    return true;
}

