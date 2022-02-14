#include "MenuLayer.h"

#include "AppDelegate.h"
#include "CCMenuItemSpriteExtra.h"
#include "GameManager.h"
#include "gameConfig.h"

USING_NS_CC;

CCScene* MenuLayer::scene(bool reload)
{
    // 'scene' is an autorelease object
    CCScene* scene = CCScene::create();

    // TODO: Missing variable.. seems to be part of CCObject
    //scene->something = 15;
    
    AppDelegate* pApp = AppDelegate::get();
    pApp->mMenuScene = scene;

    // 'layer' is an autorelease object
    MenuLayer* layer = MenuLayer::node();

    // add layer as a child to scene
    scene->addChild(layer);

    if (reload)
    {
        CCDelayTime* delay = CCDelayTime::create(0.0f);
        CCCallFunc* callFunc = CCCallFunc::create(layer, callfunc_selector(MenuLayer::onOptionsInstant));
        CCSequence* sequence = CCSequence::create(delay, callFunc, nullptr);
        layer->runAction(sequence);
    }

    // return the scene
    return scene;
}

MenuLayer* MenuLayer::node()
{
    MenuLayer* pRet = new MenuLayer();
    if (pRet && pRet->init())
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

MenuLayer::MenuLayer()
{
    
}

MenuLayer::~MenuLayer()
{
    
}

bool MenuLayer::init()
{
    if (!CCLayer::init())
        return false;

    CCDirector* pDirector = CCDirector::sharedDirector();
    CCTouchDispatcher* pTouchDispatcher = pDirector->getTouchDispatcher();
    pTouchDispatcher->setForcePrio(-500);

    GameManager* pGameManager = GameManager::sharedState();
    pGameManager->fadeInMusic("menuLoop.mp3");
    pGameManager->mUnknownBool1 = true;
    pGameManager->mUnknownInt1 = 0;
    pGameManager->mUnknownBool2 = false;

    this->setKeypadEnabled(true);

    // TODO: Missing function cocos2d::CCLayer::setKeyboardEnabled
    //this->setKeyboardEnabled(true);

    CCSize winSize = pDirector->getWinSize();

    // TODO: Missing MenuGameLayer
    //MenuGameLayer* menuGameLayer = MenuGameLayer::create();
    //this->addChild(menuGameLayer);

    CCSprite* logo = CCSprite::createWithSpriteFrameName("GJ_logo_001.png");
    this->addChild(logo, 2);
    logo->setPosition(CCPoint(winSize.width * 0.5f, pDirector->getScreenTop() - 50.0f));

#if defined(GD_SUBZERO)
    CCSprite* subLogo = CCSprite::createWithSpriteFrameName("gj_subzeroLogo_001.png");
    this->addChild(subLogo, 2);
    subLogo->setPosition(logo->getPosition() + CCPoint(120.0f, -44.0f));
#elif defined(GD_MELTDOWN)
    CCSprite* subLogo = CCSprite::createWithSpriteFrameName("GJ_md_001.png");
    this->addChild(subLogo, 2);
    subLogo->setPosition(logo->getPosition() + CCPoint(140.0f, -44.0f));
#elif defined(GD_WORLD)
    CCSprite* subLogo = CCSprite::createWithSpriteFrameName("gj_worldLogo_001.png");
    this->addChild(subLogo, 2);
    subLogo->setPosition(logo->getPosition() + CCPoint(120.0f, -44.0f));
#elif defined(GD_LITE)
    CCSprite* subLogo = CCSprite::createWithSpriteFrameName("GJ_lite_001.png");
    this->addChild(subLogo, 2);
    subLogo->setPosition(logo->getPosition() + CCPoint(150.0f, -30.0f));
#endif

    CCMenu* mainMenu = CCMenu::create();

    CCSprite* playButton = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
    CCMenuItemSpriteExtra* playExtra = CCMenuItemSpriteExtra::create(playButton, nullptr, this, menu_selector(MenuLayer::onPlay));
    mainMenu->addChild(playExtra);
    this->addChild(mainMenu);
    mainMenu->setPosition(CCPoint(winSize.width * 0.5f, (winSize.height * 0.5f) + 10.0f));

    CCSprite* garageButton = CCSprite::createWithSpriteFrameName("GJ_garageBtn_001.png");
    CCMenuItemSpriteExtra* garageExtra = CCMenuItemSpriteExtra::create(garageButton, nullptr, this, menu_selector(MenuLayer::onGarage));
    mainMenu->addChild(garageExtra);
    garageExtra->setPosition(garageExtra->getPosition() + CCPoint(-110.0f, 0.0f));

    if (!pGameManager->mUnknown6)
    {
        CCSprite* chrSel = CCSprite::createWithSpriteFrameName("GJ_chrSel_001.png");
        this->addChild(chrSel);
        chrSel->setPosition(mainMenu->convertToWorldSpace(garageExtra->getPosition()) + CCPoint(-50.0f, -50.0f));
    }

    // TODO: Implement MenuLayer::init

    CCMenu* quitMenu = CCMenu::create();
    this->addChild(quitMenu, 2);
    //quitMenu->setPosition(CCPoint(pDirector->getScreenRight() - 43.0f, pDirector->getScreenBottom() + 45.0f));
    quitMenu->setPosition(CCPoint(pDirector->getScreenRight() - 43.0f, 0.9f));

#if defined(PLATFORM_DESKTOP)
    CCSprite* closeButton = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
    closeButton->setScale(0.7f);
    CCMenuItemSpriteExtra *closeExtra = CCMenuItemSpriteExtra::create(closeButton, nullptr, this, menu_selector(MenuLayer::onQuit));
    quitMenu->addChild(closeExtra);
    CCPoint point(18.0f, pDirector->getScreenTop() - 18.0f);
    closeExtra->setPosition(quitMenu->convertToNodeSpace(point));
#endif

    // TODO: Missing PlatformToolbox
    //if (PlatformToolbox::isControllerConnected())
    //{
    //    // TODO: Implement MenuLayer::init
    //}

    // TODO: Implement MenuLayer::init

    return true;
}

void MenuLayer::onOptionsInstant()
{
    // TODO: Implement MenuLayer::onOptionsInstant
}

void MenuLayer::onPlay(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onPlay
}

void MenuLayer::onGarage(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onGarage
}

void MenuLayer::onQuit(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onClose

    // TODO: Temporary implementation copied from Hello World Example
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
    CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
