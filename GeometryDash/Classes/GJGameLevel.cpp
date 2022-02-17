#include "GJGameLevel.h"

USING_NS_CC;

#define GEN_LEVEL_KEY() static_cast<int>((static_cast<float>(rand()) / 32767.0f) * 1000.0f)

GJGameLevel::GJGameLevel()
{
    mLevelIDEncrypted = 0;
    mLevelIDKey = 0;
    mLevelID = 0;
}

GJGameLevel::~GJGameLevel()
{
    
}

bool GJGameLevel::init()
{
    // TODO: Implement GJGameLevel::init

    return true;
}

void GJGameLevel::setLevelID(int id)
{
    mLevelID = id;
    mLevelIDKey = GEN_LEVEL_KEY();
    mLevelIDEncrypted = mLevelID + mLevelIDKey;
}
