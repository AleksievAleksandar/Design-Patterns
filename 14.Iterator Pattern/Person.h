#ifndef PERSON_H
#define PERSON_H

#include <string>

struct PersonIterable
{
	std::string rightHandObj = "sword";
	std::string leftHandObj = "shield";
};

class PersonIterator
{
	PersonIterable* person;
	int itemCnt;

	static int noItemValue;
	static int maxItemNumber;

	PersonIterator(PersonIterable& person, int itemCnt) :
		person(&person), itemCnt(itemCnt) {}

public:
	static PersonIterator begin(PersonIterable& person)
	{
		return PersonIterator(person, 0);
	}
	static PersonIterator end(PersonIterable& person)
	{
		return PersonIterator(person, PersonIterator::noItemValue);
	}

	bool operator!=(const PersonIterator& other)
	{
		return this->itemCnt != other.itemCnt;
	}
	PersonIterator& operator++()
	{
		this->itemCnt++;
		if (this->itemCnt >= PersonIterator::maxItemNumber)
		{
			this->itemCnt = PersonIterator::noItemValue;
		}
		return *this;
	}
	std::string& operator*() const
	{
		switch (this->itemCnt)
		{
		case 0:
			return this->person->rightHandObj;
			break;
		case 1:
			return this->person->leftHandObj;
			break;

		default:
			break;
		}
	}
};
int PersonIterator::noItemValue = -1;
int PersonIterator::maxItemNumber = 2;

class Person : public PersonIterable
{
public:
	std::string name;
	int age;
public:
	Person() :
		name("UNKNOWN"), age(0) {}
	Person(const std::string& name, int age) :
		name(name), age(age) {}
public:
	PersonIterator begin()
	{
		return PersonIterator::begin(*this);
	}
	PersonIterator end()
	{
		return PersonIterator::end(*this);
	}
};

#endif // !PERSON_H
