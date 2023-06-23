#pragma once

#include <iostream>
#include <vector>
#include <string>&op

using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date()
	{
		day = month = year = 0;
	}
	Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	// copy constructor
	Date& operator=(const Date& bd)
	{
		if (this == &bd)
		{
			return *this;
		}
		day = bd.day;
		month = bd.month;
		year = bd.year;
		return *this;
	}
	void printDate()
	{
		cout << day << '-' << month << '-' << year;
	}
	bool checkInvalidDate();
	void setDate();
};