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

#define SYM_createWithOwner "_ZN22SpriteAnimationManager15createWithOwnerEP16CCAnimatedSpriteSs"

	[[link_name(SYM_createWithOwner)]]
	static SpriteAnimationManager* createWithOwner(
		CCAnimatedSprite* owner,
		gdstd::string animKey);

#undef SYM_createWithOwner

#define SYM_initWithOwner "_ZN22SpriteAnimationManager13initWithOwnerEP16CCAnimatedSpriteSs"

	[[link_name(SYM_initWithOwner)]]
	bool initWithOwner(
		CCAnimatedSprite* owner,
		gdstd::string animKey);

#undef SYM_initWithOwner

#define SYM_executeAnimation "_ZN22SpriteAnimationManager16executeAnimationESs"

	[[link_name(SYM_executeAnimation)]]
	void executeAnimation(gdstd::string animKey);

#undef SYM_executeAnimation

#define SYM_runAnimation "_ZN22SpriteAnimationManager12runAnimationESs"

	[[link_name(SYM_runAnimation)]]
	void runAnimation(gdstd::string animKey);

#undef SYM_runAction

#define SYM_finishAnimation "_ZN22SpriteAnimationManager15finishAnimationESs"

	[[link_name(SYM_finishAnimation)]]
	void finishAnimation(gdstd::string animKey);

#undef SYM_finishAnimation

	void doCleanup();

	void animationFinished();

#define SYM_createAnimations "_ZN22SpriteAnimationManager16createAnimationsESs"

	[[link_name(SYM_createAnimations)]]
	void createAnimations(gdstd::string animDefinition);

#undef SYM_createAnimations

#define SYM_loadAnimations "_ZN22SpriteAnimationManager14loadAnimationsESs"

	[[link_name(SYM_loadAnimations)]]
	void loadAnimations(gdstd::string animDefinition);

#undef SYM_loadAnimations

	void overridePrio();

	void playSound();

#define SYM_playSoundForAnimation "_ZN22SpriteAnimationManager21playSoundForAnimationESs"

	[[link_name(SYM_playSoundForAnimation)]]
	void playSoundForAnimation(gdstd::string animKey);

#undef SYM_playSoundForAnimation

	void resetAnimState();

	CCAnimatedSprite* owner_;

#define SYM_getPrio "_ZN22SpriteAnimationManager7getPrioESs"

	[[link_name(SYM_getPrio)]]
	int getPrio(gdstd::string animKey);

#undef SYM_getPrio

	cocos2d::CCDictionary* prios_;

#define SYM_getAnimType "_ZN22SpriteAnimationManager11getAnimTypeESs"

	[[link_name(SYM_getAnimType)]]
	int getAnimType(gdstd::string key);

#undef SYM_getAnimType

	cocos2d::CCDictionary* animTypes_;

	cocos2d::CCDictionary* storedSounds_;

#define SYM_queueAnimation "_ZN22SpriteAnimationManager14queueAnimationESs"

	[[link_name(SYM_queueAnimation)]]
	void queueAnimation(gdstd::string animKey);

#undef SYM_queueAnimation

	void runQueuedAnimation();
	gdstd::string queuedAnimation_;

#define SYM_storeAnimation "_ZN22SpriteAnimationManager14storeAnimationEPN7cocos2d9CCAnimateESsi10spriteModePNS0_13CCSpriteFrameE"

	[[link_name(SYM_storeAnimation)]]
	void storeAnimation(
		cocos2d::CCAnimate* animation,
		gdstd::string animKey,
		int prio,
		spriteMode mode,
		cocos2d::CCSpriteFrame* spriteFrame);

#undef SYM_storeAnimation

#define SYM_storeSoundForAnimation "_ZN22SpriteAnimationManager22storeSoundForAnimationEPN7cocos2d8CCStringESsf"

	[[link_name(SYM_storeSoundForAnimation)]]
	void storeSoundForAnimation(
		cocos2d::CCString* sound,
		gdstd::string animKey,
		float soundDelay);

#undef SYM_storeSoundForAnimation

	CC_SYNTHESIZE(cocos2d::CCDictionary*, animationContainer_, AnimationContainer);

protected:
	gdstd::string activeAnimation_;

public:

#define SYM_getActiveAnimation "_ZNK22SpriteAnimationManager18getActiveAnimationEv"

	[[link_name(SYM_getActiveAnimation)]]
	virtual gdstd::string getActiveAnimation() const;

#undef SYM_getActiveAnimation

#define SYM_setActiveAnimation "_ZN22SpriteAnimationManager18setActiveAnimationESs"

	[[link_name(SYM_setActiveAnimation)]]
	virtual void setActiveAnimation(gdstd::string animation);

#undef SYM_setActiveAnimation
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
	gdstd::string type_;
	
	virtual void animationFinished(const char *animName);
	virtual void animationFinishedO(CCObject *animName);
	
	void cleanupSprite();
	
	void switchToMode(spriteMode mode);
	
	CC_SYNTHESIZE_READONLY(SpriteAnimationManager*, animManager_, AnimManager);
	CC_SYNTHESIZE(CCSprite*, sprite_, Sprite);
	CC_SYNTHESIZE(CCSprite*, normalSprite_, NormalSprite);
	CC_SYNTHESIZE(CCPartAnimSprite*, animatedSprite_, AnimatedSprite);
	CC_SYNTHESIZE_READONLY(spriteMode, activeSpriteMode_, ActiveSpriteMode);

protected:
	gdstd::string defaultAnimation_;

public:

#define SYM_getDefaultAnimation "_ZNK16CCAnimatedSprite19getDefaultAnimationEv"

	[[link_name(SYM_getDefaultAnimation)]]
	virtual gdstd::string getDefaultAnimation() const;

#undef SYM_getDefaultAnimation

#define SYM_setDefaultAnimation "_ZN16CCAnimatedSprite19setDefaultAnimationESs"

	[[link_name(SYM_setDefaultAnimation)]]
	virtual void setDefaultAnimation(gdstd::string animation);

#undef SYM_setDefaultAnimation

	CC_SYNTHESIZE(AnimatedSpriteDelegate*, delegate_, Delegate);
};

#endif //__CCANIMATEDSPRITE_H__
