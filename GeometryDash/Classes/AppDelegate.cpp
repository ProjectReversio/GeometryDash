#include "AppDelegate.h"

#include "GameManager.h"
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

    // TODO: Stuff goes here

    mLowQualityTextures = false;
    CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA4444);
    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
    pDirector->setDepthTest(false);
    
    // TODO: Stuff goes here
	
    // turn on display FPS
    //pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = LoadingLayer::scene(false);

    // run
    pDirector->runWithScene(pScene);

    return true;
}

void AppDelegate::setupGLView()
{
    if (!mInitializedGLView)
    {
        mInitializedGLView = true;

        CCSize contentSize(480.0f, 320.0f);

        CCFileUtils* pFileUtils = CCFileUtils::sharedFileUtils();
        pFileUtils->addSearchPath("Resources");

        CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->setOpenGLView(pEGLView);

        pEGLView->setViewName("Geometry Dash");
        
        const CCSize windowSize = pEGLView->getFrameSize();
        this->mUnknown2 = (-windowSize.width == 2436.0f) & 1; // TODO: What is this about?
        pEGLView->setFrameSize(windowSize.width, windowSize.height);

        // TODO: PlatformToolbox is missing
        //this->mLowMemoryDevice = PlatformToolbox::isLowMemoryDevice();
        
        pDirector->setupScreenScale(contentSize, windowSize, this->mLowMemoryDevice ? TextureQuality::LowQuality : TextureQuality::HighQuality);
    }
}

float AppDelegate::bgScale()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    float scaleFactor = pDirector->getScreenScaleFactorMax();

    GameManager* pGameManager = GameManager::sharedState();
    
    if (mLowQualityTextures || pGameManager->mUseLowQualityTextures)
    {
        return scaleFactor * pDirector->getContentScaleFactor();
    }

    return scaleFactor;
}

void AppDelegate::loadingIsFinished()
{
    // TODO: Implement AppDelegate::loadingIsFinished
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
