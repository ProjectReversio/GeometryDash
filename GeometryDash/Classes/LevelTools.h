#ifndef __LEVELTOOLS_H__
#define __LEVELTOOLS_H__

#include "cocos2d.h"

class GJGameLevel;

class LevelTools
{
public:
    static GJGameLevel* getLevel(int levelId, bool someBool);
    static std::string getAudioTitle(int songId);
};

#endif // __LEVELTOOLS_H__
