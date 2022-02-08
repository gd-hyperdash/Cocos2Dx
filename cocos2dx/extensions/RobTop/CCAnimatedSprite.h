#ifndef __CCANIMATEDSPRITE_H__
#define __CCANIMATEDSPRITE_H__

#include "actions/CCActionInterval.h"
#include "cocoa/CCDictionary.h"
#include "sprite_nodes/CCSprite.h"
#include "sprite_nodes/CCSpriteFrame.h"

class CCAnimatedSprite;

enum spriteMode
{
	kSpriteModeStopped,
	kSpriteModeAnimating
};

struct frameValues
{
	cocos2d::CCPoint position;
	cocos2d::CCPoint scale;
	cocos2d::CCPoint flipped;
	float rotation;
	int zValue;
	int tag;
	bool usesCustomTag;
	cocos2d::CCSpriteFrame* texture;
};
 
class CC_DLL SpriteAnimationManager
	: public cocos2d::CCNode
{
public:
	~SpriteAnimationManager();

	static SpriteAnimationManager* createWithOwner(CCAnimatedSprite* owner, std::string animKey);
	bool initWithOwner(CCAnimatedSprite* owner, std::string animKey);

	void executeAnimation(std::string animKey);
	void runAnimation(std::string animKey);
	void finishAnimation(std::string animKey);
	void doCleanup();

	void animationFinished();
	void createAnimations(std::string animDefinition);
	void loadAnimations(std::string animDefinition);

	void overridePrio();

	void playSound();
	void playSoundForAnimation(std::string animKey);

	void resetAnimState();

	CCAnimatedSprite* owner_;

	int getPrio(std::string animKey);
	cocos2d::CCDictionary* prios_;

	int getAnimType(std::string key);
	cocos2d::CCDictionary* animTypes_;

	cocos2d::CCDictionary* storedSounds_;

	void queueAnimation(std::string animKey);
	void runQueuedAnimation();
	std::string queuedAnimation_;

	void storeAnimation(
		cocos2d::CCAnimate* animation,
		std::string animKey,
		int prio,
		spriteMode mode,
		cocos2d::CCSpriteFrame* spriteFrame);

	void storeSoundForAnimation(
		cocos2d::CCString* sound,
		std::string animKey,
		float soundDelay);

	CC_SYNTHESIZE(cocos2d::CCDictionary*, animationContainer_, AnimationContainer);
	CC_SYNTHESIZE(std::string, activeAnimation_, ActiveAnimation);
};

class CC_DLL SpriteDescription
	: public cocos2d::CCObject
{
public:
	~SpriteDescription();
	
	static SpriteDescription *createDescription(cocos2d::CCDictionary *dict);
	static SpriteDescription *createDescription(DS_Dictionary *dict);
	bool initDescription(cocos2d::CCDictionary *dict);
	bool initDescription(DS_Dictionary *dict);
	
	void getTransformValues(frameValues *values);
};

// A cache for animation files/dictionaries
class CC_DLL CCAnimateFrameCache
	: public cocos2d::CCNode
{
public:
	~CCAnimateFrameCache();
	
	static CCAnimateFrameCache *sharedSpriteFrameCache();
	static void purgeSharedSpriteFrameCache();
	
	bool init();
	
	void addCustomSpriteFramesWithFile(const char *filename);
	void addSpriteFramesWithFile(const char *filename);
	void addDict(DS_Dictionary *dict, const char *filename);
	void addDict(cocos2d::CCDictionary *dict, const char *filename);
	
	cocos2d::CCArray *spriteFrameByName(const char *name);
	
	void removeSpriteFrames();
	
protected:
	cocos2d::CCDictionary *spriteFrames_;
	[[deprecated("unused")]] cocos2d::CCDictionary *unused_;
	cocos2d::CCDictionary *files_;
};

// A child of CCPartAnimSprite
class CC_DLL CCSpritePart
{
public:
	void hideInactive();
	CC_SYNTHESIZE(bool, beingUsed_, BeingUsed);
};

class CC_DLL CCPartAnimSprite
	: public cocos2d::CCSprite
{
public:
	~CCPartAnimSprite();
	
	static CCPartAnimSprite *createWithAnimDesc(
		cocos2d::CCString *filename,
		cocos2d::CCTexture2D *texture);

	bool initWithAnimDesc(
		cocos2d::CCString *filename,
		cocos2d::CCTexture2D *texture);
	
	void setBlendFunc(cocos2d::ccBlendFunc blendFunc);
	void setDisplayFrame(cocos2d::CCSpriteFrame *frame);
	void setFlipX(bool value);
	void setFlipY(bool value);
	void setScale(float value);
	void setScaleX(float value);
	void setScaleY(float value);
	void setColor(cocos2d::ccColor3B color);
	
	void transformSprite(frameValues values);
	void dirtify();

	void changeTextureOfID(
		cocos2d::CCString *id,
		cocos2d::CCString *textureFrame);

	bool isFrameDisplayed(cocos2d::CCSpriteFrame *frame);
	
	unsigned int countParts();
	cocos2d::CCSpriteFrame *displayFrame();
	CCSprite *getSpriteForKey(cocos2d::CCString *key);
	
	cocos2d::CCDictionary *sprites_;
	cocos2d::CCSpriteFrame *displayFrame_;
	bool dirty_;
	[[deprecated("unused")]] cocos2d::CCSize unused_;
	
	CC_SYNTHESIZE_READONLY(cocos2d::CCArray*, spriteContainer_, SpriteContainer);
};

class CC_DLL AnimatedSpriteDelegate
{
public:
	void animationFinished(const char *animName);
};

// The main animated sprites class
class CC_DLL CCAnimatedSprite
	: public cocos2d::CCSprite
{
public:
	~CCAnimatedSprite();
	
	static CCAnimatedSprite *createWithType(const char *spriteType);

	bool initWithType(const char *spriteType);
	void loadType(const char *spriteType);
	std::string type_;
	
	virtual void animationFinished(const char *animName);
	virtual void animationFinishedO(CCObject *animName);
	
	void cleanupSprite();
	
	void switchToMode(spriteMode mode);
	
	CC_SYNTHESIZE_READONLY(SpriteAnimationManager*, animManager_, AnimManager);
	CC_SYNTHESIZE(CCSprite*, sprite_, Sprite);
	CC_SYNTHESIZE(CCSprite*, normalSprite_, NormalSprite);
	CC_SYNTHESIZE(CCPartAnimSprite*, animatedSprite_, AnimatedSprite);
	CC_SYNTHESIZE_READONLY(spriteMode, activeSpriteMode_, ActiveSpriteMode);
	CC_SYNTHESIZE(std::string, defaultAnimation_, DefaultAnimation);
	CC_SYNTHESIZE(AnimatedSpriteDelegate*, delegate_, Delegate);
};

#endif //__CCANIMATEDSPRITE_H__
