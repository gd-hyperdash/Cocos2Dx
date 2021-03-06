/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __SUPPORT_CCUSERDEFAULT_H__
#define __SUPPORT_CCUSERDEFAULT_H__

#include "platform/CCPlatformMacros.h"
#include <string>

NS_CC_BEGIN

/**
 * @addtogroup data_storage
 * @{
 */

/**
 * CCUserDefault acts as a tiny database. You can save and get base type values by it.
 * For example, setBoolForKey("played", true) will add a bool value true into the database.
 * Its key is "played". You can get the value of the key by getBoolForKey("played").
 * 
 * It supports the following base types:
 * bool, int, float, double, string
 */
class CC_DLL CCUserDefault
{
public:
    ~CCUserDefault();

    // get value methods

    /**
    @brief Get bool value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is false.
    */
    bool    getBoolForKey(const char* pKey, bool defaultValue = false);
    /**
    @brief Get integer value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is 0.
    */
    int        getIntegerForKey(const char* pKey, int defaultValue = 0);
    /**
    @brief Get float value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is 0.0f.
    */
    float    getFloatForKey(const char* pKey, float defaultValue=0.0f);
    /**
    @brief Get double value by key, if the key doesn't exist, a default value will return.
     You can set the default value, or it is 0.0.
    */
    double  getDoubleForKey(const char* pKey, double defaultValue=0.0);

#define SYM_getStringForKey "_ZN7cocos2d13CCUserDefault15getStringForKeyEPKcRKSs"

    /**
    @brief Get string value by key, if the key doesn't exist, a default value will return.
    You can set the default value, or it is "".
    */
    [[link_name(SYM_getStringForKey)]]
    gdstd::string getStringForKey(const char* pKey, const gdstd::string & defaultValue = "");

#undef SYM_getStringForKey

    // set value methods

    /**
    @brief Set bool value by key.
    */
    void    setBoolForKey(const char* pKey, bool value);
    /**
    @brief Set integer value by key.
    */
    void    setIntegerForKey(const char* pKey, int value);
    /**
    @brief Set float value by key.
    */
    void    setFloatForKey(const char* pKey, float value);
    /**
    @brief Set double value by key.
    */
    void    setDoubleForKey(const char* pKey, double value);

#define SYM_setStringForKey "_ZN7cocos2d13CCUserDefault15setStringForKeyEPKcRKSs"

    /**
    @brief Set string value by key.
    */
   [[link_name(SYM_setStringForKey)]]
    void    setStringForKey(const char* pKey, const gdstd::string & value);

#undef SYM_setStringForKey

    /**
     @brief Save content to xml file
     */
    void    flush();

    static CCUserDefault* sharedUserDefault();
    static void purgeSharedUserDefault();

#define SYM_getXMLFilePath "_ZN7cocos2d13CCUserDefault14getXMLFilePathEv"

    [[link_name(SYM_getXMLFilePath)]]
    const static gdstd::string& getXMLFilePath();

#undef SYM_getXMLFilePath

private:
    CCUserDefault();
    static bool createXMLFile();
    static bool isXMLFileExist();
    static void initXMLFilePath();
    
    static CCUserDefault* m_spUserDefault;
    static gdstd::string m_sFilePath;
    static bool m_sbIsFilePathInitialized;
};

// end of data_storage group
/// @}

NS_CC_END

#endif // __SUPPORT_CCUSERDEFAULT_H__
