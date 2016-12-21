//g++ -std=c++11 Fibonacci.cpp -o Fibonacci  //about compile
// test.cpp : 定义控制台应用程序的入口点。
#include <stdio.h>
#include <iostream>
using namespace std;

//解答（C++）常规解法
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
/*//解答（C++）高效解法，O(logn)
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
        
        double result=Power(base,exp>>1);
        result *=result;
        if(exponent & 0x1 ==1)
            result *= base;
        
        if(flag==1)
            return 1/result;
        return result;         
    }
};
*/
int main(int argc, char* argv[])
{
	Solution so;
	int base;
	int exponent;
	cout<<"请输入base:"<<endl;
	cin>>base;
    cout<<"exponent:"<<endl;
	cin>>exponent;
	printf("Power(%f,%d)=%f", base,exponent,so.Power(base,exponent));
	getchar();
}

