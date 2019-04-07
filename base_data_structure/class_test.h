/******************************************************************************
1 �Ǳ�������Ψһ�������򣬾���inline����, class��ģ���ຯ������ΰ���������£�
�ڱ����ʱ�򣬱��������Զ���������Ϊ��ͬһ�����������ᷢ�����ζ�������⡣ǰ��
������һģһ����
2�Ǳ��������class���涨��ĺ�������inline����������ֱ����������ʵ�ֺ����Ķ���
û�й�ϵ���������˵���������ᷢ�����ζ�������⡣
3һ�㺯����������ʵ�ַֿ����ڱ����ʱ���������������Σ����Ƕ���ֻ��һ�ݣ�ֻ��
����һ�ݺ�����.obj�������к������õĵط��������������ڵ��õĵط��ȱ����ֳ���Ȼ��
�ڻ���ʱ��ȥ���ú�����Ȼ��������ָ��ֳ������Ժ�����ͷ�ļ���ʵ�֣�������������Ρ�
������ʵ�־ͱ�������2�Σ��������д��һ��.cpp�м䣬��Ȼ�ͱ����Ϊһ��.obj������
���������Ե����⡣
3.inline�����ڱ����ʱ��ֱ�Ӹ������иú����ĵط����ڿռ��������ģ�������ʡȥ��ʱ��
�ϵ����ģ���һ��ģ�庯����Ҳ����˵������Щ�����ĵط�������Ҫȥ���ú�����Ҳ�Ͳ��漰
��2�ֺ������Ե��ò����Ķ��������⡣
******************************************************************************/
#pragma once
#include<iostream>
#include<string>

void ClassTest();

class Animal {
public:
	Animal() {
		std::cout << "Animal class constructing" << std::endl;
	}
	~Animal() {
		std::cout << "Animal class destructing" << std::endl;
	}

private:
	std::string walk_way;
};

class Cat : private Animal {
public:
	Cat() : name("tom") {
		std::cout << name << " constructing" << std::endl;
	};

	~Cat() {
		std::cout << name << " destructing" << std::endl;
	}
	void SetName(std::string s);
	void PrintCategory();
	std::string tail;
private:
	std::string name;
	static std::string category;
};
//std::string Cat::category = "animal";

class PersianCat : public Cat {
public:
	PersianCat() {
		std::cout << "PersianCat class constructing" << std::endl;
	}
	~PersianCat() {
		std::cout << "PersianCat class destructing" << std::endl;
	}
private:
	//����tail��tail����Ϊ˽�б���������ֱ�ӷ��ʣ�����ͨ��macro.Cat::tail ���ʡ�
	using Cat::tail;
};

