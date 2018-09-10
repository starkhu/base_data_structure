#include<iostream>
#pragma warning(disable:4996)


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