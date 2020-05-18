#include "test05_PointTo.h"
#include <iostream>




void test05_PointTo::classMain()
{
	std::cout << "test05_PointTo";
	//this->pointDef();
	//this->pointSize();

	//int b = 1;
	//int* a = &b;
	//std::cout<< factonOfPoint(a,b);

	this->operateMemory();
}


// 指针也是一种数据类型，指针也是一种变量，用来保存内存地址

// 指针的四个问题

// 指针的类型 --- 从语法上看，把指针声明里的指针名字(不含*的)去掉，剩下的部分是指针的类型
// 指针所指向的类型 --- 当你通过指针来访问指针所指向的内存区时，指针所指向的类型决定了编译器将把那片内存区里的内容当做什么来看待。
//					   从语法上看，你只须把指针声明语句中的指针名字和名字左边的指针声明符(一个)*去掉，剩下的就是指针所指向的类型
// 指针本身的值（指针的值） --- 指针本身存储的数值，这个值将被编译器当作一个地址，而不是一个一般的数值
// 指针所指向的内存区域的值 --- 指针所指向的内存区就是从指针的值所代表的那个内存地址开始，长度为sizeof(指针所指向的类型)的一片内存区

// 类的声明在头文件中，类的实现在cpp文件中，在main中要引入头文件
void test05_PointTo::pointDef() {
	printf("指针相关概念");
	// 来源： 
	// https://www.cnblogs.com/sumuncle/p/9773955.html
	// https://blog.csdn.net/weixin_39640298/article/details/84900326
	// https://www.cnblogs.com/aquester/p/11469872.html

	// 几种类型指针
	//int *ptr; // 指针的类型是int *	// 指针所指向的类型是int
	//char *ptr; // 指针的类型是char *	// 指针所指向的类型是char
	//int **ptr; // 指针的类型是int **	// 指针所指向的类型是int *
	//int(*ptr)[3]; // 指针的类型是int (*)[3]		// 指针所指向的类型是int()[3]	// ()可解决优先级问题
	//int *(*ptr)[4]; // 指针的类型是int *(*)[4]	// 指针所指向的类型是int *()[4]

	// 几种特殊的指针
	int num = 97;
	float score = 10.00F;
	int arr[3] = { 1,2,3 };

	int* p_num = &num;
	int* p_arr1 = arr;		// p_arr1意思是指向数组第一个元素的指针
	float* p_score = &score;
	int(*p_arr)[3] = &arr;
	//int (*fp_add)(int, int) = add;  // p_add是指向函数add的函数指针
	const char* p_msg = "Hello world"; // p_msg是指向字符数组的指针

	std::cout << "sizeof是表示变量的大小：" << sizeof(num) << "\n";

	// 物理地址
	int wu = 12;
	std::cout << "物理地址是：(&操作符)" << &wu << "\n";

	// *和&的区别
	// * 指针声明符
	// & 取地址符，结果为一个指针
	int* li = &wu;
	std::cout << "*li的值(即是*li所指内存空间所存的东西)：" << *li << " li的地址：" << li << " &wu的地址：" << &wu << "\n";
	std::cout << "*li的大小：" << sizeof(li) << "\n";
	std::cout << "*是取地址对应的值，&是取地址：" << *&wu << "\n";

	// 引用地址的内容 - 地址前加0x，表示是16进制，不能随意访问不知道的内存空间
	//std::cout << "0019FF3C = " << *(int*)0x0019FF3C << "\n";

}

// 指针对内存的操作
void test05_PointTo::operateMemory()
{
	// *p 实现对内存的操作
	// 在指针声明时，符号 * 表示所声明的变量为指针。
	// 在指针使用时，符号* 表示 操作指针所指向内存空间中的值
	//	* p 相当于通过地址（p变量的值）找到一块内存，然后对内存进行操作。
	//	* p 放在等号的左边( *p = ) 相当于是给内存赋值，即把值赋给一个内存空间，也就是写内存
	//	* p 放到等号的右边( = *p ) 相当于从内存中获取值然后赋值给其它变量，也就是读内存
	int x = 10;
	int* p = &x;
	int* a = p;

	std::cout << *p << "\n";
	std::cout << typeid(*p).name() << "\n"; // 查看某一变量的类型
	std::cout << typeid(p).name() << "\n"; // * __ptr64
	std::cout << typeid(&x).name() << "\n"; // * __ptr64 // __ptr32表示32位系统上的本机指针，而 __ptr64表示64位系统上的本机指针。
}



int test05_PointTo::add(int a, int b) {
	return 0;
}

// 点击运行后还是上一次的代码，本次的没有编译 --- 重新编译(重新生成)即可
void test05_PointTo::pointSize() {
	printf("---指针也是一种数据类型---  \n"); // +1是否可以输出不同类型数据 --- 不可以，printf只能使用格式化字符串和数据标识符

	// 指针也是一种数据类型，指针也是一种变量，用来保存内存地址


	//char *charP = ;
	int* p;
	int s = 10;
	std::cout << "指针的大小：" << sizeof(p) << " - " << s; // 输出流可以输出不同类型的数据

	int* ps[3];

	std::cout << "\nps的地址是: %d   " << &ps << "\n"; // &取地址符，%d十进制，%p十六进制

}


void test05_PointTo::pointType() {
	// 指针的类型
	// 从语法的角度看，你只要把指针声明语句里的指针名字去掉，剩下的部分就是这个指针的类型
	int* p; // 类型是int*
	int** pt; // 类型是 int**
	int*** ptr; // 类型是 int***

	int(*pta)[3]; // 类型是int(*)[3]
	int* (*ptc)[4]; // 类型是int*(*)[4]     //  int** ptc[4]; // 同？？？

	// 指针所指向的类型
	// 从语法上看，你只须把指针声明语句中的指针名字和名字左边的指针声明符*去掉(只去掉一个)，剩下的就是指针所指向的类型

}

void test05_PointTo::pointArray() {
	// 指针和数组
	// 指针数组-存储指针的数组。首先它是一个数组，数组的元素都是指针，数组占多少个字节由数组本身决定。
	// 数组指针-指向数组的指针。首先它是一个指针，它指向一个数组。在32 位系统下永远是占4 个字节，至于它指向的数组占多少字节，不知道。
	printf("指针和数组");
	int* ary[12] = {}; // []的优先级比*高，则首先是一个ary[12]的数组，int*修饰这个数组，即表明数组中每个元素都是int*类型的。即为存储指针的数组
	int(*aryp)[10] = NULL; // 【本质上是int(*)[10] aryp】()的优先级高于[]，*和aryp构成指针的定义，所以它首先是一个指针，int修饰数组，数组没有名字，是匿名数组。即aryp是一个指针，指向有10个int型元素的数组

	int b = 12;
	int* a[5] = { &b,&b,&b,&b };
	int(*ap)[5] = NULL;
	std::cout << "存储的指针值为：" << a[0] << "\n";
	std::cout << "指向的数组首地址为：" << ap << "\n";
	std::cout << "*ap的值：" << *ap << "\n"; // *ap是数组的首地址？？？

	b = 3;
	int* apam = &b;
	std::string re;
	re = this->factonOfPoint(apam, b);
	std::cout << re << "\n";

}

// 带指针的函数
std::string test05_PointTo::factonOfPoint(int* a, int b) {
	// 两种传参的区别
	std::cout << "传入的值是：" << a << "和" << b << "\n";

	return "ok";
}


void test05_PointTo::pointTestMain() {
	std::cout << "指针主方法---" << "\n";


	int* a = NULL;
	int* b = NULL;
	int d = 13;
	int e = 14;
	a = &d; // 取址运算符，结果是一个指针
	b = &e;
	this->pointDef();
	this->pointSize();
	this->pointTest01(a, b); // this指针调用本类方法
	this->pointArray();

}

void test05_PointTo::pointTest01(int* p, int* a) {
	// 两数相加
	int* c;
	int* b;
	long d;
	c = p + 1;
	b = a + 1; // 使地址+1

	d = b - c; // 两个指针不可以相加，相加后指向的地方不知。但可以相减，值为两指针之间距离多少个元素，不是字节
	std::cout << c << b << "\n";
	std::cout << "指针之间的距离为：" << d << "\n";
}

// 来源
// https://blog.csdn.net/qq_25652139/article/details/80821857
void test05_PointTo::pointTest02() {
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1); // 
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
}


// 保存插件
