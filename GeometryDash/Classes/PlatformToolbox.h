#ifndef __PLATFORMTOOLBOX_H__
#define __PLATFORMTOOLBOX_H__

#include "cocos2d.h"

class PlatformToolbox
{
public:
    static bool isControllerConnected();
    static bool isLowMemoryDevice();
    static void activateGameCenter();
};

#endif // __PLATFORMTOOLBOX_H__
