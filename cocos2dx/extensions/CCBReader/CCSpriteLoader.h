#ifndef _CCB_CCSPRITELOADER_H_
#define _CCB_CCSPRITELOADER_H_

#include "extensions/CCBReader/CCNodeLoader.h"

NS_CC_EXT_BEGIN

/* Forward declaration. */
class CCBReader;

class CC_DLL CCSpriteLoader
    : public CCNodeLoader
{
    public:
        virtual ~CCSpriteLoader();
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CCSpriteLoader, loader);

    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCSprite);

        virtual void onHandlePropTypeColor3(CCNode * pNode, CCNode * pParent, CCString * pPropertyName, ccColor3B pCCColor3B, CCBReader * pCCBReader);
        virtual void onHandlePropTypeByte(CCNode * pNode, CCNode * pParent, CCString * pPropertyName, unsigned char pByte, CCBReader * pCCBReader);
        virtual void onHandlePropTypeBlendFunc(CCNode * pNode, CCNode * pParent, CCString * pPropertyName, ccBlendFunc pCCBBlendFunc, CCBReader * pCCBReader);
        virtual void onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, CCString * pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader);
        virtual void onHandlePropTypeFlip(CCNode * pNode, CCNode * pParent, CCString * pPropertyName, bool * pFlip, CCBReader * pCCBReader);
};

NS_CC_EXT_END

#endif
