##**ReverseList 2016.12.26**

#### 题目十五: ####

> 输入一个链表，反转链表后，输出链表的所有元素。

#### 解答（C++）

    class Solution {
    public:
	ListNode* ReverseList(ListNode* pHead) 
	{
		ListNode* pReversedHead = nullptr;//记录反转链表的头结点
		ListNode* pNode = pHead;//记录当前遍历结点
		ListNode* pPrev = nullptr;//记录上一结点
		while (pNode != nullptr)
		{
			ListNode* pNext = pNode->next;

			if (pNext == nullptr)
				pReversedHead = pNode;

			pNode->next = pPrev;

			pPrev = pNode;
			pNode = pNext;
		}
		return pReversedHead;
	}
    };



#### 笔记: ####
>设置三个指针pReversedHead、pNode、pPrev分别指向反转链表的头结点
>当前遍历结点、上一结点，只需遍历一次即可完成链表反转，在纸上画一下会比较清晰，详见代码。

#### AC ####
![](http://i.imgur.com/5YwQyDp.png)
