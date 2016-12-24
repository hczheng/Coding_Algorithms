##**rectCover 2016.12.23**

#### 题目十一: ####

> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

#### 解答（C++）

    class Solution {
    public:
    void reOrderArray(vector<int> &array) {
        vector<int> res;//新建临时数组，空间换时间
        for(int i = 0; i < array.size(); i++)
        {
            if(array[i] & 1)//遍历，为奇数存入临时数组
                res.push_back(array[i]);
        }
        for(int i = 0; i < array.size(); i++)
        {
            if((array[i] & 1) == 0)//遍历，为偶数存入临时数组            
                res.push_back(array[i]);
        }
        array = res;       
    }
    };


####解答(Python)

    # -*- coding:utf-8 -*-
    class Solution:
    def reOrderArray(self, array):
        # write code here
        odd = []
        even = []
        for i in array:
            if i % 2 == 0:
                even.append(i)
            else:
                odd.append(i)
        return odd+even



#### 笔记: ####
>这题关键在于时间复杂度，如果从头到尾遍历碰到奇数然后移动，这样的时间复杂度是O(n^2).所以考虑用临时空间，可以将时间复杂度降到O(2n),详见代码。

#### AC ####
![](http://i.imgur.com/dbApKZW.png)

