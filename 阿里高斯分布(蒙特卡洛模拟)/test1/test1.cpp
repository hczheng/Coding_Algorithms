// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include<vector>
using namespace std;

double generateGaussianNoise(double mu, double sigma)
{
	const double epsilon = std::numeric_limits<double>::min();
	const double two_pi = 2.0*3.14159265358979323846;

	static double z0, z1;
	static bool generate;
	generate = !generate;

	if (!generate)
		return z1 * sigma + mu;

	double u1, u2;
	do
	{
		u1 = rand() * (1.0 / RAND_MAX);
		u2 = rand() * (1.0 / RAND_MAX);
	} while (u1 <= epsilon);

	z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
	z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
	return z0 * sigma + mu;
}

int main()
{
	//vector <double> x = { };
	int t=0, f=0;
	int n = 10;
	for(int i = 0; i < n; i++) {
	double x = generateGaussianNoise(1.5, 0.3);
	double y = generateGaussianNoise(1.0, 0.2);
	double f1 = x*x + y*y - 1;
	f1 = f1*f1;
	double f2 = x*x*y*y;
	if (f1 <= f2) {
		t++;
		printf("x:%f y:%f  是否满足：是\n", x, y);
	}
	else{
		f++;
		printf("x:%f y:%f  是否满足：否\n", x,y);
	}
	}
	printf("true:%d false:%d  概率：%f\n", t, f,t/(n+0.000));
	getchar();
}

