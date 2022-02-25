#ifndef __PLAYEROBJECT_H__
#define __PLAYEROBJECT_H__

#include "GameObject.h"

class PlayerObject : public GameObject
{
public:
    PlayerObject();
    ~PlayerObject();

    virtual bool init(int a2, int a3, cocos2d::CCLayer* layer);

    static PlayerObject* create(int a2, int a3, cocos2d::CCLayer* layer);

protected:

};

#endif // __PLAYEROBJECT_H__
