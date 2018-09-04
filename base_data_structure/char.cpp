#include<iostream>
#pragma warning(disable:4996)


void CharAndPointer() {
	char str1[] = "hello world";
	char str2[] = "hello world";
	char* str3 = "hello world";
	char* str4 = "hello world";
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	std::cout << str4 << std::endl;
	if (str1 == str2)
		std::cout << "str1 and str2 are same" << std::endl;
	else
		std::cout << "str1 and str2 are different" << std::endl;
	if (str3 == str4)
		std::cout << "str3 and str4 are same" << std::endl;
	else
		std::cout << "str3 and str4 are different" << std::endl;
}

void CharAlign() {
	char* str[] = { "aaa", "aaaaa", "a" };
	//�ַ��������ȡ��ʽ�����˶���ԭ��ռ�ÿռ��ٵ���ռ�ÿռ��Ŀ���
	std::cout << "number of elements in the array: " 
		<< sizeof(str) / sizeof(str[0]) << std::endl;

	char str1[3] = { 'a', 's' };
	//�����ֵ����С�����鳤��,��ֻ����Щ�ַ����������ǰ���Ԫ��
	//����Ԫ���Զ���Ϊ���ַ�(��'/0')
	for (int i = 0; i < 3; i++)
		std::cout << str1[i] << std::endl;
	str1[2] = 'h';
	for (int i = 0; i < 3; i++)
		std::cout << str1[i] << std::endl;
}

//�ָ��ַ��� char* strtok(char *s, const char *delim)
void CutString() {
	char ch[] = "University of Science and Technology of China";
	char *token_ptr = strtok(ch, " ");
	while (token_ptr != NULL)
	{
		std::cout << token_ptr << std::endl;
		token_ptr = strtok(NULL, " ");
	}
}

void CharTest() {
	CharAlign();
	CharAndPointer();
	CutString();
}