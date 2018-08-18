#pragma once
struct ListNode {
	int value;
	ListNode* pNext;
};
ListNode* CreateListNode();
void PrintListNode(ListNode* head);
void AddToTail(ListNode* head, int value);
void RemoveNode(ListNode** head, int value);