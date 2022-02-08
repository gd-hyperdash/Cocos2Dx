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

#ifndef __HTTP_RESPONSE__
#define __HTTP_RESPONSE__

#include "HttpRequest.h"

NS_CC_EXT_BEGIN

/** 
 @brief defines the object which users will receive at onHttpCompleted(sender, HttpResponse) callback
 Please refer to samples/TestCpp/Classes/ExtensionTest/NetworkTest/HttpClientTest.cpp as a sample
 @since v2.0.2
 */
class CCHttpResponse : public CCObject
{
public:
    /** Constructor, it's used by CCHttpClient internal, users don't need to create HttpResponse manually
     @param request the corresponding HttpRequest which leads to this response 
     */
    CCHttpResponse(CCHttpRequest* request);
    
    /** Destructor, it will be called in CCHttpClient internal,
     users don't need to desturct HttpResponse object manully 
     */
    virtual ~CCHttpResponse();
    
    /** Override autorelease method to prevent developers from calling it */
    CCObject* autorelease(void);
    
    // getters, will be called by users
    
    /** Get the corresponding HttpRequest object which leads to this response 
        There's no paired setter for it, coz it's already setted in class constructor
     */
    CCHttpRequest* getHttpRequest();
        
    /** To see if the http reqeust is returned successfully,
        Althrough users can judge if (http return code = 200), we want an easier way
        If this getter returns false, you can call getResponseCode and getErrorBuffer to find more details
     */
    bool isSucceed();
    
#define SYM_getResponseData "_ZN7cocos2d9extension14CCHttpResponse15getResponseDataEv"

    /** Get the http response raw data */
    [[link_name(SYM_getResponseData)]]
    gdstd::vector<char>* getResponseData();

#undef SYM_getResponseData

    /** Get the http response errorCode
     *  I know that you want to see http 200 :)
     */
    int getResponseCode();

    /** Get the error buffer which will tell you more about the reason why http request failed
     */
    const char* getErrorBuffer();
    
    // setters, will be called by CCHttpClient
    // users should avoid invoking these methods
    
    
    /** Set if the http request is returned successfully,
     Althrough users can judge if (http code == 200), we want a easier way
     This setter is mainly used in CCHttpClient, users mustn't set it directly
     */
    void setSucceed(bool value);
    
#define SYM_setResponseData "\x00"

    /** Set the http response raw buffer, is used by CCHttpClient      
     */
    [[link_name(SYM_setResponseData)]]
    void setResponseData(gdstd::vector<char>* data);
    
#undef SYM_setResponseData
    
    /** Set the http response errorCode
     */
    void setResponseCode(int value);
    
    
    /** Set the error buffer which will tell you more the reason why http request failed
     */
    void setErrorBuffer(const char* value);
    
protected:
    bool initWithRequest(CCHttpRequest* request);
    
    // properties
    CCHttpRequest*      _pHttpRequest;  /// the corresponding HttpRequest pointer who leads to this response 
    bool                _succeed;       /// to indecate if the http reqeust is successful simply
    gdstd::vector<char>   _responseData;  /// the returned raw data. You can also dump it as a string
    int                 _responseCode;  /// the status code returned from libcurl, e.g. 200, 404
    gdstd::string         _errorBuffer;   /// if _responseCode != 200, please read _errorBuffer to find the reason 
    
};

NS_CC_EXT_END

#endif //__HTTP_RESPONSE_H__
