#ifndef _CCB_CCMENUITEMIMAGELOADER_H_
#define _CCB_CCMENUITEMIMAGELOADER_H_

#include "extensions/CCBReader/CCMenuItemLoader.h"

NS_CC_EXT_BEGIN

/* Forward declaration. */
class CCBReader;

class CC_DLL CCMenuItemImageLoader : public CCMenuItemLoader {
    public:
        virtual ~CCMenuItemImageLoader();
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(CCMenuItemImageLoader, loader);

    protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCMenuItemImage);

        virtual void onHandlePropTypeSpriteFrame(CCNode * pNode, CCNode * pParent, CCString * pPropertyName, CCSpriteFrame * pCCSpriteFrame, CCBReader * pCCBReader);
};

NS_CC_EXT_END

#endif
