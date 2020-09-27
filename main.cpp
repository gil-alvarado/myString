#define _SCL_SECURE_NO_WARNINGS

/*
  hello from sublime text
  dont mind me, just practicing git from cmd
  now practicing from linux bash
  
  refrain from using the STD library

  g++ main.cpp myString.cxx -o main
  cd C:\FlashDrive2\Eclipse Work Area\C++\AssignementTwo_String
*/

#include <iostream>
#include "mystring.h"//namespace notstd, class myString

// using namespace notstd;
// #include "myString2.h"

#include <algorithm>  

char addone(char& cIn);

int main()
{
  // const notstd::myString MS("CONSTANT");//assign value to string
  notstd::myString msa("A");
  notstd::myString msb("Cudgel");
                      //copyConstructor called (1) +  newMyString + copyConstructor called(2)
  notstd::myString msc(msa + notstd::myString(" ") + msb);
  notstd::myString msd(msc.substr(2, 3));//newMyString(3) + copyConstructor called(3)
  char *cPtr;

  // std::cout << "hello " << std::endl;
  // std::cout << msc << std::endl;
//   //STRINGV2 TEST
//   //replaceChar(char* passedChar,  char input, const char& target)
//   std::cout << "STRINGV2 TEST " << std::endl;
//   char *temp = new char[10];

//   std::cout << "Enter your name: " << std::endl;
//   std::cin >> temp;
//   // stringV2 ob(temp);
//   //std::cout << ob.countChar('b') << std::endl;
//   //std::cout << temp << std::endl;
//   delete[]temp;

// //***********************************************
//   // MS[0];
//   // msc += "!";
//   msc += msc;
//   std::cout << msc << " : LOOK HERE \n";
//   msc.replace(2, 6, msa);
//   std::cout << msc << " : LOOK HERE \n";
//   if(msc.find(msb, 3) != -1)
// 	  msc.replace(msc.find(msb), msb.length(), MS);

//   msc.insert(5, notstd::myString("TAIN Is "));
//   if(!msb.isEmpty())
// 	  msb.erase(3, 1);
//   std::cout << msc << std::endl;

  // //msa
  // std::cout << std::endl;
  // std::cout << "String a:  " << msa << std::endl;
  // std::cout << "Length:    " << msa.length() << std::endl;
  // std::cout << "Front:     " << msa.front() << std::endl;
  // std::cout << "Back:      " << msa.back() << std::endl;
  // std::cout << "[0]:       " << msa[0]<< std::endl;
  // std::cout << "at(0):     " << msa.at(0) << std::endl;

  // //msb
  // std::cout << std::endl;
  // std::cout << "String b:  " << msb << std::endl;
  // std::cout << "Length:    " << msb.length() << std::endl;
  // std::cout << "Front:     " << msb.front() << std::endl;
  // std::cout << "Back:      " << msb.back() << std::endl;
  // std::cout << "[0]:       " << msb[0] << std::endl;
  // std::cout << "at(0):     " << msb.at(0) << std::endl;

  // //msc
  // std::cout << std::endl;
  // std::cout << "String c:  " << msc << std::endl;
  // std::cout << "Length:    " << msc.length() << std::endl;
  // std::cout << "Front:     " << msc.front() << std::endl;
  // std::cout << "Back:      " << msc.back() << std::endl;
  // std::cout << "[0]:       " << msc[0] << std::endl;
  // std::cout << "at(0):     " << msc.at(0) << std::endl;

  // //msd
  // std::cout << std::endl;
  // std::cout << "String d:  " << msd << std::endl;
  // std::cout << "Length:    " << msd.length() << std::endl;
  // std::cout << "Front:     " << msd.front() << std::endl;
  // std::cout << "Back:      " << msd.back() << std::endl;
  // std::cout << "[0]:       " << msd[0] << std::endl;
  // std::cout << "at(0):     " << msd.at(0) << std::endl;

//   std::cout << std::endl;
//   cPtr = msc.data();
//   std::cout << cPtr << std::endl;
//   std::cout << "CPTER IS HERE" << std::endl;
//   delete[] cPtr;

//   std::cout << std::endl;
  // std::cout << "Enter a string: ";
  // std::cin >> msa;
  // std::cout << msa << std::endl;

//   msb = msa;
//   msb += '!';

//   //msb
//   std::cout <<std::endl;
//   std::cout << "String:    " << msb << std::endl;
//   std::cout << "Length:    " << msb.length() << std::endl;

//   std::transform(msb.begin(), msb.end(), msb.begin(), addone);

//   //msb after transform
//   std::cout << std::endl;
//   std::cout << "String as upper: " << msb << std::endl;
//   std::cout << "Length:          " << msb.length() << std::endl;

  return EXIT_SUCCESS;
}

char addone(char& cIn)
{
	return cIn + 1;
}
