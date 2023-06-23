#include "Date.h"

Date::Date()
{
	day = rand() % 28 + 1;
	month = rand() % 12 + 1;
	year = rand() % 30 + 1970;
}

void Date::input()
{
	cout << "Enter day ";
	cin >> day;
	cout << "Enter month ";
	cin >> month;
	cout << "Enter year ";
	cin >> year;
}

bool Date::output()
{
	if (day < 1 || month < 1 || year < 1)
	{
		cout << "Invalid month\n";
		return false;
	}
	if (month > 12 || day > 31)
	{
		cout << "Invalid month\n";
		return false;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			cout << "Invalid date\n";
			return false;
		}
	}
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
	{
		if (month == 2 && day > 29)
		{
			cout << "Invalid Date\n";
			return false;
		}
	}
	else {
		if (month == 2 && day > 28)
		{
			cout << "Invalid date\n";
			return false;
		}
	}
	cout << setfill('0') << setw(2) << day << "/";
	cout << setfill('0') << setw(2) << month << "/";
	cout << setfill('0') << setw(4) << year;
	//cout << endl;
	return true;
}

//void Date::increase1day()
//{
//	switch (month)
//	{
//	case 1: case 3: case 5: case 7: case 8 : case 10 : 
//		if (day == 31)
//		{
//			day = 1;
//			month++;
//			break;
//		}
//		day++;
//		break;
//	case 2:
//		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
//		{
//			if (day == 29)
//			{
//				day = 1;
//				month++;
//				break;
//			}
//			day++;
//			break;
//		}
//		else
//		{
//			if (day == 28)
//			{
//				day = 1;
//				month++;
//				break;
//			}
//			day++;
//			break;
//		}
//	case 4: case 6: case 9 : case 11:
//		if (day == 30)
//		{
//			day = 1;
//			month++;
//			break;
//		}
//		day++;
//		break;
//	case 12:
//		if (day == 31)
//		{
//			day = 1;
//			month = 1;
//			year++;
//			break;
//		}
//		day++;
//		break;
//	default:
//		break;
//	}
//}
//
//void Date::increaseNdays(int &n)
//{
//	cout << "Enter n days u want to increase ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		increase1day();
//	}
//}
//
//void Date::decrease1day()
//{
//	if (day > 1) {
//		day--;
//		return;
//	}
//	switch (month)
//	{
//	case 1:
//		month = 12;
//		day = 31;
//		year--;
//		break;
//	case 2 : case 4: case 6: case 8: case 9: case 11:
//		day = 31;
//		month--;
//		break;
//	case 5: case 7: case 10: case 12:
//		day = 30;
//		month--;
//		break;
//	case 3:
//		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
//		{
//			day = 29;
//			month = 2;
//			break;
//		}
//		else
//		{
//			day = 28;
//			month = 2;
//		}
//		break;
//	default:
//		break;
//	}
//}
//
//void Date::decreaseNdays(int &n)
//{
//	cout << "Enter n days u want to decrease ";
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		decrease1day();
//	}
//}
//
//int Date::compare(Date d)
//{
//	if (d.year > year)
//		return -1;
//	if (d.year < year)
//		return 1;
//	if (month > d.month)
//		return 1;
//	if (month < d.month)
//		return -1;
//	if (day > d.day)
//		return 1;
//	if (day < d.day)
//		return -1;
//	return 0;
//}

int Date::getMonth()
{
	return month;
}

Date& Date::operator=(const Date& src)
{
	if (this != &src)
	{
		this->month = src.month;
		this->day = src.day;
		this->year = src.year;
	}
	return *this;
}

ostream& operator<<(ostream& out, const Date& date)
{
	if (date.day < 1 || date.month < 1 || date.year < 1)
	{
		out << "Invalid month\n";
		return out;
	}
	if (date.month > 12 || date.day > 31)
	{
		out << "Invalid month\n";
		return out;
	}
	if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
	{
		if (date.day > 30)
		{
			out << "Invalid date\n";
			return out;
		}
	}
	if (date.year % 4 == 0 && (date.year % 100 != 0 || date.year % 400 == 0))
	{
		if (date.month == 2 && date.day > 29)
		{
			out << "Invalid Date\n";
			return out;
		}
	}
	else {
		if (date.month == 2 && date.day > 28)
		{
			out << "Invalid date\n";
			return out;
		}
	}
	out << setfill('0') << setw(2) << date.day << "/";
	out << setfill('0') << setw(2) << date.month << "/";
	out << setfill('0') << setw(4) << date.year;
	return out;
	// TODO: insert return statement here
}
