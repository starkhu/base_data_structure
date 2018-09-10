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
#include"char_function.h"
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