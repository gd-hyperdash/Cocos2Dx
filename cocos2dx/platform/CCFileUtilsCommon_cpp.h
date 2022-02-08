/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

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
#ifndef __CC_PLATFORM_FILEUTILS_CPP__
#error "CCFileUtilsCommon_cpp.h can only be included for CCFileUtils.cpp in platform/win32(android,...)"
#endif /* __CC_PLATFORM_FILEUTILS_CPP__ */

#include "CCFileUtils.h"
#include "CCDirector.h"
#include "cocoa/CCDictionary.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_IOS)

#include "cocoa/CCString.h"
#include "CCSAXParser.h"
#include "support/zip_support/unzip.h"

#include <stack>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlmemory.h>

NS_CC_BEGIN

static const char *__suffixiPhoneRetinaDisplay = "-hd";
static const char *__suffixiPad = "-ipad";
static const char *__suffixiPadRetinaDisplay = "-ipadhd";

typedef enum 
{
    SAX_NONE = 0,
    SAX_KEY,
    SAX_DICT,
    SAX_INT,
    SAX_REAL,
    SAX_STRING,
    SAX_ARRAY
}CCSAXState;

typedef enum
{
    SAX_RESULT_NONE = 0,
    SAX_RESULT_DICT,
    SAX_RESULT_ARRAY
}CCSAXResult;

class CCDictMaker : public CCSAXDelegator
{
public:
    CCSAXResult m_eResultType;
    CCArray* m_pRootArray;
    CCDictionary *m_pRootDict;
    CCDictionary *m_pCurDict;
    std::stack<CCDictionary*> m_tDictStack;
    gdstd::string m_sCurKey;   ///< parsed key
    gdstd::string m_sCurValue; // parsed value
    CCSAXState m_tState;
    CCArray* m_pArray;

    std::stack<CCArray*> m_tArrayStack;
    std::stack<CCSAXState>  m_tStateStack;

public:
    CCDictMaker();
    ~CCDictMaker();

    CCDictionary* dictionaryWithContentsOfFile(const char *pFileName);

    CCArray* arrayWithContentsOfFile(const char* pFileName);

    void startElement(void *ctx, const char *name, const char **atts);

    void endElement(void *ctx, const char *name);

    void textHandler(void *ctx, const char *ch, int len);
};

CCDictionary* ccFileUtils_dictionaryWithContentsOfFileThreadSafe(const char *pFileName);

CCArray* ccFileUtils_arrayWithContentsOfFileThreadSafe(const char* pFileName);

NS_CC_END

#endif // (CC_TARGET_PLATFORM != CC_PLATFORM_IOS)
