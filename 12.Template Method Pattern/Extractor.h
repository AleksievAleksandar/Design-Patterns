#ifndef EXTRACTOR_H
#define EXTRACTOR_H

#include <string>
#include <sstream>
#include <vector>

class Extractor
{
	std::istringstream buffer;
	std::vector<std::string> result;
public:
	Extractor(const std::string& text) :
		buffer(text) {}
public:
	std::vector<std::string> extract()
	{
		char currentSymbol;
		while (this->buffer >> currentSymbol)
		{
			if (this->shouldExtract(currentSymbol))
			{
				std::string target;
				target = currentSymbol;

				this->result.push_back(target);
			}
		}
		return this->result;
	}
protected:
	virtual bool shouldExtract(char) const = 0;
};

#endif // !EXTRACTOR_H
