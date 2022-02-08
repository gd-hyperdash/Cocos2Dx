#ifndef CCContentManager_h
#define CCContentManager_h

#include "cocoa/CCDictionary.h"

class CC_DLL CCContentManager
{
public:
	~CCContentManager();
	
    static CCContentManager *sharedManager();
    
    bool init();
    
    void addCCDict(const char *path);
    void addDict(const char *path);
    void addPath(const char *path);
    
    void clearCache();
	
    cocos2d::CCDictionary *dictCache_;
    cocos2d::CCDictionary *pathCache_;
};

#endif