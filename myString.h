#pragma once
#define _SCL_SECURE_NO_WARNINGS

#include <istream>
#include <ostream>
#include <cassert>
#include <algorithm>


//custom string class
namespace notstd
{
	class myString
	{
	public:
		myString();
		myString(const myString& msIn);
		myString(const char* charPtrIn);//passed val must be const
		myString(const std::string str);
		virtual ~myString();

		myString& operator=(const myString& msIn);
		myString& operator+=(const myString& msIn);
		myString& operator+=(const char charIn);
		char& operator[](const size_t indexIn);
		const char& operator[](const size_t indexIn)const;
		char& at(const size_t indexIn);
		const char& front()const;
		char& front();
		char& back();
		const char& back()const;
		void insert(const size_t posIn, const myString& msIn);
		void replace(const size_t posIn, const size_t lenIn, const myString& msIn);
		void erase(const size_t posIn, const size_t lenIn = -1);
		void clear();
		char* data()const;
		size_t find(const myString& msIn, const size_t posIn = 0)const;
		myString substr(const size_t posIn, const size_t lenIn = -1)const;
		size_t length()const;
		bool isEmpty()const;
		myString operator+(const myString& msIn)const;
		friend std::istream& operator >>(std::istream& in, myString& msIn);
		friend std::ostream& operator <<(std::ostream& out, myString& msIn);
		char* begin();
		char* end();
	protected:
		void resize(const size_t newSize);
		char *dataPtr;
		size_t arrSize;
		size_t currLength;
		size_t minResize;
	};
}
