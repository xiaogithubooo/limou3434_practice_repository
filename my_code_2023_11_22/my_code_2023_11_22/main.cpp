#include <iostream>  
using namespace std;
int main(void)
{
    const int a = 10;
    int* p = (int*)(&a);
    *p = 20;
    cout << "a = " << a << ", *p = " << *p << endl;
    return 0;
}

//int getMaxComSubStr(const string& str1, const string& str2)
//{
//	int len1 = str1.size();
//	int len2 = str2.size();
//	vector<vector<int>> msc(len1, vector<int>(len2, 0));
//	int max_len = 0;
//	for (int i = 0; i < len1; i++)
//	{
//		for (int j = 0; j < len2; j++)
//		{
//			if (str1[i] == str2[j])
//			{
//				if (i >= 1 && j >= 1)
//				{
//					msc[i][j] = msc[i - 1][j - 1] + 1;
//				}
//				else
//				{
//					msc[i][j] = 1;
//				}
//				max_len = max(max_len, msc[i][j]);
//			}
//		}
//	}
//	return max_len;
//}
//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		int max_len = getMaxComSubStr(str1, str2);
//		cout << max_len;
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	do
//	{
//		printf("%d\n", i);
//		++i;
//	} while (i < 10);//��ִ��һ������Ĵ��룬Ȼ��Ž����жϣ��� while ���ж�������˳���෴
//
//	return 0;
//}//�ͻ��ӡ�� 0~9 �� 10 ������

//int main()
//{
//	int number = 10;
//	while (number < 20)//ֻҪ number С�� 20 �ͽ���ѭ��
//	{
//		printf("���\n");
//	}
//	return 0;
//}
////����Ǵ�ӡ�����޵ġ���á�����էһ����Щ���ˣ�
////����VS�п���ֱ�ӹرտ���̨�Ϳ��Խ������ѭ����
////���߰��¿�ݼ� [ctrl + c]����ͬϵͳ�Ŀ�ݼ����ܲ�̫һ����

//#include <stdio.h>
//int main()
//{
//	int a = 1;
//	if (a == 1)//��� a ���� 1 �ͻ�ִ�д��� 1������ִ�д��� 2
//	{
//		printf("haha\n");//���� 1
//	}
//	else
//	{
//		printf("hehe\n");//���� 2
//	}
//	return 0;
//}//���ֻ��ӡ�� haha�������ӡ hehe���������޸�һ�±�����ֵ����������

//#include <stdio.h>
//int main()
//{
//	printf("%c\n", 88);			//��� X��ʹ�� 88 ���ʮ��������ӡ�ַ�
//	printf("%c\n", '\130');		//��� X������ \130 �ǰ˽��Ƶ�����
//	printf("%c\n", '\x58');		//��� X������ \x58 ��ʮ�����Ƶ�����
//
//	//ת���ַ�Ҳ���ַ���������� \ ���ſ���һ������
//	return 0;
//}


////#define ����ı�ʶ���������ڴ����������У�
////�������� MAX �ĵط����ȱ�ȫ���滻�� 100��
////ע�⣬�곣���Ķ��壬��ĩβ���ӷֺţ����׳� bug
//#define MAX 100
//
////���´�����һ��ö�ٳ�����ֻ��ö�ٳ���ɢ�������������������Ͳ��ܱ�ö�ٳ���
//enum Sex
//{
//	MALE,		//Ĭ��ֵΪ0
//	FEMALE,		//Ĭ��ֵΪ1
//	SECRET		//Ĭ��ֵΪ2
//};
////���ǽ� MALE �趨Ϊ 5�����������θ�Ϊ 6��7��
////��С���ʼ��ֵ�������ǡ��޸�ֵ���������ǳ��������Ǳ���
//
//int main()
//{
//	//1.���泣��
//	//����ֻ��д�����泣��������˼�塰�������ϾͿ��Կ�������
//	100;	//���ͳ���
//	'W';	//�ַ�����
//	3.14;	//���㳣��
//
//	//2.const ������
//	int number_1 = 1;		//������ 1 Ҳ�ǳ��������� a �Ǳ���
//	number_1 = 20;			//number_1 �Ǳ�����ֵ���Դ� 10 ��� 20
//	const int number_2 = 10;	//const ���εĳ�����
//	//number_2 = 20;			//ʹ���� const �ؼ��ֺ�����ͻᱨ�������� number_2 �޷����޸�
//
//	//3.�곣��
//	int n = MAX;	//MAX �������ڴ�������ǰ���滻�� 100����˱��� n �ᱻ��ʼ��Ϊ 100
//
//	//4.ö�ٳ���
//	enum Sex s = FEMALE;	//���� s ��ֵ����ʼ��Ϊ 1
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string str1, str2;
//	cin >> str1 >> str2;
//
//	for (int i = 0; i < str2.size(); i++)
//	{
//		for (int j = str2.size(); j > 0; j--)
//		{
//			string sub = str2.substr(i, i);
//		}
//	}
//
//	return 0;
//}
//
////int main()
////{
////	string str;
////	cin >> str;
////	reverse(str.begin(), str.end());
////	cout << str;
////	return 0;
////}