#include "LoadingLayer.h"

#include "AppDelegate.h"
#include "GameManager.h"
#include "TextArea.h"
#include "gameConfig.h"

USING_NS_CC;

CCScene* LoadingLayer::scene(bool reload)
{
    // 'scene' is an autorelease object
    CCScene* scene = CCScene::create();

    // 'layer' is an autorelease object
    LoadingLayer* layer = LoadingLayer::create(reload);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

LoadingLayer* LoadingLayer::create(bool reload)
{
    LoadingLayer* pRet = new LoadingLayer();
    if (pRet && pRet->init(reload))
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

LoadingLayer::LoadingLayer()
{
    mUnknownBool1 = false;
    mProgressBarSize = CCSize(0.0f, 0.0f);
    mStage = 0;
    mLoadingTextLabel = nullptr;
    mLoadingTextArea = nullptr;
    mSliderBar = nullptr;
    mReload = false;
}

LoadingLayer::~LoadingLayer()
{
    
}

// on "init" you need to initialize your instance
bool LoadingLayer::init(bool reload)
{
    //////////////////////////////
    // 1. super init first
    if (!CCLayer::init())
    {
        return false;
    }

    mReload = reload;
    if (!mReload)
    {
        // TODO: Stuff goes here.
    }

    // TODO: Stuff goes here.

    CCTextureCache* pTextureCache = CCTextureCache::sharedTextureCache();
    pTextureCache->addImage("GJ_LaunchSheet.png");

    CCSpriteFrameCache* pSpriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
    pSpriteFrameCache->addSpriteFramesWithFile("GJ_LaunchSheet.plist");

    CCDirector* pDirector = CCDirector::sharedDirector();
    CCSize winSize = pDirector->getWinSize();

    GameManager* pGameManager = GameManager::sharedState();
    const char* bgTextureName = pGameManager->getBGTexture(1);
    CCSprite* bgSprite = CCSprite::create(bgTextureName);
    this->addChild(bgSprite);
    
    bgSprite->setPosition(winSize * 0.5f);
    bgSprite->setScale(AppDelegate::get()->bgScale());
    ccColor3B bgColor { 0, 102, 255 };
    bgSprite->setColor(bgColor);


    CCSprite* gjLogo = CCSprite::createWithSpriteFrameName("GJ_logo_001.png");
    this->addChild(gjLogo);
    gjLogo->setPosition(CCPoint(winSize.width * 0.5f, winSize.height * 0.5f + 26.0f));

    CCSprite* robTopLogo = CCSprite::createWithSpriteFrameName("RobTopLogoBig_001.png");
    this->addChild(robTopLogo);
    const CCPoint gjLogoPos = gjLogo->getPosition();
    const CCPoint logoPos2(0.0f, 80.0f);
    robTopLogo->setPosition(logoPos2 + gjLogoPos);

#if defined(GD_SUBZERO)
    CCSprite* subZeroLogo = CCSprite::createWithSpriteFrameName("gj_subzeroLogo_001.png");
    this->addChild(subZeroLogo, 2);
    const CCPoint logoPos3(140.0f, -46.0f);
    subZeroLogo->setPosition(logoPos3 + gjLogoPos);
#elif defined(GD_MELTDOWN)
    CCSprite* subZeroLogo = CCSprite::createWithSpriteFrameName("GJ_md_001.png");
    this->addChild(subZeroLogo, 2);
    const CCPoint logoPos3(140.0f, -46.0f);
    subZeroLogo->setPosition(logoPos3 + gjLogoPos);
#elif defined(GD_WORLD)
    CCSprite* subZeroLogo = CCSprite::createWithSpriteFrameName("gj_worldLogo_001.png");
    this->addChild(subZeroLogo, 2);
    const CCPoint logoPos3(120.0f, -46.0f);
    subZeroLogo->setPosition(logoPos3 + gjLogoPos);
#endif

    // TODO: Stuff goes here
    
    mLoadingTextLabel = CCLabelBMFont::create(getLoadingString(), "goldFont.fnt");
    this->addChild(mLoadingTextLabel);
    const CCPoint loadingTextPos(winSize.width * 0.5f, winSize.height * 0.5f - 70.0f);
    mLoadingTextLabel->setPosition(loadingTextPos);
    mLoadingTextLabel->setScale(0.7f);
    mLoadingTextLabel->setVisible(false);

    mLoadingTextArea = TextArea::create(getLoadingString(), "goldFont.fnt", 1.0f, 440.0f, CCPoint(0.5f, 0.5f), 28.0f, false);
    this->addChild(mLoadingTextArea);
    mLoadingTextArea->setPosition(CCPoint(winSize.width * 0.5f, winSize.height * 0.5f - 100.0f));
    mLoadingTextArea->setScale(0.7f);

    if (mLoadingTextLabel->getContentSize().width > 300.0f)
    {
        mLoadingTextLabel->setScale(300.0f / mLoadingTextLabel->getContentSize().width);
    }

    float textScale;
    if (mLoadingTextLabel->getScale() < 0.7f)
    {
        textScale = mLoadingTextLabel->getScale();
    } else
    {
        textScale = 0.7f;
    }

    mLoadingTextLabel->setScale(textScale);

    CCSprite* sliderGroove = CCSprite::create("slidergroove.png");
    this->addChild(sliderGroove, 3);

    mSliderBar = CCSprite::create("sliderBar.png");
    mProgressBarSize = CCSize(sliderGroove->getTextureRect().size.width - 4.0f, 8.0f);

    CCTexture2D* tex = mSliderBar->getTexture();
    ccTexParams params { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
    tex->setTexParameters(&params);

    sliderGroove->addChild(mSliderBar, -1);
    mSliderBar->setAnchorPoint(CCPoint(0.0f, 0.0f));
    mSliderBar->setPosition(CCPoint(2.0f, 4.0f));
    
    sliderGroove->setPosition(CCPoint(mLoadingTextLabel->getPosition().x, mLoadingTextArea->getPosition().y + 40.0f));

    this->updateProgress(0);

    CCActionManager* pActionManager = pDirector->getActionManager();
    CCDelayTime* delayTime = CCDelayTime::create(0.0f);
    CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(LoadingLayer::loadAssets));
    CCSequence* sequence = CCSequence::create(delayTime, callFunc, nullptr);
    pActionManager->addAction(sequence, this, false);

    if (!mReload)
    {
        // TODO: Stuff goes here
    }

    return true;
}

void LoadingLayer::updateProgress(int progress)
{
    float width = mProgressBarSize.width;
    if (width > (width * static_cast<float>(progress) / 100.0f))
        width = width * static_cast<float>(progress) / 100.0f;

    mSliderBar->setTextureRect(CCRect(0.0f, 0.0f, width, mProgressBarSize.height));
}

void LoadingLayer::loadAssets()
{
    CCDirector* pDirector = CCDirector::sharedDirector();

    switch (mStage)
    {
    case 0:
    default:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        break;
    case 13:
        break;
    case 14:
        updateProgress(100); // <- not in the original but it makes the progress bar actually render as full

        AppDelegate* pApp = AppDelegate::get();
        pApp->loadingIsFinished();
        if (!mReload)
        {
            // TODO: Stuff goes here
        }

        loadingFinished();
        return;
    }

    mStage++;
    mUnknownBool1 = true;
    updateProgress(mStage * 7);
    CCActionManager* pActionManager = pDirector->getActionManager();
    CCDelayTime* delayTime = CCDelayTime::create(0.01f);
    CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(LoadingLayer::loadAssets));
    CCSequence* sequence = CCSequence::create(delayTime, callFunc, nullptr);
    pActionManager->addAction(sequence, this, false);
}

void LoadingLayer::loadingFinished()
{
    // TODO: Implement LoadingLayer::loadingFinished
}

const char* LoadingLayer::getLoadingString()
{
    if (mReload)
        return "Loading resources";

    switch (rand() % 60)
    {
    case 1:
        return "Listen to the music to help time your jumps";
    case 2:
        return  "Back for more are ya?";
    case 3:
        return  "Use practice mode to learn the layout of a level";
    case 4:
        return  "If at first you don't succeed, try, try again...";
    case 5:
        return  "Customize your character's icon and color!";
    case 6:
        return  "You can download all songs from the level select page!";
    case 7:
        return  "Spikes are not your friends, don't forget to jump";
    case 8:
        return  "Build your own levels using the level editor";
    case 9:
        return  "Go online to play other players levels!";
    case 10:
        return  "Can you beat them all?";
    case 11:
        return  "Here be dragons...";
    case 12:
        return  "Pro tip: Don't crash";
    case 13:
        return  "Hold down to keep jumping";
    case 14:
        return  "The spikes whisper to me...";
    case 15:
        return  "Looking for pixels";
    case 16:
        return  "Loading awesome soundtracks...";
    case 17:
        return  "What if the spikes are the good guys?";
    case 18:
        return  "Pro tip: Jump";
    case 19:
        return  "Does anyone even read this?";
    case 20:
        return  "Collecting scrap metal";
    case 21:
        return  "Waiting for planets to align";
    case 22:
        return  "Starting the flux capacitor";
    case 23:
        return  "Wandering around aimlessly";
    case 24:
        return  "Where did I put that coin...";
    case 25:
        return  "Loading the progressbar";
    case 26:
        return  "Calculating chance of success";
    case 27:
        return  "Hiding secrets";
    case 28:
        return  "Drawing pretty pictures";
    case 29:
        return  "Programmer is sleeping, please wait";
    case 30:
        return  "RobTop is Love, RobTop is Life";
    case 31:
        return  "Play, Crash, Rage, Quit, Repeat";
    case 32:
        return  "Only one button required to crash";
    case 33:
        return  "Such wow, very amaze.";
    case 34:
        return  "Fus Ro DASH!";
    case 35:
        return  "Loading Rage Cannon";
    case 36:
        return  "Counting to 1337";
    case 37:
        return  "It's all in the timing";
    case 38:
        return  "Fake spikes are fake";
    case 39:
        return  "Spikes... OF DOOM!";
    case 40:
        return  "Why don't you go outside?";
    case 41:
        return  "Loading will be finished... soon";
    case 42:
        return  "This seems like a good\nplace to hide a secret...";
    case 43:
        return  "The Vault Keeper's name is 'Spooky'...";
    case 44:
        return  "Hope the big guy doesn't wake up...";
    case 45:
        return  "Shhhh! You're gonna wake the big one!";
    case 46:
        return  "I have been expecting you.";
    case 47:
        return  "A wild RubRub appeared!";
    case 48:
        return  "So many secrets...";
    case 49:
        return  "Hiding rocket launcher";
    case 50:
        return  "It's Over 9000!";
    case 51:
        return  "Programming amazing AI";
    case 52:
        return  "Hiding secret vault";
    case 53:
        return  "Spooky doesn't get out much";
    case 54:
        return  "RubRub was here";
    case 55:
        return  "Warp Speed";
    case 56:
        return  "So, what's up?";
    case 57:
        return  "Hold on, reading the manual";
    case 58:
        return  "I don't know how this works...";
    case 59:
        return  "Why u have to be mad?";
    case 60:
        return  "It is only game...";
    default:
        return "Unlock new icons and colors by completing achievements!";
    }
}
