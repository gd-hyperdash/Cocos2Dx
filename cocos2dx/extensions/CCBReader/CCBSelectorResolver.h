#ifndef _CCB_CCBSELECTORRESOLVER_H_
#define _CCB_CCBSELECTORRESOLVER_H_

#include "extensions/CCControlExtension/CCControlExtensions.h"

NS_CC_EXT_BEGIN

#define CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(TARGET, SELECTORNAME, METHOD) if(pTarget == TARGET && pSelectorName->compare(SELECTORNAME) == 0) { \
    return menu_selector(METHOD); \
}

#define CCB_SELECTORRESOLVER_CCCONTROL_GLUE(TARGET, SELECTORNAME, METHOD) if(pTarget == TARGET && pSelectorName->compare(SELECTORNAME) == 0) { \
    return cccontrol_selector(METHOD); \
}

class CC_DLL CCBSelectorResolver
{
    public:
        virtual ~CCBSelectorResolver();

        virtual SEL_MenuHandler onResolveCCBCCMenuItemSelector(
            CCObject * pTarget,
            CCString * pSelectorName) = 0;

        virtual SEL_CCControlHandler onResolveCCBCCControlSelector(
            CCObject * pTarget,
            CCString * pSelectorName) = 0;
};

NS_CC_EXT_END

#endif
