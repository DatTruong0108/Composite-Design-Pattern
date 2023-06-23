#pragma once
#include <iostream>
using namespace std;
#include<string>
#include"Date.h"
class Employee {
	string name;
	string id;
	Date dateOfBirth;
	long basicSalary;
	string role;
	int yearStarted;
	int daysWorking;
	int coef;
	int bonus;
public:
	Employee(string name, string id, long basicSalary, string role, int coef);
	void setDaysWorking(int daysWorking);
	void setID(string id);
	string getID();
	int	getDaysWorking();
	string getRole();
	void setName(string name);
	void setDob(Date dateOfBirth);
	string getName();
	long salary();
	void setYearStarted(int yearStarted);
	void setBonus(int bonus);
	friend ostream& operator<<(ostream& out, const Employee& employee);
	void outputDiagram(int level);
};

void outputTab(int level);