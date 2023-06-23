#include "Date.h"

bool Date::checkInvalidDate()
{
	if (year > 2023 || year < 0)
	{
		return false;
	}
	if (month < 1 || month > 12)
	{
		return false;
	}
	if (day < 0 || day > 31)
	{
		return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
	{
		return false;
	}
	if (month == 2)
	{
		if (day > 29)
		{
			return false;
		}
		if (year % 4 != 0 && day > 28)
		{
			return false;
		}
		if (year % 100 == 0 && year % 400 != 0 && day > 28)
		{
			return false;
		}
	}
	return true;
}

void Date::setDate()
{
	cout << "\tDay: ";
	cin >> day;
	cout << "\tMonth: ";
	cin >> month;
	cout << "\tYear: ";
	cin >> year;
	cin.ignore();
	while (!checkInvalidDate())
	{
		cout << "Khong hop le. Nhap lai day sinh:\n";
		setDate();
	}
}