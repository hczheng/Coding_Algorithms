// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include <iostream> 
#include <stack>
#include <exception>
using namespace std;

//int main(void)
//{
//	int i = 0;
//	cout << "Test execute order: " << endl
//		<< "cout: "
//		<< i << ", " << i++ << ", " << i++ + i++ << endl;
//
//	i = 0;
//	printf("printf(): %d, %d,%d\n", i,i++, i++ + i++);
//
//	getchar();
//}

int main(void)
{
	//int i = 0;
	//cout << "Test execute order: " << endl
	//	<< "cout: "
	//	<< i << ", " << ++i <<", " << ++i + ++i << ", " << ++i + ++i + ++i << endl;//6,6,12,18

	//i = 0;
	//cout << "Test execute order: " << endl
	//	<< "cout: "
	//	<< i << ", " << ++i << ", " << ++i + ++i << ", " << ++i + ++i + i++ << endl;//6,6,12,6

	//int i = 0;
	//printf("printf(): %d, %d,%d,%d\n", i, ++i, ++i + ++i, ++i + ++i + ++i);//6,6,12,18
	int i = 0;
	//printf("printf(): %d,%d,%d,%d,%d,%d\n", i,i++, ++i, ++i + ++i, i++ + i++, ++i + ++i + i++);//7,6,7,14,6
	printf("%d %d %d %d %d\n", i, i++, ++i, ++i + ++i, ++i + ++i + i++);//7 6 7 14 6

	getchar();
}