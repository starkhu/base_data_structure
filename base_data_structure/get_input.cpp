/***********************************************************************
*cin和getline()连用时会产生冲突
*原因是cin输入的回车键会被getline检测到
*解决方案是在getline之前加上cin.ignore()函数
***********************************************************************/
#include<iostream>
#include<string>

void GetInput() {
	//get int or char
	int a, b;
	std::cout << "input a and b: ";
	std::cin >> a >> b;
	std::cout << "a+b=" << a + b << std::endl;

	
	// get a line 
	std::string str2;
	std::cout << "input a string: " << std::endl;
	std::cin.ignore();
	getline(std::cin, str2);
	std::cout << str2 << std::endl;


	char * num = new char[10];
	std::cout << "size of num is: " << strlen(num) << std::endl;
	memset(num, '0', 10);
	num[9] = '\0';
	std::cout << "size of num is: " << strlen(num) << std::endl;

	//
	int c = '0';
	std::cout << "c is: " << c << std::endl;
}