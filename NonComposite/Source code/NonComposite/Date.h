#pragma once

#include <iostream>
using namespace std;
#include<iomanip>
class Date {
	int day;
	int month;
	int year;
public:
	Date();
	void input();
	bool output();
	friend ostream& operator<<(ostream& out, const Date& date);
	int getMonth();
	Date& operator=(const Date& src);
};