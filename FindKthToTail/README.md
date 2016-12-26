##**rectCover 2016.12.25**

#### 题目十二: ####

> 输入一个链表，输出该链表中倒数第k个结点。

#### 解答（C++）

    /*
    struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
    };*/
    class Solution {
    public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k == 0)
			return nullptr;

		ListNode *pAhead = pListHead;//设置两个指针
		ListNode *pBehind = nullptr;

		for (unsigned int i = 0; i < k - 1; ++i)
		{
			if (pAhead->next != nullptr)
				pAhead = pAhead->next;
			else
			{
				return nullptr;
			}
		}
		pBehind = pListHead;
		while (pAhead->next != nullptr)
		{
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		return pBehind;   
    }
    };



#### 笔记: ####
>要得到链表的倒数第K个结点，如果直接遍历一次得到链表长度n，然后再遍历到(n-k+1)可得到，但是显然这样的时间复杂度高，并不熟最优解。设置两个指针同时遍历，第一个指针先开始遍历，另一个指针不懂，等到第一个指针遍历到第k(此时走了k-1步)个结点的时候另一个指针再开始遍历(与第一个指针同步)，这样等到第一个指针遍历到链表末尾时，第二个结点刚好到倒数第k个结点。
>
>本地用例有构造链表及相关操作，见本地案例。

#### AC ####
![](http://i.imgur.com/muUTW2r.png)
