#include "GJGameLevel.h"

USING_NS_CC;

#define GEN_LEVEL_KEY() static_cast<int>((static_cast<float>(rand()) / 32767.0f) * 1000.0f)

GJGameLevel::GJGameLevel()
{
    mLevelIDEncrypted = 0;
    mLevelIDKey = 0;
    mLevelID = 0;
    mLevelName = "";

    mDifficulty = 0;
    mSongID = 0;

    mNormalPercent = 0;
    mNormalPercentKey = 0;
    mNormalPercentEncrypted = 0;
    mPracticePercent = 0;

    mDemon = 0;
    mDemonKey = 0;
    mDemonEncrypted = 0;

    mStars = 0;
    mStarsKey = 0;
    mStarsEncrypted = 0;

    mCoinsRequired = 0;

    mCapacityString = "";
}

GJGameLevel::~GJGameLevel()
{
    
}

bool GJGameLevel::init()
{
    mLevelName = "";

    // TODO: Implement GJGameLevel::init

    this->setStars(0);

    // TODO: Implement GJGameLevel::init

    return true;
}

void GJGameLevel::setLevelID(int id)
{
    mLevelID = id;
    mLevelIDKey = GEN_LEVEL_KEY();
    mLevelIDEncrypted = mLevelID + mLevelIDKey;
}

void GJGameLevel::setLevelName(std::string name)
{
    mLevelName = name;
}

std::string GJGameLevel::getLevelName()
{
    return mLevelName;
}

void GJGameLevel::setNormalPercent(int percent)
{
    mNormalPercent = percent;
    mNormalPercentKey = GEN_LEVEL_KEY();
    mNormalPercentEncrypted = mNormalPercent + mNormalPercentKey;
}

int GJGameLevel::getNormalPercent()
{
    return mNormalPercentEncrypted - mNormalPercentKey;
}

int GJGameLevel::getPracticePercent()
{
    return mPracticePercent;
}

void GJGameLevel::setStars(int stars)
{
    mStars = stars;
    mStarsKey = GEN_LEVEL_KEY();
    mStarsEncrypted = mStars + mStarsKey;
}

int GJGameLevel::getStars()
{
    return mStarsEncrypted - mStarsKey;
}

void GJGameLevel::setDemon(int demon)
{
    mDemon = demon;
    mDemonKey = GEN_LEVEL_KEY();
    mDemonEncrypted = mDemon + mDemonKey;
}

int GJGameLevel::getDemon()
{
    return mDemonEncrypted - mDemonKey;
}

int GJGameLevel::getCoinKey(int index)
{
    // TODO: Implement GJGameLevel::getCoinKey
    return 0;
}
