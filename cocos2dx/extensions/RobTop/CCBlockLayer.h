#ifndef __CCBLOCKLAYER_H__
#define __CCBLOCKLAYER_H__

#include "layers_scenes_transitions_nodes/CCLayer.h"

/* A layer that blocks everything else when shown */
class CC_DLL CCBlockLayer
	: public cocos2d::CCLayerColor
{
public:
	~CCBlockLayer();
	
	static CCBlockLayer  *create();
	
	bool init();
	
	void draw();
	void registerWithTouchDispatcher();
	
	bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	
	virtual void customSetup();
	virtual void enterLayer();
	virtual void exitLayer();
	virtual void showLayer(bool dontAnimate);
	virtual void hideLayer(bool dontAnimate);
	virtual void layerVisible();
	virtual void layerHidden();
	virtual void enterAnimFinished();
	virtual void disableUI();
	virtual void enableUI();
	virtual void keyBackClicked();
	
	CC_SYNTHESIZE(bool, removeOnExit_, RemoveOnExit);
};

#endif //__CCBLOCKLAYER_H__
