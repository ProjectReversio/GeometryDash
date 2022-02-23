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

    void setDemon(int demon);
    int getDemon();

    void setCoinsRequired(int amount) { mCoinsRequired = amount; }
    int getCoinsRequired() { return mCoinsRequired; }

    void setSongID(int songId) { mSongID = songId; }
    int getSongID() { return mSongID; }

    void setCapacityString(std::string capacityString) { mCapacityString = capacityString; }
    std::string getCapacityString() { return mCapacityString; }

    void setLevelString(std::string levelString) { mLevelString = levelString; }
    std::string getLevelString() { return mLevelString; }

    int getCoinKey(int index);

    CREATE_FUNC(GJGameLevel);

public:
    int mUnknown7;

protected:
    int mLevelIDEncrypted;
    int mLevelIDKey;
    int mLevelID;
    std::string mLevelName;
    std::string mLevelString;
    std::string mCapacityString;

    int mDifficulty;

    int mNormalPercent;
    int mNormalPercentKey;
    int mNormalPercentEncrypted;

    int mPracticePercent;

    int mStars;
    int mStarsKey;
    int mStarsEncrypted;

    int mCoinsRequired;

    int mSongID;

    int mDemon;
    int mDemonKey;
    int mDemonEncrypted;
};

#endif // __GJGAMELEVEL_H__