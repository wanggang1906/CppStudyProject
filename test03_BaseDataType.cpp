﻿#include"test03_BaseDataType.h"
#include <iostream>

#include <string> // 引入string类
#include<cstring> // c类型的string


// 基本数据类型

// 预定义类型
// @1-整型
//		short - 16bit
//		int - 至少与short一样长
//		long - 至少32bit，且至少与int一样长
//		long long - 至少64bit，且至少与long一样长
// @2-字符型
//		char - 字符
//		wchar_t - 宽字符
//		char16_t - unicode字符
//		char32_t - unicode字符
// @3-布尔型
//		bool - C++新增的
// @4-浮点型
//		float - 32为单精度浮点数
//		double - 64bit双精度浮点数
// @5-空类型
//		void - 不能用于普通变量的声明和普通的操作，只能用于指针型变量，函数返回值和函数参数
// @6-指针类型
//		(类型)*(指针变量) - 用来描述内存地址，并通过提供指针操作来实现与内存相关的程序功能
//			#1 - <类型>决定了指向的内存空间的大小(数据类型)
//			#2 - 指针变量也是一种变量，有着自己的内存空间，该空间上存储的是另一个变量的内存空间

// 自定义数据类型
// @7-数组
// @8-结构体（struct）
//		普通结构体
//		结构体数组
//		结构体嵌套
//		结构体指针
//@9-联合体（union）
//		定义 - 联合体的主要作用就是节省内存，因为联合体中的·变量不像结构体中的成员变量那样，系统会给其中的每一个变量都分配相应的内存。
//			在联合体中，所有的成员变量共享一块内存空间。该内存空间是其成员变量中占字节数最多的变量所占用的内存空间，并且所有的成员
//			变量共用这一块内存空间，因此联合体中所有成员变量地址是一样的
//		使用 - 联合体的使用方式和结构体及普通变量类似
// @10-枚举（enum）
//		定义 - C++中的一种派生数据类型，它是由用户定义的若干枚举常量的集合
//		使用 - 

void test03_BaseDataType::claMain()
{
	std::cout << "test03 ";
	//this->testString();
	this->pointerTest();
	this->dataSize();


}



using namespace std;

int test03_BaseDataType::testString() {

	std::string str; // 字符串是一个对象，在C++标准库中，功能非常多，如提取，比较，搜索字符串

	cout << "输入一个字符串";
	std::getline(std::cin, str); // getline()不是iostream类的方法，而是使用string类中的一个友元函数
	cout << str;

	char cstr[20] = "ee"; // 用字符数组来承载字符串
	cout << cstr;

	string sstr = "ss";
	cout << sstr;

	string in;
	cin >> in; // cin可以输入多段字符串
	cout << "输入的内容为：" << in << "\n";
	return 0;
}


// 指针
// 指针的作用是存放地址
// 创建指针时空格不影响，如int *p; int * p; int* p;等同
// *的两种用途，@1-创建指针。@2-对指针进行解引用
// 允许多个指针指向相同的值，且同步改变
// 支持无类型指针，如void *vPointer，但解应用前要转换为适当的数据类型
int test03_BaseDataType::pointerTest()
{
	const unsigned short ITEM = 5; // 常量 无符号短整型
	int intArray[ITEM] = { 1,2,3,4,5 };
	char charArray[ITEM] = { 'f','i','s','a','q' };

	int* intPtr = intArray;
	char* charPtr = charArray;
	std::cout << "整型数组输出" << '\n';
	for (int i = 0; i < ITEM; i++)
	{
		// reinterpret_cast<unsigned long>()是对地址进行强制转换
		std::cout << *intPtr << " at " << reinterpret_cast<unsigned long>(intPtr)
			<< '\n';
		intPtr++;

	}
	std::cout << "字符型数组输出" << '\n';
	for (int i = 0; i < ITEM; i++)
	{
		std::cout << *charPtr << " at " << reinterpret_cast<unsigned long>(charPtr)
			<< '\n';
		charPtr++;
	}
	return 0;
}


// 数据类型及其所占内存空间大小
void test03_BaseDataType::dataSize() {
	// 基本数据类型
	int a;
	float b;
	double c;
	bool d;
	char e;
	void; // 无类型
	wchar_t i; // 宽字符型
	//std::cout<< 

	// 所有数据类型
	cout << "type: \t\t" << "************ size **************" << endl; // /t/t 表示两个tab键
	cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);
	cout << "\t最大值：" << (numeric_limits<bool>::max)(); // numeric_limits是C++的模板类，提供基础数据的极值等数学信息，其中的max,min是宏常量
	cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;

	cout << "char: \t\t" << "所占字节数：" << sizeof(char);
	cout << "\t最大值：" << (numeric_limits<char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;

	cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);
	cout << "\t最大值：" << (numeric_limits<signed char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;

	cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);
	cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();
	cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;

	cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);
	cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();
	cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;

	cout << "short: \t\t" << "所占字节数：" << sizeof(short);
	cout << "\t最大值：" << (numeric_limits<short>::max)();
	cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;

	cout << "int: \t\t" << "所占字节数：" << sizeof(int);
	cout << "\t最大值：" << (numeric_limits<int>::max)();
	cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;

	cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);
	cout << "\t最大值：" << (numeric_limits<unsigned>::max)();
	cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;

	cout << "long: \t\t" << "所占字节数：" << sizeof(long);
	cout << "\t最大值：" << (numeric_limits<long>::max)();
	cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;

	cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);
	cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();
	cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;

	cout << "double: \t" << "所占字节数：" << sizeof(double);
	cout << "\t最大值：" << (numeric_limits<double>::max)();
	cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;

	cout << "long double: \t" << "所占字节数：" << sizeof(long double);
	cout << "\t最大值：" << (numeric_limits<long double>::max)();
	cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;

	cout << "float: \t\t" << "所占字节数：" << sizeof(float);
	cout << "\t最大值：" << (numeric_limits<float>::max)();
	cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;

	cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);
	cout << "\t最大值：" << (numeric_limits<size_t>::max)();
	cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;

	cout << "string: \t" << "所占字节数：" << sizeof(string);
	cout << "\t最大值：" << (numeric_limits<string>::max)();
	cout << "\t最小值：" << (numeric_limits<string>::min)() << endl;

	cout << "type: \t\t" << "************ size **************" << endl;
}



// 数据类型复习
void test03_BaseDataType::dataType() {
	std::cout << "数据\n";
	int a;
	std::cout << sizeof(a) << "\n";
	float b;
	std::cout << sizeof(b) << "\n";
}
