

// �����ͷ�ļ�


#include <fstream>

//#include <iostream.h> // ͷ�ļ�����չ��ʱ���Բ���namespace

#include <iostream> // Ԥ����������ָ�include
					// C++��ͷ�ļ�������.h�Ļ�����չ����C���Ե���.h��





// ������ͷ�ļ�

// �Զ���ͷ�ļ���main����������
// .hͷ�ļ��ᱨ�����޷��������ⲿ���ţ�	��cpp�Ŀ���
//#include"test11_binary_tree.h" // ͬʱ����.cpp��.h�������ظ�����Ĵ���

#include"test02_MinExample.h"
#include"test03_BaseDataType.h"
#include"test04_Struct.h"
#include"test05_PointTo.h"





using namespace std; // using����ָ������ռ䣬��֤�������ظ������ں����ڱ�ʾֻ�ڱ�������ʹ��



int main() // ����ͷ
// һ������ֻ����һ��main����
{
	//char sa = NULL;
	//scanf("%sa",sa); // C++ ����ʹ������C�ı�׼������������������д�
	//printf("%sa", sa);
	printf("��������� \n");
	cout << "����ļ���";
	cout << "������" << "\n"; // endl���á�\n������
	// printf��C�еı�׼���������������cout��iostream���еķ������Ƕ������������

	std::cout << "<< " << endl; // endl��ʾ�������һ�У��������ƻ��з�\n
	// << �Ƕ�����������أ��������Զ������������жϷ��ŵ�ʵ�ʺ��壬C������ &��*Ҳ�����أ���ʾλ������߼�����


	test02_MinExample t02me;
	//t02me.claMain();

	test03_BaseDataType t03me;
	//t03me.claMain();

	test04_Struct t04me;
	//t04me.clsMain();

	// new ���ٶ��ڴ�
	test05_PointTo *te05me = new test05_PointTo();
	te05me->claMain();

















	return 0;
}
