# FindInPartiallySortedMatrix #

## 写在前面： ##
2016.12.07开始刷题模式，掌握基础算法的同时学习巩固C++和Python编程基础,每道算法题我会尽量用两种语言去实现。目前是从剑指offer（牛客网）开始，欢迎同道中人共同学习，批评指正。本地测试代码和笔记会更新在我的github上[Coding_Algorithms](https://github.com/zhenghuangcheng/Coding_Algorithms)。
#### 题目一: ####
> 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#### 解答: ####

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

#### 笔记: ####
> 这道题思路倒不难，从左下角开始遍历，如果当前值大于目标值则上移，当前值小于目标值则下移，最坏时间复杂度为O(M+N),M×N的矩阵。
> 
> 本地测试的时候vector数组初始化折腾了一会，之前没接触过vector，以为可以像C-style二维数组那样直接初始化，然而并不行。最后找到这个[教程](http://blog.csdn.net/zsuguangh/article/details/6135529 )，实现了循环初始化，同时学习了vector的优点（）。首先，数组的越界可能会引起程序的崩溃，其次是动态性不好，包括动态改变大小，动态申请。
> 
> 此外，编译遇到一些小问题，在VS2015中编译、运行成功的代码在g++编译时出错，问题出在**nullptr**。解决方法是g++编译命令需要加上C++11版本：`g++ -std=c++11 FindInPartiallySortedMatrix.cpp -o test` 。  
> 还有string Name值作为参数传入方法中（char* Name）会出警告` warning: deprecated conversion from string constant to 'char*' [-Wwrite-strings]`，解决方法将参数改为：`const char* testName`。
