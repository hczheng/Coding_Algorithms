# ReplaceSpace #

#### 题目二: ####
> 请实现一个函数，将一个字符串中的空格替换成“ % 20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We % 20Are % 20Happy。

#### 解答（C++）: ####

    void replaceSpace(char *str, int length) {
	if (str == nullptr && length <= 0)//字符串为空直接返回
		return;
	//str_len为字符串原始长度
	int str_len = 0;
	int space_num = 0;
	int i = 0;
	while (str[i] != '\0')//字符串以'\0'作为结尾符号O(n)
	{
		++str_len;//统计字符串原始长度
		if (str[i] == ' ')
			++space_num;//空格数
		++i;
	}
	//new_len为替换后的字符串长度
	int new_len = str_len + space_num * 2;
	if (new_len > length)
		return;

	int p1 = str_len;//p1指向原始字符串末尾
	int p2 = new_len;//p2指向新字符串末尾
	while (p1 >= 0 && p2 > p1)//从后往前遍历O(n)
	{
		if (str[p1] == ' ')//p1指向的位置为空格
		{
			str[p2--] = '0';//p2填充替换字符串'%20'
			str[p2--] = '2';
			str[p2--] = '%';
		}
		else 
		{
			str[p2--] = str[p1];
		}
		--p1;//继续向前遍历
	}
}





#### 笔记: ####
> 解题关键在于先遍历一遍字符串记录空格数，然后设置两个指针p1、p2分别指向旧字符串与新字符串的末尾，p1从后往前遍历，碰到空格就将p2所在的位置填充%20（依次往前填充）。这样所有的字符串都只需要进行依此复制即可，时间复杂度为O(n)，注意一开始就遍历了一次字符串，因而实际复杂度为O(2n),详细见代码注释即可。
>
> C/C++把常量字符串放到单独的一个内存区域，当几个指针赋值相同的常量字符串时，它们实际上指向相同的内存地址，但是用常量内存初始化数组时就不是这样了。

#### AC ####

![](http://i.imgur.com/PtGsGso.png)

