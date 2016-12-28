#include <stdio.h>
#include <iostream>
#include<vector>
#include <stdlib.h>
using namespace std;

//g++ -std=c++11 Merge.cpp -o Merge
// test.cpp : 定义控制台应用程序的入口点。
//
#include <exception>
using namespace std;

//链表定义
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
	{
		printf("Error to connect two nodes.\n");
		exit(1);
	}

	pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		printf("The node is nullptr\n");
	}
	else
	{
		printf("The key in node is %d.\n", pNode->val);
	}
}

void PrintList(ListNode* pHead)
{
	printf("PrintList starts.\n");

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->val);
		pNode = pNode->next;
	}

	printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->next;
		delete pNode;
		pNode = pHead;
	}
}

//void AddToTail(ListNode** pHead, int value)
//{
//	ListNode* pNew = new ListNode();
//	pNew->val = value;
//	pNew->next = nullptr;
//
//	if (*pHead == nullptr)
//	{
//		*pHead = pNew;
//	}
//	else
//	{
//		ListNode* pNode = *pHead;
//		while (pNode->next != nullptr)
//			pNode = pNode->next;
//
//		pNode->next = pNew;
//	}
//}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->val == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->next;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->next != nullptr && pNode->next->val != value)
			pNode = pNode->next;

		if (pNode->next != nullptr && pNode->next->val == value)
		{
			pToBeDeleted = pNode->next;
			pNode->next = pNode->next->next;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

//--------------------------分割线----------------------------------------//

//递归版本
//class Solution {
//public:
//	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//	{
//		ListNode* pResult = NULL;//合并后链表的头指针
//		if (pHead1 == NULL)
//			return pHead2;//list1为空，直接返回list2
//		if (pHead2 == NULL)
//			return pHead1;//list2为空，直接返回list1
//
//		if (pHead1->val <= pHead2->val) {
//			pResult = pHead1;
//			pResult->next = Merge(pHead1->next, pHead2);//递归，两个链表中值小的头结点作为合并结点的下一结点
//		}
//		else {
//			pResult = pHead2;
//			pResult->next = Merge(pHead1, pHead2->next);
//		}
//		return pResult;
//	}
//};
//非递归版本
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* pResult = NULL;//合并后链表的头指针
		ListNode* current = NULL;//遍历指针

		if (pHead1 == NULL)
			return pHead2;//list1为空，直接返回list2
		if (pHead2 == NULL)
			return pHead1;//list2为空，直接返回list1
		while (pHead1 != NULL && pHead2 != NULL) {
			if (pHead1->val <= pHead2->val) {
				if (pResult == NULL) {
					current = pResult = pHead1;
				}
				else {
					current->next = pHead1;
					current = current->next;
				}
				pHead1 = pHead1->next;
			}
			else {
				if (pResult == NULL) {
					current = pResult = pHead2;
				}
				else {
					current->next = pHead2;
					current = current->next;
				}
				pHead2 = pHead2->next;
			}
		}

		if (pHead1 == NULL) {
			current->next = pHead2;
		}
		if (pHead2 == NULL) {
			current->next = pHead1;
		}

		return pResult;
	}
};

int main(int argc, char* argv[])
{
	Solution so;
	printf("=====Test starts:=====\n");
	ListNode* pNode1 = new ListNode(1);
	ListNode* pNode2 = new ListNode(2);
	ListNode* pNode3 = new ListNode(3);
	ListNode* pNode4 = new ListNode(4);
	ListNode* pNode5 = new ListNode(5);
	ListNode* pNode6 = new ListNode(6);
	ListNode* pNode7 = new ListNode(7);
	ListNode* pNode8 = new ListNode(8);
	ListNode* pNode9 = new ListNode(9);
	ListNode* pNode10 = new ListNode(10);

	ConnectListNodes(pNode1, pNode3);
	ConnectListNodes(pNode3, pNode5);
	ConnectListNodes(pNode5, pNode7);
	ConnectListNodes(pNode7, pNode9);

	ConnectListNodes(pNode2, pNode4);
	ConnectListNodes(pNode4, pNode6);
	ConnectListNodes(pNode6, pNode8);
	ConnectListNodes(pNode8, pNode10);

	printf("The list1 is: \n");
	PrintList(pNode1);

	printf("The list2 is: \n");
	PrintList(pNode2);

	ListNode* pReversedHead = so.Merge(pNode1,pNode2);

	printf("The merge list is: \n");
	PrintList(pReversedHead);
    DestroyList(pReversedHead);
	getchar();
}