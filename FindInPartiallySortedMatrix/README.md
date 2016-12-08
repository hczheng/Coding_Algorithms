# FindInPartiallySortedMatrix #

#### 题目一: ####
> 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#### 解答（C++）: ####

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


#### 解答（Python）: ####
 
    # -*- coding:utf-8 -*-
    class Solution:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        rows = len(array)
        columns = len(array[0])
        x = rows - 1
        y = 0 
        while x >=0 and y <=columns-1:
            if array[x][y]>target:
                x -= 1
            elif array[x][y]<target:
                y += 1
            else:
                return True
            
        return False   
 
    print Solution().Find(5,[[5,2,1]])



#### 笔记: ####
> 这道题思路倒不难，从左下角开始遍历，如果当前值大于目标值则上移，当前值小于目标值则下移，最坏时间复杂度为O(M+N),M×N的矩阵。另外，加上二分查找理论上应该可以更快一点。
> 
> 本地测试的时候vector数组初始化折腾了一会，之前没接触过vector，以为可以像C-style二维数组那样直接初始化，然而并不行。最后找到这个[教程](http://blog.csdn.net/zsuguangh/article/details/6135529 )，实现了循环初始化，同时学习了vector的优点（）。首先，数组的越界可能会引起程序的崩溃，其次是动态性不好，包括动态改变大小，动态申请。
> 
> 此外，编译遇到一些小问题，在VS2015中编译、运行成功的代码在g++编译时出错，问题出在**nullptr**。解决方法是g++编译命令需要加上C++11版本：`g++ -std=c++11 FindInPartiallySortedMatrix.cpp -o test` 。  
> 还有string Name值作为参数传入方法中（char* Name）会出警告` warning: deprecated conversion from string constant to 'char*' [-Wwrite-strings]`，解决方法将参数改为：`const char* testName`。

#### AC ####

![](http://i.imgur.com/qqGnahL.png)

