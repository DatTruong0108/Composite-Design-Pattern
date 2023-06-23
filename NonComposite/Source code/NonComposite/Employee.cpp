#include "Employee.h"

Employee::Employee(string name, string id, long basicSalary, string role, int coef)
{
	this->name = name;
	this->id = id;
	this->basicSalary = basicSalary;
	this->role = role;
	this->coef = coef;
	this->bonus = 0;
	this->yearStarted = 2022;
	this->daysWorking = 0;
	Date dob;
	this->dateOfBirth = dob;
}

void Employee::setDaysWorking(int daysWorking)
{
	this->daysWorking = daysWorking;
}

void Employee::setID(string id)
{
	this->id = id;
}

string Employee::getID()
{
	return this->id;
}

int Employee::getDaysWorking()
{
	return this->daysWorking;
}

string Employee::getRole()
{
	return this->role;
}

void Employee::setName(string name)
{
	this->name = name;
}

void Employee::setDob(Date dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

string Employee::getName()
{
	return this->name;
}

long Employee::salary()
{
	return this->basicSalary * this->daysWorking * this->coef;
}

void Employee::setYearStarted(int yearStarted)
{
	this->yearStarted = yearStarted;
}

void Employee::setBonus(int bonus)
{
	this->bonus = bonus;
}

void Employee::outputDiagram(int level)
{

	outputTab(level);
	cout << this->role << ": [" << this->id << "] " << this->name << endl;
	outputTab(level);
	cout << this->dateOfBirth << " - YearStarted: " << this->yearStarted << " - This Month: " << this->daysWorking << " days\n";
	outputTab(level);
	cout << "Basic salary: " << this->basicSalary << " - Coef: " << this->coef << " - " << "Bonus: " << this->bonus << endl;
	outputTab(level);
	cout << endl;
}


ostream& operator<<(ostream& out, const Employee& employee)
{
	out << "Role: " << employee.role << endl;
	out << "ID: " << employee.id << endl;
	out << "Name: " << employee.name << endl;
	out << "Date Of Birth: " << employee.dateOfBirth << endl;
	out << "Basic salary: " << employee.basicSalary << endl;
	out << "YearStarted" << employee.yearStarted << endl;
	out << "Coef" << employee.coef << endl;
	out << "Bonus: " << employee.bonus << endl;
	out << "DaysWorking this month: " << employee.daysWorking << endl;
	return out;
	// TODO: insert return statement here
}


void outputTab(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "|\t";
	}
}