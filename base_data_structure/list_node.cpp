#include<iostream>
#include"list_node.h"

ListNode* CreateListNode() {
	ListNode* head = nullptr;
	// ListNode* s = nullptr;
	ListNode* e = nullptr;// s stands for start point, e stands for end point
	ListNode* node = new ListNode;
	std::cout << "please input a number as value of head ListNode" << std::endl;
	std::cin >> node->value;
	if (head == nullptr) 
		head = node;
	// s = node;
	e = node;
	e->pNext = nullptr;
	return head;
}

void PrintListNode(ListNode* head) {
	std::cout << "\n print list node start" << std::endl;
	if (head == nullptr) {
		std::cout << "this is a null listnode" << std::endl;
	} else {
		ListNode* pNode = nullptr;
		pNode = head;
		while (pNode != nullptr) {
			std::cout << " " << pNode->value;
			pNode = pNode->pNext;
		}
	}
	std::cout << "\n print list node completed" << std::endl;
}

void AddToTail(ListNode* head, int value) {
	ListNode* node = new ListNode;
	node->value = value;
	node->pNext = nullptr;
	if (head == nullptr)
		head = node;
	else {
		ListNode* pNode = nullptr;
		pNode = head;
		while (pNode->pNext != nullptr)
		{
			pNode = pNode->pNext;
		}
		pNode->pNext = node;
	}
}

void RemoveNode(ListNode** head, int value) {
	if (*head == nullptr)
		return;
	if ((*head)->value == value) {
		ListNode* target_node = nullptr;
		target_node = *head;
		*head = (*head)->pNext;
		delete target_node;
		std::cout << "successfully remove node " << std::endl;
		return;
	}
	ListNode* node = nullptr;
	node = *head;
	while (node->pNext != nullptr && node->pNext->value != value)
		node = node->pNext;
	if (node->pNext == nullptr) {
		std::cout << "failed to find this node" << std::endl;
		return;
	}
	if (node->pNext->value == value) {
		ListNode* target_node = nullptr;
		target_node = node->pNext;
		node->pNext = node->pNext->pNext;
		delete target_node;
		std::cout << "successfully remove node " << std::endl;
		return;
	}  
}

// delete the specified node
// the specified node must be in the list node.
void DeleteSpecifiedNode(ListNode* pHead, ListNode* pToBeDeleted) {
	if (!pHead && !pToBeDeleted)
		return;
	if (pToBeDeleted->pNext != nullptr) {
		ListNode* temp = pToBeDeleted->pNext;
		pToBeDeleted->value = temp->value;
		pToBeDeleted->pNext = temp->pNext;
		delete temp;
		temp = nullptr;
	}
	else if (pHead == pToBeDeleted) {
		delete pHead;
		pHead = nullptr;
	}
	else {
		ListNode* pNode = pHead;
		while (pNode->pNext != pToBeDeleted)
			pNode = pNode->pNext;
		pNode->pNext = nullptr;
		delete pNode->pNext;
		pToBeDeleted = nullptr;
	}
}

