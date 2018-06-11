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
//打印日期
void Date::PrintDate()
{
	cout << this->_year << '/' << this->_month << '/' << this->_day << endl;
}


/////////////////////////////////////////测试函数
void TestDate()
{
	Date d1(2018,6,11);
	d1.PrintDate();
	d1 = d1 - 100000;
	d1.PrintDate();
	system("pause");
}