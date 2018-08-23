#include<iostream>

void size_test() {
	struct ListNode {
		//char value_c;
		int value_i;
		char value_c0;
		char value_c1;
		//ListNode* pNext;
	};
	ListNode* pNode = new ListNode;
	//指针占4个字节 
	std::cout << "size of ListNode is: " << sizeof(ListNode) << std::endl;
	std::cout << "size of int is: " << sizeof(char) << std::endl;
	std::cout << "size of int* is: " << sizeof(int*) << std::endl;


}