/***********************************************************************
*C++���ṩstring��������C��������'\0'��β��char������
*string���ͱ������ͷ�ļ�string
*����Ա��������ڴ�ķ��䣬Ҳ���账��'\0'�Ľ����ַ�����ϵͳ�Զ�����
***********************************************************************
*�ַ������Ӵ���������
*�ַ�����Ԫ�ز��ظ�������Ϊn�� �൱�ڴ�(n+1)��λ����ѡ���������������Ϊ�Ӵ�
*��ˣ��Ӵ�����Ϊ���C(n,2)+1,(��һ����Ϊ���Ͽ��ַ���) 
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

	//�ж��ַ����Ƿ�Ϊ��
	int is_empty = 0;
	is_empty = s1.empty();
	std::cout << "s1 is empty? " << is_empty << std::endl;

	
	//���� erase(int pos, int len)
	std::string s2 = s1;
	s2.erase(0, 14);
	std::cout << "s2 is " << s2 << std::endl;

	//���� insert(int pos, string s)
	s2.insert(0, "University of ");
	std::cout << "s2 is " << s2 << std::endl;

	//��� replace(int start, int len, string s)
	//��s���ԭ�ַ����е�start��ʼ������Ϊlen������
	s2.replace(0, 1, "uu");
	std::cout << "s2 is " << s2 << std::endl;

	//����swap(string s2)
	std::string s3 = "Brave Heart";
	s2.swap(s3);
	std::cout << "s2 is " << s2 << std::endl;

	//��ȡ�Ӵ� substr(int start, int len)
	std::string s4 = s2.substr(6, 5);
	std::cout << "s4 is " << s4 << std::endl;

	//����
	//find(string s2, int index = 0)���s2��s1�е�λ�ô��ڵ���index���򷵻�index��
	//     ���û���ҵ�s2�� ����-1�� 
	//indexĬ��Ϊ0.
	//s2�������ַ�����Ҳ������C�����ַ�������char�ַ�
	std::string s5 = "Bravee";
	int f;
	f = s2.find(s5);
	std::cout << " f is " << f << std::endl;
	if (f < s2.length())
		std::cout << "found s5" << std::endl;
	else
		std::cout << "not found s5" << std::endl;

	//rfind������find���ƣ� ������С�ڵ���index������ֵ
	// indexĬ��Ϊ�����

	//find_first_of(string s2)���� s1,s2�����еĵ�һ���ַ�������
	//find_first_not_of(string s2)�����׸�s1, s2��ͬʱ���е��ַ�������

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