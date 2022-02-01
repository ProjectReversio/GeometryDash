#include "TextArea.h"

USING_NS_CC;

TextArea::TextArea()
{
    
}

TextArea::~TextArea()
{
    
}

bool TextArea::init(std::string s, const char* font, float separation, float maxWidth, cocos2d::CCPoint anchorPoint, float lineSeparation, bool plainText)
{
    if (!CCSprite::init())
        return false;

    // TODO: Implement TextArea::init
    return true;
}

void TextArea::draw()
{
    // Intentionally empty
}

void TextArea::setString(std::string s)
{
    // TODO: Implement TextArea::setString
}

TextArea* TextArea::create(std::string s, const char* font, float separation, float maxWidth, cocos2d::CCPoint anchorPoint, float lineSeparation, bool plainText)
{
    TextArea* pRet = new TextArea();
    if (pRet && pRet->init(s, font, separation, maxWidth, anchorPoint, lineSeparation, plainText))
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
