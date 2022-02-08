#ifndef __CCCOUNTDOWN_H__
#define __CCCOUNTDOWN_H__

#include "label_nodes/CCLabelBMFont.h"
#include "misc_nodes/CCProgressTimer.h"
#include "sprite_nodes/CCSprite.h"

/* A timer */
class [[deprecated("unused")]] CC_DLL CCCountdown
	: public cocos2d::CCSprite
{
public:
	static CCCountdown *create();
	
	bool init();
	void setOpacity(GLubyte value);
	
	void lapFinished();
	void startTimerWithSeconds(
		float seconds,
		cocos2d::SEL_CallFunc selector,
		CCNode *handler);
	
	cocos2d::CCProgressTimer innerCircle_;
	int unused_;
	int seconds_;
	cocos2d::CCLabelBMFont *label_;
	cocos2d::SEL_CallFunc selector_;
	CCNode *handler_;
};

#endif //__CCCOUNTDOWN_H__
