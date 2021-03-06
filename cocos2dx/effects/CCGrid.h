/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org
Copyright (c) 2009      On-Core
 
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
#ifndef __EFFECTS_CCGRID_H__
#define __EFFECTS_CCGRID_H__

#include "cocoa/CCObject.h"
#include "base_nodes/CCNode.h"
#include "CCCamera.h"
#include "ccTypes.h"
#include "textures/CCTexture2D.h"
#include "CCDirector.h"
#include "kazmath/mat4.h"

NS_CC_BEGIN

class CCTexture2D;
class CCGrabber;
class CCGLProgram;

/**
 * @addtogroup effects
 * @{
 */

/** Base class for other
*/
class CCGridBase : public CCObject
{
public:
    virtual ~CCGridBase(void);

    /** wheter or not the grid is active */
    bool isActive(void);
    void setActive(bool bActive);

    /** number of times that the grid will be reused */
    int getReuseGrid(void);
    void setReuseGrid(int nReuseGrid);

    /** size of the grid */
    const ccGridSize& getGridSize(void);
    void setGridSize(const ccGridSize& gridSize);

    /** pixels between the grids */
    const CCPoint& getStep(void);
    void setStep(const CCPoint& step);

    /** is texture flipped */
    bool isTextureFlipped(void);
    void setTextureFlipped(bool bFlipped);

    bool initWithSize(const ccGridSize& gridSize, CCTexture2D *pTexture, bool bFlipped);
    bool initWithSize(const ccGridSize& gridSize);

    void beforeDraw(void);
    void afterDraw(CCNode *pTarget);
    virtual void blit(void);
    virtual void reuse(void);
    virtual void calculateVertexPoints(void);

public:
    /** create one Grid 
    @deprecated: This interface will be deprecated sooner or later.
    */
    CC_DEPRECATED_ATTRIBUTE static CCGridBase* gridWithSize(const ccGridSize& gridSize, CCTexture2D *texture, bool flipped);
    /** create one Grid 
    @deprecated: This interface will be deprecated sooner or later.
    */
    CC_DEPRECATED_ATTRIBUTE static CCGridBase* gridWithSize(const ccGridSize& gridSize);

    /** create one Grid */
    static CCGridBase* create(const ccGridSize& gridSize, CCTexture2D *texture, bool flipped);
    /** create one Grid */
    static CCGridBase* create(const ccGridSize& gridSize);

    void set2DProjection(void);

protected:
    bool m_bActive;
    int  m_nReuseGrid;
    ccGridSize m_sGridSize;
    CCTexture2D *m_pTexture;
    CCPoint m_obStep;
    CCGrabber *m_pGrabber;
    bool m_bIsTextureFlipped;
    CCGLProgram* m_pShaderProgram;
    ccDirectorProjection m_directorProjection;
};

/**
 CCGrid3D is a 3D grid implementation. Each vertex has 3 dimensions: x,y,z
 */
class CCGrid3D : public CCGridBase
{
public:
    CCGrid3D();
    ~CCGrid3D(void);

    /** returns the vertex at a given position */
    ccVertex3F vertex(const ccGridSize& pos);
    /** returns the original (non-transformed) vertex at a given position */
    ccVertex3F originalVertex(const ccGridSize& pos);
    /** sets a new vertex at a given position */
    void setVertex(const ccGridSize& pos, const ccVertex3F& vertex);

    virtual void blit(void);
    virtual void reuse(void);
    virtual void calculateVertexPoints(void);

public:
    static CCGrid3D* gridWithSize(const ccGridSize& gridSize, CCTexture2D *pTexture, bool bFlipped);
    static CCGrid3D* gridWithSize(const ccGridSize& gridSize);

protected:
    GLvoid *m_pTexCoordinates;
    GLvoid *m_pVertices;
    GLvoid *m_pOriginalVertices;
    GLushort *m_pIndices;
};

/**
 CCTiledGrid3D is a 3D grid implementation. It differs from Grid3D in that
 the tiles can be separated from the grid.
*/
class CCTiledGrid3D : public CCGridBase
{
public:
    CCTiledGrid3D();
    ~CCTiledGrid3D(void);

    /** returns the tile at the given position */
    ccQuad3 tile(const ccGridSize& pos);
    /** returns the original tile (untransformed) at the given position */
    ccQuad3 originalTile(const ccGridSize& pos);
    /** sets a new tile */
    void setTile(const ccGridSize& pos, const ccQuad3& coords);

    virtual void blit(void);
    virtual void reuse(void);
    virtual void calculateVertexPoints(void);

public:
    static CCTiledGrid3D* gridWithSize(const ccGridSize& gridSize, CCTexture2D *pTexture, bool bFlipped);
    static CCTiledGrid3D* gridWithSize(const ccGridSize& gridSize);

protected:
    GLvoid *m_pTexCoordinates;
    GLvoid *m_pVertices;
    GLvoid *m_pOriginalVertices;
    GLushort *m_pIndices;
};

// end of effects group
/// @}

NS_CC_END

#endif // __EFFECTS_CCGRID_H__
