#include "AppDelegate.h"
#include "LoadingLayer.h"

USING_NS_CC;

AppDelegate::AppDelegate() : mInitializedGLView(false), mLowMemoryDevice(false), mUnknown2(false)
{
}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // seed rng
    timeval tv{};
    gettimeofday(&tv, nullptr);
    srand(tv.tv_sec * tv.tv_usec);

    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();

    CCFileUtils* pFileUtils = CCFileUtils::sharedFileUtils();
    // TODO: Missing function setAndroidPath
    //pFileUtils->setAndroidPath("/data/data/com.robtopx.geometryjump/");

    this->setupGLView();
    pDirector->setProjection(kCCDirectorProjection2D);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = LoadingLayer::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

void AppDelegate::setupGLView()
{
    if (!mInitializedGLView)
    {
        mInitializedGLView = true;

        CCSize size(480.0f, 320.0f);

        CCFileUtils* pFileUtils = CCFileUtils::sharedFileUtils();
        pFileUtils->addSearchPath("Resources");

        CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->setOpenGLView(pEGLView);

        pEGLView->setViewName("Geometry Dash");

        //CCSize windowSize(640.0f, 480.0f);
        CCSize windowSize = pEGLView->getFrameSize();
        this->mUnknown2 = (-windowSize.width == 2436.0f) & 1; // TODO: What is this about?
        pEGLView->setFrameSize(windowSize.width, windowSize.height);

        // TODO: PlatformToolbox is missing
        //this->mLowMemoryDevice = PlatformToolbox::isLowMemoryDevice();

        // TODO: Missing setupScreenScale
        //pDirector->setupScreenScale(size, windowSize, this->mLowMemoryDevice);
    }
}

float AppDelegate::bgScale()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    //float scaleFactor = pDirector->getScreenScaleFactorMax();

    // TODO: implement properly
    return 1.0f;
}


// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
