#pragma once
class test04_Struct
{

	// ���ж���ṹ�壬������Ϊ����
	// ���ⶨ��ṹ�壬�����������
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

