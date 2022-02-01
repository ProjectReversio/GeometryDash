#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include "cocos2d.h"

class GameManager : public cocos2d::CCNode
{
public:
    GameManager();
    virtual ~GameManager();

    bool init() override;

    const char* getBGTexture(int index);
    void loadBackground(int index);

    static GameManager* sharedState();
    
    CREATE_FUNC(GameManager);

private:
    int mCurrentBackground;
};

#endif // __GAMEMANAGER_H__