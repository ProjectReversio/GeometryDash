#include "LevelTools.h"

#include "GJGameLevel.h"
#include "gameConfig.h"

USING_NS_CC;

GJGameLevel* LevelTools::getLevel(int levelId, bool someBool)
{
    GJGameLevel* result = GJGameLevel::create();

    switch (levelId)
    {
        case 1: // Stereo Madness
        {
            result->setLevelName(LevelTools::getAudioTitle(0));
            result->setSongID(0);
            result->setDifficulty(1);
            result->setStars(1);
            result->setCapacityString("29_98_29_40_29_29_29_29_29_29_177_29_73_29_29_29");
            break;
        }
        case 2: // Back On Track
        {
            result->setLevelName(LevelTools::getAudioTitle(1));
            result->setSongID(1);
            result->setDifficulty(1);
            result->setStars(2);
            result->setCapacityString("29_54_29_40_29_29_29_29_29_29_98_29_54_29_29_29");
            break;
        }
        case 3: // Polargeist
        {
            result->setLevelName(LevelTools::getAudioTitle(2));
            result->setSongID(2);
            result->setDifficulty(2);
            result->setStars(3);
            result->setCapacityString("29_98_29_40_29_29_29_29_29_29_29_29_98_29_29_29");
            break;
        }
        case 4: // Dry Out
        {
            result->setLevelName(LevelTools::getAudioTitle(3));
            result->setSongID(3);
            result->setDifficulty(2);
            result->setStars(4);
            result->setCapacityString("29_73_29_40_29_29_29_29_29_29_73_29_73_29_29_29");
            break;
        }
        case 5: // Base After Base
        {
            result->setLevelName(LevelTools::getAudioTitle(4));
            result->setSongID(4);
            result->setDifficulty(3);
            result->setStars(5);
            result->setCapacityString("29_73_29_40_29_29_29_29_29_29_98_29_73_29_29_29");
            break;
        }
        case 6: // Cant Let Go
        {
            result->setLevelName(LevelTools::getAudioTitle(5));
            result->setSongID(5);
            result->setDifficulty(3);
            result->setStars(6);
            result->setCapacityString("29_73_29_40_29_29_29_29_29_29_29_29_73_29_29_29");
            break;
        }
        case 7: // Jumper
        {
            result->setLevelName(LevelTools::getAudioTitle(6));
            result->setSongID(6);
            result->setDifficulty(4);
            result->setStars(7);
            result->setCapacityString("29_98_29_40_29_29_29_29_29_29_98_29_98_29_29_29");
            break;
        }
        case 8: // Time Machine
        {
            result->setLevelName(LevelTools::getAudioTitle(7));
            result->setSongID(7);
            result->setDifficulty(4);
            result->setStars(8);
            result->setCapacityString("29_132_29_40_29_29_29_29_29_29_73_29_98_29_29_29");
            break;
        }
        case 9: // Cycles
        {
            result->setLevelName(LevelTools::getAudioTitle(8));
            result->setSongID(8);
            result->setDifficulty(4);
            result->setStars(9);
            result->setCapacityString("29_98_29_40_29_29_29_40_29_29_98_29_98_29_29_29");
            break;
        }
        case 10: // xStep
        {
            result->setLevelName(LevelTools::getAudioTitle(9));
            result->setSongID(9);
            result->setDifficulty(5);
            result->setStars(10);
            result->setCapacityString("29_132_29_40_29_29_29_54_29_29_132_29_73_29_29_29");
            break;
        }
        case 11: // Clutterfunk
        {
            result->setLevelName(LevelTools::getAudioTitle(10));
            result->setSongID(10);
            result->setDifficulty(5);
            result->setStars(11);
            result->setCapacityString("29_237_29_40_29_29_29_73_29_29_29_29_98_29_29_29");
            break;
        }
        case 12: // Theory of Everything
        {
            result->setLevelName(LevelTools::getAudioTitle(11));
            result->setSongID(11);
            result->setDifficulty(5);
            result->setStars(12);
            result->setCapacityString("29_237_29_54_29_29_29_73_29_29_132_29_132_29_29_29");
            break;
        }
        case 13: // Electroman Adventures
        {
            result->setLevelName(LevelTools::getAudioTitle(12));
            result->setSongID(12);
            result->setDifficulty(5);
            result->setStars(10);
            result->setCapacityString("29_237_29_40_29_29_29_98_29_29_98_29_132_29_29_29");
            break;
        }
        case 14: // Clubstep
        {
            result->setLevelName(LevelTools::getAudioTitle(13));
            result->setSongID(13);
            result->setDifficulty(6);
            result->setStars(14);
            result->setCoinsRequired(10);
            result->setDemon(1);
            result->setCapacityString("29_237_29_54_29_29_29_132_29_29_98_29_132_29_29_29");
            break;
        }
        case 15: // Electrodynamix
        {
            result->setLevelName(LevelTools::getAudioTitle(14));
            result->setSongID(14);
            result->setDifficulty(5);
            result->setStars(12);
            result->setCapacityString("29_237_98_40_29_29_29_237_29_29_98_73_177_29_29_29");
            break;
        }
        case 16: // Hexagon Force
        {
            result->setLevelName(LevelTools::getAudioTitle(15));
            result->setSongID(15);
            result->setDifficulty(5);
            result->setStars(12);
            result->setCapacityString("29_317_73_73_29_29_54_132_29_29_237_132_177_29_29_29");
            break;
        }
        case 17: // Blast Processing
        {
            result->setLevelName(LevelTools::getAudioTitle(16));
            result->setSongID(16);
            result->setDifficulty(4);
            result->setStars(10);
            result->setCapacityString("29_237_29_73_29_29_98_132_29_29_566_54_132_29_29_29");
            break;
        }
        case 18: // Theory of Everything 2
        {
            result->setLevelName(LevelTools::getAudioTitle(17));
            result->setSongID(17);
            result->setDifficulty(6);
            result->setStars(14);
            result->setCoinsRequired(20);
            result->setDemon(1);
            result->setCapacityString("29_317_40_54_29_40_132_132_29_29_424_98_237_29_29_29");
            break;
        }
        case 19: // Geometrical Dominator
        {
            result->setLevelName(LevelTools::getAudioTitle(18));
            result->setSongID(18);
            result->setDifficulty(4);
            result->setStars(10);
            result->setCapacityString("29_424_132_40_29_29_566_132_29_29_756_237_132_29_73_29");
            break;
        }
        case 20: // Deadlocked
        {
            result->setLevelName(LevelTools::getAudioTitle(19));
            result->setSongID(19);
            result->setDifficulty(6);
            result->setStars(15);
            result->setCoinsRequired(30);
            result->setDemon(1);
            result->setCapacityString("29_317_73_73_29_29_317_424_73_29_566_317_177_29_132_54");
            break;
        }
        case 21: // Fingerdash
        {
            result->setLevelName(LevelTools::getAudioTitle(20));
            result->setSongID(20);
            result->setDifficulty(5);
            result->setStars(12);
            break;
        }
        case 3001: // Secret
        {
            result->setLevelName("The Challenge");
            result->setSongID(24);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("73_237_29_40_29_29_237_98_29_29_237_237_132_29_29_29");
            break;
        }
#ifdef GD_MELTDOWN
        case 1001: // The Seven Seas
        {
            result->setLevelName(LevelTools::getAudioTitle(21));
            result->setSongID(21);
            result->setDifficulty(1);
            result->setStars(1);
            result->setCapacityString("29_317_29_40_29_29_177_98_29_29_177_132_98_29_29_29");
            break;
        }
        case 1002: // Viking Arena
        {
            result->setLevelName(LevelTools::getAudioTitle(22));
            result->setSongID(22);
            result->setDifficulty(2);
            result->setStars(2);
            result->setCapacityString("29_424_40_40_29_73_237_237_73_29_73_317_98_29_29_40");
            break;
        }
        case 1003: // Airborne Robots
        {
            result->setLevelName(LevelTools::getAudioTitle(23));
            result->setSongID(23);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("73_237_29_40_29_29_237_98_29_29_237_237_132_29_29_29");
            break;
        }
#endif
#ifdef GD_WORLD
        case 2001: // Payload
        {
            result->setLevelName(LevelTools::getAudioTitle(25));
            result->setSongID(25);
            result->setDifficulty(2);
            result->setStars(2);
            result->setCapacityString("0_107_0_0_0_0_0_0_0_0_92_0_52_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 2002: // Beast Mode
        {
            result->setLevelName(LevelTools::getAudioTitle(26));
            result->setSongID(26);
            result->setDifficulty(2);
            result->setStars(2);
            result->setCapacityString("0_168_0_0_0_0_0_119_0_0_166_72_60_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 2003: // Machina
        {
            result->setLevelName(LevelTools::getAudioTitle(27));
            result->setSongID(27);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("0_213_0_0_0_0_0_0_0_0_114_37_51_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 2004: // Years
        {
            result->setLevelName(LevelTools::getAudioTitle(28));
            result->setSongID(28);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("0_106_0_0_0_0_80_74_0_0_151_61_69_0_0_50_0_0_0_0_0_0_93_37_56_0_37_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 2005: // Frontlines
        {
            result->setLevelName(LevelTools::getAudioTitle(29));
            result->setSongID(29);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("0_265_113_0_0_0_38_0_0_0_62_0_56_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 2006: // Space Pirates
        {
            result->setLevelName(LevelTools::getAudioTitle(30));
            result->setSongID(30);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("37_118_0_0_0_0_135_0_0_0_286_48_91_0_82_0_0_0_0_167_0_0_266_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 2007: // Striker
        {
            result->setLevelName(LevelTools::getAudioTitle(31));
            result->setSongID(31);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("0_222_82_0_0_0_0_45_0_0_201_40_77_0_0_0_0_0_0_90_37_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 2008: // Embers
        {
            result->setLevelName(LevelTools::getAudioTitle(32));
            result->setSongID(32);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("46_201_0_0_0_0_0_62_0_0_172_171_53_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 2009: // Round 1
        {
            result->setLevelName(LevelTools::getAudioTitle(33));
            result->setSongID(33);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("0_71_143_0_0_0_0_0_0_0_0_0_49_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 2010: // Monster Dance Off
        {
            result->setLevelName(LevelTools::getAudioTitle(34));
            result->setSongID(34);
            result->setDifficulty(3);
            result->setStars(3);
            result->setCapacityString("0_101_135_0_0_0_96_0_0_0_202_145_102_0_48_0_0_0_0_96_0_48_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
#endif
#ifdef GD_SUBZERO
        case 4001: // Press Start
        {
            result->setLevelName(LevelTools::getAudioTitle(35));
            result->setSongID(35);
            result->setDifficulty(2);
            result->setStars(4);
            result->setCapacityString("0_277_213_41_0_0_257_86_0_0_633_250_152_0_0_0_209_319_0_158_86_48_63_0_452_0_0_0_0_0_0_0_0_0_128_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 4002: // Nock Em
        {
            result->setLevelName(LevelTools::getAudioTitle(36));
            result->setSongID(36);
            result->setDifficulty(3);
            result->setStars(6);
            result->setCapacityString("105_305_0_42_0_0_424_74_0_0_108_481_159_0_0_0_0_0_0_0_0_0_158_0_39_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
        case 4003: // Power Trip
        {
            result->setLevelName(LevelTools::getAudioTitle(37));
            result->setSongID(37);
            result->setDifficulty(4);
            result->setStars(8);
            result->setCapacityString("0_192_136_45_0_0_0_290_0_0_601_229_159_0_0_0_57_0_0_0_0_0_35_0_0_40_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0");
            break;
        }
#endif
        default:
        {
            return LevelTools::getLevel(1, someBool);
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
        case 35: return "Press Start";
        case 36: return "Nock Em";
        case 37: return "Power Trip";
        default: return "Unknown";
    }
}
