//g++ -std=c++11 minNumberInRotateArray.cpp -o minNumberInRotateArray  //about compile
// test.cpp : 定义控制台应用程序的入口点。
#include <stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
	int MinInOrder(vector<int> num,int index1,int index2)
	{
		int res = num[index1];
		for (int i = index1 + 1; i < index2;++i)//循环遍历，找到最小值
		{
			if (res > num[i])
				res = num[i]; break;
		}
		return res;
	}
	int minNumberInRotateArray(vector<int> rotateArray) {
		int len = rotateArray.size();
		if (len <= 0)
			return 0;
		int index1 = 0;
		int index2 = len - 1;
		int indexMid = index1;//假如第一个值即为最小值，直接返回
		while(rotateArray[index1]>=rotateArray[index2])
		{
			if (index2 - index1 == 1)
			{
				//如果两个指针的距离是1，说明第一个指针已经指向第一个递增序列的末尾，
				//而第二个指针已经指向第二个递增子数组的开头。
				indexMid = index2;//第二个递增数组的第一个数字即为最小值
				break;
			}
			indexMid = (index1 + index2) / 2;
			//如果下标为index1、index2和indexMid指向的三个数字都相等
			//那么只能进行顺序查找
			if (rotateArray[index1] == rotateArray[index2]&& rotateArray[index1]== rotateArray[indexMid])
			{
				return MinInOrder(rotateArray,index1,index2);
			}
			if (rotateArray[index1] <= rotateArray[indexMid])
				index1 = indexMid;
			else if (rotateArray[index2] >= rotateArray[indexMid])
				index2 = indexMid;
		}
		return rotateArray[indexMid];
	}
};
int main(int argc, char* argv[])
{
	Solution so;
	// 典型输入，单调升序的数组的一个旋转
	vector<int> array1= { 1, 0, 1, 1, 1 };
	printf("min=0\nmin=%d", so.minNumberInRotateArray(array1));
	getchar();
}

