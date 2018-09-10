/*********************************************************************************
*scanf()��gets()������ͻ����
*�������
*����1����һ�� while(getchar()!='\n');  
        ���������������Ļس����з���Ȼ����gets()�������ˡ�
*����2���������ȷ�ؾ�֪����������������ô���س����з����Ǿ�ֱ�Ӷ���ɣ�
        scanf("\n"); ����getchar()����һ���ַ���Ȼ�� ����gets()Ҳ�Ͳ�����������
*********************************************************************************
printf��ӡ��ʽ
(1).������"%"����ĸ֮�������ֱ�ʾ��󳡿�
���� : % 3d ��ʾ���3λ������, ����3λ�Ҷ��롣
	%9.2f ��ʾ�������Ϊ9�ĸ�����, ����С��λΪ2, ����λΪ6,
	С����ռһλ, ����9λ�Ҷ��롣
	% 8s ��ʾ���8���ַ����ַ���, ����8���ַ��Ҷ��롣
	����ַ����ĳ��ȡ���������λ������˵���ĳ���, ������ʵ�ʳ��������
	���Ը�����, ����������λ��������˵��������λ���, ����ʵ������λ���;
��С������λ��������˵����С��λ���, ��˵���Ŀ�����������������
����, ���������ֵǰ��һЩ0, ��Ӧ�ڳ�����ǰ�Ӹ�0��
���� : % 04d ��ʾ�����һ��С��4λ����ֵʱ, ����ǰ�油0ʹ���ܿ��
	Ϊ4λ��
	����ø�������ʾ�ַ����������������ʽ, С���������ִ��������,
	С����ǰ�����ִ�����С��ȡ�
	���� : %6.9s ��ʾ��ʾһ�����Ȳ�С��6�Ҳ�����9���ַ�����������9, ��
	��9���ַ��Ժ�����ݽ���ɾ����
	(2).������"%"����ĸ֮���Сд��ĸl, ��ʾ������ǳ�������
	���� : %ld ��ʾ���long����
	%lf ��ʾ���double������
	(3).���Կ�������������Ҷ���, ����"%"����ĸ֮�����һ��"-" �ſ�
	˵�����Ϊ�����, ����Ϊ�Ҷ��롣
	���� : %-7d ��ʾ���7λ���������
	%-10s ��ʾ���10���ַ������
*********************************************************************************
*��ӡchar���ַ������ַ����ĵ�ַ
*char c; (&c)������������(char*) ��char�ͱ����Ǵ�ӡ�������ַ�('\0')�Ż�ֹͣ
*������Ҫ��ӡ�ַ�����ַ����Ҫ��static_cast<void*>ת��һ��
*��ʵ�ϣ�������Ҫ��ӡ������ַ�ĵط���ö���Ҫ��static_cast<void*>ת��һ��
*********************************************************************************/

#include<iostream>
#include<string.h>
#include"char_function.h"
#pragma warning(disable:4996)

void CharRef1(char* str) {
	str++;
}
void CharRef2(char**  str) {
	(*str)++;
}

void CharRef0(char* str) {
	//str�������˻���һ��ָ�룬ָ��Ĵ�С��Զ��4���ֽ�
	std::cout << "sizeof str is " << sizeof(str) << std::endl;
	std::cout << "str is " << str << std::endl;
	//CharRef1��str�ı仯����Ӱ�챾������str
	//CharRef2��str��ָ�򱾺�����str��ָ�룬��Ӱ�챾������str�ı仯
	CharRef1(str);
	std::cout << "str is " << str << std::endl;
	CharRef2(&str);
	std::cout << "str is " << str << std::endl;
}

void CharPointer(){
	char str[20] = "hello world!";
	std::cout << "sizeof str is " << sizeof(str) << std::endl;
	CharRef0(str);
}

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
	char c = 'c';
	char str1[] = "hello world";
	char str2[] = "hello world";
	char* str3 = "hello world";
	char* str4 = "hello world";
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	std::cout << str4 << std::endl;
	
	//����ַ����ĵ�ַ
	std::cout << static_cast<void*>(&c) << std::endl;

	//str1��str2�Ƕ�������������ڴ�ռ�
	//str3��str4������ָ��ָ��ͬ�ĵ�ַ
	if (str1 == str2)
		std::cout << "str1 and str2 are same" << std::endl;
	else
		std::cout << "str1 and str2 are different" << std::endl;
	if (str3 == str4)
		std::cout << "str3 and str4 are same" << std::endl;
	else
		std::cout << "str3 and str4 are different" << std::endl;
	std::cout << " address of str1 is " << static_cast<void*>(str1) << std::endl;
	std::cout << " address of str2 is " << static_cast<void*>(str2) << std::endl;
	std::cout << " address of str3 is " << static_cast<void*>(str3) << std::endl;
	std::cout << " address of str4 is " << static_cast<void*>(str4) << std::endl;
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
	printf(" str 6.9s is %6.9s\n", str);
	CharPointer();
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