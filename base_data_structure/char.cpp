/*********************************************************************************
*scanf()��gets()������ͻ����
*�������
*����1����һ�� while(getchar()!='\n');  
        ���������������Ļس����з���Ȼ����gets()�������ˡ�
*����2���������ȷ�ؾ�֪����������������ô���س����з����Ǿ�ֱ�Ӷ���ɣ�
        scanf("\n"); ����getchar()����һ���ַ���Ȼ�� ����gets()Ҳ�Ͳ�����������
*********************************************************************************/
#include<iostream>
#include<string.h>
#pragma warning(disable:4996)


void SolveInputConflict() {
	char a0[20], a1[20];
	printf("please enter a0 and a1: ");
	scanf("%s %s", a0, a1);
	printf("a0 is %s, a1 is %s\n", a0, a1);
	getchar();//�������ջ��з�
	printf("please enter str: ");
	char str[100];
	gets_s(str);
	printf("str is %s\n", str);
}

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

//�����ַ� char *strcpy(char * destin, char *source);
void CopyString(char* str) {
	char str1[100];
	strcpy(str1, str);
	printf("str1 is: %s\n", str1);
}

//�ַ���ƴ�� char* strcat(char *destin, char *source);
void ConcatString() {
	char str0[50] = "brave";
	char *str1 = "heart";
	strcat(str0, str1);
	printf("str0 is %s\n", str0);
}

//��һ�����в��Ҹ����ַ��ĵ�һ��ƥ��֮��
// char *strchr(char *str, char c);
//���ƥ�䵽�����ظ��ַ����׵�ַ�����򣬷��ؿ�
void MatchFirstChar() {
	char *str = "this is a string";
	char *ptr;
	char c = 'c';
	ptr = strchr(str, c);
	if (ptr)
		printf("position is %d\n", ptr - str);
	else
		printf("not found\n");
}

//�ַ����Ƚ�
//int strcmp(char *str1, char *str2);
void CompareString() {
	char* str1 = "abcd";
	char* str2 = "apple";
	int rst;
	rst = strcmp(str1, str2);
	if (rst > 0)
		printf("str1 is greater than str2");
	else
		printf("str1 is less than str2");
}

//�ڴ��в���ָ���ַ��ĵ�һ�γ���
//char *strstr(char *str1, char *str2);
void StrStrTest() {
	char *str1 = "better man, not bad";
	char *str2 = "man";
	char *ptr;
	ptr = strstr(str1, str2);
	printf("the substring is %s\n", ptr);
}

void StrToDoubleTest() {
	//char str[20] = "123.9";
	char str[20];
	char  *endptr;
	double value;
	printf("enter a number: ");
	strcpy(str, "123.89");
	//str = "123";
	//gets_s(str, 20);
	value = strtod(str, &endptr);
	printf("the string is %s , the number is %5.1lf\n", str, value);
}

void CharTest() {
	char str[] = "University of Science and Technology of China";
	SolveInputConflict();
	CharAlign();
	CharAndPointer();
	CutString();
	CopyString(str);
	ConcatString();
	MatchFirstChar();
	StrStrTest();
	StrToDoubleTest();
}