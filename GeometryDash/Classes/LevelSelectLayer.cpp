#include "LevelSelectLayer.h"

#include "AppDelegate.h"
#include "CCMenuItemSpriteExtra.h"
#include "ExtendedLayer.h"
#include "GameLevelManager.h"
#include "GameManager.h"
#include "GJGroundLayer.h"
#include "LevelPage.h"
#include "MenuLayer.h"
#include "PlatformToolbox.h"
#include "gameConfig.h"

USING_NS_CC;

#if defined(GD_SUBZERO)
#define LEVEL_INDEX_START 4001
#define LEVEL_INDEX_END 4004
#elif defined(GD_MELTDOWN)
#define LEVEL_INDEX_START 1001
#define LEVEL_INDEX_END 1004
#elif defined(GD_WORLD)
#define LEVEL_INDEX_START 2001
#define LEVEL_INDEX_END 2011
#elif defined(GD_LITE)
#define LEVEL_INDEX_START 1
#define LEVEL_INDEX_END 15
#else
#define LEVEL_INDEX_START 1
#define LEVEL_INDEX_END 22
#endif

LevelSelectLayer::LevelSelectLayer()
{
    mUnknown1 = 0.0f;
    mBackgroundSprite = nullptr;
    mGroundLayer = nullptr;



    mEarnedAchievement = false;
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

    this->setKeypadEnabled(true);

    // TODO: Missing function cocos2d::CCLayer::setKeyboardEnabled
    //this->setKeyboardEnabled(true);

    s_didClick = false;

    // TODO: Missing AchievementManager
    //AchievementManager* pAchievementManager = AchievementManager::sharedState();
    //this->mEarnedAchievement = pAchievementManager->isAchievementEarned("geometry.ach.secret04");

    CCDirector* pDirector = CCDirector::sharedDirector();
    CCSize winSize = pDirector->getWinSize();

    mBackgroundSprite = CCSprite::create("GJ_gradientBG.png");
    mBackgroundSprite->setAnchorPoint(CCPoint(0.0f, 0.0f));
    this->addChild(mBackgroundSprite, -2);
    mBackgroundSprite->setScaleX((winSize.width + 10.0f) / mBackgroundSprite->getTextureRect().size.width);
    mBackgroundSprite->setScaleY((winSize.height + 10.0f) / mBackgroundSprite->getTextureRect().size.height);
    mBackgroundSprite->setPosition(CCPoint(-5.0f, -5.0f));
    mBackgroundSprite->setColor({40, 125, 255});

    GameManager* pGameManager = GameManager::sharedState();

    mGroundLayer = GJGroundLayer::create(pGameManager->mGroundTexture, 1);
    this->addChild(mGroundLayer, 0);

    float groundPos = winSize.height * 0.5f - 110.0f;
    if (groundPos > 128.0f)
        groundPos = 128.0f;

    mGroundLayer->positionGround(groundPos);

    CCSprite* topBar = CCSprite::createWithSpriteFrameName("GJ_topBar_001.png");
    topBar->setAnchorPoint(CCPoint(0.5f, 1.0f));
    topBar->setPosition(CCPoint(winSize.width * 0.5f, pDirector->getScreenTop() + 1.0f));
    this->addChild(topBar, 1);

    CCSprite* sideArtLeft = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    sideArtLeft->setAnchorPoint(CCPoint(0.0f, 0.0f));
    sideArtLeft->setPosition(CCPoint(pDirector->getScreenLeft() - 1.0f, pDirector->getScreenBottom() - 1.0f));
    this->addChild(sideArtLeft, 1);

    CCSprite* sideArtRight = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
    sideArtRight->setAnchorPoint(CCPoint(1.0f, 0.0f));
    sideArtRight->setPosition(CCPoint(pDirector->getScreenRight() + 1.0f, pDirector->getScreenBottom() - 1.0f));
    sideArtRight->setFlipX(true);
    this->addChild(sideArtRight, 1);

    CCArray* levelArray = CCArray::create();
    CCArray* pageArray = CCArray::create();

    int index = LEVEL_INDEX_START;

    GameLevelManager* pLevelManager = GameLevelManager::sharedState();
    
    do
    {
#ifdef GD_LITE
        int index2;
        if (index == 14)
            index2 = 15;
        else
            index2 = index;
        index++;
        levelArray->addObject(pLevelManager->getMainLevel(index2, true));
#else
        levelArray->addObject(pLevelManager->getMainLevel(index++, true));
#endif
    } while(index != LEVEL_INDEX_END);

    int index2 = 3;
    do
    {
        LevelPage* lvlPage = LevelPage::create(nullptr);
        index2--;
        pageArray->addObject(lvlPage);
    } while (index2 > 0);
    
    GJGameLevel* level = GJGameLevel::create();
    level->setLevelID(-1);
    levelArray->addObject(level);

    this->mBoomScrollLayer = BoomScrollLayer::create(pageArray, 0, true, levelArray, this);
    this->addChild(mBoomScrollLayer);

    mBoomScrollLayer->setPagesIndicatorPosition(CCPoint(winSize.width * 0.5f, pDirector->getScreenBottom() + 15.0f));

    this->mUnknown1 = winSize.width;

    mBoomScrollLayer->mUnknown1->mUnknown3 = this;

    if (page == 0)
    {
        this->scrollLayerMoved(CCPoint());
    }
    else if (page == (LEVEL_INDEX_END - LEVEL_INDEX_START))
    {
        mBoomScrollLayer->instantMoveToPage((LEVEL_INDEX_END - LEVEL_INDEX_START) - 1);

#ifdef GD_MELTDOWN
        // Why does meltdown do this?
        mBoomScrollLayer->instantMoveToPage((LEVEL_INDEX_END - LEVEL_INDEX_START));
#endif
    }
    else
    {
        mBoomScrollLayer->instantMoveToPage(page);
    }

    CCLabelBMFont* downloadTxt = CCLabelBMFont::create("Download the soundtracks", "bigFont.fnt");
    downloadTxt->setScale(0.5f);
    CCMenuItemSpriteExtra* downloadExtra = CCMenuItemSpriteExtra::create(downloadTxt, nullptr, this, menu_selector(LevelSelectLayer::onDownload));
    downloadExtra->setSizeMult(2.0f);

    CCMenu* downloadMenu = CCMenu::create(downloadExtra, nullptr);
    this->addChild(downloadMenu);
    downloadMenu->setPosition(CCPoint(winSize.width * 0.5f, pDirector->getScreenBottom() + 35.0f));

    CCMenu* navigationMenu = CCMenu::create();
    this->addChild(navigationMenu, 5);
    
    bool controller = PlatformToolbox::isControllerConnected();

    const char* leftBtnImg;
    if (controller)
        leftBtnImg = "controllerBtn_DPad_Left_001.png";
    else
        leftBtnImg = "navArrowBtn_001.png";

    CCSprite* leftBtnSprite = CCSprite::createWithSpriteFrameName(leftBtnImg);
    if (!controller)
        leftBtnSprite->setFlipX(true);

    CCMenuItemSpriteExtra* leftBtn = CCMenuItemSpriteExtra::create(leftBtnSprite, nullptr, this, menu_selector(LevelSelectLayer::onPrev));
    navigationMenu->addChild(leftBtn);
    leftBtn->setSizeMult(2.0f);
    leftBtn->setPosition(navigationMenu->convertToNodeSpace(CCPoint(pDirector->getScreenLeft() + 25.0f, winSize.height * 0.5f)));

    const char* rightBtnImg;
    if (controller)
        rightBtnImg = "controllerBtn_DPad_Right_001.png";
    else
        rightBtnImg = "navArrowBtn_001.png";

    CCSprite* rightBtnSprite = CCSprite::createWithSpriteFrameName(rightBtnImg);
    CCMenuItemSpriteExtra* rightBtn = CCMenuItemSpriteExtra::create(rightBtnSprite, nullptr, this, menu_selector(LevelSelectLayer::onNext));
    navigationMenu->addChild(rightBtn);
    rightBtn->setSizeMult(2.0f);
    rightBtn->setPosition(navigationMenu->convertToNodeSpace(CCPoint(pDirector->getScreenRight() - 25.0f, winSize.height * 0.5f)));

    CCSprite* backBtnSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png");
    CCMenuItemSpriteExtra* backBtn = CCMenuItemSpriteExtra::create(backBtnSprite, nullptr, this, menu_selector(LevelSelectLayer::onBack));
    backBtn->setSizeMult(1.6f);
    CCMenu* backMenu = CCMenu::create(backBtn, nullptr);
    this->addChild(backMenu, 1);
    backMenu->setPosition(CCPoint(pDirector->getScreenLeft() + 25.0f, pDirector->getScreenTop() - 22.0f));

    if (pGameManager->mUnknownBool2)
    {
        // TODO: Implement LevelSelectLayer::init
    }

    pGameManager->mUnknownBool2 = false;

    CCMenu* infoMenu = CCMenu::create();
    this->addChild(infoMenu);

    CCSprite* infoBtnSprite = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
    CCMenuItemSpriteExtra* infoBtn = CCMenuItemSpriteExtra::create(infoBtnSprite, nullptr, this, menu_selector(LevelSelectLayer::onInfo));
    infoBtn->setSizeMult(2.0f);
    infoMenu->addChild(infoBtn);

    infoMenu->setPosition(CCPoint(pDirector->getScreenRight() - 20.0f, pDirector->getScreenTop() - 20.0f));

    // TODO: Missing GameToolbox
    //if (controller)
    //    GameToolbox::addBackButton(this, backBtn);

    return true;
}

void LevelSelectLayer::keyBackClicked()
{
    this->onBack(nullptr);
}

void LevelSelectLayer::onBack(cocos2d::CCObject* pSender)
{
    this->setKeypadEnabled(false);

    CCDirector* pDirector = CCDirector::sharedDirector();
    CCScene* scene = MenuLayer::scene(false);
    CCTransitionFade* fade = CCTransitionFade::create(0.5f, scene);
    pDirector->replaceScene(fade);
}

void LevelSelectLayer::onPrev(cocos2d::CCObject* pSender)
{
    // TODO: Implement LevelSelectLayer::onPrev
}

void LevelSelectLayer::onNext(cocos2d::CCObject* pSender)
{
    // TODO: Implement LevelSelectLayer::onNext
}

void LevelSelectLayer::onInfo(cocos2d::CCObject* pSender)
{
    // TODO: Implement LevelSelectLayer::onInfo
}

void LevelSelectLayer::onDownload(cocos2d::CCObject* pSender)
{
    // TODO: Implement LevelSelectLayer::onDownload
}

void LevelSelectLayer::scrollLayerMoved(const cocos2d::CCPoint& point)
{
    // TODO: Implement LevelSelectLayer::scrollLayerMoved
}

void LevelSelectLayer::updatePageWithObject(cocos2d::CCObject* obj1, cocos2d::CCObject* obj2)
{
    LevelPage* page = (LevelPage*)obj1;
    GJGameLevel* level = (GJGameLevel*)obj2;

    page->updateDynamicPage(level);
}
