/*********************************************************************************
*scanf()和gets()函数冲突问题
*解决方案
*方法1，用一句 while(getchar()!='\n');  
        来处理掉缓冲区里的回车换行符，然后再gets()就正常了。
*方法2，如果很明确地就知道缓冲区还留着这么个回车换行符，那就直接读入吧：
        scanf("\n"); 或者getchar()读入一个字符，然后 接着gets()也就不会有问题了
*********************************************************************************
printf打印格式
(1).可以在"%"和字母之间插进数字表示最大场宽。
例如 : % 3d 表示输出3位整型数, 不够3位右对齐。
	%9.2f 表示输出场宽为9的浮点数, 其中小数位为2, 整数位为6,
	小数点占一位, 不够9位右对齐。
	% 8s 表示输出8个字符的字符串, 不够8个字符右对齐。
	如果字符串的长度、或整型数位数超过说明的场宽, 将按其实际长度输出。
	但对浮点数, 若整数部分位数超过了说明的整数位宽度, 将按实际整数位输出;
若小数部分位数超过了说明的小数位宽度, 则按说明的宽度以四舍五入输出。
另外, 若想在输出值前加一些0, 就应在场宽项前加个0。
例如 : % 04d 表示在输出一个小于4位的数值时, 将在前面补0使其总宽度
	为4位。
	如果用浮点数表示字符或整型量的输出格式, 小数点后的数字代表最大宽度,
	小数点前的数字代表最小宽度。
	例如 : %6.9s 表示显示一个长度不小于6且不大于9的字符串。若大于9, 则
	第9个字符以后的内容将被删除。
	(2).可以在"%"和字母之间加小写字母l, 表示输出的是长型数。
	例如 : %ld 表示输出long整数
	%lf 表示输出double浮点数
	(3).可以控制输出左对齐或右对齐, 即在"%"和字母之间加入一个"-" 号可
	说明输出为左对齐, 否则为右对齐。
	例如 : %-7d 表示输出7位整数左对齐
	%-10s 表示输出10个字符左对齐
*********************************************************************************
*打印char型字符或者字符串的地址
*char c; (&c)的数据类型是(char*) 而char型变量是打印遇到空字符('\0')才会停止
*所以想要打印字符串地址，需要用static_cast<void*>转换一下
*事实上，所有需要打印变量地址的地方最好都需要用static_cast<void*>转换一下
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
	//str在这里退化成一个指针，指针的大小永远是4个字节
	std::cout << "sizeof str is " << sizeof(str) << std::endl;
	std::cout << "str is " << str << std::endl;
	//CharRef1中str的变化不会影响本函数中str
	//CharRef2中str是指向本函数中str的指针，会影响本函数中str的变化
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
	getchar();//用来接收换行符
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
	
	//输出字符串的地址
	std::cout << static_cast<void*>(&c) << std::endl;

	//str1和str2是独立分配的两个内存空间
	//str3和str4是两个指针指向共同的地址
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