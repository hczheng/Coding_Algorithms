//g++ -std=c++11 Fibonacci.cpp -o Fibonacci  //about compile
// test.cpp : 定义控制台应用程序的入口点。
#include <stdio.h>
#include <iostream>
using namespace std;

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
int main(int argc, char* argv[])
{
	Solution so;
	int a;
	cout<<"请输入台阶数."<<endl;
	cin>>a;
	printf("f(%d)=%d", a,so.jumpFloor(a));
	getchar();
}

