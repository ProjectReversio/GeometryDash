#include "MenuLayer.h"

#include "AppDelegate.h"
#include "CCMenuItemSpriteExtra.h"
#include "GameManager.h"
#include "gameConfig.h"
#include "PlatformToolbox.h"

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
    mProfileHelpText = nullptr;
    mProfileText = nullptr;
    mProfileButton = nullptr;
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

    // ----------------------------------------------------------------------------------------------
    // Logos
    // ----------------------------------------------------------------------------------------------

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

    // ----------------------------------------------------------------------------------------------
    // Main Menu
    // ----------------------------------------------------------------------------------------------

    CCMenu* mainMenu = CCMenu::create();

    CCSprite* playButton = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
    CCMenuItemSpriteExtra* playExtra = CCMenuItemSpriteExtra::create(playButton, nullptr, this, menu_selector(MenuLayer::onPlay));
    mainMenu->addChild(playExtra);
    this->addChild(mainMenu);
    mainMenu->setPosition(CCPoint(winSize.width * 0.5f, (winSize.height * 0.5f) + 10.0f));

    CCSprite* garageButton = CCSprite::createWithSpriteFrameName("GJ_garageBtn_001.png");
    CCMenuItemSpriteExtra* garageExtra = CCMenuItemSpriteExtra::create(garageButton, nullptr, this, menu_selector(MenuLayer::onGarage));
    mainMenu->addChild(garageExtra);
    garageExtra->setPosition(playExtra->getPosition() + CCPoint(-110.0f, 0.0f));

    if (!pGameManager->mUsedGarageButton)
    {
        CCSprite* chrSel = CCSprite::createWithSpriteFrameName("GJ_chrSel_001.png");
        this->addChild(chrSel);
        chrSel->setPosition(mainMenu->convertToWorldSpace(garageExtra->getPosition()) + CCPoint(-50.0f, -50.0f));
    }

#if defined(GD_TRIAL_VERSION) && !defined(GD_WORLD)
    CCSprite* fullButton = CCSprite::createWithSpriteFrameName("GJ_fullBtn_001.png");
    CCMenuItemSpriteExtra* fullExtra = CCMenuItemSpriteExtra::create(fullButton, nullptr, this, menu_selector(MenuLayer::onFullVersion));
#else
    CCSprite* fullButton = CCSprite::createWithSpriteFrameName("GJ_creatorBtn_001.png");
    CCMenuItemSpriteExtra* fullExtra = CCMenuItemSpriteExtra::create(fullButton, nullptr, this, menu_selector(MenuLayer::onCreator));
#endif
    mainMenu->addChild(fullExtra);
    fullExtra->setPosition(playExtra->getPosition() + CCPoint(110.0f, 0.0f));

#if !defined(GD_TRIAL_VERSION) || defined(GD_WORLD)
    if (!pGameManager->mUsedCreatorButton)
    {
#ifdef GD_WORLD
        CCSprite* lvlEditButton = CCSprite::createWithSpriteFrameName("GJ_lvlEditWorld_001.png");
#else
        CCSprite* lvlEditButton = CCSprite::createWithSpriteFrameName("GJ_lvlEdit_001.png");
#endif
        this->addChild(lvlEditButton);
        lvlEditButton->setPosition(mainMenu->convertToWorldSpace(fullExtra->getPosition()) + CCPoint(50.0f, -50.0f));
    }
#endif

    // ----------------------------------------------------------------------------------------------
    // Bottom Menu
    // ----------------------------------------------------------------------------------------------

    CCMenu* bottomMenu = CCMenu::create();
    this->addChild(bottomMenu);

    CCSprite* achievementsButton = CCSprite::createWithSpriteFrameName("GJ_achBtn_001.png");
    achievementsButton->setScale(1.0f);
    CCMenuItemSpriteExtra* achievementsExtra = CCMenuItemSpriteExtra::create(achievementsButton, nullptr, this, menu_selector(MenuLayer::onAchievements));
    bottomMenu->addChild(achievementsExtra);
    
    CCSprite* optionsButton = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
    optionsButton->setScale(1.0f);
    CCMenuItemSpriteExtra* optionsExtra = CCMenuItemSpriteExtra::create(optionsButton, nullptr, this, menu_selector(MenuLayer::onOptions));
    bottomMenu->addChild(optionsExtra);

    CCSprite* statsButton = CCSprite::createWithSpriteFrameName("GJ_statsBtn_001.png");
    statsButton->setScale(1.0f);
    CCMenuItemSpriteExtra* statsExtra = CCMenuItemSpriteExtra::create(statsButton, nullptr, this, menu_selector(MenuLayer::onStats));
    bottomMenu->addChild(statsExtra);

#if defined(PLATFORM_MOBILE)
    // TODO: Missing EveryplayToolbox
    //if (EveryplayToolbox::isEveryplaySupported())
    {
        CCSprite* everyplayButton = CCSprite::createWithSpriteFrameName("GJ_everyplayBtn_001.png");
        everyplayButton->setScale(1.0f);
        CCMenuItemSpriteExtra* everyplayExtra = CCMenuItemSpriteExtra::create(everyplayButton, nullptr, this, menu_selector(MenuLayer::onEveryplay));
        bottomMenu->addChild(everyplayExtra);
    }
#endif

    CCSprite* newgroundsButton = CCSprite::createWithSpriteFrameName("GJ_ngBtn_001.png");
    newgroundsButton->setScale(1.0f);
    CCMenuItemSpriteExtra* newgroundsExtra = CCMenuItemSpriteExtra::create(newgroundsButton, nullptr, this, menu_selector(MenuLayer::onNewgrounds));
    bottomMenu->addChild(newgroundsExtra);

    bottomMenu->setPosition(CCPoint(winSize.width * 0.5f, pDirector->getScreenBottom() + 45.0f));
    bottomMenu->alignItemsHorizontallyWithPadding(5.0f);

    // ----------------------------------------------------------------------------------------------
    // Social Menu
    // ----------------------------------------------------------------------------------------------

    CCSprite* robtopLogo = CCSprite::createWithSpriteFrameName("robtoplogo_small.png");
    robtopLogo->setScale(0.8f);
    CCMenuItemSpriteExtra* robtopExtra = CCMenuItemSpriteExtra::create(robtopLogo, nullptr, this, menu_selector(MenuLayer::onRobTop));
    robtopExtra->setSizeMult(1.5f);

    CCMenu* socialsMenu = CCMenu::create(robtopExtra, nullptr);
    this->addChild(socialsMenu, 2);
    socialsMenu->setPosition(CCPoint(pDirector->getScreenLeft() + 50.0f, pDirector->getScreenBottom() + 30.0f - 6.0f));
    
    CCSprite* facebookIcon = CCSprite::createWithSpriteFrameName("gj_fbIcon_001.png");
    facebookIcon->setScale(0.8f);
    CCMenuItemSpriteExtra* facebookExtra = CCMenuItemSpriteExtra::create(facebookIcon, nullptr, this, menu_selector(MenuLayer::onFacebook));
    facebookExtra->setSizeMult(1.5f);
    socialsMenu->addChild(facebookExtra);

    CCSprite* twitterIcon = CCSprite::createWithSpriteFrameName("gj_twIcon_001.png");
    twitterIcon->setScale(0.8f);
    CCMenuItemSpriteExtra* twitterExtra = CCMenuItemSpriteExtra::create(twitterIcon, nullptr, this, menu_selector(MenuLayer::onTwitter));
    twitterExtra->setSizeMult(1.5f);
    socialsMenu->addChild(twitterExtra);

    CCSprite* youtubeIcon = CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png");
    youtubeIcon->setScale(0.8f);
    CCMenuItemSpriteExtra* youtubeExtra = CCMenuItemSpriteExtra::create(youtubeIcon, nullptr, this, menu_selector(MenuLayer::onYouTube));
    youtubeExtra->setSizeMult(1.5f);
    socialsMenu->addChild(youtubeExtra);

    facebookExtra->setPosition(socialsMenu->convertToNodeSpace(CCPoint(pDirector->getScreenLeft() + 22.0f, pDirector->getScreenBottom() + 30.0f + 25.0f)));
    twitterExtra->setPosition(facebookExtra->getPosition() + CCPoint(30.0f, 0.0f));
    youtubeExtra->setPosition(twitterExtra->getPosition() + CCPoint(30.0f, 0.0f));

    // ----------------------------------------------------------------------------------------------
    // Extra Menu
    // ----------------------------------------------------------------------------------------------

    // TODO: Why is this called here on android?
    //lrand48();

#ifdef GD_TRIAL_VERSION
    CCSprite* freeLevelsButton = CCSprite::createWithSpriteFrameName("GJ_freeLevelsBtn_001.png");
    CCMenuItemSpriteExtra* freeLevelsExtra = CCMenuItemSpriteExtra::create(freeLevelsButton, nullptr, this, menu_selector(MenuLayer::onFreeLevels));
    
    if (!pGameManager->getGameVariable("0053"))
    {
        CCScaleTo* scaleTo = CCScaleTo::create(0.5f, 1.1f);
        CCEaseInOut* easeInOut = CCEaseInOut::create(scaleTo, 2.0f);
        CCScaleTo* scaleTo2 = CCScaleTo::create(0.5f, 1.0f);
        CCEaseInOut* easeInOut2 = CCEaseInOut::create(scaleTo2, 2.0f);
        CCSequence* sequence = CCSequence::create(easeInOut, easeInOut2, nullptr);
        CCRepeatForever* repeatForever = CCRepeatForever::create(sequence);
        freeLevelsButton->runAction(repeatForever);
    }
#else
    CCSprite* freeLevelsButton = CCSprite::createWithSpriteFrameName("GJ_moreGamesBtn_001.png");
    CCMenuItemSpriteExtra* freeLevelsExtra = CCMenuItemSpriteExtra::create(freeLevelsButton, nullptr, this, menu_selector(MenuLayer::onMoreGames));
#endif
    
    CCMenu* extraMenu = CCMenu::create(freeLevelsExtra, nullptr);
    this->addChild(extraMenu, 2);

    extraMenu->setPosition(CCPoint(pDirector->getScreenRight() - 43.0f, pDirector->getScreenBottom() + 45.0f));
    //extraMenu->setPosition(CCPoint(pDirector->getScreenRight() - 43.0f, 0.9f));

#if defined(PLATFORM_MOBILE)
    // TODO: Missing AdToolbox
    //AdToolbox::cacheInterstitial();

    if (!pGameManager->mUnknownBool3)
    {
        if (!pGameManager->getGameVariable("0106"))
        {
            // Only show promo once
            pGameManager->setGameVariable("0106", true);

            CCDelayTime* delay = CCDelayTime::create(0.1f);
            CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(MenuLayer::showMeltdownPromo));
            CCSequence* sequence = CCSequence::create(delay, callFunc, nullptr);
            this->runAction(sequence);
        }
    }
#endif

    pGameManager->mUnknownBool4 = false;

#if defined(PLATFORM_DESKTOP)
    CCSprite* closeButton = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
    closeButton->setScale(0.7f);
    CCMenuItemSpriteExtra *closeExtra = CCMenuItemSpriteExtra::create(closeButton, nullptr, this, menu_selector(MenuLayer::onQuit));
    extraMenu->addChild(closeExtra);
    CCPoint point(18.0f, pDirector->getScreenTop() - 18.0f);
    closeExtra->setPosition(extraMenu->convertToNodeSpace(point));
#endif

    if (PlatformToolbox::isControllerConnected())
    {
        // TODO: Implement MenuLayer::init
    }
    
    CCSprite* profileButton = CCSprite::createWithSpriteFrameName("GJ_profileButton_001.png");
    this->mProfileButton = CCMenuItemSpriteExtra::create(profileButton, nullptr, this, menu_selector(MenuLayer::onMyProfile));
    mainMenu->addChild(this->mProfileButton, 2);
    this->mProfileButton->setPosition(mainMenu->convertToNodeSpace(CCPoint(45.0f, 105.0f)));

    this->mProfileText = CCLabelBMFont::create(" ", "goldFont.fnt");
    this->addChild(this->mProfileText, 2);
    this->mProfileText->setPosition(CCPoint(45.0f, 105.0f) + CCPoint(2.0f, 36.0f));

    // TODO: Missing CCLabelBMFont::limitLabelWidth
    //this->mProfileText->limitLabelWidth(70.0f, 0.7f, 0.0f);

    if (!pGameManager->getGameVariable("0048") && pGameManager->mUsedGarageButton)
    {
        this->mProfileHelpText = CCSprite::createWithSpriteFrameName("GJ_viewProfileTxt_001.png");
        this->addChild(this->mProfileHelpText, 2);
        this->mProfileHelpText->setPosition(CCPoint(45.0f, 105.0f) + CCPoint(76.0f, -1.0f));
    }

    this->updateUserProfileButton();
    pGameManager->mCurrentMenu = this;

#if !defined(GD_TRIAL_VERSION) || defined(GD_WORLD)
    CCSprite* dailyButton = CCSprite::createWithSpriteFrameName("GJ_dailyRewardBtn_001.png");
#else
    CCSprite* dailyButton = CCSprite::createWithSpriteFrameName("GJ_freeStuffBtn_001.png");
#endif
    CCMenuItemSpriteExtra* dailyExtra = CCMenuItemSpriteExtra::create(dailyButton, nullptr, this, menu_selector(MenuLayer::onDaily));
    bottomMenu->addChild(dailyExtra);
    dailyExtra->setPosition(bottomMenu->convertToNodeSpace(CCPoint(pDirector->getScreenRight() - 40.0f, winSize.height * 0.5f + 20.0f)));
    dailyExtra->setSizeMult(1.5f);

    return true;
}

void MenuLayer::onOptionsInstant()
{
    // TODO: Implement MenuLayer::onOptionsInstant
}

void MenuLayer::showMeltdownPromo()
{
    // TODO: Implement MenuLayer::showMeltdownPromo
}

void MenuLayer::updateUserProfileButton()
{
    // This implementation is specific to SubZero
    // TODO: Implement other versions of this

    // TODO: Missing GJAccountManager
    //GJAccountManager* pAccountManager = GJAccountManager::sharedState();

    mProfileButton->setVisible(false);
    mProfileText->setVisible(false);
    if (mProfileHelpText)
        mProfileHelpText->setVisible(false);

    // TODO: Implement MenuLayer::updateUserProfileButton
}

void MenuLayer::onPlay(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onPlay
}

void MenuLayer::onGarage(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onGarage

    GameManager::sharedState()->mUsedGarageButton = true;

    // TODO: Implement MenuLayer::onGarage
}

void MenuLayer::onCreator(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onCreator

    GameManager::sharedState()->mUsedCreatorButton = true;

    // TODO: Implement MenuLayer::onCreator
}

void MenuLayer::onMyProfile(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onMyProfile
}

void MenuLayer::onAchievements(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onAchievements
}

void MenuLayer::onOptions(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onOptions
}

void MenuLayer::onStats(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onStats
}

void MenuLayer::onDaily(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onDaily
}

void MenuLayer::onEveryplay(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onEveryplay
}

void MenuLayer::onNewgrounds(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onNewgrounds
}

void MenuLayer::onRobTop(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onRobTop
}

void MenuLayer::onFacebook(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onFacebook
}

void MenuLayer::onTwitter(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onTwitter
}

void MenuLayer::onYouTube(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onYouTube
}

void MenuLayer::onMoreGames(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onMoreGames
}

void MenuLayer::onFreeLevels(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onFreeLevels
}

void MenuLayer::onFullVersion(cocos2d::CCObject* pSender)
{
    // TODO: Implement MenuLayer::onFullVersion
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
