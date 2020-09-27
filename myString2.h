//NOTE THIS IS INCOMPLETE
#ifndef MYSTRING2_H_
#define MYSTRING2_H_

#include "myString.h"

using namespace::notstd;

class stringV2
{
	public:

	stringV2();
	stringV2(char*);
	~stringV2();

	size_t rSearchChar(const char&, const char*);
	size_t rSearchMyString(const myString&);

	size_t countChar(const char&);
	size_t countMyString(const myString&);
					//LOCATION, LENGTH, CHAR
	void replaceChar(char *, char, const char&);

	//void resize(const size_t newSize);
	//INCOMPLETE
	char* begin();
	char* end();
	char* next();

	private:
	char* data;
	size_t aSize;
	size_t length;

};
#endif /* MYSTRING2_H_ */
