##jumpFloor 2016.12.16

#### 题目九: ####

> 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

#### 解答（C++）: ####

    class Solution {
    public:
    int jumpFloor(int number) {
        int f = 1, g = 2;
        while(number-->1) {
        //循环迭代
        //F[n]=F[n-1]+F[n-2](n>=2,F[1]=1,F[2]=2)
            g += f;
            f = g - f;
        }
        return f;      
    }
    };


#### 解答（Python）: ####

    # -*- coding:utf-8 -*-
    class Solution:
    def jumpFloor(self, number):
        # write code here
        f = 1
        g = 1
        for i in range(number):
            f,g = g,f+g
        return f



#### 笔记: ####

> 对于第n个台阶来说，只能从n-1或者n-2的台阶跳上来，所以F(n) = F(n-1) + F(n-2)斐波拉契数序列
>   
> 初始条件  
n=1:只能一种方法  
n=2:两种
斐波拉契数序列第七题已经写过了，这道题难点在于能不能看出这是一个斐波拉契数序列(只是初始条件改变了)，嘿嘿，都是套路。后面还有一题变态跳台阶，关键还是在于问题思路转换。

#### AC ####
![](http://i.imgur.com/TRHR3lH.png)

