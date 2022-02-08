/*
 *  CCTableViewCell.h
 *  SkeletonX
 *
 *  Created by Vincent on 11-11-21.
 *  Copyright 2011 GeekStudio. All rights reserved.
 *
 */

#ifndef _CCTABLEVIEWCELL_H_
#define _CCTABLEVIEWCELL_H_

#include "menu_nodes/CCMenu.h"
#include "menu_nodes/CCMenuItem.h"

#include "CCTableView.h"

class CCTableViewCell
    : public cocos2d::CCLayer
{
private:
    cocos2d::CCMenu * menuItem;
    void deleteButtonSelector(CCObject * mObject);
public:
    CCTableView * parentView; //must be point to CCTableView instance 
    CCIndexPath indexPath;
    //whether CCTableView is editable
    CC_SYNTHESIZE(bool,editable,Editable);
    /*defalut is ccRED*/
    CC_SYNTHESIZE(cocos2d::ccColor3B, delBtnColor, DelBtnColor);
    CC_SYNTHESIZE(cocos2d::CCMenuItem *, deleteButton, DeleteButton);
    CC_SYNTHESIZE_PASS_BY_REF(std::string,cellIdentifier,CellIdentifier);
    /*it is called automatically*/
    void resetDeleteButtonPosition();
    void showDeleteButton(bool mShow);
    bool isDeleteButtonShow();
    
    float cellWidth;
    float cellHeight;
    cocos2d::CCLayerColor *backgroundLayer;
    cocos2d::CCLayer *contentLayer;
    
    void updateVisibility();
public:
    CCTableViewCell(const char * mCellIdentifier, float mCellWidth, float mCellHeight);
    virtual ~CCTableViewCell();
};

#endif