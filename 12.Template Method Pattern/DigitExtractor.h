#ifndef DIGIT_EXTRACOR_H
#define DIGIT_EXTRACOR_H

#include "Extractor.h"

#include <string>

class DigitExtractor : public Extractor
{
public:
	DigitExtractor(const std::string& text) :
		Extractor(text) {}
protected:
	virtual bool shouldExtract(char symbol) const override
	{
		return isdigit(symbol);
	}
};

#endif // !DIGIT_EXTRACOR_H
