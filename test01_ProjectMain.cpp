

// 引入库头文件

#include <fstream>

//#include <iostream.h> // 头文件有扩展名时可以不用namespace

#include <iostream> // 预处理器编译指令，include
					// C++的头文件可以是.h的或无扩展名，C语言的是.h的





// 引入各类的头文件

// 自定义头文件在main方法中引入
// .h头文件会报错，报无法解析的外部符号，	但cpp的可以
// vs自动生成的类可以导入.h文件
//#include"test11_binary_tree.h" // 同时引入.cpp和.h会引起重复编译的错误

#include"test02_MinExample.h"
#include"test03_BaseDataType.h"
#include"test04_Struct.h"
#include"test05_PointTo.h"
#include "test06_Oop.h"
#include "test10_ADTAndAlgorithms.h"
#include "test11_ADTOfLinearList.h"
#include "test12_ADTOfStack.h"
#include "test13_ADTOfQueue.h"
#include "test14_ADTOfTree.h"
#include "test15_ADTOfGraph.h"
#include "test16_AlgOfSearch.h"
#include "test17_AlgOfSort.h"
#include "test20_StlAbstract.h"




// 说明
// 项目结构
// @1，一个主方法，其余按知识点分为若干个类，
// @2，数据的默认作用域为本类，如结构体等
// @3，每个类中有一个claMain（）方法作为调用本类的入口，类名为test0x_大驼峰的形式
// @4，特殊类会有相似的类名
// @5，外部文件中的函数的使用
//		#1 - 定义外部函数实现的cpp文件
//		#2 - 在主类中先声明，再使用

// winC++说明文档
// 来源
// https://docs.microsoft.com/zh-cn/cpp/cpp/ptr32-ptr64?view=vs-2019


using namespace std; // using编译指令，命名空间，保证命名不重复，放在函数内表示只在本函数内使用



int main() // 函数头
// 一个类中只能有一个main函数
{
	//char sa = NULL;
	//scanf("%sa",sa); // C++ 可以使用所有C的标准输入输出函数，好像有错啊
	//printf("%sa", sa);
	printf("这是主类的 \n");
	cout << "入口文件的";
	cout << "主方法" << "\n"; // endl可用“\n”代替
	// printf是C中的标准输入输出函数，而cout是iostream类中的方法，是对运算符的重载

	std::cout << "<< " << endl; // endl表示光标重起一行，作用类似换行符\n
	// << 是对用算符的重载，编译器自动根据上下文判断符号的实际含义，C语言中 &和*也是重载，表示位运算和逻辑运算



	test02_MinExample t02me;
	//t02me.claMain();

	test03_BaseDataType t03me;
	//t03me.claMain();

	test04_Struct t04me;
	//t04me.clsMain();

	// new 开辟堆内存
	test05_PointTo* te05me = new test05_PointTo();
	//te05me->classMain();

	test06_Oop* te06me = new test06_Oop();
	//te06me->classMain();

	test10_ADTAndAlgorithms* te10me = new test10_ADTAndAlgorithms();
	//te10me->classMain();

	// 统一类实例的初始化
	test11_ADTOfLinearList te11me;
	test12_ADTOfStack* te12me = new test12_ADTOfStack();
	test13_ADTOfQueue te13me;
	test14_ADTOfTree te14me;
	test15_ADTOfGraph te15me;
	test16_AlgOfSearch te16me;
	test17_AlgOfSort te17me;




	// 使用switch-case实现选择跳转

	int choice;

	//等待用户选择菜单项
	while (1)
	{
		printf("\n输入类编号: ");
		std::cin >> choice;
		//根据用户不同的选择，调用相应的函数               
		switch (choice)
		{
		case 2:
			t02me.claMain();
			break;
		case 3:
			t03me.claMain();
			break;
		case 4:
			t04me.clsMain();
			break;
		case 5:
			te05me->classMain();
			break;
		case 6:
			te06me->classMain();
			break;
		case 10:
			te10me->classMain();
			break;
		case 11:
			te11me.classMain();
			break;
		case 12:
			te12me->classMain();
			break;
		case 13:
			te13me.classMain();
			break;
		case 14:
			te14me.classMain();
			break;
		case 15:
			te15me.classMain();
			break;
		case 16:
			te16me.classMain();
			break;
		case 17:
			te17me.classMain();
			break;
		default:
			printf("\n无效的输入!\n");
		}
	}

	return 0;
}
