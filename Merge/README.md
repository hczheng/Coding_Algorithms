##**Merge 2016.12.27**

#### 题目十六: ####

> 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

#### 解答（C++）：递归

    class Solution {
    public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* pResult = NULL;//合并后链表的头指针
		if (pHead1 == NULL)
			return pHead2;//list1为空，直接返回list2
		if (pHead2 == NULL)
			return pHead1;//list2为空，直接返回list1

		if (pHead1->val <= pHead2->val) {
			pResult = pHead1;
			pResult->next = Merge(pHead1->next, pHead2);//递归，两个链表中值小的头结点作为合并结点的下一结点
		}
		else {
			pResult = pHead2;
			pResult->next = Merge(pHead1, pHead2->next);
		}
		return pResult;
	}
    };

#### 解答（C++）：非递归

    class Solution {
    public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* pResult = NULL;
		ListNode* current = NULL;

		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
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




#### 笔记: ####
>主要思路就是选取合并链表的下一节点，同步遍历两个链表，选择值比较小（相等取其一即可）的链表的当前结点作为合并链表的下一节点。可以通过递归和非递归实现，详见代码。

#### AC ####

![](http://i.imgur.com/OFuJtAJ.png)

![](http://i.imgur.com/3gEhjW5.png)
