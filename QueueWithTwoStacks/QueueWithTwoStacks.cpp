//g++ -std=c++11 QueueWithTwoStacks.cpp -o QueueWithTwoStacks  //about compile
#include <stack>
#include <exception>
#include <stdio.h>
using namespace std;

//QueueWithTwoStacks
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
class Solution
{
public:
	void push(int node) {
		stack1.push(node);//压入第一个栈
	}

	int pop() {
		if (stack2.empty()) {//如果stack2为空,这里保证了只有stack2完全为空的时候才会继续讲将stack1中元素压入到stack2
			while (!stack1.empty()) {
				int temp = stack1.top();//将stack1栈顶元素保存并压入stack2
				stack2.push(temp);
				stack1.pop();//删除stack1当前栈顶元素
			}
		}
		if (stack2.empty()) {
			printf("queue is empty");
			return -1;
		}
		else{
			int res = stack2.top();//去当前stack2栈顶元素作为pop输出
			stack2.pop();//删除stack2栈顶元素，即新队列的top元素
			return res;
		}

	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
int main(int argc, char* argv[])
{
	Solution so;
	so.push(1);
	so.push(2);
	printf("1:%d\n", so.pop());
	so.push(3);
	printf("2:%d\n", so.pop());
	so.push(4);
	printf("3:%d\n", so.pop());
	printf("4:%d\n", so.pop());
	printf("5:%d\n", so.pop());
	getchar();
}

