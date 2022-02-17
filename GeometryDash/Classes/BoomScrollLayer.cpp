#include "BoomScrollLayer.h"

#include "ExtendedLayer.h"

USING_NS_CC;

BoomScrollLayer::BoomScrollLayer()
{
    mUnknownArray2 = nullptr;
    mUnknownBool1 = false;
    mUnknown555 = nullptr;
    mUnknownArray0 = nullptr;
    mUnknown6 = false;
    mUnknownArray1 = nullptr;
    mUnknownPoint1 = CCPoint();
    mUnknown1 = nullptr;
    mUnknownRect1 = CCRect();
    mUnknownFloat4 = 0.0f;
    mUnknownFloat5 = 0.0f;
    mUnknownFloat6 = 0.0f;
    mUnknownFloat1 = 0.0f;
    mUnknownFloat2 = 0.0f;
    mUnknownFloat3 = 0.0f;
    mUnknown2 = false;
    mUnknown3 = false;
    mUnknownPoint2 = CCPoint();
    mUnknown4 = 0;
    mUnknown5 = 0.0f;
    mUnknownRect2 = CCRect();
}

BoomScrollLayer::~BoomScrollLayer()
{
    
}

bool BoomScrollLayer::init(cocos2d::CCArray* a1, int a2, bool a3, cocos2d::CCArray* a4, DynamicScrollDelegate* scroll)
{
    if (!CCLayer::init())
        return false;

    mUnknown1 = ExtendedLayer::create();
    this->addChild(mUnknown1);

    // TODO: Missing some variable in CCObject?
    //CCObjectUnknown1 = 4;

    this->setTouchEnabled(true);

    mUnknown2 = true;
    mUnknownFloat1 = 40.0f;
    mUnknownFloat2 = 100.0f;

    CCDirector* pDirector = CCDirector::sharedDirector();
    CCSize winSize = pDirector->getWinSize();
    mUnknownFloat3 = winSize.width;
    mUnknown3 = true;
    this->setPagesIndicatorPosition(CCPoint(this->getContentSize().width * 0.5f, 60.0f));

    mUnknownByte5 = 150;
    mUnknownByte6 = 150;
    mUnknownByte7 = 150;
    mUnknownByte8 = 255;
    mUnknownByte1 = 255;
    mUnknownByte2 = 255;
    mUnknownByte3 = 255;
    mUnknownByte4 = 255;

    mUnknownRect1 = CCRect(0.0f, 0.0f, winSize.width, winSize.height);

    mUnknown4 = 0;
    mUnknownFloat4 = 0.3f;
    mUnknownFloat6 = 0.4f;
    mUnknownFloat5 = 0.6f;
    mUnknown5 = a2;
    mUnknownArray1 = a1;
    mUnknownArray1->retain();

    CCSpriteBatchNode* smallDots = CCSpriteBatchNode::create("smallDot.png", 29);
    this->addChild(smallDots, 5);

    this->updatePages();

    mUnknownBool1 = a3;

    if (mUnknownBool1)
        this->repositionPagesLooped();
    if (a4)
        this->setupDynamicScrolling(a4, scroll);

    mUnknownArray2 = CCArray::create();
    mUnknownArray2->retain();

    for (int i = 0; i < this->getTotalPages(); i++)
    {
        CCSprite* smallDot = CCSprite::create("smallDot.png");
        smallDots->addChild(smallDot);
        mUnknownArray2->addObject(smallDot);
    }

    this->schedule(schedule_selector(BoomScrollLayer::updateDots), 0.1f);

    return true;
}

int BoomScrollLayer::pageNumberForPosition(cocos2d::CCPoint point)
{
    const float f = (-(mUnknown1->getPosition().x)) / this->getContentSize().width - mUnknown5;
    const int i = static_cast<int>(ceilf(f));

    int i2 = i - ((static_cast<float>(i) - f >= 0.5f) ? 1 : 0);

    if (!mUnknownBool1)
    {
        i2 &= ~i2 >> 31;
        const int total = this->getTotalPages();
        if (total - 1 < i2)
            i2 = total - 1;
    }

    return i2;
}

int BoomScrollLayer::getRelativePageForNum(int num)
{
    const int total = this->getTotalPages();

    if (num > 0)
        return num % total;

    int n = num;
    while (n < 0)
        n += total;

    return n;
}

void BoomScrollLayer::setPagesIndicatorPosition(cocos2d::CCPoint point)
{
    mUnknownPoint2 = point;
    this->updateDots(0.0f);
}

void BoomScrollLayer::instantMoveToPage(int page)
{
    // TODO: Implement BoomScrollLayer::instantMoveToPage
}

void BoomScrollLayer::updatePages()
{
    CCDirector* pDirector = CCDirector::sharedDirector();

    unsigned int index = 0;
    while(true)
    {
        if (index >= mUnknownArray1->count())
            break;

        CCLayer* pageLayer = (CCLayer*)mUnknownArray1->objectAtIndex(index);

        pageLayer->setAnchorPoint(CCPoint(0.0f, 0.0f));
        pageLayer->setContentSize(pDirector->getWinSize());
        pageLayer->setPosition(CCPoint(index * (this->getContentSize().width - mUnknown5), 0.0f));

        if (!pageLayer->getParent())
            mUnknown1->addChild(pageLayer);

        index++;
    }
}

void BoomScrollLayer::repositionPagesLooped()
{
    // TODO: Implement BoomScrollLayer::repositionPagesLooped
}

void BoomScrollLayer::setupDynamicScrolling(cocos2d::CCArray* arr, DynamicScrollDelegate* scroll)
{
    mUnknown555 = scroll;
    if (mUnknownArray0)
        mUnknownArray0->release();
    mUnknownArray0 = arr;
    mUnknownArray0->retain();
    mUnknown6 = true;
    CCLayer* layer = (CCLayer*)mUnknownArray1->lastObject();
    
    // TODO: Implement BoomScrollLayer::setupDynamicScrolling

    mUnknown555->updatePageWithObject(mUnknownArray1->lastObject(), mUnknownArray0->lastObject());
    mUnknown555->updatePageWithObject(mUnknownArray1->objectAtIndex(0), mUnknownArray0->objectAtIndex(0));
    mUnknown555->updatePageWithObject(mUnknownArray1->objectAtIndex(1), mUnknownArray0->objectAtIndex(1));

    // TODO: Implement BoomScrollLayer::setupDynamicScrolling
}

int BoomScrollLayer::getTotalPages()
{
    if (mUnknown6)
        return mUnknownArray0->count();

    return mUnknownArray1->count();
}

void BoomScrollLayer::updateDots(float f)
{
    if (mUnknownArray2)
    {
        int totalPages = this->getTotalPages();

        float y = mUnknownPoint2.y;
        
        int num = this->pageNumberForPosition(mUnknown1->getPosition());

        if (mUnknownBool1)
            num = this->getRelativePageForNum(num);

        for (int i = 0; i < totalPages; i++)
        {
            float x = mUnknownPoint2.x;
            
            if (i < mUnknownArray2->count())
            {
                CCSprite* sprite = (CCSprite*)mUnknownArray2->objectAtIndex(i);
                sprite->setPosition(CCPoint(x + (i - (totalPages - 1.0f) * 0.5f) * 16.0f, y));

                if (i == num)
                {
                    sprite->setColor(ccWHITE);
                } else
                {
                    sprite->setColor({125, 125, 125});
                }

                sprite->setVisible(mUnknown3);
            }
        }

    }
}

BoomScrollLayer* BoomScrollLayer::create(cocos2d::CCArray* a1, int a2, bool a3, cocos2d::CCArray* a4, DynamicScrollDelegate* scroll)
{
    BoomScrollLayer* pRet = new BoomScrollLayer();
    if (pRet && pRet->init(a1, a2, a3, a4, scroll))
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

BoomScrollLayer* BoomScrollLayer::create(cocos2d::CCArray* a1, int a2, bool a3)
{
    return BoomScrollLayer::create(a1, a2, a3, nullptr, nullptr);
}
