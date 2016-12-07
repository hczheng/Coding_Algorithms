#include <stdio.h>
#include<vector>
using namespace std;

//g++ -std=c++11 FindInPartiallySortedMatrix.cpp -o test
bool Find(int target, vector<vector<int> > array) {
    int rows, columns, x, y;
	rows = array.size();//行数
	columns = array[0].size();//列数
	x = rows - 1; y = 0;//坐标定在左下角
	while (x >=0 && y <=columns-1)
	{
		if (array[x][y] > target)
		{
			x--;//当前值大于目标值则上移
		}
		else if(array[x][y] < target)
		{
			y++;//当前值小于目标值则下移
		}
		else
		{
			return true;
		}
	}
	return false;     
}
// ====================测试代码====================
void Test(int target, vector<vector<int> > array, const char* testName, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	bool result = Find(target, array);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}
// ====================测试数据Test1====================
//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
	int matrix[][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	vector <   vector <int>   >   array(4);
	for (int i = 0; i <4; i++)
		array[i].resize(4);//设置数组的大小4X4
	for (int i = 0; i<4; i++)
		for (int j = 0; j <4; j++)
			array[i][j] = matrix[i][j];
	Test(7, array, "Test1",true);
}
// ====================测试数据Test2====================
//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	vector <   vector <int>   >   array(4);
	for (int i = 0; i <4; i++)
		array[i].resize(4);//设置数组的大小4X4
	for (int i = 0; i<4; i++)
		for (int j = 0; j <4; j++)
			array[i][j] = matrix[i][j];
    Test(5, array, "Test2", false);
}
// Test3鲁棒性测试，输入空数组
void Test3()
{
	vector < vector <int> > array(3);
    Test(16, array, "Test3", false);
}
int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	return 0;
}