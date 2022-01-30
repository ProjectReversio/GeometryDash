#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__

#include "cocos2d.h"

class LoadingLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    bool init() override;

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();

    const char* getLoadingString();

    void updateProgress(int progress);
    void loadAssets();

    // implement the "static node()" method manually
    CREATE_FUNC(LoadingLayer);

private:
    bool mDontUseRandomText = false;
    cocos2d::CCLabelBMFont* mLoadingTextLabel;
    //TextArea* mLoadingTextArea; // TODO: TextArea is missing!
    cocos2d::CCSprite* mSliderBar;
};

#endif // __LOADINGLAYER_H__
