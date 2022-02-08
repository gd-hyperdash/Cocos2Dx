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
    std::vector<pugi::xml_node> dictTree;

    //Constructor blockers
    DS_Dictionary(const DS_Dictionary& dictionary);                //Copy constructor - blocker
    DS_Dictionary& operator= (const DS_Dictionary& dictionary);    //Assignment - blocker

                                                                   //Methods
    std::string cleanStringWhiteSpace(const std::string& _str);

    void split(
        const std::string& src,
        const char* token,
        std::vector<std::string>& vect);

    bool splitWithForm(
        const std::string& content,
        std::vector<std::string>& strs);

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
    std::string getKey(unsigned int index);
    std::vector<std::string> getAllKeys();
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
    std::vector<std::string> getStringArrayForKey(const char* key);
    std::vector<cocos2d::CCPoint> getVec2ArrayForKey(const char* key);
    std::vector<cocos2d::CCRect> getRectArrayForKey(const char* key);
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
    void setStringArrayForKey(const char* key, const std::vector<std::string>& value);
    void setStringArrayForKey(const char* key, const std::vector<std::string>& value, bool alphaNumericallySorted);
    void setVec2ArrayForKey(const char* key, const std::vector<cocos2d::CCPoint>& value);
    void setVec2ArrayForKey(const char* key, const std::vector<cocos2d::CCPoint>& value, bool alphaNumericallySorted);
    void setRectArrayForKey(const char* key, const std::vector<cocos2d::CCRect>& value);
    void setRectArrayForKey(const char* key, const std::vector<cocos2d::CCRect>& value, bool alphaNumericallySorted);
    void setArrayForKey(const char *key, cocos2d::CCArray *value);
    void setDictForKey(const char *key, cocos2d::CCDictionary *value);
    void setObjectForKey(const char *key, cocos2d::CCObject *value);
    cocos2d::CCObject *decodeObjectForKey(const char *key);
};

#endif