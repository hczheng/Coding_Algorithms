## QueueWithTwoStacks #

#### 题目五: ####
> 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

#### 解答（C++）: ####
    

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
		if (stack2.empty()) {//经过上面的判断，如果stack2还为空说明队列中已经没有元素了。
			printf("queue is empty");
			return -1;
		}
		else{
			int res = stack2.top();//去当前stack2栈顶元素作为pop输出
			stack2.pop();//删除stack2栈顶元素，即新队列的top元素
			return res;
		}

	}

#### 解答（Python）: ####

    class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    def push(self, node):
        # write code here
        self.stack1.append(node)
    def pop(self):
        # return xx
        if self.stack2 == []:
            while self.stack1:
                a = self.stack1.pop()
                self.stack2.append(a)
		return self.stack2.pop()


#### 笔记: ####

> 这题相对比较简单，知道栈先进后出，队列先进先出就差不多了。可以在纸上画一下，把抽象问题形象化。
> 
> stack1\stack2的出栈入栈顺序需要考虑周到，见代码注释。


#### AC ####
![](http://i.imgur.com/9wePtCU.png)

