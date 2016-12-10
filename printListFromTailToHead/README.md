# printListFromTailToHead #

#### 题目三: ####
> 输入一个链表，从尾到头打印链表每个节点的值。

#### 解答（C++）: ####
    
    /**
    /**
    *  struct ListNode {
    *        int val;
    *        struct ListNode *next;
    *        ListNode(int x) :
    *              val(x), next(NULL) {
    *        }
    *  };
    */

    class Solution {
    public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        int a[10000];//新建一个数组存储链表数值
        ListNode *p = head;
        int i = 0;
        while (p != NULL)
        {
            a[i++] = p->val;
            p = p->next;
        }
        for (int j = i - 1; j >= 0; j--)//逆序输出
        {
            v.push_back(a[j]);
        }
        return(v);
        
    }
};

#### 解答（Python）: ####
 
    # -*- coding:utf-8 -*-
    # class ListNode:
    #     def __init__(self, x):
    #         self.val = x
    #         self.next = None

    class Solution:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        l = []
        head = listNode
        while head:
            l.insert(0, head.val)
            head = head.next
        return l     

#### 笔记: ####

> 因为链表中的内存不是一次性分配的，因此想要得到第i个结点必须从头结点开始遍历，时间效率为O(n)，而在数组中可以根据下标在O(1)时间内找到。
> 
> 从前往后遍历链表，额外使用一个数组或者栈存储数值，然后输出即可。
> 
> 本地测试用例有点麻烦，需要自己构建链表结构以及相关的操作方法。

#### AC ####

![](http://i.imgur.com/CtAXEhH.png)
