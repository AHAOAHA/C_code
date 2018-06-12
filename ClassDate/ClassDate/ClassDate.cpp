#include"ClassDate.h"
//��������(�ӷ�����)
Date& Date::AdjustDateAdd(Date& d)
{
	//������������
	if (d._day <= 28 || (d._month != 2 && d._day <= 30) || (((d._month != 2) && ((d._month != 4) || (d._month != 6) || (d._month != 9) || (d._month != 11))&&d._day<=31)))
		return d;
	
	//��Ҫ���������
	while (!(d._day <= 28 || (d._month != 2 && d._day <= 30) || (((d._month != 2) && ((d._month != 4) || (d._month != 6) || (d._month != 9) || (d._month != 11)) && d._day <= 31))))
	{
		if (d._month == 2)
		{
			//�ж�����
			if (((d._year % 100 == 0) && (d._year % 400 == 0)) || ((d._year % 100 != 0) && (d._year % 4 == 0)))
			{
				d._day -= 29;
				d._month += 1;
			}
			else
			{
				d._day -= 28;
				d._month += 1;
			}
		}

		//��30����·�
		else if ((d._month == 4) || (d._month == 6) || (d._month == 9) || (d._month == 11))
		{
			d._day -= 30;
			d._month += 1;
		}

		//��31����·�
		else
		{
			d._day -= 31;
			d._month += 1;
		}


		//�ж��·��Ƿ񳬹�12
		if (d._month > 12)
		{
			d._year += 1;
			d._month = 1;
		}
	}
	return d;
}

//��ǰ����x��֮����ʲô����
Date Date::operator+(int days)
{
	Date temp(*this);//��Ϊ���ܸı�ԭ�������ݣ�����Ҫ������ʱ����
	temp._day += days;

	//��������
	AdjustDate(temp);
	//����
	return temp;
}

//��ǰ����x��ǰ��ʲô����
Date Date::operator-(int days)
{
	Date temp(*this);
	temp._day -= days;

	//��������
	AdjustDate(temp);
	return temp;
}


//��������(����)
Date& Date::AdjustDateSub(Date& d)
{
	if (d._day > 0)
		return d;
	while (d._day<=0)
	{
		//��d.dayǡ�õ���0
		if (0 == d._day)
		{
			d._month -= 1;
			if (0 == d._month)
			{
				d._year -= 1;
				d._month = 12;
				d._day = 31;
			}

			//�жϵ�ǰd,month��ʲô��

			//d.month��2��
			else if (2 == d._month)
			{
				//�ж�����
				if (((d._year % 100 == 0) && (d._year % 400 == 0)) || ((d._year % 100 != 0) && (d._year % 4 == 0)))
				{
					d._day = 29;
				}
				else
					d._day = 28;
			}
			else if ((d._month = 4) || (d._month = 6) || (d._month = 9) || (d._month = 11))
			{
				d._day = 30;
			}
			else
			{
				d._month = 31;
			}
		}

		//�ȸ��·ݼ�1
		d._month -= 1;

		//�ж��·��Ƿ�Ϊ0
		if (0 == d._month)
		{
			d._year -= 1;
			d._month = 12;
		}

		//�����ǰ����2��
		if (2 == d._month)
		{
			if (((d._year % 100 == 0) && (d._year % 400 == 0)) || ((d._year % 100 != 0) && (d._year % 4 == 0)))
				d._day += 29;
			else
				d._day += 28;
		}
		else if (4 == d._month || 6 == d._month || 9 == d._month || 11 == d._month)
			d._day += 30;
		else
			d._day += 31;
	}
	AdjustDateAdd(d);
	return d;
}
Date& Date::AdjustDate(Date& d)
{
	if (d._day > 0)
	{
		AdjustDateAdd(d);
	}
	else
	{
		AdjustDateSub(d);
	}
	return d;
}

//��������֮����������
Date Date::operator-(const Date& d)
{
	Date temp(*this);
	//this����d
	if ((*this)>d)
	{
		if (this->_day >= d._day)
			temp._day = this->_day - d._day;
		else
		{
			temp._month =this->_month - 1;
			if (2 == temp._month)
			{
				if (((d._year % 100 == 0) && (d._year % 400 == 0)) || ((d._year % 100 != 0) && (d._year % 4 == 0)))
				{
					temp._day =this->_day + 29;
				}
				else
					temp._day =this->_day + 28;
			}
			else if ((4 == temp._month) || (6 == temp._month) || (9 == temp._month) || (11 == temp._month))
			{
				temp._day =this->_day + 30;
			}
			else
			{
				temp._day =this->_day + 31;
			}
			temp._day = temp._day - d._day;
		}
		if (temp._month >= d._month)
			temp._month = temp._month - d._month;
		else
		{
			temp._year -= 1;
			temp._month += 12;
			temp._month -= d._month;
		}
		temp._year -= d._year;
	}
	else
	{
		temp._day = d._day;
		temp._month = d._month;
		temp._year = d._year;
		if (this->_day <= d._day)
			temp._day = d._day-this->_day;
		else
		{
			temp._month -= 1;
			if (2 == temp._month)
			{
				if (((d._year % 100 == 0) && (d._year % 400 == 0)) || ((d._year % 100 != 0) && (d._year % 4 == 0)))
				{
					temp._day += 29;
				}
				else
					temp._day += 28;
			}
			else if ((4 == temp._month) || (6 == temp._month) || (9 == temp._month) || (11 == temp._month))
			{
				temp._day += 30;
			}
			else
			{
				temp._day += 31;
			}
			temp._day = temp._day - this->_day;
		}
		if (temp._month >= this->_month)
			temp._month -= this->_month;
		else
		{
			temp._year -= 1;
			temp._month += 12;
			temp._month = temp._month - this->_month;
		}
		temp._year = temp._year - this->_year;
	}
	return temp;
}

//�Ƚ��������ڵĴ�С
bool Date::operator>(const Date& d)
{
	if ((this->_year > d._year) || ((this->_year == d._year) && (this->_month > d._month)) || ((this->_year == d._year) && (this->_month == d._month) && (this->_day > d._day)))
		return true;
	return false;
}
bool Date::operator<(const Date& d)
{
	if ((this->_year > d._year) || ((this->_year == d._year) && (this->_month > d._month)) || ((this->_year == d._year) && (this->_month == d._month) && (this->_day > d._day)))
		return false;
	return true;
}
bool Date::operator==(const Date& d)
{
	if ((this->_year == d._year) && (this->_month == d._month) && (this->_day == d._day))
		return true;
	return false;
}
bool Date::operator!=(const Date& d)
{
	if ((this->_year == d._year) && (this->_month == d._month) && (this->_day == d._day))
		return false;
	return true;
}

//���ظ�ֵ������
Date& Date::operator=(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return (*this);
}

//����ȡ��ַ����
Date* Date::operator&()
{
	return this;
}

//ǰ��++/--
Date& Date::operator++()
{
	this->_year += 1;
	this->_month += 1;
	this->_day += 1;
	return (*this);
}
Date& Date::operator--()
{
	this->_year -= 1;
	this->_month -= 1;
	this->_day -= 1;
	return (*this);
}

//����++/--
Date Date::operator++(int)
{
	Date temp(*this);
	this->_year += 1;
	this->_month += 1;
	this->_day += 1;
	return temp;
}
Date Date::operator--(int)
{
	Date temp(*this);
	this->_year -= 1;
	this->_month -= 1;
	this->_day -= 1;
	return temp;
}
//��ӡ����
void Date::PrintDate()
{
	cout << this->_year << '/' << this->_month << '/' << this->_day << endl;
}


/////////////////////////////////////////���Ժ���
void TestDate()
{
	Date d1(2018,6,11);
	Date d2(2019,5,10);
	Date d3;
	d3 = d2 - d1;
	d3.PrintDate();
	d1.PrintDate();
	d1 = d1 - 100000;
	d1.PrintDate();
	cout << &d1 << ' ' << &d2 << endl;
	system("pause");
}