#pragma once
#ifndef _COMPANY_H_
#define _COMPANY_H_

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "Employee.h"
#include "Office.h"
#include "HR.h"

using namespace std;

// client
class Company {
private:
	string name;
	string id;
	string product;
	int startYear;
	Date date;
	vector<HR*> cpnList;
public:
	Company(string name, string id, string product, int year, Date date);
	~Company();
	void add(HR*);
	void add(HR*, string);
	void remove(string);
	void setEmployee()
	{
		return;
	}
	long long getSalary();
	int countEmployee();
	double avgSalary();
	//string getPosition();
	HR* maxSalary();
	HR* findHR(string);
	void printHRInfo(string);
	void createCompany();
	void greeting();
	void part01();
	void part02();
	void part03();
	void part04();
	void part05();
	void part06();
	void part07();
	void menu(int t, char& next);
	void workOnCompany();
};

#endif // !_COMPOSITE_DESIGN_PATTERN_H_
