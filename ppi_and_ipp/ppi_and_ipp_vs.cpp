#include <iostream> 
#include <stack>
#include <exception>
using namespace std;

int main(void)
{
	
	//int i = 0;
	//printf("printf(): %d, %d,%d,%d\n", i, ++i, ++i + ++i, ++i + ++i + ++i);//6,6,12,18
	int i = 0;
	printf("%d %d %d %d %d\n", i, i++, ++i, ++i + ++i, ++i + ++i + i++);//7 6 7 10 6
	getchar();
}

