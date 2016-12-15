##Fibonacci 2016.12.14

#### 题目七: ####

> 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。 n<=39

#### 解答（C++）: ####

    class Solution {
    public:
    int Fibonacci(int n) {
        int f = 0, g = 1;
        while(n--) {
        //循环迭代
        //F[n]=F[n-1]+F[n-2](n>=2,F[0]=0,F[1]=1)
            g += f;
            f = g - f;
        }
        return f;
    }
    };


#### 解答（Python）: ####

    # -*- coding:utf-8 -*-
    class Solution:
    def Fibonacci(self, n):
        # write code here
        a=[0,1,1]
        if(n<3):
            return a[n]
        for i in range(3,n+1):
            a.append(a[i-2]+a[i-1])
        return a[n]



#### 笔记: ####

> 斐波那契数列是个非常经典的问题了（`F[n]=F[n-1]+F[n-2](n>=2,F[0]=0,F[1]=1)`）。主要就是迭代（Iteration）VS 递归（Recursion），一般来说递归的代码比较简洁，但是因为递归是调用函数本身，函数调用是有时间和空间消耗的。
> 
> 首先，每一次函数调用都需要在内存栈中分配空间保存参数，返回地址及临时变量，在入栈、出栈的过程中也会有时间消耗，因而实现的效率不如迭代循环。
> 
>其次，递归的思想是把一个大问题分成一个个小问题，这样造成很多 计算重复，因为这些小问题很可能发生重复现象。比如f(7)=f(6)+f(5);f(6)=f(5)+f(4);这里就发生重复计算了，因而影响效率。
> 
> 此外，递归层数过多的话还会出现栈溢出，这是程序员最不想看到的吧。

#### AC ####
![这里写图片描述](http://img.blog.csdn.net/20161215090746837?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvc2IxOTkzMTIwMQ==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

