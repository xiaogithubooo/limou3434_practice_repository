#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    struct S1
    {
        char c1;//char��СΪ1����Ĭ�϶�����8�ȣ��ó�Ա�Ķ�������1
        char c2;//char��СΪ1����Ĭ�϶�����8�ȣ��ó�Ա�Ķ�������1
        int i;//���ʹ�СΪ4����Ĭ�϶�����8�ȣ��ó�Ա�Ķ�������4
    };//����������4
    printf("%d\n", sizeof(struct S1));//���Ϊ8
    struct S2
    {
        char c1;
        int i;
        char c2;
    };
    printf("%d\n", sizeof(struct S2));
	return 0;
}
int main()
{
    //Ƕ�׽ṹ��
    struct S3
    {
        double d;//��СΪ8����Ĭ�϶�����8��ȣ��ó�Ա�ĳ�Ա������Ϊ8
        char c;//��СΪ1����Ĭ�϶�����8��ȣ��ó�Ա�ĳ�Ա������Ϊ1
        int i;//��СΪ4����Ĭ�϶�����8��ȣ��ó�Ա�ĳ�Ա������Ϊ4
    };//����Ա������Ϊ8���ṹ����ܴ�С������8�ı���
    printf("%d\n", sizeof(struct S3));//���16

    struct S4
    {
        char c1;//��СΪ1����Ĭ�϶�����8��ȣ��ó�Ա�ĳ�Ա������Ϊ1
        struct S3 s3;//��СΪ16����Ĭ�϶�����8��ȣ��ó�Ա�ĳ�Ա������Ϊ8
        double d;//��СΪ8����Ĭ�϶�����8��ȣ��ó�Ա�ĳ�Ա������Ϊ8
    };//����Ա������Ϊ8���ṹ����ܴ�С������8�ı���
    printf("%d\n", sizeof(struct S4));//ֵΪ32
	return 0;
}
#pragma pack(8)//��Ĭ�϶���������Ϊ8
struct S1
{
    char c1;//char��СΪ1����Ĭ�϶�����8�ȣ��ó�Ա�ĳ�Ա��������1
    char c2;//char��СΪ1����Ĭ�϶�����8�ȣ��ó�Ա�ĳ�Ա��������1
    int i;//���ʹ�СΪ4����Ĭ�϶�����8�ȣ��ó�Ա�ĳ�Ա��������4
};//����Ա��������4
int main()
{
    printf("%d\n", sizeof(struct S1));//���Ϊ8
}
#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��
#pragma pack(1)//����Ĭ�϶�����Ϊ1
struct S2
{
    char c1;//��СΪ1�������ú��Ĭ�϶�����1�ȣ��ó�Ա�ĳ�Ա��������1
    int i;//��СΪ4�������ú��Ĭ�϶�����1�ȣ��ó�Ա�ĳ�Ա��������1
    char c2;//��СΪ1�������ú��Ĭ�϶�����1�ȣ��ó�Ա�ĳ�Ա������Ϊ1
};//����Ա��������1���ṹ���С������1�ı���
#pragma pack()//ȡ�����õ�Ĭ�϶���������ԭΪĬ��

int main()
{
    printf("%d\n", sizeof(struct S2));//���Ϊ5
    return 0;
}