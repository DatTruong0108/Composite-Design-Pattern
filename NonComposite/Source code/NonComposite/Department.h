#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"Employee.h"
#include"Section.h"

class Department {
	string name;
	string id;
	Employee* manager;
	vector<Section*> listOfSection;
public:
	Department(string name, string id);
	~Department();
	void addSection(Section* section);
	bool removeSection(string id);
	bool addStaff(Employee* staff);
	bool removeStaff(string id);
	string getName();
	string getID();
	int getNumOfSection();
	int getNumOfStaff();
	Section* findSection(string id);
	Employee* findEmployee(string id);
	long totalSalary();
	long averageSalary();
	Employee* highestSalaryStaff();
	friend ostream& operator<<(ostream& out, const Department& department);
	void outputDiagram(int level);
};