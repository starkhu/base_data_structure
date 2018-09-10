#include<iostream>
#include<string>
#include<map>
#include"size_function.h"
#include"char.h"
#include"list_node.h"
#include"stack.h"
#include"string_test.h"
#include"get_input.h"
#include"pointer_test.h"
#include"const_test.h"
#include"set_output.h"
#include"stl_map_test.h"
#include"stl_vector_test.h"
#include"big_little_endian.h"

extern int extern_value; //声明变量

static enum TestOption
{
	CharTest_,
	SizeTest_,
	ListNodeTest_,
	StackTest_,
	StringTest_,
	InputTest_,
	PointerTest_,
	ExternTest_,
	ConstTest_,
	OutputTest_,
	MapTest_,
	VectorTest_,
	BigLittleTest_,
	Quit_,
};

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
	std::cout << "10: set output format test" << std::endl;
	std::cout << "11: map test" << std::endl;
	std::cout << "12: vector test" << std::endl;
	std::cout << "13: big little endian test" << std::endl;
	std::cout << "q: quit" << std::endl;
}

void ExternTest() {
	std::cout << "extern value is: " << extern_value << std::endl;
}

void NumberMapToFunction(std::map<std::string, enum TestOption>* test_map) {
	test_map->insert(std::pair<std::string, enum TestOption>("1", CharTest_));
	test_map->insert(std::map<std::string, enum TestOption>::value_type("2", SizeTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("3", ListNodeTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("4", StackTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("5", StringTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("6", InputTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("7", PointerTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("8", ExternTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("9", ConstTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("10", OutputTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("11", MapTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("12", VectorTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("13", BigLittleTest_));
	test_map->insert(std::pair<std::string, enum TestOption>("q", Quit_));
}
int main() {
	PrintOptions();
	std::string options;

	std::map<std::string, enum TestOption> TestMap;
	// TestMap["1"] = CharTest;
	std::cout << "please input your option:";
	std::cin >> options;
	enum TestOption test_option;
	NumberMapToFunction(&TestMap);
	test_option = TestMap[options];
	//std::cout << "test option is: " << test_option << std::endl;
	while (test_option != Quit_) {
		//std::cout << "test option is: " << test_option << std::endl;
		switch (test_option) {
		//case 不识别字符串
		case CharTest_:
			CharTest();
			break;
		case SizeTest_:
			size_test();
			break;
		case ListNodeTest_:
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
		case StackTest_:
			StackTest();
			break;
		case StringTest_:
			StringTest();
			break;
		case InputTest_:
			GetInput();
			break;
		case PointerTest_:
			PointerTest();
			break;
		case ExternTest_:
			ExternTest();
			break;
		case ConstTest_:
			ConstTest();
			break;
		case OutputTest_:
			SetOutputFormat();
			break;
		case MapTest_:
			MapTest();
			break;
		case VectorTest_:
			VectorTest();
			break;
		case BigLittleTest_:
			BigEndianTest();
		default:
			break;
		}
		std::cout << "please input your option:";
		std::cin >> options;
		test_option = TestMap[options];
	}
	std::cout << "test completed" << std::endl;

	system("pause");
	return 0;
}