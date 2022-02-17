#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "cocos2d.h"

class GameObject : public cocos2d::CCSprite
{
public:
    GameObject();
    ~GameObject() override;

    bool init(const char* frameName);

protected:

};

#endif // __GAMEOBJECT_H__
