#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "HR.h"

using namespace std;

// leaf
class Employee : public HR
{
	int hourlyWage;
	int workingHours;
	int workingDays;
	string role;
public:
	Employee();
	Employee(string, string, int, Date, int, int, int, string);
	bool isLeaf() override
	{
		return true;
	}
	void add(HR*) override
	{
		return;
	}
	void add(HR*, string) override
	{
		return;
	}
	void remove(string) override
	{
		return;
	}
	void setEmployee();
	void setName(string);
	string getName();
	void setID(string);
	string getID() override;
	void setStartYear(int);
	int getStartYear();
	void setDateOfBirth(Date);
	Date getDateOfBirth();
	void setHourlyWage(int);
	int getHourlyWage();
	void setWorkingHours(int);
	int getWorkingHours();
	void setWorkingDays(int);
	int getWorkingDays();
	void setRole(string);
	string getRole();
	long long getSalary() override;
	int countEmployee() override;
	//string getPosition() override;
	HR* maxSalary() override;
	HR* findHR(string) override;
	void printHRInfo(string) override;
	double avgSalary() override
	{
		return getSalary();
	}
};