#include "myString.h"

namespace notstd
{
	//default constructor
	myString::myString()
		: dataPtr(NULL), arrSize(0), currLength(0), minResize(5)
	{
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	//copy constructor
	myString::myString(const myString& msIn)
		: currLength(msIn.length()), minResize(5)
	{				//length of myString,
		if (currLength == 0)
		{//empty string
			dataPtr = NULL;
			arrSize = 0;
		}
		else
		{
			arrSize = currLength + minResize - currLength  % minResize;
			dataPtr = new char[arrSize]();
			char *tempPtr = msIn.data();
			std::copy(tempPtr, tempPtr + currLength, dataPtr);
			delete[] tempPtr;
		}
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	//pre: charPtrIn must be a NULL terminated array
	myString::myString(const char* charPtrIn)//character passed
		: currLength(0), minResize(5)// default length,
	{
		const char *cPtr = charPtrIn;//tempPtr has same value as charPtrIn

			//reaching the end of cPtr
		while (*(cPtr + currLength) != 0)//NULL)
			++currLength;//increment currLength from length of cPtr AND currentLength

		if (currLength == 0)
		{//if the char passed is empty, empty array
			arrSize = 0;
			dataPtr = NULL;
		}
		else
		{
			arrSize = currLength + minResize - currLength % minResize;//set arr size
			dataPtr = new char[arrSize]();//dynamic char array created
			std::copy(charPtrIn, charPtrIn + currLength, dataPtr);
		}			//source, length, copy to
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	myString::~myString()
	{
		delete[] dataPtr;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	myString& myString::operator=(const myString& msIn)
	{
		if (&msIn != this)
		{
			if (msIn.length() == 0)
			{
				delete[] dataPtr;
				dataPtr = NULL;
				arrSize = 0;
				currLength = 0;
			}
			else
			{
				currLength = msIn.length();
				char *tempPtr = msIn.data();

				if (msIn.length() > arrSize)
				{
					arrSize = currLength + minResize - currLength % minResize;
					delete[] dataPtr;
					dataPtr = new char[arrSize]();
				}

				std::copy(tempPtr, tempPtr + currLength, dataPtr);
				delete[] tempPtr;
			}
		}
		return *this;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	myString& myString::operator+=(const myString& msIn)
	{
		if(!msIn.isEmpty())
		{
			arrSize = msIn.length() + currLength;
			arrSize += minResize - (arrSize % minResize);
 			char* tPtr = new char[arrSize]();
 			std::copy(dataPtr, dataPtr + currLength, tPtr);
			char* msInPtr = msIn.data();
			std::copy(msInPtr, msInPtr + msIn.length(), tPtr + currLength);
			delete [] dataPtr;
			delete [] msInPtr;
			dataPtr = tPtr;
			currLength = msIn.length() + currLength;
		}
		return *this;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	myString& myString::operator+=(const char charIn)
	{
		if(currLength + 1 > arrSize)
		{
			arrSize += minResize;
			char* tPtr = new char[arrSize]();
			std::copy(dataPtr, dataPtr + currLength, tPtr);
			delete [] dataPtr;
			dataPtr = tPtr;
		}
		dataPtr[currLength] = charIn;
		++currLength;
		return *this;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	char& myString::operator[](const size_t indexIn)
	{
		return dataPtr[indexIn];
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	const char& myString::operator[](const size_t indexIn)const
	{
		return dataPtr[indexIn];
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	char& myString::at(const size_t indexIn)
	{
		return dataPtr[indexIn];
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	char& myString::front()
	{
		return dataPtr[0];
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	const char& myString::front()const
	{
		return dataPtr[0];
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	char& myString::back()
	{
		return dataPtr[currLength - 1];
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	const char& myString::back()const
	{
		return dataPtr[currLength - 1];
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	//location, myString
	void myString::insert(const size_t posIn, const myString& msIn)
	{		//myString not empty AND location to insert string is not greater than
			//the current length
		if (!msIn.isEmpty() && posIn < currLength)
		{
			char* cPtr = NULL;//temp ptr
			cPtr = msIn.data();
			if (currLength + msIn.length() > arrSize)
			{
				arrSize = msIn.length() + currLength;
				arrSize += minResize - (arrSize % minResize);
			}
			char* tPtr = new char[arrSize]();
			std::copy(dataPtr, dataPtr + posIn, tPtr);//source,length, copy to
			std::copy(cPtr, cPtr + msIn.length(), tPtr + posIn);
			std::copy(dataPtr + posIn, dataPtr + currLength, tPtr + msIn.length() + posIn);
			delete[] dataPtr;
			delete[] cPtr;
			dataPtr = tPtr;
			currLength += msIn.length();
		}
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	
							//location , length, myString
	void myString::replace(const size_t fromIn, size_t lenIn, const myString& msIn)
	{
		if (fromIn <= currLength || (msIn.isEmpty() && lenIn == 0))
		{
			if (fromIn + lenIn > currLength)
			{
				lenIn = currLength - fromIn;
			}

			erase(fromIn, lenIn);//LOCATION, length
			insert(fromIn, msIn);//location, string
		}
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
							//location, length
	void myString::erase(const size_t posIn, const size_t lenIn)
	{
		if(currLength != 0 && lenIn > 0 && posIn < currLength)
		{
            if(posIn + lenIn >= currLength)
			{
            	currLength = posIn;
			}
			else
			{
			  char* tPtr = new char[arrSize]();
			  if(posIn == 0)
			  {
				  std::copy(dataPtr + lenIn, dataPtr + currLength , tPtr);
			  }
			  else
			  {
				  std::copy(dataPtr, dataPtr + posIn, tPtr);
				  std::copy(dataPtr + posIn + lenIn, dataPtr + currLength, tPtr + posIn);
			  }
			  delete [] dataPtr;
			  dataPtr = tPtr;
			  currLength -= lenIn;
			}
		}
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	void myString::clear()
	{
		delete[]dataPtr;
		dataPtr = NULL;
		currLength = 0;
		arrSize = 0;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	char* myString::data()const
	{
		char *tempPtr = new char[currLength + 1]();
		std::copy(dataPtr, dataPtr + currLength, tempPtr);//source, length, copy to
		tempPtr[currLength] = 0;//NULL;
		return tempPtr;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
							//myString, location
	size_t myString::find(const myString& msIn	, const size_t posIn)const
	{
		bool mismatch;
		//currentLength must be greater than the length of myString and location
		if (currLength >= posIn + msIn.length())
		{
				//location, location < length
			for (size_t datai = posIn; datai <= currLength - msIn.length(); ++datai)
			{
				mismatch = false;
				for (size_t msIni = 0; msIni < msIn.length() && !mismatch; ++msIni)
					if (msIn[msIni] != dataPtr[datai + msIni])
						mismatch = true;
				if (mismatch == false)
					return datai;
			}
		}
		return -1;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

							//location, length
	myString myString::substr(const size_t posIn, size_t lenIn)const
	{
		if(lenIn == 0 || posIn > currLength)
			return myString();


		if(currLength < posIn + lenIn)
			lenIn = currLength - posIn;

		char* tempData;
		tempData = new char[lenIn+1]();
		std::copy(dataPtr + posIn, dataPtr + posIn + lenIn, tempData);
		myString tempMS(tempData);
		delete [] tempData;

		return tempMS;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	size_t myString::length()const
	{
		return currLength;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	bool myString::isEmpty()const
	{
		return currLength == 0;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	myString myString::operator+(const myString& msIn)const
	{
		myString tempMS(*this);
		tempMS += msIn;
		return tempMS;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	std::istream& operator >>(std::istream& in, myString& msIn)
	{
		msIn.clear();
		char cIn;
		while (in.get(cIn) && cIn != '\n')
		{
			if (msIn.currLength == msIn.arrSize)
				msIn.resize(msIn.arrSize + msIn.minResize);
			msIn.dataPtr[msIn.currLength] = cIn;
			++msIn.currLength;
		}

		return in;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	std::ostream& operator <<(std::ostream& out, myString& msIn)
	{
		char* tempPtr = msIn.data();
		out << tempPtr;
		delete[] tempPtr;
		return out;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	void myString::resize(const size_t newSize)
	{
		if (newSize > arrSize)
		{
			char* tempPtr = new char[newSize]();
			std::copy(dataPtr, dataPtr + currLength, tempPtr);
			delete [] dataPtr;
			dataPtr = tempPtr;
			arrSize = newSize;
		}
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	char* myString::begin()
	{
		return dataPtr;
	}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	char* myString::end()
	{
		return dataPtr + currLength;
	}
}
