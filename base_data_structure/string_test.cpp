#include<iostream>
#include<string>
//#include<string.h>

void StringTest() {
	std::string str;
	//std::string str1 = "hello";
	std::cout << "please input a string:";
	std::cin >> str;

	// get size of string.
	std::cout << "sizeof of str1 is: " << sizeof(str) << std::endl;
	std::cout << "size of str1 is: " << str.size() << std::endl;
	std::cout << "length of str1 is: " << str.length() << std::endl;
	std::cout << "strlen of str1 is: " << strlen(str.c_str()) << std::endl;
	std::cout << "size of str is: " << sizeof(str) << std::endl;

	//case swtching to letter
	for (int i = 0; i < str.size(); i++) {
		//std::cout << str[i] << std::endl;
		if ((char)str[i] >= 'a' && (char)str[i] <= 'z') {
			// std::cout << "lower letter: " << str[i] << std::endl;
			str[i] = toupper((char)str[i]);
		}
	    else if ((char)str[i] >= 'A' && (char)str[i] <= 'Z') {
			//std::cout << "upper letter: " << str[i] << std::endl;
			str[i] = tolower((char)str[i]);
		}
		std::cout << str[i] << std::endl;
	}
	std::cout << str << std::endl;
	//std::cout << "function strupr and strlwr: " << std::endl;
	//std::cout << strupr(const_cast<char*>(str.c_str())) << std::endl;
	//std::cout << strlwr(const_cast<char*>(str.c_str())) << std::endl;


}