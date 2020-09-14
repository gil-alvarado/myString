	/*
 * myString2.cxx
 *
 *  Created on: Oct 13, 2017
 *      Author: Gilbert Alvarado
		Compiler Used: Eclipse
		Assignment 2
 */
//NOTE THIS IS INCOMPLETE
#include "myString2.h"

stringV2::stringV2() : aSize(0), length(0)
{}
/*
 * stringV2(char *)
 * copy constructor
 * accepts a char pointer and it initializes data[]
 */
stringV2::stringV2(char * charIn) : length(0), aSize(0)
{

	while(*(charIn + length) != NULL)
		++length;//sets length for data

	if(length == 0)
	{
		aSize = 0;
		data[aSize] = '\0';//null terminated
	}
	else
	{
		aSize = length;
		data[aSize];
		for(unsigned int i = 0; i < length; ++i)
		{
			data[i] =charIn[i];
		}
	}
}
stringV2::~stringV2()
{
}
/*
 * rSearchChar(const char& ar)
 * passed char is searched within data
 *in the for loop, the position of search starts at the end of data
 *the position is returned
 */
size_t stringV2::rSearchChar(const char& letter, const char* arr)
{
	bool end = false;

	while(end == false)
	{
	for(unsigned int i = aSize; arr!='\0'; --i,--arr)
	{
		if(*arr == letter)
		{
			return i;
			end = true;
		}
	}
	}
	return -1;
}
/*
 * rSearchChar(const char& ar)
 * passed char is searched within data
 *in the for loop, the position of search starts at the end of data
 *the position is returned
 */
size_t stringV2::rSearchMyString(const myString& target)
{
	int pos;
	char * temp = NULL;
	temp = target.data();
	bool end = false;

		while(end == false)
		{
		for(unsigned int i = length; temp!='\0'; --i)
		{
			if(data[i] == temp[i])
			{
				pos = i;
				end = true;
			}
		}
		}
		return pos;
}
/*
 *countChar(const char& target)
 *checks number of occurrences  of passed char within data
 */
size_t stringV2::countChar(const char& target)
{
	size_t count = 0;
	size_t i;

	for(i = 0; i < length; ++i)
	{
		if(data[i] == target)
		{
			++count;
		}
	}
	return count;
}
/*
 * countMyString(const myString& target)
 * checks number of occurrences of myString in data
 * butI know it still needs work done
 */
size_t stringV2::countMyString(const myString& target)
{
	size_t count = 0;
	size_t i;
	char *temp = NULL;
	temp = target.data();
	for(i = 0; i < length; ++i)
	{
		if( temp[i] == data[i])
		{
			++count;
		}
	}
	delete [] temp;
	temp = NULL;
	return count;
}
/*
 * replaceChar(char* passedChar,  char input, const char& target)
 * searches passedChar for the char to be changed
 * if the first occurrence of target is found, the value is changed and the loop breaks
 */
void stringV2::replaceChar(char* passedChar,  char input, const char& target)
{
	bool end = true;

		while(end == true)
		{
			for(int i = 0; i < passedChar[i]; ++i)
			{
				if(target == passedChar[i])
				{
					passedChar[i] = input;
					end = false;
				}
			}
		}
}
//returns the first string of data
char* stringV2::begin()
{
	return data;
}
//returns the last char of data
char* stringV2::end()
{
	return (data + length);
}
//returns second char in data
char* stringV2::next(){
	return (data + 1);
}
