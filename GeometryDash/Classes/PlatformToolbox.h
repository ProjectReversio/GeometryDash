#ifndef __PLATFORMTOOLBOX_H__
#define __PLATFORMTOOLBOX_H__

#include "cocos2d.h"

class PlatformToolbox
{
public:
    static bool isControllerConnected();
    static bool isLowMemoryDevice();
    static void activateGameCenter();
    static void hideCursor();
};

#endif // __PLATFORMTOOLBOX_H__
