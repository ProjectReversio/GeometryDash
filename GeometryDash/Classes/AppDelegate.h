#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by CCDirector.
*/
class  AppDelegate : private cocos2d::CCApplication
{
    friend class GameManager;
public:
    AppDelegate();
    virtual ~AppDelegate();

    static AppDelegate* get()
    {
        return static_cast<AppDelegate*>(sharedApplication());
    }

    virtual void loadingIsFinished();

    /**
    @brief    Implement CCDirector and CCScene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching() override;

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground() override;

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground() override;

    virtual void setupGLView();

    float bgScale();

    bool isLowMemoryDevice() { return mLowMemoryDevice; }

private:
    bool mInitializedGLView;
    bool mLowMemoryDevice;
    bool mLowQualityTextures;
    bool mUnknown2;

public:
    cocos2d::CCScene* mMenuScene;
};

#endif // _APP_DELEGATE_H_

