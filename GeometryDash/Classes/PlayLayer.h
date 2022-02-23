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
    void update(float delta) override;

    void removeAllObjects();
    void onQuit();
    void setDamageVerifiedIdx(int damage);
    void stopRecording();

    static cocos2d::CCScene* scene(GJGameLevel* level);

    static PlayLayer* create(GJGameLevel* level);

public:
    static float smScreenRight;
    static float smScreenLeft;
    static float smScreenTop;
    static float smScreenBottom;
    static float smScreenRightHalf;

protected:
    bool mUnknownNew1;
    bool mUnknownNew2;
    bool mUnknownNew3;
    bool mUnknownNew4;
    bool mUnknownNew5;
    bool mUnknownNew6;
    bool mUnknownNew7;
    bool mUnknownNew8;
    int mUnknownNew12;
    int mUnknownNew16;
    int mUnknownNew20;
    int mUnknownNew21;
    int mUnknownNew13;
    int mUnknownNew14;
    bool mUnknownNew19;
    bool mUnknownNew10;
    int mUnknownNew22;
    int mUnknownNew23;
    cocos2d::CCArray* mUnknownNew24;
    cocos2d::CCPoint mUnknownNew11;
};

#endif // __PLAYLAYER_H__
