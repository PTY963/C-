#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

Date Date::operator+=(int day)
{
	_day += day;

	while (_day > GetDayOfMonth(_year, _month))
	{
		_day -= GetDayOfMonth(_year, _month);
		_month += 1;

		if (_month == 13)
		{
			_month -= 12;
			_year += 1;
		}

	}

	return *this;
}
