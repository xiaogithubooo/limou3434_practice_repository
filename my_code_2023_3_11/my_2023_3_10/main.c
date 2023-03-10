#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int x = 5;//定义并且初始化x为5
	x += x *= x + 1;
	//可以理解为(x += (x *= (x + 1))
	//等价于(x += (x *= (6))
	//等价于(x += (x=5*6))
	//等价于(x += (x=30))
	//等价于(x = 30 + 30)
	//等价于x = 60

	printf("%d\n", x);
	if (x > 10)
		printf("%d\n", ++x);
	else
		printf("%d\n", x++);
	return 0;
}
int main()
{
	int a = 3, b = -4, c = 5;
	int x = !(a > b) + (b == c) || (a + b) && (b - c);
	//等价于:!(1)+(0) || (-1) && (-9),注意再C语言中非0为正,因此负数也是真
	//等价于:0||1
	//等价于:1
	printf("%d\n", x);
	return 0;
}
int main()
{
	int x = 11, y = 10;
	int z = (x - ++y ? 10 : 11 >= y ? 'a' : 'z');//条件运算符只高于赋值类运算符，这个里面++优先级是最高的
	//先++，y = 11,等价于(x - ++y) ? (10) : (11 >= y ? 'a' : 'z'))
	//(x - 11) ? (10) : (1 ? 'a' : 'z')
	//(x - 11) ? (10) : ('a')//注意a的ascii的值为97
	//(11 - 11) ? (10) : ('a')
	//(0) ? (10) : ('a')
	//因此选择a，得到97
	printf("%d\n", z);
	return 0;
}
int main()
{
	//本题没有说明变量的类型
	int x = 43;
	char ch = 'A';//注意'A'的ascii的值65
	int y = 0;
	int z = (x >= y && ch < 'B' && !y);
	//(x >= y && ch < 'B' && !y
	//&&的优先级低于比较运算符
	//等价于(  (x >= y) && (ch < 'B') && (!y)  )
	//等价于(  (43 >= 0) && (65 < 66) && (!0)  )
	//等价于(  (1) && (1) && (1)  )
	//等价于z = 1
	printf("%d", z);
	return 0;
}