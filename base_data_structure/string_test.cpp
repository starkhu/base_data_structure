/***********************************************************************
*C++中提供string类来代替C语言中以'\0'结尾的char型数组
*string类型必须包含头文件string
*程序员不需关心内存的分配，也无需处理'\0'的结束字符，由系统自动处理
***********************************************************************
*字符串中子串的数量：
*字符串中元素不重复，长度为n， 相当于从(n+1)个位置中选择两个间隔起来作为子串
*因此，子串数量为组合C(n,2)+1,(加一是因为加上空字符串) 
***********************************************************************/

#include<iostream>
#include<string>
//#include<string.h>

// get size of string.
void StringSize(const std::string& str) {
	std::cout << "sizeof of str is: " << sizeof(str) << std::endl;
	std::cout << "size of str is: " << str.size() << std::endl;
	std::cout << "length of str is: " << str.length() << std::endl;
	std::cout << "strlen of str is: " << strlen(str.c_str()) << std::endl;
}

void CaseSwitchTest(std::string str) {
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

void AssignmentTest(const std::string& str) {
	std::string s2 = " Stark";
	std::string s3 = s2;
	std::string s4(10, 'z');
	std::string s5 = str + s2;
	std::cout << "s4 is : " << s4 << std::endl;
	std::cout << "s5 is : " << s5 << std::endl;
}

void RegularOperationTest() {
	std::string s1 = "University of Science and Technology of China";

	//判断字符串是否为空
	int is_empty = 0;
	is_empty = s1.empty();
	std::cout << "s1 is empty? " << is_empty << std::endl;

	
	//擦除 erase(int pos, int len)
	std::string s2 = s1;
	s2.erase(0, 14);
	std::cout << "s2 is " << s2 << std::endl;

	//插入 insert(int pos, string s)
	s2.insert(0, "University of ");
	std::cout << "s2 is " << s2 << std::endl;

	//替代 replace(int start, int len, string s)
	//用s替代原字符串中的start开始，长度为len的数据
	s2.replace(0, 1, "uu");
	std::cout << "s2 is " << s2 << std::endl;

	//调换swap(string s2)
	std::string s3 = "Brave Heart";
	s2.swap(s3);
	std::cout << "s2 is " << s2 << std::endl;

	//提取子串 substr(int start, int len)
	std::string s4 = s2.substr(6, 5);
	std::cout << "s4 is " << s4 << std::endl;

	//查找
	//find(string s2, int index = 0)如果s2在s1中的位置大于等于index，则返回index。
	//     如果没有找到s2， 返回-1， 
	//index默认为0.
	//s2可以是字符串，也可以是C风格的字符串或者char字符
	std::string s5 = "Bravee";
	int f;
	f = s2.find(s5);
	std::cout << " f is " << f << std::endl;
	if (f < s2.length())
		std::cout << "found s5" << std::endl;
	else
		std::cout << "not found s5" << std::endl;

	//rfind功能与find类似， 它返回小于等于index的索引值
	// index默认为无穷大

	//find_first_of(string s2)返回 s1,s2都具有的第一个字符的索引
	//find_first_not_of(string s2)返回首个s1, s2不同时具有的字符的索引

	char s6 = s5[3];
	char s7 = s5.at(3);
	std::cout << "s6: " << s6 << "s7: " << s7 << std::endl;



}

void StringTest() {
	std::string str;
	std::cout << "please input a string:";
	std::cin >> str;

	StringSize(str);
	CaseSwitchTest(str);
	AssignmentTest(str);
	RegularOperationTest();
}