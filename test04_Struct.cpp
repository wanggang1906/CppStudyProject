#include "test04_Struct.h"


#include<iostream>



void test04_Struct::clsMain()
{
	// ������ṹ�з������Ա���Ƽ�ʹ�� -> 

	structTe struTe = { 0,0 }; // ʹ��ǰҪ��ʼ��
	structTe *struTe2 = new structTe; // new���ٶ��ڴ�
	struTe2->a = 8;
	struTe2->b = 8;
	structTe stu0;
	this->structTeOfFunction(struTe);
	stu0 = functionRequestStruct();
	std::cout << stu0.b;
	this->structTePointOfFun(struTe2);
}

/*

// ������ǰ�� --- ��������ʵ����ͬһ���ļ���������������д��
// 

//class StructClass;

class StructClass
{

private:
	// ���������ṹ����������
	typedef struct info {
		std::string name;
		int age;
	};

	typedef struct infoName {
		int af;
	};


	// �ṹ�嶨��
	typedef struct {
		int data[2];
		int length;
	}SqList;


	// �ṹ�����Ҫ��ʼ��


public:
	void structureTestMain()
	{
		this->getStructureOfClass();
	}


	// �ṹ��
	// .�� -> ��������ṹ����ʱ��. ָ��ָ��ʱ�� ->
	int structureTypeTest()
	{
		struct FishOil
		{
			std::string name; // �ַ�������
			int age;
			char sex;
		};
		return 0;
	}


	// ʹ�����еĽṹ��

	void getStructureOfClass()
	{
		struct info inf001 = { "",0 };
		inf001.name = "inf01";
		inf001.age = 10;
		std::cout << "�ṹ�����ĵ�ַ��" << &inf001 << "\n";

		//Inm02* inm002 = NULL;
		//inm002->af = 20;
		//std::cout << inm002->af << "\n";


	}

	// ����������
	void jiaoHuan()
	{
		int s = 1;
		int d = 2;
		//swap(&s, &d);
	}

	void swap(int* x, int* y)
	{
		*x ^= *y;
		*y ^= *x; // ������
		*x ^= *y;
	}




};

*/



// �����������ж���ṹ��ָ�룬������





// �ṹ������������ --- ��ֵ����
void test04_Struct::structTeOfFunction(structTe x) {
	std::cout << "structTeOfFunction" << "\n";
	// ����һ���ṹ�����
	structTe stTe = {1,2}; // ʹ��ǰҪ��ʼ��
	std::cout << stTe.a;
}

// �ṹ������������ֵ
test04_Struct::structTe test04_Struct::functionRequestStruct()
{
	test04_Struct::structTe se;
	se.a = 9;
	se.b = 9;
	return se;
}


// �ṹ��ָ������������
void test04_Struct::structTePointOfFun(structTe * x) {
	std::cout << "structTePointOfFun" << "\n";
	std::cout << x->b;
	std::cout << &x;
}


