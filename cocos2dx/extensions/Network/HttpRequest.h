/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 
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

#ifndef __HTTP_REQUEST_H__
#define __HTTP_REQUEST_H__

#include "cocoa/CCObject.h"

#include <vector>
#include <string>

NS_CC_EXT_BEGIN

/** 
 @brief defines the object which users must packed for CCHttpClient::send(HttpRequest*) method.
 Please refer to samples/TestCpp/Classes/ExtensionTest/NetworkTest/HttpClientTest.cpp as a sample
 @since v2.0.2
 */
class CCHttpRequest : public CCObject
{
public:
    /** Use this enum type as param in setReqeustType(param) */
    typedef enum
    {
        kHttpGet,
        kHttpPost,
        kHttpUnkown,
    } HttpRequestType;
    
    /** Constructor 
        Because HttpRequest object will be used between UI thead and network thread,
        requestObj->autorelease() is forbidden to avoid crashes in CCAutoreleasePool
        new/retain/release still works, which means you need to release it manually
        Please refer to HttpRequestTest.cpp to find its usage
     */
    CCHttpRequest();
    
    /** Destructor */
    virtual ~CCHttpRequest();
    
    /** Override autorelease method to avoid developers to call it */
    CCObject* autorelease(void);
            
    // setter/getters for properties
     
    /** Required field for HttpRequest object before being sent.
        kHttpGet & kHttpPost is currently supported
     */
    void setRequestType(HttpRequestType type);

    /** Get back the kHttpGet/Post/... enum value */
    HttpRequestType getRequestType();
    
    /** Required field for HttpRequest object before being sent.
     */
    void setUrl(const char* url);

    /** Get back the setted url */
    const char* getUrl();
    
    /** Option field. You can set your post data here
     */
    void setRequestData(const char* buffer, unsigned int len);

    /** Get the request data pointer back */
    char* getRequestData();

    /** Get the size of request data back */
    int getRequestDataSize();
    
    /** Option field. You can set a string tag to identify your request, this tag can be found in HttpResponse->getHttpRequest->getTag()
     */
    void setTag(const char* tag);

    /** Get the string tag back to identify the request. 
        The best practice is to use it in your MyClass::onMyHttpRequestCompleted(sender, HttpResponse*) callback
     */
    const char* getTag();
    
    /** Option field. You can attach a customed data in each request, and get it back in response callback.
        But you need to new/delete the data pointer manully
     */
    void setUserData(void* pUserData);

    /** Get the pre-setted custom data pointer back.
        Don't forget to delete it. HttpClient/HttpResponse/HttpRequest will do nothing with this pointer
     */
    void* getUserData();
    
    /** Required field. You should set the callback selector function at ack the http request completed
     */
    void setResponseCallback(CCObject* pTarget, SEL_CallFuncND pSelector);

    /** Get the target of callback selector funtion, mainly used by CCHttpClient */
    CCObject* getTarget();

    /** Get the selector function pointer, mainly used by CCHttpClient */
    SEL_CallFuncND getSelector();

#define SYM_setHeaders "\x00"

    /** Set any custom headers **/
    [[link_name(SYM_setHeaders)]]
    void setHeaders(gdstd::vector<gdstd::string> pHeaders);

#undef SYM_setHeaders
   
#define SYM_getHeaders "_ZN7cocos2d9extension13CCHttpRequest10getHeadersEv"

    /** Get custom headers **/
    [[link_name(SYM_getHeaders)]]
    gdstd::vector<gdstd::string> getHeaders();

#undef SYM_getHeaders


protected:
    // properties
    HttpRequestType             _requestType;    /// kHttpRequestGet, kHttpRequestPost or other enums
    gdstd::string                 _url;            /// target url that this request is sent to
    gdstd::vector<char>           _requestData;    /// used for POST
    gdstd::string                 _tag;            /// user defined tag, to identify different requests in response callback
    CCObject*                   _pTarget;        /// callback target of pSelector function
    SEL_CallFuncND              _pSelector;      /// callback function, e.g. MyLayer::onHttpResponse(CCNode *sender, void *data)
    void*                       _pUserData;      /// You can add your customed data here 
    gdstd::vector<gdstd::string>    _headers;		      /// custom http headers
};

NS_CC_EXT_END

#endif //__HTTP_REQUEST_H__