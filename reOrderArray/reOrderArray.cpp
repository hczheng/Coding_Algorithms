#include <stdio.h>
#include <iostream>
#include<vector>
using namespace std;

//g++ -std=c++11 reOrderArray.cpp -o reOrderArray
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> res;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] & 0x1)
				res.push_back(array[i]);
		}
		for (int i = 0; i < array.size(); i++)
		{
			if ((array[i] & 0x1) == 0)
				res.push_back(array[i]);
		}
		array = res;
	}
};
int main(int argc, char* argv[])
{
	Solution so;
	vector <int> array = {5,2,3, 1, 2, 8, 9 };
	for (int i = 0; i < array.size();i++)
		printf("%d  ", array[i]);
	printf("\n");
	so.reOrderArray(array);
	for (int i = 0; i < array.size(); i++)
		printf("%d  ", array[i]);
	getchar();
}

