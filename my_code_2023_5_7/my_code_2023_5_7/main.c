#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = -1;
	//1000 0000|0000 0000|0000 0000|0000 0001（原）
	//1111 1111|1111 1111|1111 1111|1111 1110（反）
	//1111 1111|1111 1111|1111 1111|1111 1111（补）
	int j = -3;
	//1000 0000|0000 0000|0000 0000|0000 0011（原）
	//1111 1111|1111 1111|1111 1111|1111 1100（反）
	//1111 1111|1111 1111|1111 1111|1111 1101（补）
	int z = i ^ j;
	//1111 1111|1111 1111|1111 1111|1111 1111（补）
	//1111 1111|1111 1111|1111 1111|1111 1101（补）
	//											^
	//-------------------------------------------
	//0000 0000|0000 0000|0000 0000|0000 0010（a^b后，补，检测到是正数）
	//0000 0000|0000 0000|0000 0000|0000 0010（反）
	//0000 0000|0000 0000|0000 0000|0000 0010（原）
	printf("%d\n", z);
	printf("%d\n", ~(i));

	int a = -2;
	//1000 0000|0000 0000|0000 0000|0000 0010（原）
	//1111 1111|1111 1111|1111 1111|1111 1101（反）
	//1111 1111|1111 1111|1111 1111|1111 1110（补）
	int b = 3;
	//0000 0000|0000 0000|0000 0000|0000 0011（原）
	//0000 0000|0000 0000|0000 0000|0000 0011（反）
	//0000 0000|0000 0000|0000 0000|0000 0011（补）
	int c = a | b;
	//1111 1111|1111 1111|1111 1111|1111 1110（补）
	//0000 0000|0000 0000|0000 0000|0000 0011（补）
	//											|
	//-------------------------------------------
	//1111 1111|1111 1111|1111 1111|1111 1111（a|b后，补，检测到是负数）
	//1111 1111|1111 1111|1111 1111|1111 1110（反）
	//1000 0000|0000 0000|0000 0000|0000 0001（原）== -1
	printf("%d\n", c);
	return 0;
}

//int main()
//{
//	printf("%zd\n", sizeof("abcd"));
//	printf("%zd\n", sizeof("ab"));
//	printf("%zd\n", sizeof(""));
//	return 0;
//}

//char ch = '1';//这里实际上一直在发生一个现象，就是截断4个字节数据写到1个字节的数据，因为在C99标准规定，'a'叫做整型字符常量，被看作是int类型
//int main()
//{
//	const char* lable = "|/-\\";
//	int index = 0;
//	while (1)
//	{
//		index %= 4;
//		printf("[%c]\r", lable[index]);
//		index++;
//		Sleep(20);
//	}
//	return 0;
//}