#ifndef __CCTEXTINPUTNODE_H__
#define __CCTEXTINPUTNODE_H__

#include "label_nodes/CCLabelBMFont.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "text_input_node/CCTextFieldTTF.h"

class CCTextInputNode;

class CC_DLL TextInputDelegate {
public:
	virtual void textChanged(CCTextInputNode *textInput);
	virtual void textInputOpened(CCTextInputNode *textInput);
	virtual void textInputClosed(CCTextInputNode* textInput);
};

class CC_DLL CCTextInputNode
	: public cocos2d::CCLayer,
	public cocos2d::CCIMEDelegate,
	public cocos2d::CCTextFieldDelegate
{
public:
	~CCTextInputNode();
	
	static CCTextInputNode *create(float width, float height, const char *placeholder, const char *labelPlaceholderFont, int labelPlaceholderFontSize, const char *labelNormalFont);
	bool init(float width, float height, const char *placeholder, const char *labelPlaceholderFont, int labelPlaceholderFontSize, const char *labelNormalFont);
	
	void visit();
	void registerWithTouchDispatcher();
	bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	
	virtual void textChanged();
	virtual void onClickTrackNode(bool bClicked);
	
	virtual void keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& info);
	virtual void keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& info);
	
	virtual bool onTextFieldInsertText(cocos2d::CCTextFieldTTF *pSender, const char *text, int nLen);
	virtual bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF *pSender);
	virtual bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF *pSender);
	
	void refreshLabel();
	void setString(const char *str);
	void updateLabel(const char *str);
	
	gdstd::string placeholder_;
	float verticalPosition_;
	bool showedKeyboard_;
	bool needAdjustVerticalPosition_;
	gdstd::string allowedChars_;
	float maxLabelWidth_;
	float maxLabelScale_;
	float labelPlaceholderScale_;
	cocos2d::ccColor3B labelPlaceholderColor_;
	cocos2d::ccColor3B labelNormalColor_;
	CC_SYNTHESIZE_READONLY(cocos2d::CCTextFieldTTF*, textField_, TextField);
	CC_SYNTHESIZE(TextInputDelegate*, delegate_, Delegate);
	CC_SYNTHESIZE(int, charLimit_, CharLimit);
	CC_SYNTHESIZE_READONLY(cocos2d::CCLabelBMFont*, label_, Label);
	CC_SYNTHESIZE(bool, profanityFilter_, ProfanityFilter);
};

#endif //__CCTEXTINPUTNODE_H__
