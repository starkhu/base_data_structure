#include<iostream>
#include<string>

void GetInput() {
	// get int or char
	int a, b;
	std::cout << "input a and b: ";
	std::cin >> a >> b;
	std::cout << "a+b=" << a + b << std::endl;

	//get a string
	/*char a[10];
	std::cout << "input a string: ";
	std::cin >> a;
	std::cout << "string is: " << a << std::endl;*/
	//std::cout << "size of a is: " << a.size() << std::endl;

	//get a char
	char ch;
	std::cout << "input a char: " << std::endl;
	//ch = std::cin.get(); // cin.get(ch)
	std::cin.get(ch);
	std::cout << "char is: " << ch << std::endl;

	// Receive a string of the specified length. incluing blank tab.
	char str1[10];
	std::cout << "input a string which length is 5: ";
	std::cin.get(str1, 5);
	std::cout << "string is: " << str1 << std::endl;

	// get a line
	char m[20];
	std::cout << "input a string which length is 5: " << std::endl;
	std::cin.getline(m, 5);
	std::cout << m << std::endl;

	// get a line 
	std::string str2;
	getline(std::cin, str2);
	std::cout << str2 << std::endl;

}