#ifndef BOOK_PARSER_H
#define BOOK_PARSER_H

#include <string>

struct IBookParser
{
	virtual int requestNumberOfWords() = 0;
	virtual ~IBookParser() = default;
};

class BookParser : public IBookParser
{
	const std::string& book;
	size_t numberOfPages;
public:
	BookParser(const std::string& book) :
		book(book), numberOfPages(book.size()) {}
public:
	int requestNumberOfWords() override
	{
		return this->numberOfPages;
	}
};

class BookParserProxy : public IBookParser
{
	BookParser* bookParser;
	const std::string& book;
public:
	BookParserProxy(const std::string& book) :
		bookParser(nullptr), book(book) {}
	~BookParserProxy()
	{
		if (this->bookParser != nullptr)
		{
			delete this->bookParser;
		}
	}
public:
	int requestNumberOfWords() override
	{
		if (this->bookParser == nullptr)
		{
			this->bookParser = new BookParser(this->book); //expensive operation
		}
		return this->bookParser->requestNumberOfWords();
	}
};

#endif // !BOOK_PARSER_H
