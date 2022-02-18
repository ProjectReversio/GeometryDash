#include "LevelPage.h"

#include "CCMenuItemSpriteExtra.h"
#include "GameObject.h"
#include "PlatformToolbox.h"
#include "GUI/CCControlExtension/CCScale9Sprite.h"

USING_NS_CC;

LevelPage::LevelPage()
{
    mUnknown1 = false;
    mLevel = nullptr;
    mMenu = nullptr;
    mUnknownSize1 = CCSize();
    mSecretCoin = nullptr;
    mSecretDoor = nullptr;
}

LevelPage::~LevelPage()
{
    if (mLevel)
        mLevel->release();
    if (mUnknownArray4)
        mUnknownArray4->release();
    if (mUnknownArray1)
        mUnknownArray1->release();
    if (mCoinArray)
        mCoinArray->release();
    if (mUnknownArray2)
        mUnknownArray2->release();
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

    mNormalPercentText = CCLabelBMFont::create(" ", "bigFont.fnt");
    this->addChild(mNormalPercentText, 4);
    mNormalPercentText->setPosition(pBarNormalSprite->getPosition());
    mNormalPercentText->setScale(0.5f);
    mUnknownArray1->addObject(mNormalPercentText);
    
    mPracticePercentText = CCLabelBMFont::create(" ", "bigFont.fnt");
    this->addChild(mPracticePercentText, 4);
    mPracticePercentText->setPosition(pBarPracticeSprite->getPosition());
    mPracticePercentText->setScale(0.5f);
    mUnknownArray1->addObject(mPracticePercentText);
    
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
    
    mLevelNameText = CCLabelBMFont::create(" ", "bigFont.fnt");
    mLevelNameText->setAnchorPoint(CCPoint(0.0f, 0.5f));
    mLevelInfoBox->addChild(mLevelNameText);
    mUnknownArray2->addObject(mLevelNameText);

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

    mCoinArray = CCArray::create();
    mCoinArray->retain();

    CCPoint point(mUnknownSize1.width - 16.0f, 16.0f);

    int index = 2;
    do
    {
        CCSprite* coinIcon = CCSprite::createWithSpriteFrameName("GJ_coinsIcon_001.png");
        mLevelInfoBox->addChild(coinIcon);
        coinIcon->setScale(1.0f);
        coinIcon->setPosition(point + CCPoint(index * -26.0f, 0.0f));
        mCoinArray->addObject(coinIcon);
        mUnknownArray2->addObject(coinIcon);
    } while (index-- != 0);

    mUnknownArray4 = CCArray::create();
    mUnknownArray4->retain();

    if (PlatformToolbox::isControllerConnected())
    {
        CCSprite* controllerStartBtn = CCSprite::createWithSpriteFrameName("controllerBtn_Start_001.png");
        sp->addChild(controllerStartBtn, 10);
        controllerStartBtn->setPosition(mLevelInfoBox->getPosition() + CCPoint(0.0f, -35.0f));
        mUnknownArray2->addObject(controllerStartBtn);
    }

    return true;
}

void LevelPage::updateDynamicPage(GJGameLevel* level)
{
    if (mUnknown1)
        return;

    if (mLevel)
    {
        if (mLevel->getLevelID() == level->getLevelID())
            return;
        mLevel->release();
        mLevel = nullptr;
    }

    for (int i = 0; ; i++)
    {
        if (i >= mUnknownArray4->count())
            break;

        CCNode* node = (CCNode*) mUnknownArray4->objectAtIndex(i);
        node->removeFromParent();
    }

    mUnknownArray4->removeAllObjects();
    mSecretDoor = nullptr;
    mLevel = level;
    mLevel->retain();

    if (mLevel->getLevelID() == -1)
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        CCSize winSize = pDirector->getWinSize();
        for (int i = 0; i < mUnknownArray1->count(); i++)
        {
            CCNode* node = (CCNode*)mUnknownArray1->objectAtIndex(i);
            node->setVisible(false);
        }

        CCLabelBMFont* comingSoonText = CCLabelBMFont::create("Coming Soon!", "bigFont.fnt");
        this->addChild(comingSoonText);
        comingSoonText->setPosition(CCPoint(winSize.width * 0.5f, winSize.height * 0.5f + 50.0f));

        mUnknownArray4->addObject(comingSoonText);
        this->addSecretDoor();

    }
    else
    {
        unsigned int j = 0;
        while (j < mUnknownArray1->count())
        {
            CCNode* node = (CCNode*)mUnknownArray1->objectAtIndex(j++);
            node->setVisible(true);
        }

        for (int i = 0; i < mUnknownArray2->count(); i++)
        {
            CCNode* node = (CCNode*)mUnknownArray2->objectAtIndex(i);
            node->setVisible(true);
        }

        float normPercent = mUnknownFloat1;

        if (normPercent > (mUnknownFloat1 * (static_cast<float>(mLevel->getNormalPercent()) / 100.0f)))
            normPercent = mUnknownFloat1 * (static_cast<float>(mLevel->getNormalPercent()) / 100.0f);

        mProgressBarNormal->setTextureRect(CCRect(0.0f, 0.0f, normPercent, mProgressBarNormal->getTextureRect().size.height));

        float pracPercent = mUnknownFloat1;
        if (pracPercent > (mUnknownFloat1 * (mLevel->getPracticePercent() / 100.0f)))
            pracPercent = mUnknownFloat1 * (mLevel->getPracticePercent() / 100.0f);

        mProgressBarPractice->setTextureRect(CCRect(0.0f, 0.0f, pracPercent, mProgressBarPractice->getTextureRect().size.height));

        CCString* normalPercentText = CCString::createWithFormat("%i%%", mLevel->getNormalPercent());
        mNormalPercentText->setString(normalPercentText->getCString());

        CCString* practicePercentText = CCString::createWithFormat("%i%%", mLevel->getPracticePercent());
        mPracticePercentText->setString(practicePercentText->getCString());

        // TODO: Missing GameStatsManager
        //GameStatsManager* pStatsManager = GameStatsManager::sharedState();
        //int totalCoins = pStatsManager->getStat("8");
        int totalCoins = 0;

        mLevelNameText->setScale(1.0f);
        mLevelNameText->setString(mLevel->getLevelName().c_str());
        if (mLevelNameText->getContentSize().width > 250.0f)
            mLevelNameText->setScale(250.0f / mLevelNameText->getContentSize().width);
        if (mLevelNameText->getScale() > 1.0f)
            mLevelNameText->setScale(1.0f);
        else
            mLevelNameText->setScale(mLevelNameText->getScale()); // The original game did this, even though it's not needed

        int diff = 1;
        int diff2 = mLevel->getDifficulty();
        if (diff2 > 0)
        {
            diff = diff2;
            if (diff2 > 6)
                diff = 6;
        }

        CCSpriteFrameCache* pFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();

        CCString* diffString = CCString::createWithFormat("diffIcon_%02d_btn_001.png", diff);
        mDifficultySprite->setDisplayFrame(pFrameCache->spriteFrameByName(diffString->getCString()));

        CCRect diffRect = mDifficultySprite->getTextureRect();
        float diffX = diffRect.size.width * mDifficultySprite->getScale() * 0.5f;

        float unknownText3ContentWidth = mLevelNameText->getContentSize().width;
        float unknownText3Scale = mLevelNameText->getScale();

        mDifficultySprite->setPosition(CCPoint((mUnknownSize1.width * 0.5f - (float)((float)((float)(diffX + (float)((float)(unknownText3ContentWidth * unknownText3Scale) + 5.0)) + 30.0) * 0.5)) + diffX, mUnknownSize1.height * 0.5f + 3.0f));

        mLevelNameText->setPosition(CCPoint(mDifficultySprite->getPosition().x + 30.0f, mUnknownSize1.height * 0.5f + 3.0f));

        CCString* starText = CCString::createWithFormat("%i", mLevel->getStars());
        mUnknownText4->setString(starText->getCString());

        // TODO: Missing GameStatsManager
        //if (pStatsManager->hasCompletedStarLevel(mLevel))
        if (false)
        {
            mUnknownText4->setColor({255, 255, 50});
        } else
        {
            mUnknownText4->setColor(ccWHITE);
        }

        int index = 1;
        do
        {
            // TODO: Missing GameStatsManager
            bool hasCoin = false;//pStatsManager->hasSecretCoin(mLevel->getCoinKey(index));

            const char* coinIconName = "GJ_coinsIcon_gray_001.png";
            if (hasCoin)
                coinIconName = "GJ_coinsIcon_001.png";

            CCSprite* coinSprite = (CCSprite*)mCoinArray->objectAtIndex(index - 1);
            coinSprite->setDisplayFrame(pFrameCache->spriteFrameByName(coinIconName));
            if (hasCoin)
                coinSprite->setColor({255, 255, 255});
            else
                coinSprite->setColor({ 225, 225, 225 });

            index++;
        } while (index != 4);

        int requiredCoins = mLevel->getCoinsRequired();
        if (requiredCoins > totalCoins)
        {
            int index2 = 0;
            while (index2 < mUnknownArray2->count())
            {
                CCNode* node = (CCNode*)mUnknownArray2->objectAtIndex(index2++);
                node->setVisible(false);
            }

            CCSprite* lockSprite = CCSprite::createWithSpriteFrameName("GJLargeLock_001.png");
            mLevelInfoBox->addChild(lockSprite);
            lockSprite->setPosition(CCPoint(mUnknownSize1.width * 0.5f, mUnknownSize1.height * 0.5f));

            CCSprite* coinLockSprite = CCSprite::createWithSpriteFrameName("GJ_coinsIcon_001.png");
            mLevelInfoBox->addChild(coinLockSprite);
            coinLockSprite->setScale(1.0f);
            coinLockSprite->setPosition(CCPoint(mUnknownSize1.width - 15.0f, 15.0f));

            CCString* requiredCoinsText = CCString::createWithFormat("%i/%i", totalCoins, requiredCoins);
            CCLabelBMFont* requiredCoinsLabel = CCLabelBMFont::create(requiredCoinsText->getCString(), "bigFont.fnt");
            mLevelInfoBox->addChild(requiredCoinsLabel);
            requiredCoinsLabel->setAnchorPoint(CCPoint(1.0f, 0.5f));
            requiredCoinsLabel->setPosition(coinLockSprite->getPosition() + CCPoint(-15.0f, 0.5f));
            requiredCoinsLabel->setScale(0.7f);

            mUnknownArray4->addObject(lockSprite);
            mUnknownArray4->addObject(coinLockSprite);
            mUnknownArray4->addObject(requiredCoinsLabel);
        }
    }

    if (mSecretCoin)
    {
        mSecretCoin->setVisible(mLevel->getLevelID() == -1);
    }

    mUnknown1 = false;
}

void LevelPage::addSecretDoor()
{
    // TODO: Implement LevelPage::addSecretDoor
}

void LevelPage::onPlay(cocos2d::CCObject* pSender)
{
    // TODO: Implement LevelPage::onPlay
}
