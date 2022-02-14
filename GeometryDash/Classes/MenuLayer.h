#ifndef __MENULAYER_H__
#define __MENULAYER_H__

#include "cocos2d.h"

class MenuLayer : public cocos2d::CCLayer
{
public:
    MenuLayer();
    ~MenuLayer() override;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    void onOptionsInstant();
    void onPlay(cocos2d::CCObject* pSender);
    void onGarage(cocos2d::CCObject* pSender);
    void onQuit(cocos2d::CCObject* pSender);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene(bool reload);

    // implement the "static node()" method manually
    static MenuLayer* node();
};

#endif // __MENULAYER_H__
