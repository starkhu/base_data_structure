#include<iostream>

void LeftConst() {
	int a0 = 55;
	int a1 = 66;
	const int b = 10;
	//���constλ��*��࣬��ʾָ����ָ�����ǳ���������ͨ���������޸ĸ�����
	//ָ�뱾���Ǳ���������ָ���������ڴ浥Ԫ
	int const *p0 = &a0;
	int *p1 = &a1;
	std::cout << "*p0  is " << *p0 << std::endl;
	std::cout << "*p1  is " << *p1 << std::endl;
	// *p0 = 56; //��������
	*p1 = 56;
	std::cout << "*p1  is " << *p1 << std::endl;
	std::cout << "a1  is " << a1 << std::endl;

	p0 = &a1;
	std::cout << "*p0  is " << *p0 << std::endl;
}

void RightConst() {
	int a0 = 5;
	int a1 = 6;
	const int b = 10;
	//���constλ��*�Ҳ࣬��ʾָ�뱾���ǳ���������ָ�������ڴ��ַ
	//ָ����ָ�����ݿ���ͨ���������޸�
	int* const p0 = &a0;
	std::cout << "*p0  is " << *p0 << std::endl;
	*p0 = 15;
	std::cout << "*p0  is " << *p0 << std::endl;
	std::cout << " a0  is " << a0 << std::endl;
	//p = &a1; //��������
}

void ConstTest() {
	LeftConst();
	RightConst();
}



