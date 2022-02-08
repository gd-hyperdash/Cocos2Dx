#ifndef __CCMENUITEMTOGGLER_H__
#define __CCMENUITEMTOGGLER_H__

#include "extensions/RobTop/CCMenuItemSpriteExtra.h"

class CC_DLL CCMenuItemToggler
	: public cocos2d::CCMenuItem
{
public:
	static CCMenuItemToggler *create(
		cocos2d::CCNode *normalSprite,
		cocos2d::CCNode *selectedSprite,
		cocos2d::CCObject *target,
		cocos2d::SEL_MenuHandler selector);
	
	cocos2d::CCMenuItem *activeItem();
	
	void activate();
	void selected();
	void unselected();
	void setEnabled(bool state);
	
	void toggle(bool state);
	void normalTouch();
	void selectedTouch();
	
	CC_SYNTHESIZE_READONLY(CCMenuItemSpriteExtra*, normalButton_, NormalButton);
	CC_SYNTHESIZE_READONLY(CCMenuItemSpriteExtra*, selectedButton_, SelectedButton);
	CC_SYNTHESIZE_READONLY(CCMenuItemSpriteExtra*, isActive_, IsActive);
};

#endif //__CCMENUITEMTOGGLER_H__
