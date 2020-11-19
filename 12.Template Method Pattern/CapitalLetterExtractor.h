#ifndef CAPITAL_LETTER_EXTRACTOR_H
#define CAPITAL_LETTER_EXTRACTOR_H

#include "Extractor.h"

#include <string>

class CapitalLetterExtractor : public Extractor
{
public:
	CapitalLetterExtractor(const std::string& text) :
		Extractor(text) {}
protected:
	virtual bool shouldExtract(char symbol) const override
	{
		return isupper(symbol);
	}
};

#endif // !CAPITAL_LETTER_EXTRACTOR_H
