#pragma once
class test04_Struct
{

	// 类中定义结构体，作用域为本类
	// 类外定义结构体，作用域会扩大
	typedef struct structTe {
		int a;
		int b;
	};


public:
	void clsMain();
	void structTeOfFunction(structTe x);
	void structTePointOfFun(structTe * x);
	structTe functionRequestStruct();



};

