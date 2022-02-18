#include "LevelTools.h"

#include "GJGameLevel.h"

USING_NS_CC;

GJGameLevel* LevelTools::getLevel(int levelId, bool someBool)
{
    GJGameLevel* result = GJGameLevel::create();

    switch (levelId)
    {
        case 1:
        {
            result->setLevelName(LevelTools::getAudioTitle(0));
            result->setSongID(0);
            result->setDifficulty(1);
            result->setStars(1);
            result->setCapacityString("29_98_29_40_29_29_29_29_29_29_177_29_73_29_29_29");
            break;
        }
        // TODO: Implement LevelTools::getLevel
        case 21:
        {
            result->setLevelName(LevelTools::getAudioTitle(20));
            result->setSongID(20);
            result->setDifficulty(5);
            result->setStars(12);
            break;
        }
    }

    if (!someBool)
    {
        // TODO: Missing LocalLevelManager
        //LocalLevelManager* pLocalLevelManager = LocalLevelManager::sharedState();
        //result->setLevelString(pLocalLevelManager->getMainLevelString());
    }

    result->setLevelID(levelId);

    // TODO: Unknown Values for GJGameLevel
    //result->mUnknown7 = 1;
    //if (levelId != 3001)
    //    result->mUnknown16 = 3;

    return result;
}

std::string LevelTools::getAudioTitle(int songId)
{
    switch (songId)
    {
        case -1: return "Practice: Stay Inside Me";
        case 0: return "Stereo Madness";
        case 1: return "Back On Track";
        case 2: return "Polargeist";
        case 3: return "Dry Out";
        case 4: return "Base After Base";
        case 5: return "Cant Let Go";
        case 6: return "Jumper";
        case 7: return "Time Machine";
        case 8: return "Cycles";
        case 9: return "xStep";
        case 10: return "Clutterfunk";
        case 11: return "Theory of Everything";
        case 12: return "Electroman Adventures";
        case 13: return "Clubstep";
        case 14: return "Electrodynamix";
        case 15: return "Hexagon Force";
        case 16: return "Blast Processing";
        case 17: return "Theory of Everything 2";
        case 18: return "Geometrical Dominator";
        case 19: return "Deadlocked";
        case 20: return "Fingerdash";
        case 21: return "The Seven Seas";
        case 22: return "Viking Arena";
        case 23: return "Airborne Robots";
        case 24: return "Secret";
        case 25: return "Payload";
        case 26: return "Beast Mode";
        case 27: return "Machina";
        case 28: return "Years";
        case 29: return "Frontlines";
        case 30: return "Space Pirates";
        case 31: return "Striker";
        case 32: return "Embers";
        case 33: return "Round 1";
        case 34: return "Monster Dance Off";
        default: return "Unknown";
    }
}
