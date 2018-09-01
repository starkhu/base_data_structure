#include<iostream>
#include<iomanip>

void AssignmentTest() {
	std::cout << "******Assignment Test******" << std::endl;
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
	std::cout << "******Assignment Test******" << std::endl;
}

void PointerAndArray() {
	std::cout << "******Pointer&Array Test 0D******" << std::endl;
	int *p0 = new int;
	*p0 = 1;
	std::cout << "*p0 is: " << *p0 << std::endl;

	// 1D Array
	std::cout << "******Pointer&Array Test 1D******" << std::endl;
	int *p1 = new int[3];
	for (int i = 0; i < 3; i++) {
		p1[i] = 2 * i + 1;
	}
	std::cout << "p1 is: " << p1 << std::endl;
	std::cout << "*p1 is: " << *p1 << std::endl;
	std::cout << "*(p1+1) is: " << *(p1+1) << std::endl;

	//2D Array
	std::cout << "******Pointer&Array Test 2D******" << std::endl;
	int (*p2)[4] = new int[3][4];
	// std::cout << setw(6);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			p2[i][j] = 4 * i + j;
			std::cout << std::setw(6) <<  p2[i][j] << " ";
		}
		std::cout << std::endl;	
	}
	std::cout << "*p2 is:" << *p2 << std::endl;
	std::cout << "**p2 is:" << **p2 << std::endl;
	std::cout << "*£¨* (p2 + 1£©+ 2£©is:" << *(*(p2 + 1)+ 2) << std::endl;

}

void PointerTest() {
	AssignmentTest();
	PointerAndArray();
}