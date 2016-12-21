##Power 2016.12.21

#### 题目十二: ####

> 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

#### 解答（C++）常规解法

    class Solution {
    public:
    double Power(double base, int exponent) {
        if(exponent==0)//任何数的0次方都是1
            return 1.0;
        if(base-0.0<0.0000001 && base-0.0>-0.0000001)//如果base为0.0...返回0.0
            return 0.0;        
        int exp;
        if(exponent<0){//如果乘方数为负数，取负，结果取倒数
            exp = -exponent;
        }
        else
            exp = exponent;     
		
        double result =1.0;
         
        while(exp>0){//循环累乘
            result = result*base;
            exp--;
        }
        if(exponent<0){//循环累除
            result=1.0/result;
        }       
        return result;            
    }
    };

#### 解答（C++）高效解法，O(logn)

    class Solution {
    public:
    double Power(double base, int exponent) {
        if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        int exp,flag=0;
        if(exponent<0){//如果乘方数为负数，取负，结果取倒数
            exp = -exponent;
            flag=1;
        }
        else
            exp = exponent;
        
        double result=Power(base,exp>>1);//右移，相当于除以2
        result *=result;
        if(exponent & 0x1 ==1)//取余判断奇数or偶数
            result *= base;
        
        if(flag==1)
            return 1/result;
        return result;         
    }
    };



#### 笔记: ####
>求数值的正数次方，思路不难，关键要考虑到几个特殊情况，0的0次方无意义，任何数的0次方都为1，指数为负数时要记得取倒数等。（详见代码及注释）
>
>第二种高效解法并没想到...边看边理解。用右移运算代替除以2，用位与运算代替求余来判断奇偶。
>假如输入的exponent为32，我们的目标是求出一个数的32次方，那么只要求出整数的16次方然后再取平方就行了，而16次方就是8次方的基础上取平方，依此类推...32次方只需要做5次乘法，显然提高了效率。  
>用公式表示：a(n)表示a的n次方  
>①当n为偶数时：a(n)=a(n/2)*a(n/2)  
>②当n为奇数时：a(n)=a((n-1)/2)*a((n-1)/2)*a
>然后类似于斐波那契数列，递归解决。
>
>**小插曲，本地测试的时候犯了个小错误，如下：**
>
>![](http://i.imgur.com/vxPQyxa.png)  
>
>我把base定义成int型了，结果输出的时候，显示base是0.000000，但是结果却是正确的。无意中发现这个问题，于是跟好基友[Zack.J.Dsg刷题小王子](http://blog.csdn.net/zkj126521)请教了一下。
>解释如下：  
>我输入的base=2，64位double分为3段（下段解释），2的二进制0000.....00010，00000........010的解释成double型就是一个很小的小数值可能是0.00000000000000000000000××，后面显示不出来了，但是参与运算是又把int型提升到double型了。
>
>浮点标准用V=（-1）^s * M * 2 ^ E. M是小数部分的结果，E是指数部分的结果。根据指数部分（k代替）分为3种情况，k全为0，那个对应的十进制结果（e表示）就是0，E = 1 - Bias。Bias = 2 ^ (k - 1) - 1 double型就是1023  
>所以E=-1022，2^E=**************（自己算好了）
>小数部分（f表示）00000.....10。f=0.0000000....10（二进制小数），然后算出十进制就是M，就可以得到V的结果了
>k全为1可以提供很大的数，k不全为0和不全为1是另一种情况，就不详细讲了。

#### AC ####
![](http://i.imgur.com/r9qCsCb.png)

