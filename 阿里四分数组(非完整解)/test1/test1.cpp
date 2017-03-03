// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	vector <int> array = { 2,5,1, 1,1,1,4,1,7,3,7};

	int sum=0;//保存四分之一和
	int n = 11;
	int i = 0;
	int j = n - 1;
	int sum_l = 0;//记录左边之和
	int sum_r = 0;//记录右边之和
	while (i <=j) {
		if (sum_l == 0 && sum_r == 0) {
			sum_l = array[i++];
			sum_r = array[j--];
			continue;
		}
		if (sum_l < sum_r){ 
			sum_l += array[i++]; 
		}
		else if (sum_l>sum_r){ 
			sum_r += array[j--]; 
		}
		else {
			if (sum == 0) {//第一次查找结束
				sum = sum_l;
				sum_l = 0;//重新置0
				sum_r = 0;
				i++; j--;//各跳过一个数		
			}
			else {//第二次查找结束
				if (sum == sum_l&&i == j) {
					printf("true");
					break;
				}
				else {
					printf("false");
					break;
				}

			}
		}

	}
	getchar();
}

