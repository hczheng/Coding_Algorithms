## minNumberInRotateArray #

#### 题目六: ####
> 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

#### 解答（C++）: ####
    

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
		int indexMid = index1;//假如第一个值即为最小值，不会进入下面循环了，直接返回
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

#### 解答（Python）: ####

    class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if len(rotateArray) == 0:
            return 0
        
        ret = rotateArray[0]
        if len(rotateArray) == 1:
            return ret
        for i in range(1,len(rotateArray)):
            now = rotateArray[i]
            if now < ret:
                ret = now
                break
        return ret


#### 笔记: ####

> 这道题要答得很好还是有点难得，最简单的思路就是遍历找最小值了，找到了就返回，见Python代码。这种方法效率比较低，时间复杂度为O(n)，因此这道题的关键在于提高效率。  
> 
> 观察旋转数组的特点，其实可以分为两个递增数组，第二个数组的第一个元素即为最小值（咱叔还没有考虑特殊情况）。为了提高效率，采用二分查找的思想，时间复杂度提升到O(logn)。具体地，用两个指针p1、p2分别指向数组的开始与末尾，然后和二分查找一样取一个中间位置的值mid，分别与p1、p2所指的值比较，如果mid>=p1说明最小值还在mid的后面，然后把p1指向mid，如果mid<=p2说明最小值在mid前面或者就是它本身,然后把p2指向mid。如此循环，p1最终会指向第一个子序列的末尾，p2指向第二个子序列的开头，此时p2所在位置就是我们要找的最小值。每次查找，范围都会缩小一般，所以效率提高。
> 
>以上方法可以解决一般情况，但是题目没有说数组中的元素没有重复值，因此还要考虑这种情况。比如{1,0,1，1,1}、{1,1,1,0,1}，它们的原始数组都为{0,1,1,1,1}。但是按照我们上面的思路，会发现p1、P2和mid的值都为1，这个时候就无法判断最小值是在mid之前还是之后了。所以针对这种特殊情况，还是要采用循环遍历解决。
>
>还有数组已经排好序的情况，查找过程就不会进入循环，直接返回第一个值，详细见代码注释。


#### AC ####
![](http://i.imgur.com/7RTBeeb.png)

