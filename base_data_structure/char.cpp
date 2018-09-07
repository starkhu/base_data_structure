/*********************************************************************************
*scanf()和gets()函数冲突问题
*解决方案
*方法1，用一句 while(getchar()!='\n');  
        来处理掉缓冲区里的回车换行符，然后再gets()就正常了。
*方法2，如果很明确地就知道缓冲区还留着这么个回车换行符，那就直接读入吧：
        scanf("\n"); 或者getchar()读入一个字符，然后 接着gets()也就不会有问题了
*********************************************************************************/
#include<iostream>
#include<string.h>
#pragma warning(disable:4996)


void SolveInputConflict() {
	char a0[20], a1[20];
	printf("please enter a0 and a1: ");
	scanf("%s %s", a0, a1);
	printf("a0 is %s, a1 is %s\n", a0, a1);
	getchar();//用来接收换行符
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
	//字符串数组存取方式采用了对齐原则，占用空间少的向占用空间多的靠齐
	std::cout << "number of elements in the array: " 
		<< sizeof(str) / sizeof(str[0]) << std::endl;

	char str1[3] = { 'a', 's' };
	//如果初值个数小于数组长度,则只将这些字符赋绐数组中前面的元素
	//其余元素自动定为空字符(即'/0')
	for (int i = 0; i < 3; i++)
		std::cout << str1[i] << std::endl;
	str1[2] = 'h';
	for (int i = 0; i < 3; i++)
		std::cout << str1[i] << std::endl;
}

//分割字符串 char* strtok(char *s, const char *delim)
void CutString() {
	char ch[] = "University of Science and Technology of China";
	char *token_ptr = strtok(ch, " ");
	while (token_ptr != NULL)
	{
		std::cout << token_ptr << std::endl;
		token_ptr = strtok(NULL, " ");
	}
}

//拷贝字符 char *strcpy(char * destin, char *source);
void CopyString(char* str) {
	char str1[100];
	strcpy(str1, str);
	printf("str1 is: %s\n", str1);
}

//字符串拼接 char* strcat(char *destin, char *source);
void ConcatString() {
	char str0[50] = "brave";
	char *str1 = "heart";
	strcat(str0, str1);
	printf("str0 is %s\n", str0);
}

//在一个串中查找给定字符的第一个匹配之处
// char *strchr(char *str, char c);
//如果匹配到，返回该字符的首地址，否则，返回空
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

//字符串比较
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

//在串中查找指定字符的第一次出现
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