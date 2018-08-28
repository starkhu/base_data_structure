#include<iostream>
#include<string>
#include"size_function.h"
#include"char.h"
#include"list_node.h"
#include"stack.h"
#include"string_test.h"
#include"get_input.h"
#include"pointer_test.h"
#include"const_test.h"

extern int extern_value; //ÉùÃ÷±äÁ¿

void PrintOptions() {
	std::cout << "1: char_test" << std::endl;
	std::cout << "2: size_test" << std::endl;
	std::cout << "3: listnode_test" << std::endl;
	std::cout << "4: stack_test" << std::endl;
	std::cout << "5: string_test" << std::endl;
	std::cout << "6: get input test" << std::endl;
	std::cout << "7: pointer test" << std::endl;
	std::cout << "8: extern test" << std::endl;
	std::cout << "9: const_test" << std::endl;
}

void ExternTest() {
	std::cout << "extern value is: " << extern_value << std::endl;
}

int main() {
	PrintOptions();
	char options;
	std::cout << "please input your option:";
	std::cin >> options;
	while (options != 'q') {
		switch (options) {
		case '1':
			char_test();
			CharTest();
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
			AddToTail(head, 3);
			AddToTail(head, 4);
			DeleteSpecifiedNode(head, head->pNext);
			PrintListNode(head);
			break;
		case '4':
			StackTest();
			break;
		case '5':
			StringTest();
			break;
		case '6':
			GetInput();
			break;
		case '7':
			PointerTest();
		case '8':
			ExternTest();
		case '9':
			ConstTest();
		default:
			break;
		}
		std::cout << "please input your option:";
		std::cin >> options;
	}
	std::cout << "test completed" << std::endl;

	system("pause");
	return 0;
}