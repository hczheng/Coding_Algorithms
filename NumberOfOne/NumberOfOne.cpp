//g++ -std=c++11 Fibonacci.cpp -o Fibonacci  //about compile
// test.cpp : 定义控制台应用程序的入口点。
#include <stdio.h>
#include <iostream>
using namespace std;

//解答（C++）常规解法:32位整数需要循环32次 ####

    class Solution {
    public:
     int  NumberOf1(int n) {
		 int count=0;
		 unsigned int flag=1;
		 while(flag)
		 {
			if(n & flag)//判断n的最低位是不是1->次低位是不是1->....
				count++;
			flag=flag<<1;//左移一位，1->2->4...
		 }
		 return count;        
     }
    };
	
//解答（C++）牛X解法: 整数中有几个1就循环几次####
/*     class Solution {
    public:
     int  NumberOf1(int n) {
		 int count=0;
		 while(n)
		 {
			++count;
			n=(n-1)&n;//n与n-1位与运算，相当于把n最右边的1变成0,之后的全为0.如：1100&1011->1000 
		 }
		 return count;        
     }
    }; */
int main(int argc, char* argv[])
{
	Solution so;
	int a;
	cout<<"请输入n:"<<endl;
	cin>>a;
	printf("f(%d)=%d", a,so.NumberOf1(a));
	getchar();
}

