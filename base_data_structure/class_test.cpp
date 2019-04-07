/******************************************************************************
*static:
*static��Ա�������Ա���������κ��������������ռ�������ڴ�ռ�
*static��Ա����ֻ�ܷ���static��Ա������
*��static��Ա�����ȿ��Է���static��Ա����Ҳ���Է��ʷ�static��Ա����

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