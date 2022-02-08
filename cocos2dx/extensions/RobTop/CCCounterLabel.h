#ifndef __CCCOUNTERLABEL_H__
#define __CCCOUNTERLABEL_H__

#include "label_nodes/CCLabelBMFont.h"

enum FormatterType {
	kFormatTypePercentage,
	kFormatTypeInteger
};

class CC_DLL CCCounterLabel
	: public cocos2d::CCLabelBMFont
{
public:
	~CCCounterLabel();
	
	static CCCounterLabel *create(const char *str, const char *font, int count, FormatterType formatterType);
	bool init(const char *str, const char *font, int count, FormatterType formatterType);
	
	void calculateStepSize();
	void disableCounter();
	void enableCounter();
	void fastUpdateCounter();
	int getTargetCount();
	void setTargetCount(int count);
	void setupFormatter(FormatterType type);
	void updateCounter(double dt);
	
	int stepSize_;
	bool counterEnabled_;
	FormatterType formatterType_;
	[[deprecated("unused")]] int unused_;
	int targetCount_;
	CC_SYNTHESIZE_READONLY(int, currentCount_, CurrentCount);
};

#endif //__CCCOUNTERLABEL_H__
