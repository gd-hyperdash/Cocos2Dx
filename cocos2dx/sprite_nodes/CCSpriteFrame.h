/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org
Copyright (c) 2008-2011 Ricardo Quesada
Copyright (c) 2011      Zynga Inc.

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

#ifndef __SPRITE_CCSPRITE_FRAME_H__
#define __SPRITE_CCSPRITE_FRAME_H__

#include "base_nodes/CCNode.h"
#include "CCProtocols.h"
#include "cocoa/CCObject.h"
#include "cocoa/CCGeometry.h"

NS_CC_BEGIN

class CCTexture2D;
class CCZone;

/**
 * @addtogroup sprite_nodes
 * @{
 */

/** @brief A CCSpriteFrame has:
    - texture: A CCTexture2D that will be used by the CCSprite
    - rectangle: A rectangle of the texture


 You can modify the frame of a CCSprite by doing:
 
    CCSpriteFrame *frame = CCSpriteFrame::frameWithTexture(texture, rect, offset);
    sprite->setDisplayFrame(frame);
 */
class CC_DLL CCSpriteFrame : public CCObject
{
public:
    // attributes

    const CCRect& getRectInPixels(void);
    void setRectInPixels(const CCRect& rectInPixels);

    bool isRotated(void);
    void setRotated(bool bRotated);

    /** get rect of the frame */
    const CCRect& getRect(void);
    /** set rect of the frame */
    void setRect(const CCRect& rect);

    /** get offset of the frame */
    const CCPoint& getOffsetInPixels(void);
    /** set offset of the frame */
    void setOffsetInPixels(const CCPoint& offsetInPixels);

    /** get original size of the trimmed image */
    const CCSize& getOriginalSizeInPixels(void);
    /** set original size of the trimmed image */
    void setOriginalSizeInPixels(const CCSize& sizeInPixels);

    /** get original size of the trimmed image */
    const CCSize& getOriginalSize(void);
    /** set original size of the trimmed image */
    void setOriginalSize(const CCSize& sizeInPixels);

    /** get texture of the frame */
    CCTexture2D* getTexture(void);
    /** set texture of the frame, the texture is retained */
    void setTexture(CCTexture2D* pobTexture);

    const CCPoint& getOffset(void);
    void setOffset(const CCPoint& offsets);

public:
    ~CCSpriteFrame(void);
    virtual CCObject* copyWithZone(CCZone *pZone);

    /** Create a CCSpriteFrame with a texture, rect in points.
    @deprecated: This interface will be deprecated sooner or later.
     It is assumed that the frame was not trimmed.
     */
    CC_DEPRECATED_ATTRIBUTE static CCSpriteFrame* frameWithTexture(CCTexture2D* pobTexture, const CCRect& rect);

    /** Create a CCSpriteFrame with a texture filename, rect in points.
     It is assumed that the frame was not trimmed.
     @deprecated: This interface will be deprecated sooner or later.
     */
    CC_DEPRECATED_ATTRIBUTE static CCSpriteFrame* frameWithTextureFilename(const char* filename, const CCRect& rect);

    /** Create a CCSpriteFrame with a texture, rect, rotated, offset and originalSize in pixels.
     The originalSize is the size in points of the frame before being trimmed.
     @deprecated: This interface will be deprecated sooner or later.
     */
    CC_DEPRECATED_ATTRIBUTE static CCSpriteFrame* frameWithTexture(CCTexture2D* pobTexture, const CCRect& rect, bool rotated, const CCPoint& offset, const CCSize& originalSize);

    /** Create a CCSpriteFrame with a texture filename, rect, rotated, offset and originalSize in pixels.
     The originalSize is the size in pixels of the frame before being trimmed.
     @deprecated: This interface will be deprecated sooner or later.
     */
    CC_DEPRECATED_ATTRIBUTE static CCSpriteFrame* frameWithTextureFilename(const char* filename, const CCRect& rect, bool rotated, const CCPoint& offset, const CCSize& originalSize);

        /** Create a CCSpriteFrame with a texture, rect in points.
     It is assumed that the frame was not trimmed.
     */
    static CCSpriteFrame* create(CCTexture2D* pobTexture, const CCRect& rect);

    /** Create a CCSpriteFrame with a texture filename, rect in points.
     It is assumed that the frame was not trimmed.
     */
    static CCSpriteFrame* create(const char* filename, const CCRect& rect);

    /** Create a CCSpriteFrame with a texture, rect, rotated, offset and originalSize in pixels.
     The originalSize is the size in points of the frame before being trimmed.
     */
    static CCSpriteFrame* create(CCTexture2D* pobTexture, const CCRect& rect, bool rotated, const CCPoint& offset, const CCSize& originalSize);

    /** Create a CCSpriteFrame with a texture filename, rect, rotated, offset and originalSize in pixels.
     The originalSize is the size in pixels of the frame before being trimmed.
     */
    static CCSpriteFrame* create(const char* filename, const CCRect& rect, bool rotated, const CCPoint& offset, const CCSize& originalSize);

public:
    /** Initializes a CCSpriteFrame with a texture, rect in points.
     It is assumed that the frame was not trimmed.
     */
    bool initWithTexture(CCTexture2D* pobTexture, const CCRect& rect);

    /** Initializes a CCSpriteFrame with a texture filename, rect in points;
     It is assumed that the frame was not trimmed.
     */
    bool initWithTextureFilename(const char* filename, const CCRect& rect);

    /** Initializes a CCSpriteFrame with a texture, rect, rotated, offset and originalSize in pixels.
    The originalSize is the size in points of the frame before being trimmed.
    */
    bool initWithTexture(CCTexture2D* pobTexture, const CCRect& rect, bool rotated, const CCPoint& offset, const CCSize& originalSize);

    /** Initializes a CCSpriteFrame with a texture, rect, rotated, offset and originalSize in pixels.
     The originalSize is the size in pixels of the frame before being trimmed.

     @since v1.1
     */
    bool initWithTextureFilename(const char* filename, const CCRect& rect, bool rotated, const CCPoint& offset, const CCSize& originalSize);


protected:
    CCPoint m_obOffset;
    CCSize m_obOriginalSize;
    CCRect m_obRectInPixels;
    bool   m_bRotated;
    CCRect m_obRect;
    CCPoint m_obOffsetInPixels;
    CCSize m_obOriginalSizeInPixels;
    CCTexture2D *m_pobTexture;
    gdstd::string  m_strTextureFilename;
};

// end of sprite_nodes group
/// @}

NS_CC_END

#endif //__SPRITE_CCSPRITE_FRAME_H__
