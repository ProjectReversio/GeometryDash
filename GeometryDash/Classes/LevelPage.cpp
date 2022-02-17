#include "LevelPage.h"

#include "CCMenuItemSpriteExtra.h"
#include "PlatformToolbox.h"
#include "GUI/CCControlExtension/CCScale9Sprite.h"

USING_NS_CC;

LevelPage::LevelPage()
{
    
}

LevelPage::~LevelPage()
{
    
}

LevelPage* LevelPage::create(GJGameLevel* level)
{
    LevelPage* pRet = new LevelPage();
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

bool LevelPage::init(GJGameLevel* level)
{
    if (!CCLayer::init())
        return false;

    this->setTouchEnabled(true);

    CCDirector* pDirector = CCDirector::sharedDirector();
    CCSize winSize = pDirector->getWinSize();

    mUnknownSize1 = CCSize(340.0f, 95.0f);

    mUnknownArray1 = CCArray::create();
    mUnknownArray1->retain();

    mUnknownArray2 = CCArray::create();
    mUnknownArray2->retain();

    mMenu = CCMenu::create();
    this->addChild(mMenu, -1);
    mMenu->setPosition(CCPoint(winSize.width * 0.5f, winSize.height * 0.5f + 60));

    CCRect rect(0.0f, 0.0f, 80.0f, 80.0f);
    mLevelInfoBox = extension::CCScale9Sprite::create("square02_001.png", rect);
    mLevelInfoBox->setOpacity(125);
    mLevelInfoBox->setContentSize(mUnknownSize1);
    mLevelInfoBox->setPosition(CCPoint(winSize.width * 0.5f, winSize.height * 0.5f + 50.0f));

    CCSprite* sp = CCSprite::create();
    sp->addChild(mLevelInfoBox);
    sp->setContentSize(mLevelInfoBox->getContentSize());
    mLevelInfoBox->setPosition(mLevelInfoBox->getContentSize() * 0.5f);

    CCMenuItemSpriteExtra* playButton = CCMenuItemSpriteExtra::create(sp, nullptr, this, menu_selector(LevelPage::onPlay));
    playButton->setSelectedScale(1.1f);
    mMenu->addChild(playButton);

    mUnknownArray1->addObject(mMenu);

    // --------------------------------------------------------------------------------
    // Normal Bar
    // --------------------------------------------------------------------------------

    CCSprite* pBarNormalSprite = CCSprite::create("GJ_progressBar_001.png");
    pBarNormalSprite->setColor(ccBLACK);
    pBarNormalSprite->setOpacity(125);
    pBarNormalSprite->setScale(1.0f);
    this->addChild(pBarNormalSprite, 3);
    pBarNormalSprite->setPosition(CCPoint(winSize.width * 0.5f, winSize.height * 0.5f - 30.0f));

    mUnknownArray1->addObject(pBarNormalSprite);

    mProgressBarNormal = CCSprite::create("GJ_progressBar_001.png");
    mProgressBarNormal->setScaleX(0.992f);
    mProgressBarNormal->setScaleY(0.86f);
    mProgressBarNormal->setColor({0, 255, 0});

    CCRect pBarRectNormal = mProgressBarNormal->getTextureRect();

    mUnknownFloat1 = pBarRectNormal.size.width;

    float valNormal = pBarRectNormal.size.width - pBarRectNormal.size.width * 0.992f;

    pBarNormalSprite->addChild(mProgressBarNormal, 1);

    mProgressBarNormal->setAnchorPoint(CCPoint(0.0f, 0.5f));
    mProgressBarNormal->setPosition(CCPoint(valNormal * 0.5f, pBarNormalSprite->getContentSize().height * 0.5f));

    // --------------------------------------------------------------------------------
    // Practice Bar
    // --------------------------------------------------------------------------------

    CCSprite* pBarPracticeSprite = CCSprite::create("GJ_progressBar_001.png");
    pBarPracticeSprite->setColor(ccBLACK);
    pBarPracticeSprite->setOpacity(125);
    pBarPracticeSprite->setScale(1.0f);
    this->addChild(pBarPracticeSprite, 3);
    pBarPracticeSprite->setPosition(pBarNormalSprite->getPosition() + CCPoint(0.0f, -50.0f));
    mUnknownArray1->addObject(pBarPracticeSprite);

    mProgressBarPractice = CCSprite::create("GJ_progressBar_001.png");
    mProgressBarPractice->setScaleX(0.992f);
    mProgressBarPractice->setScaleY(0.86f);
    mProgressBarPractice->setColor({ 0, 255, 255 });
    pBarPracticeSprite->addChild(mProgressBarPractice, 1);
    mProgressBarPractice->setAnchorPoint(CCPoint(0.0f, 0.5f));
    mProgressBarPractice->setPosition(mProgressBarNormal->getPosition());

    // --------------------------------------------------------------------------------

    mUnknownText1 = CCLabelBMFont::create(" ", "bigFont.fnt");
    this->addChild(mUnknownText1, 4);
    mUnknownText1->setPosition(pBarNormalSprite->getPosition());
    mUnknownText1->setScale(0.5f);
    mUnknownArray1->addObject(mUnknownText1);
    
    mUnknownText2 = CCLabelBMFont::create(" ", "bigFont.fnt");
    this->addChild(mUnknownText2, 4);
    mUnknownText2->setPosition(pBarPracticeSprite->getPosition());
    mUnknownText2->setScale(0.5f);
    mUnknownArray1->addObject(mUnknownText2);
    
    CCLabelBMFont* normalText = CCLabelBMFont::create("Normal Mode", "bigFont.fnt");
    this->addChild(normalText, 4);
    normalText->setPosition(pBarNormalSprite->getPosition() + CCPoint(0.0f, 20.0f));
    normalText->setScale(0.5f);
    mUnknownArray1->addObject(normalText);

    CCLabelBMFont* practiceText = CCLabelBMFont::create("Practice Mode", "bigFont.fnt");
    this->addChild(practiceText, 4);
    practiceText->setPosition(pBarPracticeSprite->getPosition() + CCPoint(0.0f, 20.0f));
    practiceText->setScale(0.5f);
    mUnknownArray1->addObject(practiceText);
    
    mUnknownText3 = CCLabelBMFont::create(" ", "bigFont.fnt");
    mUnknownText3->setAnchorPoint(CCPoint(0.0f, 0.5f));
    mLevelInfoBox->addChild(mUnknownText3);
    mUnknownArray2->addObject(mUnknownText3);

    mDifficultySprite = CCSprite::createWithSpriteFrameName("diffIcon_01_btn_001.png");
    mLevelInfoBox->addChild(mDifficultySprite);
    mDifficultySprite->setScale(1.1f);
    mUnknownArray2->addObject(mDifficultySprite);
    
    mStarSprite = CCSprite::createWithSpriteFrameName("GJ_starsIcon_001.png");
    mLevelInfoBox->addChild(mStarSprite);
    mStarSprite->setScale(0.7f);
    mStarSprite->setPosition(CCPoint(mUnknownSize1.width - 15.0f, mUnknownSize1.height - 13.0f));
    mUnknownArray2->addObject(mStarSprite);

    mUnknownText4 = CCLabelBMFont::create(" ", "bigFont.fnt");
    mLevelInfoBox->addChild(mUnknownText4);
    mUnknownText4->setAnchorPoint(CCPoint(1.0f, 0.5f));
    mUnknownText4->setPosition(mStarSprite->getPosition() + CCPoint(-12.0f, 0.5f));
    mUnknownText4->setScale(0.5f);
    mUnknownArray2->addObject(mUnknownText4);

    mUnknownArray3 = CCArray::create();
    mUnknownArray3->retain();

    CCPoint point(mUnknownSize1.width - 16.0f, 16.0f);

    int index = 2;
    do
    {
        CCSprite* coinIcon = CCSprite::createWithSpriteFrameName("GJ_coinsIcon_001.png");
        mLevelInfoBox->addChild(coinIcon);
        coinIcon->setScale(1.0f);
        coinIcon->setPosition(point + CCPoint(index * -26.0f, 0.0f));
        mUnknownArray3->addObject(coinIcon);
        mUnknownArray2->addObject(coinIcon);
    } while (index-- != 0);

    mUnknownArray4 = CCArray::create();
    mUnknownArray4->retain();

    if (PlatformToolbox::isControllerConnected())
    {
        // TODO: Implement LevelPage::init
    }

    return true;
}

void LevelPage::updateDynamicPage(GJGameLevel* level)
{
    // TODO: Implement LevelPage::updateDynamicPage

    CCRect diffRect = mDifficultySprite->getTextureRect();
    float diffX = diffRect.size.width * mDifficultySprite->getScale() * 0.5f;

    float unknownText3ContentWidth = mUnknownText3->getContentSize().width;
    float unknownText3Scale = mUnknownText3->getScale();

    mDifficultySprite->setPosition(CCPoint(mUnknownSize1.width * 0.5f - (float)((float)((float)(diffX + (float)((float)(unknownText3ContentWidth * unknownText3Scale) + 5.0)) + 30.0) * 0.5), mUnknownSize1.height * 0.5f + 3.0f));

    // TODO: Implement LevelPage::updateDynamicPage
}

void LevelPage::onPlay(cocos2d::CCObject* pSender)
{
    // TODO: Implement LevelPage::onPlay
}
