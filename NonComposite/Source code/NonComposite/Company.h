#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<iomanip>
#include"Employee.h"
#include"Department.h"

class Company {
	string name;
	string product;
	vector<Department*> listOfDepartment;
	Employee* ceo;
public:
	Company(string name);
	~Company();
	void addDepartment(Department* department);
	bool removeDepartment(string id);
	bool addSection(Section* section);
	bool removeSection(string id);
	bool addStaff(Employee* staff);
	bool removeStaff(string id);
	string getName();
	string getProduct();
	void setProduct(string product);
	int getNumOfDepartment();
	int getNumOfSection();
	int getNumOfStaff();
	long totalSalary();
	long averageSalary();
	Department* findDepartment(string id);
	Section* findSection(string id);
	Employee* findEmployee(string id);
	Employee* highestSalaryStaff();
	friend ostream& operator<<(ostream& out, const Company& company);
	void outputDiagram(int level);
};