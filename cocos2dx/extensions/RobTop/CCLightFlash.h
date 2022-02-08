#ifndef __CCLIGHTFLASH_H__
#define __CCLIGHTFLASH_H__

#include "layers_scenes_transitions_nodes/CCLayer.h"

#define flashStartDelay     0.8f
#define flashFadeInTime     0.3f
#define flashMidDelay       0.5f
#define flashFadeOutTime    1.5f

class CC_DLL CCLightFlash
	: public cocos2d::CCNode
{
public:
	~CCLightFlash();
	
	static CCLightFlash* create();
	bool init();

	/** Play a light flash.
	 * \param origin effect position
	 * \param color effect color
	 * \param bW start width
	 * \param bWVar start width variance
	 * \param tW end width
	 * \param tWVar end width variance
	 * \param tH end height
	 * \param dur light strip duration 
	 * \param durVar light strip duration variance
	 * \param stripInterval time between light strips
	 * \param stripDelay light strips start delay
	 * \param stripDelayVar light strips start delay variance
	 * \param rotation strip rotation
	 * \param rotationVar strip rotation variance
	 * \param opacity opacity
	 * \param opacityVar opacity variance
	 * \param lightStripCount light strip count
	 * \param circleRotation setup rotation depending on flash number
	 * \param fadeIn should fade in
	 * \param delay effect delay
	 */
	void playEffect(cocos2d::CCPoint origin, cocos2d::ccColor3B color, 
					float bW, float bWVar, float tW, float tWVar, float tH, float dur, float durVar, 
					float flashInterval, float flashDelay, float flashDelayVar, 
					float rotation, float rotationVar, float opacity, float opacityVar, 
					int lightStripCount, bool circleRotation, bool fadeIn, float delay);
	void fadeAndRemove();
	
	void showFlash();
	void removeLights();

	void cleanupFlash();

public:

	cocos2d::CCArray *container_;

	cocos2d::CCLayerColor *flashLayer_;
	
	bool fadeIn_;

	CC_SYNTHESIZE(CCNode*, flashP_, FlashP);
	CC_SYNTHESIZE(int, flashZ_, FlashZ);
};

class CC_DLL CCLightStrip : public cocos2d::CCNode {
public:
	/** Create a light strip.
	 * \param bW start width
	 * \param tW end width
	 * \param tH end height
	 * \param dur light strip duration 
	 * \param delay light strip delay
	 */
	static CCLightStrip* create(float bW, float tW, float tH, float dur, float delay);
	/** Init a light strip.
	 * \param bW start width
	 * \param tW end width
	 * \param tH end height
	 * \param dur light strip duration 
	 * \param delay light strip delay
	 */
	bool init(float bW, float tW, float tH, float dur, float delay);

	void draw();

	void updateTweenAction(float value, const char* key);

public:
	/* Start width */
	float bW_;
	/* End width */
	float tW_;
	/* End height */
	float tH_;
	/* Duration */
	float dur_;

	CC_SYNTHESIZE(cocos2d::ccColor3B, color_, Color);
	CC_SYNTHESIZE(float, opacity_, Opacity);
	CC_SYNTHESIZE(float, width_, Width);
	CC_SYNTHESIZE(float, height_, Height);
};

#endif