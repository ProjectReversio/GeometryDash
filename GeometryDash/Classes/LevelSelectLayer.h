#ifndef __LEVELSELECTLAYER_H__
#define __LEVELSELECTLAYER_H__

#include "cocos2d.h"

class LevelSelectLayer : public cocos2d::CCLayer
{
public:
    LevelSelectLayer();
    ~LevelSelectLayer() override;

    virtual bool init(int page);
    
    static cocos2d::CCScene* scene(int page);
    
    static LevelSelectLayer* create(int page);

protected:

};

#endif // __LEVELSELECTLAYER_H__
