#include<vector>
#include <iostream> 
using namespace std;

//g++ -std=c++11 reConstructBinaryTree.cpp -o reConstructBinaryTree  //about compile
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
//假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，则重建二叉树并返回。

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->left = pLeft;
		pParent->right = pRight;
	}
}
void PrintTreeNode(const TreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->val);

		if (pNode->left != nullptr)
			printf("value of its left child is: %d.\n", pNode->left->val);
		else
			printf("left child is nullptr.\n");

		if (pNode->right != nullptr)
			printf("value of its right child is: %d.\n", pNode->right->val);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}

	printf("\n");
}

void PrintTree(const TreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->left != nullptr)
			PrintTree(pRoot->left);

		if (pRoot->right != nullptr)
			PrintTree(pRoot->right);
	}
}
void DestroyTree(TreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		TreeNode* pLeft = pRoot->left;
		TreeNode* pRight = pRoot->right;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}
//class Solution {
//public:
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
			//	throw exception("Invalid input.");//说明输入的前序遍历序列跟中序遍历序列不匹配，输出异常
		}
		int i = vin_start;//在中序遍历虚列中找到根结点的位置
		while (i < vin_end && vin[i] != root->val)
			++i;
		//if (i>vin_end)//遍历到最后也没在中序遍历序列中找着根结点，说明前序遍历序列与中遍历序列不匹配
		//	throw exception("Invalid input.");
		int leftlen = i - vin_start;//左子树长度
		if (leftlen > 0)//构建左子树
			root->left = Construct(pre, pre_start + 1, pre_start + leftlen, vin, vin_start, i - 1);
		if (leftlen < pre_end - pre_start)//构建右子树
			root->right = Construct(pre, pre_start + leftlen + 1, pre_end, vin, i + 1, vin_end);
		return root;
	}

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty())
			return NULL;
		return Construct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}	
//};

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8

void Test()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	try
	{
		TreeNode *output = reConstructBinaryTree(pre, vin);
		PrintTree(output);//输出
		DestroyTree(output);
	}
	catch (exception e)
	{
		printf("Invalid Input.\n");
	}
}
int main(int argc, char* argv[])
{
	Test();
	getchar();
}

