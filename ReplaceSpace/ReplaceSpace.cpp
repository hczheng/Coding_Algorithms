#include <stdio.h>
#include <string.h>  
using namespace std;

//请实现一个函数，将一个字符串中的空格替换成“ % 20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We % 20Are % 20Happy。

void replaceSpace(char *str, int length) {
	if (str == nullptr && length <= 0)//字符串为空直接返回
		return;
	//str_len为字符串原始长度
	int str_len = 0;
	int space_num = 0;
	int i = 0;
	while (str[i] != '\0')//字符串以'\0'作为结尾符号
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
	while (p1 >= 0 && p2 > p1)//从后往前遍历
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
// ====================测试代码====================
void Test(const char *testName,char *str, int length,const char *expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	replaceSpace(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}
// 空格在句子中间
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
	const int length = 100;

	char str[length] = "   ";
	Test("Test9", str, length, "%20%20%20");
}
int main(int argc, char* argv[])
{
	Test1();
	Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
	return 0;
}




