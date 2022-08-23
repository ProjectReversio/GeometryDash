#ifndef __MENULAYER_H__
#define __MENULAYER_H__

#include "cocos2d.h"

class CCMenuItemSpriteExtra;

class MenuLayer : public cocos2d::CCLayer
{
public:
    MenuLayer();
    ~MenuLayer() override;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    void onOptionsInstant();
    void showMeltdownPromo();
    void updateUserProfileButton();
    void willClose();

    void onPlay(cocos2d::CCObject* pSender);
    void onGarage(cocos2d::CCObject* pSender);
    void onCreator(cocos2d::CCObject* pSender);
    void onMyProfile(cocos2d::CCObject* pSender);
    void onAchievements(cocos2d::CCObject* pSender);
    void onOptions(cocos2d::CCObject* pSender);
    void onStats(cocos2d::CCObject* pSender);
    void onDaily(cocos2d::CCObject* pSender);
    void onEveryplay(cocos2d::CCObject* pSender);
    void onNewgrounds(cocos2d::CCObject* pSender);
    void onRobTop(cocos2d::CCObject* pSender);
    void onFacebook(cocos2d::CCObject* pSender);
    void onTwitter(cocos2d::CCObject* pSender);
    void onYouTube(cocos2d::CCObject* pSender);
    void onTwitch(cocos2d::CCObject* pSender);
    void onDiscord(cocos2d::CCObject* pSender);
    void onMoreGames(cocos2d::CCObject* pSender);
    void onFreeLevels(cocos2d::CCObject* pSender);
    void onFullVersion(cocos2d::CCObject* pSender);
    void onQuit(cocos2d::CCObject* pSender);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene(bool reload);

    // implement the "static node()" method manually
    static MenuLayer* node();

protected:
    CCMenuItemSpriteExtra* mProfileButton;
    cocos2d::CCSprite* mProfileHelpText;
    cocos2d::CCLabelBMFont* mProfileText;
};

#endif // __MENULAYER_H__
