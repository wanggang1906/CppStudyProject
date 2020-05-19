#include "test04_Struct.h"


#include<iostream>

// 结构体


void test04_Struct::clsMain()
{
	// 函数或结构中访问其成员，推荐使用 -> 

	structTe struTe = { 0,0 }; // 使用前要初始化
	structTe *struTe2 = new structTe; // new开辟堆内存
	struTe2->a = 8;
	struTe2->b = 8;
	structTe stu0;
	this->structTeOfFunction(struTe);
	stu0 = functionRequestStruct();
	std::cout << stu0.b;
	this->structTePointOfFun(struTe2);
}

/*

// 类声明前置 --- 类声明和实现在同一个文件的是内联方法的写法
// 

//class StructClass;

class StructClass
{

private:
	// 定义两个结构体数据类型
	typedef struct info {
		std::string name;
		int age;
	};

	typedef struct infoName {
		int af;
	};


	// 结构体定义
	typedef struct {
		int data[2];
		int length;
	}SqList;


	// 结构体必须要初始化


public:
	void structureTestMain()
	{
		this->getStructureOfClass();
	}


	// 结构体
	// .和 -> 的区别，如结构变量时用. 指针指向时用 ->
	int structureTypeTest()
	{
		struct FishOil
		{
			std::string name; // 字符串对象
			int age;
			char sex;
		};
		return 0;
	}


	// 使用类中的结构体

	void getStructureOfClass()
	{
		struct info inf001 = { "",0 };
		inf001.name = "inf01";
		inf001.age = 10;
		std::cout << "结构体对象的地址：" << &inf001 << "\n";

		//Inm02* inm002 = NULL;
		//inm002->af = 20;
		//std::cout << inm002->af << "\n";


	}

	// 交换两个数
	void jiaoHuan()
	{
		int s = 1;
		int d = 2;
		//swap(&s, &d);
	}

	void swap(int* x, int* y)
	{
		*x ^= *y;
		*y ^= *x; // 异或操作
		*x ^= *y;
	}




};

*/



// 单独测试类中定义结构体指针，并引用





// 结构体做函数参数 --- 按值传递
void test04_Struct::structTeOfFunction(structTe x) {
	std::cout << "structTeOfFunction" << "\n";
	// 定义一个结构体变量
	structTe stTe = {1,2}; // 使用前要初始化
	std::cout << stTe.a;
}

// 结构体做函数返回值
test04_Struct::structTe test04_Struct::functionRequestStruct()
{
	test04_Struct::structTe se;
	se.a = 9;
	se.b = 9;
	return se;
}


// 结构体指针做函数参数
void test04_Struct::structTePointOfFun(structTe * x) {
	std::cout << "structTePointOfFun" << "\n";
	std::cout << x->b;
	std::cout << &x;
}


