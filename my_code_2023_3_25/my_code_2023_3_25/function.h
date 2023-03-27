#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_DATA 100

#define DEFAULT_SZ 3//Ĭ������3����ע�����������ӵĺ�<limou>
#define INC_SZ 2//ÿ�η���������ע�����������ӵĺ�<limou>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

//1.��ʾһ�����ˡ��ṹ��
typedef struct PeoInfo
{
    char name[MAX_NAME];//����
    int age;//����
    char sex[MAX_SEX];//�Ա�
    char tele[MAX_TELE];//�绰
    char addr[MAX_ADDR];//��ַ
}PeoInfo;

//2.��ʾһ�ݡ�ͨѶ¼���ṹ��
/*typedef struct Contact<limou>
{
    PeoInfo data[MAX_DATA];//��š��ˡ������ݣ�����ע�⵽������ʹ�ú����ṹ���ڵ�����
    int sz;//ʵʱ��¼ͨѶ¼����������
}Contact, *pContact;//����д��*/
typedef struct Contact
{
    PeoInfo* data;//ָ��̬�ڴ��ָ��
    int sz;//ʵʱ��¼ͨѶ¼����������
    int capacity;//����ͨѶ¼��ǰ����
}Contact, * pContact;//����д��

//3.��������
//3.1.1.��ʼ������
void Init_Contact(Contact* pcon);//��������ĳ�ʼ�����޸��ˣ���ע��<limou>
//3.1.2.���ٺ���
void Destroy_Contact(Contact* pcon);//����������¼ӵģ���ע��<limou>
//3.2.����ָ����ϵ�˺���
void Add_Contact(Contact* pcon);//��������ĳ�ʼ�����޸��ˣ���ע��<limou>
//3.3.��ʾ��ϵ����Ϣ
void Show_Contact(const Contact* pcon);
//3.4.ɾ����ϵ��
void Dle_Contact(pContact pcon);
//3.5.������ϵ��
void Search_Contact(const pContact pcon);
//3.6.�޸���ϵ��
void Modify_Contact(Contact* pcon);
//3.7.����Ԫ��
void Sort_Contact(Contact* pcon);