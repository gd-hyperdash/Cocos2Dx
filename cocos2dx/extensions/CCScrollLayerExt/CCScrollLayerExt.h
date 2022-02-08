/*
 *  CCScrollLayerExt.h
 *  SkeletonX
 *
 *  Created by mac on 11-11-18.
 *  Copyright 2011 GeekStudio. All rights reserved.
 *
 */

#ifndef _CCSCROLLLAYER_EXT_H
#define _CCSCROLLLAYER_EXT_H

//TODO: this is a hack, need to find the right type /cos
using ccTime = float;
//

#include "platform/platform.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"

class CCScrollLayerExt;

class CCContentLayer
    : public cocos2d::CCLayerColor
{
public:
    static CCContentLayer *create(
        const cocos2d::ccColor4B &color,
        GLfloat width,
        GLfloat height);

    void setPosition(const cocos2d::CCPoint &pos);
};

class CCScrollLayerExtDelegate
{
public:
    virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt * mScrollView){} // called on finger up as we are moving
    virtual void scrollViewDidEndDecelerating(CCScrollLayerExt * mScrollView){}// called when scroll view grinds to a halt
    virtual void scrollViewTouchMoving(CCScrollLayerExt * mScrollView){}//touch moving.
    virtual void scrollViewDidEndMoving(CCScrollLayerExt * mScrollView){}//it's not decelerating
    virtual void scrollViewTouchBegin(CCScrollLayerExt * mScrollView){}//touch begin
    virtual void scrollViewTouchEnd(CCScrollLayerExt * mScrollView){}//touch end
};

class CCScrollLayerExt
    : public cocos2d::CCLayer
{
private:
    cocos2d::CCTouch * beginTouch;
    cocos2d::CCPoint touchOnLocation,firstTouchLocation;//stay on screen touch, and first touch
    cocos2d::cc_timeval beginTime;
    CC_SYNTHESIZE(bool,isTouch,IsTouch);
    CC_SYNTHESIZE(bool,isScrolling,IsScrolling);
    CC_SYNTHESIZE(cocos2d::CCLayerColor *,verticalScrollIndicator,VerticalScrollIndicator);
    CC_SYNTHESIZE(cocos2d::CCLayerColor *,horizontalScrollIndicator,HorizontalScrollIndicator);
    float getMinY();
    float getMaxY();
    void constraintContent();
    void scrollingEnd();
    void updateIndicators(ccTime mTime);
public:
    CCScrollLayerExt(cocos2d::CCRect mRect = cocos2d::CCRectZero);
    virtual ~CCScrollLayerExt();
    
    CC_SYNTHESIZE(CCScrollLayerExtDelegate*,scrollDelegate,ScrollDelegate);
    CC_SYNTHESIZE(cocos2d::CCLayerColor *,contentLayer,ContentLayer);
    CC_SYNTHESIZE(bool,clipsToBounds,ClipsToBounds);
    CC_SYNTHESIZE(bool,showsHorizontalScrollIndicator,ShowsHorizontalScrollIndicator);
    CC_SYNTHESIZE(bool,showsVerticalScrollIndicator,ShowsVerticalScrollIndicator);
    CC_SYNTHESIZE(bool,lockHorizontal,LockHorizontal);//lock horizontal indicator to scrolling
    CC_SYNTHESIZE(bool,lockVertical,LockVertical);//lock vertical indicator to scrolling
    CC_SYNTHESIZE(bool,touchDispatch,TouchDispatch);
    CC_SYNTHESIZE(bool,topPadding,TopPadding);
    CC_SYNTHESIZE(bool,bottomPadding,BottomPadding);
    CC_SYNTHESIZE(bool,maxOffsetTop,MaxOffsetTop);
    CC_SYNTHESIZE(bool,maxOffsetBottom,MaxOffsetBottom);
    
public:
    void setContentLayerSize(cocos2d::CCSize mSize);
    void setContentOffset(cocos2d::CCPoint mOffset,bool mAnimate);// animate at constant velocity to new offset
    void scrollToTop();
    
    void moveToTop();
    void moveToTopWithOffset(float offset);

public:
    
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    
    virtual void visit();
    virtual void preVisitWithClippingRect(cocos2d::CCRect clipRect);
    virtual void postVisit();
};

#endif