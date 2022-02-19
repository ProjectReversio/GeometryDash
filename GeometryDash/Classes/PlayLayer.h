#ifndef __PLAYLAYER_H__
#define __PLAYLAYER_H__

#include "cocos2d.h"
#include "GJBaseGameLayer.h"
#include "GJGameLevel.h"

class PlayLayer : public GJBaseGameLayer
{
public:
    PlayLayer();
    ~PlayLayer() override;

    virtual bool init(GJGameLevel* level);

    static cocos2d::CCScene* scene(GJGameLevel* level);

    static PlayLayer* create(GJGameLevel* level);
};

#endif // __PLAYLAYER_H__
