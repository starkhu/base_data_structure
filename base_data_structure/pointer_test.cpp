#include<iostream>

void PointerTest() {
	char* a0 = new char[2];
	char* b0 = new char[2];
	//memset(a0, '\0', 1);
	//memset(b0, '\0', 1);
	memset(a0, 'a', 1);
	memset(b0, 'b', 1);
	a0[1] = '\0';
	b0[1] = '\0';
	std::cout << *a0 << std::endl;
	std::cout << *b0 << std::endl;
	char* p0 = a0;
	delete[] a0;
	//p0 = nullptr;
	p0 = b0;
	std::cout << *p0 << std::endl;
}