#include "test20_StlAbstract.h"
#include <iostream>
#include <string>

#include <vector>
#include<algorithm> // sort
#include<functional>

#include<cstdlib> // abort()
#include<cstdio> // snprintf()
#include<ctime>
#include<stdexcept>

#include<array>


// stl引入

// 6组件
// 8容器
// 若干算法

// 参考资料
// https://blog.csdn.net/qq_42322103/article/details/99685797
// http://c.biancheng.net/stl/


void test20_StlAbstract::classMain()
{
	std::cout << "test20_StlAbstract" << "\n";



}






// 教程网址
// http://c.biancheng.net/stl/

// STL是容器的集合，也是组件的集合。
// 容器包括list, vector向量, set, map 等
// 组件包括容器，迭代器，算法，仿函数
// 容器 - 存储并管理某类对象的集合。容器分为序列容器和关联容器
// 迭代器 - 在一个对象集群上进行遍历。迭代器分两类，双向迭代器和随机存取迭代器
// 算法 - 算法用于处理集群内的元素，可实现搜寻，排序，修改，使用
// 仿函数 - 具有泛型编程强大的威力，是纯粹抽象的例证


int test20_StlAbstract::tVector()
{
	const int NUM = 5;
	// 向量
	std::vector <std::string>names(NUM);    //定义矢量对象
	std::vector <int> sexs(NUM);    //同上
	std::cout << "Please Do Exactly As Told You Will enter \n" << NUM << " Personal Name and Their Sex.\n";
	int i = 0;
	for (i = 0; i < NUM; i++)    //输入信息
	{
		std::cout << "Enter title # " << i + 1 << ": ";
		std::getline(std::cin, names[i]); //获取输入信息
		std::cout << "Enter sex (0/1) #";
		std::cin >> sexs[i];    //获取输入信息
		std::cin.get();    //等待
	}
	std::cout << "Thank you. You entered the following:    \n" << "name/sex" << std::endl;
	for (i = 0; i < NUM; i++)    //输出信息
	{
		std::cout << names[i] << "\t" << sexs[i] << std::endl;
	}
	return 0;
}


// stl综合使用
int test20_StlAbstract::stlUse()
{
	int ia[6] = {};
	std::vector<int, std::allocator<int>> vi(ia, ia + 6);
	std::cout << count_if(vi.begin(), vi.end(),
		std::not1(std::bind2nd(std::less<int>(), 40)));
	return 0;
}

// 向量测试
void test20_StlAbstract::testVector(long& value)
{
	std::cout << "向量";
	std::vector<std::string> c;
	char buf[10];
	clock_t timeStart = clock(); // 计时函数

	for (long i = 0; i < value; ++i)
	{
		try {
			snprintf(buf, 10, "%d", rand());
			c.push_back(std::string(buf));
		}
		catch (std::exception& p) {
			std::cout << i << p.what() << std::endl;
			abort();
		}
	}
	// 常用的方法
	std::cout << (clock() - timeStart) << std::endl;
	std::cout << c.size() << std::endl;
	std::cout << c.front() << std::endl;
	std::cout << c.back() << std::endl;
	std::cout << c.data() << std::endl;
	std::cout << c.capacity() << std::endl;
}


// 
void test20_StlAbstract::testArray()
{
#define ASIZE 10;
	std::cout << "";
	std::array<long, 10> c;
	clock_t timeStart = clock();
	for (long i = 0; i < 10; ++i) {
		c[i] = rand();
	}

	//
	std::cout << (clock() - timeStart) << std::endl;
	std::cout << c.size() << std::endl;
	std::cout << c.front() << std::endl;
	std::cout << c.back() << std::endl;
	std::cout << c.data() << std::endl;

	long target;
	timeStart = clock();
	//qsort(c.data(), 10, sizeof(long), compareLongs);
	//long* pItem = (long*)bsearch(&target, (c.data(), 10, sizeof(long));
	//cout << (clock() - timeStart) << endl;
	//if (pItem != NULL)
	//	cout << *pItem << endl;
	//else
	//	cout << "not found" << endl;
}
