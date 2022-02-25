#include "PlayLayer.h"

#include "AppDelegate.h"
#include "GameManager.h"
#include "PlatformToolbox.h"
#include "support/zip_support/ZipUtils.h"

USING_NS_CC;

float PlayLayer::smScreenRight = 0;
float PlayLayer::smScreenLeft = 0;
float PlayLayer::smScreenTop = 0;
float PlayLayer::smScreenBottom = 0;
float PlayLayer::smScreenRightHalf = 0;

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

    mUnknownNew1 = false;
    mUnknownNew2 = pGameManager->getGameVariable("0081");
    mUnknownNew3 = pGameManager->getGameVariable("0095");
    mUnknownNew5 = pGameManager->getGameVariable("0099");
    pGameManager->mUnknownBool6 = true;
    mUnknownNew4 = pGameManager->mUnknownBool5;
    pGameManager->mUnknownBool5 = false;

    if (pGameManager->mUnknown4)
        this->stopRecording();

    // TODO: Missing AdToolbox
    //AdToolbox::cacheInterstitial();

    mUnknownNew8 = false;

    PlayLayer::smScreenRight = pDirector->getScreenRight();
    PlayLayer::smScreenLeft = pDirector->getScreenLeft();
    PlayLayer::smScreenTop = pDirector->getScreenTop();
    PlayLayer::smScreenBottom = pDirector->getScreenBottom();
    PlayLayer::smScreenRightHalf = pDirector->getScreenRight() * 0.5f;

    mUnknownNew6 = level->mUnknown7 == 2;
    mUnknownNew7 = false;

    CCPoint somePoint = mUnknownNew11;

    mUnknown34 = 1;
    mUnknownNew11 = CCPoint(0.0f, 105.0f);

    mUnknownNew12 = 0;
    mUnknownNew16 = 0;
    mUnknownNew20 = 0;
    mUnknownNew21 = 0;
    mUnknownNew13 = 0;
    mUnknownNew14 = 0;
    mUnknownNew19 = false;
    mUnknownNew10 = true;

    mUnknownBool7 = false;

    mUnknownNew22 = 4;

    AppDelegate* pApp = AppDelegate::get();
    if (pApp->isLowMemoryDevice() || pApp->usesLowQualityTextures())
        mUnknownNew22 = 2;
    mUnknownNew23 = 40;
    if (pApp->isLowMemoryDevice() || pApp->usesLowQualityTextures())
        mUnknownNew23 = 10;
    mUnknownNew24 = CCArray::create();
    mUnknownNew24->retain();

    int index = 0;
    while (index < mUnknownNew22)
    {
        index++;
        // TODO: Missing GravityEffectSprite
        //mUnknownNew24->addObject(GravityEffectSprite::create());
    }

    mUnknownNew25 = CCArray::create();
    mUnknownNew25->retain();

    // TODO: Implement PlayLayer::init

    mLevel = level;
    mLevel->retain();

    // TODO: Implement PlayLayer::init

    CCSize winSize = pDirector->getWinSize();

    // TODO: Implement PlayLayer::init

    mUnknownNew29 = CCDrawNode::create();
    this->addChild(mUnknownNew29, 10);

    // TODO: Implement PlayLayer::init

    mUnknownNew33 = CCNode::create();
    this->addChild(mUnknownNew33);
    mUnknownNew33->setVisible(false);

    this->setupLayers();

    // TODO: Implement PlayLayer::init

    mPlayerObject = PlayerObject::create(
        pGameManager->mUnknownNew100 - pGameManager->mUnknownNew101,
        pGameManager->mUnknownNew103 - pGameManager->mUnknownNew104,
        nullptr);

    // TODO: Implement PlayLayer::init

    mPlayObject = PlayerObject::create(
        pGameManager->mUnknownNew100 - pGameManager->mUnknownNew101,
        pGameManager->mUnknownNew103 - pGameManager->mUnknownNew104,
        nullptr);

    // TODO: Implement PlayLayer::init

    mPlayObject->retain();

    // TODO: Implement PlayLayer::init

    // TODO: Missing cocos2d::ZipUtils::decompressString
    //std::string levelString = ZipUtils::decompressString(mLevel->getLevelString(), 0, 11);
    
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

void PlayLayer::stopRecording()
{
    // TODO: Implement PlayLayer::stopRecording
}
