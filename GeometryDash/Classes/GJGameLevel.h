#ifndef __GJGAMELEVEL_H__
#define __GJGAMELEVEL_H__

#include "cocos2d.h"

class GJGameLevel : public cocos2d::CCNode
{
public:
    GJGameLevel();
    ~GJGameLevel() override;
    
    bool init() override;

    void setLevelID(int id);
    int getLevelID() { return mLevelIDEncrypted - mLevelIDKey; }

    void setDifficulty(int difficulty) { mDifficulty = difficulty; }
    int getDifficulty() { return mDifficulty; }

    void setLevelName(std::string name);
    std::string getLevelName();

    void setNormalPercent(int percent);
    int getNormalPercent();
    int getPracticePercent();

    void setStars(int stars);
    int getStars();

    int getCoinsRequired() { return mCoinsRequired; }

    int getCoinKey(int index);

    CREATE_FUNC(GJGameLevel);

protected:
    int mLevelIDEncrypted;
    int mLevelIDKey;
    int mLevelID;
    std::string mLevelName;

    int mDifficulty;

    int mNormalPercent;
    int mNormalPercentKey;
    int mNormalPercentEncrypted;

    int mPracticePercent;

    int mStars;
    int mStarsKey;
    int mStarsEncrypted;

    int mCoinsRequired;
};

#endif // __GJGAMELEVEL_H__