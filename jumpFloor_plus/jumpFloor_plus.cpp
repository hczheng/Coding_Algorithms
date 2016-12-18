//g++ -std=c++11 Fibonacci.cpp -o Fibonacci  //about compile
// test.cpp : 定义控制台应用程序的入口点。
#include <stdio.h>
#include <iostream>
using namespace std;

//解答（C++）牛X解...: #

    class Solution {
    public:
    int jumpFloorII(int number) {
        return  1<<--number;
    }
    };

/*//解答（C++）递归解: ####

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
//解答（C++）迭代循环解: ####

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
*/
int main(int argc, char* argv[])
{
	Solution so;
	int a;
	cout<<"请输入台阶数的参数."<<endl;
	cin>>a;
	printf("f(%d)=%d", a,so.jumpFloorII(a));
	getchar();
}

