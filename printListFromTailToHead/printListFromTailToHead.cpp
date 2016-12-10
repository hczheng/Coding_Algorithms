#include <cstdlib>
#include<vector>
#include <iostream> 
using namespace std;

//g++ -std=c++11 printListFromTailToHead.cpp -o printListFromTailToHead  //about compile
//输入一个链表，从尾到头打印链表每个节点的值。
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;

	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
	if (pCurrent == nullptr)
	{
		printf("Error to connect two nodes.\n");
		exit(1);
	}

	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode)
{
	if (pNode == nullptr)
	{
		printf("The node is nullptr\n");
	}
	else
	{
		printf("The key in node is %d.\n", pNode->m_nValue);
	}
}

void PrintList(ListNode* pHead)
{
	printf("PrintList starts.\n");

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		printf("%d\t", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}

	printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		pHead = pHead->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNew;
	}
}

void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pToBeDeleted = nullptr;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;

		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> v;
	int a[10000];//新建一个数组存储链表数值
	ListNode *p = head;
	int i = 0;
	while (p != NULL)
	{
		a[i++] = p->m_nValue;
		p = p->m_pNext;
	}
	for (int j = i - 1; j >= 0; j--)//逆序输出
	{
		v.push_back(a[j]);
	}
	return(v);
}
// ====================测试代码====================
void Test(ListNode* pHead)
{
	PrintList(pHead);
	vector<int>::iterator iter;
	vector<int> ivector =printListFromTailToHead(pHead);
	for (iter = ivector.begin(); iter != ivector.end(); iter++)
	{
		printf("%d\t", *iter);
	}
	printf("\n");
}

// 1->2->3->4->5
void Test1()
{
	printf("\nTest1 begins.\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}


int main(int argc, char* argv[])
{
	Test1();
	//return 0;
	getchar();
}

