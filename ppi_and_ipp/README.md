## ppi and ipp 2016.12.15

#### i++和++i的问题: ####
>i++和++i的问题

#### part1:i++ ####
    int main(void)
    {
	int i = 0;
	cout << "Test execute order: " << endl
		<< "cout: "
		<< i << ", " << i++ << ", " << i++ + i++ << endl;

	i = 0;
	printf("printf(): %d, %d,%d\n", i,i++, i++ + i++);//3,2,0

    //output:
 	/*Test execute order:
    cout: 3, 2, 0
    printf(): 3, 2,0 */
	getchar();
    }

#### part2:++i ####
    int main(void)
    {
	int i = 0;
	cout << "Test execute order: " << endl
		<< "cout: "
		<< i << ", " << ++i <<", " << ++i + ++i << endl;

	i = 0;
	printf("printf(): %d, %d,%d\n", i, ++i, ++i + ++i);//3,3,6

    //output:
    /*Test execute order:
    cout: 3, 3, 6
    printf(): 3, 3,6*/
	getchar();
    }


#### part3:纯printf()  难难难 ####


    int main(void)
    {
    	int i = 0;
    	printf("%d %d %d %d %d\n", i, i++, ++i, ++i + ++i, ++i + ++i + i++);//7 6 7 14 6
    
    	getchar();
    }

#### 笔记: ####

>这个问题还没怎么搞明白，主要是part3，在VS编译环境下输出是7 6 7 14 6，而在g++下编译结果是 7 6 7 10 6。下午跟同学看了汇编代码还是没怎么整明白，路过大神求指导！下图是g++反编译出来的。
>
>![](http://i.imgur.com/EmcvZ1Z.jpg)
>
>来自好基友jack.j的手解汇编：[POFEI_IS_SHIT的博客](http://blog.csdn.net/zkj126521)
>
>![](http://i.imgur.com/p95J6H0.jpg)

> 之前只知道i++是先运算在赋值，++i是先赋值再运算，昨天学妹问了个问题把我给难住了(得好好补基础啊！)...如上面代码中所示，当i++与++i在同一表达式里进行运算的时候，各种情况各种输出结果。

>下面几点是根据网友别总结的，没怎么看懂啊！
>
> 编译器决定对函数实参的表达式求解顺序，从右到左(看printf()的输出)。 
> 
> 只要出现i++，就会先对i作相关运算,然后再增1.
> 
> 因为C语言函数参数入栈顺序是从右到左的，所以计算顺序是从右到左开始计算的；对于a++的结果，是有ebp寻址函数栈空间来记录中间结果的，在最后给printf压栈的时候，再从栈中把中间结果取出来；而对于++a的结果，则直接压寄存器变量，寄存器经过了所有的自增操作。

