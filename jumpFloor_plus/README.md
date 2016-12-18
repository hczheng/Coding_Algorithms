##jumpFloor_plus 2016.12.16

#### 题目九: ####

> 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

#### 解答（C++）牛X解...: ####

    class Solution {
    public:
    int jumpFloorII(int number) {
        return  1<<--number;
    }
    };

#### 解答（C++）递归解: ####

    class Solution {
    public:
    int jumpFloorII(int number) {
        if(number == 0)
            return 0;
        else if(number == 1)
            return 1;
        else
            return 2*jumpFloorII(number-1);
 
    }
    };
#### 解答（C++）迭代循环解: ####

    class Solution {
    public:
    int jumpFloorII(int number) {
        if(number <= 0)     return 0;
        if(number == 1)     return 1;
        int result = 1;
        // 2^(n-1)
        while(number-->1)
        {
           result *= 2; 
        }
        return result;
    }
    };

#### 解答（Python）: ####

    # -*- coding:utf-8 -*-
    class Solution:
    def jumpFloorII(self, number):
        # write code here
        return 2 ** (number - 1)



#### 笔记: ####
>从上一题的思路出发：对于第n个台阶来说，只能从n-1或者n-2的台阶跳上来(只有两种跳法),F(n) = F(n-1) + F(n-2);对于本题来说，对于第n个台阶有可能是从第n-1,n-2,n-3...1,0跳上来，因此可以归纳出：
>
>f(0)=0  
> f(1)=1   
> f(2)=f(2-1)+f(2-2)    
> f(3)=f(3-1)+f(3-2)+f(3-3)  
> **.**    
>**.**  
> **.** 
> f(n-1)=f(n-2)+f(n-3)+...f(n-n)  ①    
> f(n)=f(n-1)+f(n-2)+f(n-3)+...f(n-n) ②    
> ②-①=f(n-1)  
> 可以得出f(n)=2f(n-1)  
> 这样问题就简单了。

#### AC ####
![](http://i.imgur.com/rQWbbQ3.png)

