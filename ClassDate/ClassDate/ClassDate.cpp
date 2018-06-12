#include"ClassDate.h"
//调整日期(加法调整)
Date& Date::AdjustDateAdd(Date& d)
{
	//无需调整的情况
	if (d._day <= 28 || (d._month != 2 && d._day <= 30) || (((d._month != 2) && ((d._month != 4) || (d._month != 6) || (d._month != 9) || (d._month != 11))&&d._day<=31)))
		return d;
	
	//需要调整的情况
	while (!(d._day <= 28 || (d._month != 2 && d._day <= 30) || (((d._month != 2) && ((d._month != 4) || (d._month != 6) || (d._month != 9) || (d._month != 11)) && d._day <= 31))))
	{
		if (d._month == 2)
		{
			//判断闰年
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

		//有30天的月份
		else if ((d._month == 4) || (d._month == 6) || (d._month == 9) || (d._month == 11))
		{
			d._day -= 30;
			d._month += 1;
		}

		//有31天的月份
		else
		{
			d._day -= 31;
			d._month += 1;
		}


		//判断月份是否超过12
		if (d._month > 12)
		{
			d._year += 1;
			d._month = 1;
		}
	}
	return d;
}

//当前日期x天之后是什么日期
Date Date::operator+(int days)
{
	Date temp(*this);//因为不能改变原本的数据，所以要创建临时变量
	temp._day += days;

	//调整日期
	AdjustDate(temp);
	//返回
	return temp;
}

//当前日期x天前是什么日期
Date Date::operator-(int days)
{
	Date temp(*this);
	temp._day -= days;

	//调整日期
	AdjustDate(temp);
	return temp;
}


//调整日期(减法)
Date& Date::AdjustDateSub(Date& d)
{
	if (d._day > 0)
		return d;
	while (d._day<=0)
	{
		//当d.day恰好等于0
		if (0 == d._day)
		{
			d._month -= 1;
			if (0 == d._month)
			{
				d._year -= 1;
				d._month = 12;
				d._day = 31;
			}

			//判断当前d,month是什么月

			//d.month是2月
			else if (2 == d._month)
			{
				//判断闰年
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

		//先给月份减1
		d._month -= 1;

		//判断月份是否为0
		if (0 == d._month)
		{
			d._year -= 1;
			d._month = 12;
		}

		//如果当前月是2月
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

//两个日期之间相差多少天
Date Date::operator-(const Date& d)
{
	Date temp(*this);
	//this大于d
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

//比较两个日期的大小
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

//重载赋值操作符
Date& Date::operator=(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
	return (*this);
}

//重载取地址符号
Date* Date::operator&()
{
	return this;
}

//前置++/--
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

//后置++/--
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
//打印日期
void Date::PrintDate()
{
	cout << this->_year << '/' << this->_month << '/' << this->_day << endl;
}


/////////////////////////////////////////测试函数
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