#include <iostream>

#include <string>
#include <vector>

#include "Extractor.h"

void printResults(const std::vector<std::string>& result)
{
	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	}
}

int main()
{
	std::string text = "Hello 123 World 0";
	std::vector<std::string> digitResult;
	std::vector<std::string> capLettResult;

	DigitExtractor digitExtractor(text);
	digitResult = digitExtractor.extract();
	printResults(digitResult);

	CapitalLetterExtractor capitalLetterExtractor(text);
	capLettResult = capitalLetterExtractor.extract();
	printResults(capLettResult);

	return 0;
}
