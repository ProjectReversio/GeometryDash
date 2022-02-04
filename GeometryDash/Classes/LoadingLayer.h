#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__

#include "cocos2d.h"

class TextArea;

class LoadingLayer : public cocos2d::CCLayer
{
public:
    LoadingLayer();
    ~LoadingLayer() override;

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init(bool reload);

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene(bool reload);

    const char* getLoadingString();

    void updateProgress(int progress);
    void loadAssets();
    void loadingFinished();

    // implement the "static node()" method manually
    static LoadingLayer* create(bool reload);

private:
    bool mReload;
    cocos2d::CCLabelBMFont* mLoadingTextLabel;
    TextArea* mLoadingTextArea;
    cocos2d::CCSprite* mSliderBar;
    cocos2d::CCSize mProgressBarSize;
    int mStage;
    bool mUnknownBool1;
};

#endif // __LOADINGLAYER_H__
