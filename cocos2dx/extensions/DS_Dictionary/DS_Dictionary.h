#ifndef DS_Dictionary_h
#define DS_Dictionary_h

#include "pugixml.hpp" 

#include "base_nodes/CCNode.h"
#include "cocoa/CCDictionary.h"

#include <vector>
#include <string>

class CC_DLL DS_Dictionary
{
private:
    //Data
    pugi::xml_document doc;
    gdstd::vector<pugi::xml_node> dictTree;

    //Constructor blockers
    DS_Dictionary(const DS_Dictionary& dictionary);                //Copy constructor - blocker
    DS_Dictionary& operator= (const DS_Dictionary& dictionary);    //Assignment - blocker

                                                                   //Methods
    std::string cleanStringWhiteSpace(const std::string& _str);

#define SYM_split "_ZN13DS_Dictionary5splitERKSsPKcRSt6vectorISsSaISsEE"

    [[link_name(SYM_split)]]
    void split(
        const std::string& src,
        const char* token,
        gdstd::vector<gdstd::string>& vect);

#undef SYM_split

#define SYM_splitWithForm "_ZN13DS_Dictionary13splitWithFormERKSsRSt6vectorISsSaISsEE"

    [[link_name(SYM_splitWithForm)]]
    bool splitWithForm(
        const std::string& content,
        gdstd::vector<gdstd::string>& strs);

#undef SYM_splitWithForm

    bool rectFromString(
        const std::string& pszContent,
        cocos2d::CCRect& rect);

    bool vec2FromString(
        const std::string& pszContent,
        cocos2d::CCPoint& vec2);

public:
    //Constructor
    DS_Dictionary();

    //Methods
    bool loadRootSubDictFromFile(const char* fileName);
    bool saveRootSubDictToFile(const char* fileName);
    bool loadRootSubDictFromString(std::string val);
    std::string saveRootSubDictToString();
    bool stepIntoSubDictWithKey(const char* key);
    void stepOutOfSubDict();
    void stepBackToRootSubDict();

    unsigned int getNumKeys();

#define SYM_getKey "_ZN13DS_Dictionary6getKeyEj"

    [[link_name(SYM_getKey)]]
    gdstd::string getKey(unsigned int index);

#undef SYM_getKey

#define SYM_getAllKeys "_ZN13DS_Dictionary10getAllKeysEv"

    [[link_name(SYM_getAllKeys)]]
    gdstd::vector<gdstd::string> getAllKeys();

#undef SYM_getAllKeys

    unsigned int getIndexOfKey(const char* key);
    unsigned int getIndexOfKeyWithClosestAlphaNumericalMatch(const char* key);

    void removeKey(unsigned int index);
    void removeKey(const char* key);
    void removeAllKeys();

    int getIntegerForKey(const char* key);
    bool getBoolForKey(const char* key);
    float getFloatForKey(const char* key);
    std::string getStringForKey(const char* key);
    cocos2d::CCPoint getVec2ForKey(const char* key);
    cocos2d::CCRect getRectForKey(const char* key);

#define SYM_getStringArrayForKey "_ZN13DS_Dictionary20getStringArrayForKeyEPKc"

    [[link_name(SYM_getStringArrayForKey)]]
    gdstd::vector<gdstd::string> getStringArrayForKey(const char* key);

#undef SYM_getStringArrayForKey

#define SYM_getVec2ArrayForKey "_ZN13DS_Dictionary18getVec2ArrayForKeyEPKc"

    [[link_name(SYM_getVec2ArrayForKey)]]
    gdstd::vector<cocos2d::CCPoint> getVec2ArrayForKey(const char* key);

#undef SYM_getVec2ArrayForKey

#define SYM_getRectArrayForKey "_ZN13DS_Dictionary18getRectArrayForKeyEPKc"

    [[link_name(SYM_getRectArrayForKey)]]
    gdstd::vector<cocos2d::CCRect> getRectArrayForKey(const char* key);

#undef SYM_getRectArrayForKey

    cocos2d::CCArray *getArrayForKey(const char *key);
    cocos2d::CCDictionary *getDictForKey(const char *key);
    cocos2d::CCObject *getObjectForKey(const char *key);

    void setSubDictForKey(const char* key);
    void setSubDictForKey(const char* key, bool alphaNumericallySorted);
    void setIntegerForKey(const char* key, int value);
    void setIntegerForKey(const char* key, int value, bool alphaNumericallySorted);
    void setBoolForKey(const char* key, bool value);
    void setBoolForKey(const char* key, bool value, bool alphaNumericallySorted);
    void setFloatForKey(const char* key, float value);
    void setFloatForKey(const char* key, float value, bool alphaNumericallySorted);
    void setStringForKey(const char* key, const std::string& value);
    void setStringForKey(const char* key, const std::string& value, bool alphaNumericallySorted);
    void setVec2ForKey(const char* key, const cocos2d::CCPoint& value);
    void setVec2ForKey(const char* key, const cocos2d::CCPoint& value, bool alphaNumericallySorted);
    void setRectForKey(const char* key, const cocos2d::CCRect& value);
    void setRectForKey(const char* key, const cocos2d::CCRect& value, bool alphaNumericallySorted);

#define SYM_setStringArrayForKey "_ZN13DS_Dictionary20setStringArrayForKeyEPKcRKSt6vectorISsSaISsEE"

    [[link_name(SYM_setStringArrayForKey)]]
    void setStringArrayForKey(
        const char* key,
        const gdstd::vector<gdstd::string>& value);

#undef SYM_setStringArrayForKey

#define SYM_setStringArrayForKey "_ZN13DS_Dictionary20setStringArrayForKeyEPKcRKSt6vectorISsSaISsEEb"

    [[link_name(SYM_setStringArrayForKey)]]
    void setStringArrayForKey(
        const char* key,
        const gdstd::vector<gdstd::string>& value, bool alphaNumericallySorted);

#undef SYM_setStringArrayForKey

#define SYM_setVec2ArrayForKey "_ZN13DS_Dictionary18setVec2ArrayForKeyEPKcRKSt6vectorIN7cocos2d7CCPointESaIS4_EE"

    [[link_name(SYM_setVec2ArrayForKey)]]
    void setVec2ArrayForKey(
        const char* key,
        const gdstd::vector<cocos2d::CCPoint>& value);

#undef SYM_setVec2ArrayForKey

#define SYM_setVec2ArrayForKey "_ZN13DS_Dictionary18setVec2ArrayForKeyEPKcRKSt6vectorIN7cocos2d7CCPointESaIS4_EEb"

    [[link_name(SYM_setVec2ArrayForKey)]]
    void setVec2ArrayForKey(
        const char* key,
        const gdstd::vector<cocos2d::CCPoint>& value,
        bool alphaNumericallySorted);

#undef SYM_setVec2ArrayForKey

#define SYM_setRectArrayForKey "_ZN13DS_Dictionary18setRectArrayForKeyEPKcRKSt6vectorIN7cocos2d6CCRectESaIS4_EE"

    [[link_name(SYM_setRectArrayForKey)]]
    void setRectArrayForKey(
        const char* key,
        const gdstd::vector<cocos2d::CCRect>& value);

#undef SYM_setRectArrayForKey

#define SYM_setRectArrayForKey "_ZN13DS_Dictionary18setRectArrayForKeyEPKcRKSt6vectorIN7cocos2d6CCRectESaIS4_EEb"

    [[link_name(SYM_setRectArrayForKey)]]
    void setRectArrayForKey(
        const char* key,
        const gdstd::vector<cocos2d::CCRect>& value,
        bool alphaNumericallySorted);

#undef SYM_setRectArrayForKey

    void setArrayForKey(const char *key, cocos2d::CCArray *value);
    void setDictForKey(const char *key, cocos2d::CCDictionary *value);
    void setObjectForKey(const char *key, cocos2d::CCObject *value);
    cocos2d::CCObject *decodeObjectForKey(const char *key);
};

#endif