#include "GJBaseGameLayer.h"

USING_NS_CC;

GJBaseGameLayer::GJBaseGameLayer()
{
    mUnknownArray8 = nullptr;
    mUnknownArray1 = nullptr;
    mUnknownArray2 = nullptr;
    mUnknownArray3 = nullptr;
    mUnknownArray4 = nullptr;
    mUnknownArray5 = nullptr;
    mUnknownNode = nullptr;
    mUnknownArray6 = nullptr;
    mUnknownArray7 = nullptr;
    mUnknownDictionary1 = nullptr;
}

GJBaseGameLayer::~GJBaseGameLayer()
{
    
}

bool GJBaseGameLayer::init()
{
    if (!CCLayer::init())
        return false;

    mUnknownArray6 = cocos2d::CCArray::create();
    mUnknownArray6->retain();

    mUnknownArray8 = cocos2d::CCArray::create();
    mUnknownArray8->retain();

    // TODO: Missing OBB2D
    //mOBB2D = OBB2D::create(CCPoint(), 1.0f, 1.0f, 0.0f);
    //mOBB2D->retain();

    // TODO: Missing GJEffectManager
    //mEffectManager = GJEffectManager::create();
    //mEffectManager->retain();
    //this->addChild(mEffectManager);
    //mEffectManager->setVisible(false);
    // TODO: Implement GJBaseGameLayer::init

    mUnknownArray1 = cocos2d::CCArray::create();
    mUnknownArray1->retain();
    mUnknownArray2 = cocos2d::CCArray::create();
    mUnknownArray2->retain();
    mUnknownArray3 = cocos2d::CCArray::create();
    mUnknownArray3->retain();
    mUnknownArray5 = cocos2d::CCArray::create();
    mUnknownArray5->retain();
    mUnknownArray4 = cocos2d::CCArray::create();
    mUnknownArray4->retain();

    mUnknownDictionary1 = CCDictionary::create();
    mUnknownDictionary1->retain();

    mUnknownNode = CCNode::create();
    mUnknownNode->retain();

    mUnknownArray7 = cocos2d::CCArray::create();
    mUnknownArray7->retain();

    mUnknownDictionary2 = CCDictionary::create();
    mUnknownDictionary2->retain();

    mUnknownDictionary3 = CCDictionary::create();
    mUnknownDictionary3->retain();

    mUnknownDictionary4 = CCDictionary::create();
    mUnknownDictionary4->retain();

    mUnknownDictionary5 = CCDictionary::create();
    mUnknownDictionary5->retain();

    mArrVec1.resize(1101, nullptr);
    mArrVec2.resize(1101, nullptr);
    mArrVec3.resize(1101, nullptr);

    for (int i = 0; i < 1101; i++)
    {
        mArrVec1[i] = nullptr;
        mArrVec2[i] = nullptr;
        mArrVec3[i] = nullptr;
    }

    return true;
}

bool GJBaseGameLayer::shouldExitHackedLevel()
{
    // TODO: Implement GJBaseGameLayer::shouldExitHackedLevel
    return false;
}
