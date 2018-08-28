#include<iostream>

void LeftConst() {
	int a0 = 55;
	int a1 = 66;
	const int b = 10;
	//如果const位于*左侧，表示指针所指数据是常量，不能通过解引用修改该数据
	//指针本身是变量，可以指向其他的内存单元
	int const *p0 = &a0;
	int *p1 = &a1;
	std::cout << "*p0  is " << *p0 << std::endl;
	std::cout << "*p1  is " << *p1 << std::endl;
	// *p0 = 56; //不被允许
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
	//如果const位于*右侧，表示指针本身是常量，不能指向其他内存地址
	//指针所指的数据可以通过解引用修改
	int* const p0 = &a0;
	std::cout << "*p0  is " << *p0 << std::endl;
	*p0 = 15;
	std::cout << "*p0  is " << *p0 << std::endl;
	std::cout << " a0  is " << a0 << std::endl;
	//p = &a1; //不被允许
}

void ConstTest() {
	LeftConst();
	RightConst();
}



