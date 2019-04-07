/******************************************************************************
1 是编译器的唯一命名规则，就是inline函数, class和模板类函数被多次包含的情况下，
在编译的时候，编译器会自动把他们认为是同一个函数，不会发生二次定义的问题。前提
是他们一模一样。
2是编译器会把class里面定义的函数当做inline函数，所以直接在类里面实现函数的定义
没有关系。由上面的说明，他不会发生二次定义的问题。
3一般函数的声明和实现分开，在编译的时候，声明可以无数次，但是定义只能一份，只会
生成一份函数的.obj，所以有函数调用的地方，编译器必须在调用的地方先保持现场，然后
在花点时间去调用函数，然后回来，恢复现场。所以函数在头文件中实现，如果被包含二次。
函数的实现就被编译了2次，如果单独写在一个.cpp中间，自然就编译成为一份.obj，不会
产生二义性的问题。
3.inline函数在编译的时候直接复制在有该函数的地方，在空间上有消耗，但是在省去了时间
上的消耗，是一个模板函数。也就是说在有这些函数的地方都不需要去调用函数，也就不涉及
有2种函数可以调用产生的二义性问题。
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
	//设置tail中tail变量为私有变量，不能直接访问，可以通过macro.Cat::tail 访问。
	using Cat::tail;
};

