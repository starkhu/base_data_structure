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
#include"char_function.h"
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


void CharTest() {
	char str[] = "University of Science and Technology of China";
	printf(" str 6.9s is %6.9s", str);
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