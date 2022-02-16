#include "LevelPage.h"

USING_NS_CC;

LevelPage::LevelPage()
{
    
}

LevelPage::~LevelPage()
{
    
}

LevelPage* LevelPage::create(GJGameLevel* level)
{
    LevelPage* pRet = new LevelPage();
    if (pRet && pRet->init(level))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool LevelPage::init(GJGameLevel* level)
{
    if (!CCLayer::init())
        return false;

    // TODO: Implement LevelPage::init

    return true;
}

void LevelPage::updateDynamicPage(GJGameLevel* level)
{
    // TODO: Implement LevelPage::updateDynamicPage
}
