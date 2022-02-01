#ifndef __TEXTAREA_H__
#define __TEXTAREA_H__

#include "cocos2d.h"

class TextArea : public cocos2d::CCSprite
{
public:
    TextArea();
    ~TextArea() override;
    
    bool init(std::string s, const char* font, float separation, float maxWidth, cocos2d::CCPoint anchorPoint, float lineSeparation, bool plainText);

    void draw() override;

    void setString(std::string s);

    static TextArea* create(std::string s, const char* font, float separation, float maxWidth, cocos2d::CCPoint anchorPoint, float lineSeparation, bool plainText);
};

#endif // __TEXTAREA_H__
