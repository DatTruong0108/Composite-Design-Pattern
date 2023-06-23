#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"Employee.h"
class Section {
	string name;
	string id;
	vector<Employee*> staff;
public:
	Section(string name, string id);
	~Section();
	void addStaff(Employee* staff);
	bool removeStaff(string id);
	long totalSalary();
	string getName();
	string getID();
	int getNumOfStaffs();
	long averageSalary();
	Employee* findStaff(string id);
	Employee* highestSalaryStaff();
	friend ostream& operator<<(ostream& out, const Section& section);
	void outputDiagram(int level);
};