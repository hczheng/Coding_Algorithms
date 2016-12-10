## reConstructBinaryTree #

#### 题目四: ####
> 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
> 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
> 例如输入前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，
> 则重建二叉树并返回。

#### 解答（C++）: ####
    

    class Solution {
    
    public:   
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if (pre.empty() || vin.empty())
			return NULL;
		return Construct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
	TreeNode* Construct//构建递归函数划分左右子树
		(
			vector<int> pre, int pre_start, int pre_end, //前序遍历序列，序列开始位置，序列结束位置
			vector<int> vin, int vin_start, int vin_end  //中序遍历序列，序列开始位置，序列结束位置
			)
	{
		TreeNode* root = new TreeNode(pre[pre_start]);//前序遍历的第一个元素为当前树的根结点
		if (pre_start == pre_end)//如果当前前序遍历序列只剩下一个结点
		{
			if (vin_start == vin_end && pre[pre_start] == vin[vin_start])//如果中序遍历序列也只有一个结点并且与前序相同
				return root;//返回当前唯一结点
			//else//如果当前前序遍历序列只剩一个结点，但是中序遍历序列还有多个结点或者与前序遍历序列不同
				//throw std::exception("Invalid input.");//说明输入的前序遍历序列跟中序遍历序列不匹配，输出异常
		}
		int i = vin_start;//在中序遍历虚列中找到根结点的位置
		while (i < vin_end && vin[i] != root->val)
			++i;
		int leftlen = i - vin_start;//左子树长度
		if (leftlen > 0)
			root->left = Construct(pre, pre_start + 1, pre_start + leftlen, vin, vin_start, i - 1);
		if (leftlen < pre_end - pre_start)
			root->right = Construct(pre, pre_start + leftlen + 1, pre_end, vin, i + 1, vin_end);

		return root;
	}
    
};

   

#### 笔记: ####

> 前序遍历第一个数字就是根结点的值，然后根据中序遍历序列中根结点的位置就可以划分左右子树。然后再在划分后左右子树上递归地调用划分函数，去分别构建它们的左右子树，直至左右子树都不可再分为止。
> 
> 实现该划分方法后还要考虑各种特殊情况，比如二叉树的根结点为空、输入的前序遍历序列与中序遍历序列不匹配等，考虑的越周到越好。
> 
> 本地测试用例有点麻烦，需要自己构建二叉树结构以及相关的操作方法。
> 
> 这题废了挺多时间，Python就不写了。

#### AC ####

![](http://i.imgur.com/or7W4Un.png)
