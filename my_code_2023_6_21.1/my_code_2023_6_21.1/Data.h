#pragma once
#include <iostream>
using namespace std;
class Data
{
public:
	//1.���캯���������Ĺ��캯����
	Data(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//2.�������캯����ʹ��Ĭ�ϵļ��ɣ�
	
	//3.��ֵ��������غ���
	//3.1.д��1�������ǿ��ԣ����ǲ�֧��������ֵ��
	//void operator=(const Data& d)
	//{
	//	//thisָ����ǡ�=��ǰ��Ĳ�������d�ǡ�=������Ĳ�����
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
	//3.2.д��2������������ֵ��
	Data& operator=(const Data& d)
	{
		//thisָ����ǡ�=��ǰ��Ĳ�������d�ǡ�=������Ĳ�����
		if(this != &d)//�õ�ֵַ�жϱȽϺ�
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//4.�Ƚ���������غ�����ֻ��Ҫд��>��==���͡�<��==���ļ��ɣ����Բ��ϸ��õ������Ƚ���������غ���
	bool operator==(const Data& d);
	bool operator!=(const Data& d);
	bool operator>(const Data& d);
	bool operator>=(const Data& d);
	bool operator<(const Data& d);
	bool operator<=(const Data& d);

	//5.�ӷ���ӷ���ֵ��������غ���
	Data& operator+=(int day);
	Data operator+(int day);
	//Data& operator++(int day);//ֱ����ô���ء�++����û�а취����ǰ�úͺ��õģ����C++�ṩ����������
	Data& operator++();//ǰ��++
	Data operator++(int);//����++����������һ��int������ǰ���ǰ��++���ɺ������ؽ�������

	//6.�����������ֵ��������غ���
	Data& operator-=(int day);
	Data operator-(int day);
	//Data& operator--(int day);//ֱ����ô���ء�--����û�а취����ǰ�úͺ��õģ����C++�ṩ����������
	Data& operator--();
	Data operator--(int);
	int operator-(const Data& d);
public: 
	//7.��ӡ����
	void Print(void)
	{
		cout << _year << ":" << _month << ":" << _day << endl;
	}

	//8.��ȡĳ��ĳ�µ���������
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//��̬��������Ч�ʣ������ظ����ٿռ���ʹ��
		int day = days[month];
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}
		return day;
	}
private:
	int _year;
	int _month;
	int _day;
};