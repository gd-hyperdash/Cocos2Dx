/*
 *  CCTableView.h
 *  SkeletonX
 *
 *  Created by Vincent on 11-11-19.
 *  Copyright 2011 GeekStudio. All rights reserved.
 *
 */

#ifndef _CCTABLEVIEW_H_
#define _CCTABLEVIEW_H_

#include "extensions/CCScrollLayerExt/CCScrollLayerExt.h"

enum CCTableViewCellEditingStyle{
    CCTableViewCellEditingStyleNone,
    CCTableViewCellEditingStyleDelete,
    CCTableViewCellEditingStyleInsert
};

/*
 class CCIndexPath,it describe CCTableView's section & row
 */
class CCIndexPath
    : public cocos2d::CCObject
{
public:
    int row;
    int section;
public:
    CCIndexPath(){}
    CCIndexPath(int mSection,int mRow):row(mRow),section(mSection){}
    CCIndexPath(const CCIndexPath &mIndexPath)
    {
        section = mIndexPath.section;
        row        = mIndexPath.row;
    }
    bool operator ==(CCIndexPath & mIndexPath)
    {
        return (section == mIndexPath.section && row == mIndexPath.row);
    }
    static CCIndexPath * CCIndexPathWithSectionRow(int mSection,int mRow)
    {
        CCIndexPath * tmpIndexPath = new CCIndexPath(mSection,mRow);
        tmpIndexPath->autorelease();
        return tmpIndexPath;
    }
};


class CCTableViewCell;
class CCTableView;

/*
 class CCTableViewDelegate for accessing CCTableView's property
 */
class CCTableViewDelegate {
public:
    virtual void willTweenToIndexPath(CCIndexPath &mIndexPath,CCTableViewCell * mTableViewCell,CCTableView * mTableView){}
    virtual void didEndTweenToIndexPath(CCIndexPath &mIndexPath,CCTableView * mTableView){}
    virtual void ccTableViewWillDisplayCellForRowAtIndexPath(CCIndexPath &mIndexPath,CCTableViewCell * mTableViewCell,CCTableView * mTableView){}
    virtual void ccTableViewDidDisplayCellForRowAtIndexPath(CCIndexPath &mIndexPath,CCTableViewCell * mTableViewCell,CCTableView * mTableView){}
    virtual void ccTableViewWillReloadCellForRowAtIndexPath(CCIndexPath &mIndexPath,CCTableViewCell * mTableViewCell,CCTableView * mTableView){}
    virtual float cellHeightForRowAtIndexPath(CCIndexPath & mIndexPath,CCTableView * mTableView)=0;
    virtual void didSelectRowAtIndexPath(CCIndexPath & mIndexPath,CCTableView * mTableView)=0;
};

class CCTableViewDataSource {
public:
    virtual unsigned int numberOfRowsInSection(unsigned int mSection,CCTableView * mTableView)=0;
    virtual unsigned int numberOfSectionsInCCTableView(CCTableView * mTableView){return 1;}
    virtual void ccTableViewCommitCellEditingStyleForRowAtIndexPath(CCTableView * mTableView,CCTableViewCellEditingStyle mCellEditStyle,CCIndexPath &mIndexPath){}
    /*cell was set to anchor point(0.5,0.5)*/
    virtual CCTableViewCell * cellForRowAtIndexPath(CCIndexPath &mIndexPath,CCTableView * mTableView)=0;
};


enum BoundaryType {
    BOUNDARY_OUT  = 1,
    BOUNDARY_IN      = 2
};

/*
 class CCTableView
 */
class CCTableView : public CCScrollLayerExt,public CCScrollLayerExtDelegate {   
private:
    CC_SYNTHESIZE(bool,isScheduled,IsScheduled);
    CC_SYNTHESIZE(cocos2d::CCTouch*,beginTouch,BeginTouch);
    CC_SYNTHESIZE(cocos2d::CCPoint,beginLocation,BeginLocation);
    CC_SYNTHESIZE(cocos2d::CCPoint, lastCellPos, LastCellPos);
    CC_SYNTHESIZE(cocos2d::CCPoint,checkLocation,CheckLocation);
    //temporary CCTableViewCell for checking touch begin & end.
    CC_SYNTHESIZE(CCTableViewCell*,touchCell,TouchCell);
    //whether CCTableView is editable,default is false
    CC_SYNTHESIZE(bool,editable,Editable);
    //touch begin
    CC_SYNTHESIZE(bool,isTouch,IsTouch);
    //handle touch finish
    void touchFinish(cocos2d::CCTouch * touch);
    //check duplicate in visible cell array
    CCTableViewCell * isDuplicateInVisibleCellArray(CCIndexPath *mIndexPath);
    //check duplicate index path.
    bool isDuplicateIndexPath(CCIndexPath & mIndexPath);
    bool removeIndexPathFromPathAddedArray(CCIndexPath & mIndexPath);
    //init CCTableView cells when CCTableView onEnter()
    void initCCTableViewCells();
    //return CCTableViewCell for touch event
    CCTableViewCell* cellForTouch(cocos2d::CCTouch *touch);
    /*it is called automatically*/
    bool deleteCCTableViewCell(CCTableViewCell * mCell); /*TODO*/
    /*check boundary of content layer*/
    void checkBoundaryOfContent(ccTime mTime);
    /*check boundary of cell*/
    BoundaryType checkBoundaryOfCell(CCTableViewCell * mCell);
    /*check boundary of cell*/
    BoundaryType checkBoundaryOfCell(cocos2d::CCPoint &mPosition,float mCellHeight);
    /*check first cell and then load more or delete sth else*/
    void checkFirstCell(CCTableViewCell * firstCell);
    /*check last cell and then load more or delete sth else*/
    void checkLastCell(CCTableViewCell * lastCell);
    
public:
    CCTableView(cocos2d::CCRect mRect= cocos2d::CCRectZero);
    virtual ~CCTableView();
    
    static CCTableView *create(CCTableViewDelegate *delegate, CCTableViewDataSource *dataSource, cocos2d::CCRect mRect= cocos2d::CCRectZero);
    
    CC_SYNTHESIZE(cocos2d::CCArray*,cellVisibleArray,CellVisibleArray);
    CC_SYNTHESIZE(cocos2d::CCArray*,cellRemovedArray,CellRemovedArray);
    CC_SYNTHESIZE(cocos2d::CCArray*,indexPathAddedArray,indexPathAddedArray);/*all the added index path*/
    
    CC_SYNTHESIZE(CCTableViewDelegate *,delegate,Delegate);
    CC_SYNTHESIZE(CCTableViewDataSource *,dataSource,DataSource);
    
    CC_SYNTHESIZE(bool,clipsToBounds,ClipsToBounds);
    
    CC_SYNTHESIZE(CCIndexPath*,scrollingToIndexPath,ScrollingToIndexPath);
    
    CC_SYNTHESIZE(bool,touchDispatch,TouchDispatch);
    
public:
    
    CCTableViewCell * dequeueReusableCellWithIdentifier(const char *mCellIdentifier);
    CCTableViewCell * cellForRowAtIndexPath(CCIndexPath &mIndexPath);// returns nil if cell is not visible or index path is out of range
    void reloadData();
    
    /*TODO*/
    void scrollToIndexPath(CCIndexPath & mIndexPath);
    
public:

//    virtual void visit();
    virtual void onEnter();
    virtual void onExit();
    
    void claimTouch(cocos2d::CCTouch* pTouch);
    void cancelAndStoleTouch(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent* event);
    virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
    
    //CCScrollViewExt delegate
    virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt * mScrollView);
    virtual void scrollViewDidEndDecelerating(CCScrollLayerExt * mScrollView);
    virtual void scrollViewTouchMoving(CCScrollLayerExt * mScrollView);
    virtual void scrollViewDidEndMoving(CCScrollLayerExt * mScrollView);
};

#endif