#ifndef __CCEXTENDERNODE_H__
#define __CCEXTENDERNODE_H__

#include "base_nodes/CCNode.h"

class [[deprecated("unused")]] CC_DLL CCExtenderNode
	: public cocos2d::CCNode
{
public:
	/* Set children opacity.
	 * Note that all the children must inherit CCSprite.
	 */
	void setOpacity(unsigned int value);
};

#endif //__CCEXTENDERNODE_H__
