#include <iostream>
#include <string>

#include "BookParser.h"

int main()
{
	std::string book = " Plenty of Room at the Bottom"; //huge book
	BookParserProxy* bookProxy = new BookParserProxy(book);

	std::cout << bookProxy->requestNumberOfWords();

	delete bookProxy;

	return 0;
}
