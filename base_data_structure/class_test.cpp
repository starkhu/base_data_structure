/******************************************************************************
*static:
*static成员属于类成员，不属于任何类对象，所以它不占类对象的内存空间
*static成员既可以通过类对象访问，也可以通过类本省进行访问
*static成员函数只能访问static成员变量，
*非static成员变量既可以访问static成员变量也可以访问非static成员变量

******************************************************************************/
#include<iostream>
#include"class_test.h"
#include<string>

static std::string category="animal";

std::string Cat::category = "animal";

void Cat::SetName(std::string s) {
	name = s;
}
void Cat::PrintCategory() {
	std::cout << "category is:" << category << std::endl;
}


void ClassTest() {
	Cat cat;
	cat.PrintCategory();
	std::cout << "size of cat is  " << sizeof(cat) << std::endl;

	PersianCat macro;

}