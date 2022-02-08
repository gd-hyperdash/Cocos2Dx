#ifndef __CCCIRCLEWAVE_H__
#define __CCCIRCLEWAVE_H__

#include "layers_scenes_transitions_nodes/CCLayer.h"

enum CircleMode {
	kCircleModeFilled,
	kCircleModeNormal
};

/* A circle effect */
class CC_DLL CCCircleWave
{
public:
	~CCCircleWave();
	
	static CCCircleWave *create(float radius, float radiusEnd, float duration, bool fadeIn);
	
	bool init(float radius, float radiusEnd, float duration, bool fadeIn);
	void baseSetup(float radius);
	
	void draw();
	void updateTweenAction(float value, const char *key);
	
	void followObject(cocos2d::CCNode *object);
	void updatePosition();
	
	cocos2d::CCNode *following_;
	CC_SYNTHESIZE(float, width_, Width);
	CC_SYNTHESIZE(float, radius_, Radius);
	CC_SYNTHESIZE(float, opacity_, Opacity);
	CC_SYNTHESIZE(cocos2d::ccColor3B, color_, Color);
	CC_SYNTHESIZE(cocos2d::CCPoint, position_, Position);
	CC_SYNTHESIZE(CircleMode, circleMode_, CircleMode);
	CC_SYNTHESIZE(int, lineWidth_, LineWidth);
	CC_SYNTHESIZE(float, opacityMod_, OpacityMod);
};

/* Transparent CCCircleWave */
class CC_DLL CCCircleAlert : public CCCircleWave {
public:
	static CCCircleAlert *create(float radius, float radiusEnd, float duration);
	bool init(float radius, float radiusEnd, float duration);
};

/* A container for CCCircleAlert with default settings */
class CC_DLL CCAlertCircle : public cocos2d::CCNode
{
public:
	~CCAlertCircle();
	
	static CCAlertCircle *create();
	
	bool init();
	void draw();
	
	CC_SYNTHESIZE_READONLY(CCCircleAlert*, circle_, Circle);
};
#endif //__CCCIRCLEWAVE_H__