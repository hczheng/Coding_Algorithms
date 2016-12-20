##rectCover 2016.12.19

#### 题目十: ####

> 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

#### 解答（C++）迭代循环解: ####

    class Solution {
    public:
    int rectCover(int number) {
        if(number<1)
            return 0;
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
    def rectCover(self, number):
        # write code here
        if number<1:
            return 0
        f = 1
        g = 1
        for i in range(number):
            f,g = g,f+g
        return f



#### 笔记: ####
>思路在纸上画的，直接上图了，总之还是个斐波那契数列，归纳一下就好。 
>
>![](http://i.imgur.com/scRwzUA.jpg)
>

#### AC ####
![](http://i.imgur.com/NyWdqPj.png)

