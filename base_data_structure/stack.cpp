#include<iostream>
#include<stack>

void StackTest() {
	std::stack<int> stk;
	for (int i = 0; i < 10; i++)
		stk.push(i);
	while (!stk.empty()) {
		int value = stk.top();
		std::cout << value << std::endl;
		stk.pop();
	}	
}