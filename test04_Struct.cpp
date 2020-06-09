#include "test04_Struct.h"


#include<iostream>

// 结构体
// 结构体可定义在类中，也可定义在类外，两者的作用域不同
// 类里的结构体 - 定义在.h文件中
// 使用时当成普通变量

// 类外的结构体 - 定义在.h文件的class外
// 使用时





// .h和.cpp文件分别写的内容
// @1 - .h文件
//		写类的声明(包括类里面的成员和方法声明)，函数原型，#define常数宏等，一般不写具体的实现
//		一般加预编译语句，防止重复编译 #ifndef CIRCLE_H(名称一般为头文件_H)   #define CIRCLE_H   //你的代码写在这里   #endif
//		头文件中只处理常量，变量，函数，类的声明，所有实现都在源文件中。头文件不编译，每个cpp文件会被编译成.obj文件
//			然后所有obj文件连接起来形成可执行程序
// @2 - .cpp文件
//		写头文件中已经声明的函数的具体代码，在开头必须#include一下要实现的头文件，以及其他要用到的头文件
//		是
//@3 - package
//		定义 - 一个package是由同名的.h和.cpp文件组成，但可以少任意一个，若只有.h文件，则package是接口/模板(template)的定义
//			只有.cpp的package可以是一个程序的入口
//		参考 - https://www.cnblogs.com/fenghuan/p/4794514.html
//
//

void test04_Struct::clsMain()
{
	// 函数或结构中访问其成员，推荐使用(箭头，表示指向，指针) -> 

	structTe struTe = { 0,0 }; // 使用前要初始化
	structTe* struTe2 = new structTe; // new开辟堆内存
	struTe2->a = 8;
	struTe2->b = 8;
	structTe stu0;
	this->structTeOfFunction(struTe);
	stu0 = functionRequestStruct();
	std::cout << stu0.b;
	this->structTePointOfFun(struTe2);

	// 结构体指针的初始化
	structByExternalClass* sbec = new structByExternalClass;
	sbec->sa = 2;
	sbec->sb = 2;
	this->useExternalClassStruct(sbec);


}


// 结构体做函数参数 --- 按值传递
void test04_Struct::structTeOfFunction(structTe x)
{
	std::cout << "structTeOfFunction" << "\n";
	// 定义一个结构体变量
	structTe stTe = { 1,2 }; // 使用前要初始化
	std::cout << stTe.a;
}

// 结构体做函数返回值
// 那个类::类里的结构体 哪个类::类中方法
test04_Struct::structTe test04_Struct::functionRequestStruct()
{
	test04_Struct::structTe se;
	se.a = 9;
	se.b = 9;
	return se;
}


// 结构体指针做函数参数
void test04_Struct::structTePointOfFun(structTe* x)
{
	std::cout << "structTePointOfFun" << "\n";
	std::cout << x->b << "\n";
	std::cout << &x << "\n";
}


// 使用类外的结构体，类外结构体指针做函数参数
void test04_Struct::useExternalClassStruct(structByExternalClass* sbP)
{
	// 初始化结构体
	structByExternalClass sbc = { 1,1 };
	std::cout << "类外部的结构体：" << sbc.sb << "\n";
	std::cout << "结构体参数：" << sbP->sa << "\n";
}
