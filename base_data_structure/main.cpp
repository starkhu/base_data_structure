#include<iostream>
#include<string>
#include"size_function.h"
#include"char.h"
#include"list_node.h"
#include"stack.h"

void PrintOptions() {
	std::cout << "1: char_test" << std::endl;
	std::cout << "2: size_test" << std::endl;
	std::cout << "3: listnode_test" << std::endl;
	std::cout << "4: stack_test" << std::endl;
}

int main() {
	PrintOptions();
	char options;
	std::cin >> options;
	while (options != 'q') {
		switch (options) {
		case '1':
			char_test();
			break;
		case '2':
			size_test();
			break;
		case '3':
			ListNode* head;
			head = CreateListNode();
			AddToTail(head, 2);
			RemoveNode(&head, 1);
			PrintListNode(head);
			break;
		case '4':
			StackTest();
		}
		std::cin >> options;
	}
	std::cout << "test completed" << std::endl;

	system("pause");
	return 0;
}