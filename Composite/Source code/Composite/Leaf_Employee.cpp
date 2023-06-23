#include "Employee.h"

Employee::Employee()
{
	name = id = role = "";
	startYear = hourlyWage = workingHours = workingDays = 0;
}

Employee::Employee(string name, string id, int year, Date bd, int hw, int wh, int wd, string role)
{
	setName(name);
	setID(id);
	setStartYear(year);
	setDateOfBirth(bd);
	setHourlyWage(hw);
	setWorkingHours(wh);
	setWorkingDays(wd);
	setRole(role);
}

void Employee::setEmployee()
{
	string str;
	int num;
	Date bd;
	cout << "Name: ";
	getline(cin, str);
	setName(str);
	cout << "ID: ";
	getline(cin, str);
	setID(str); 
	cout << "Starting year: ";
	cin >> num;
	cin.ignore();
	setStartYear(num);
	cout << "Date of Birth:\n";
	bd.setDate();
	setDateOfBirth(bd);
	cout << "Hourly Wage: ";
	cin >> num;
	setHourlyWage(num); 
	cout << "Working hours: ";
	cin >> num;
	cin.ignore();
	while (num < 0)
	{
		cout << "Try another value: ";
		cin >> num;
		cin.ignore();
	}
	setWorkingHours(num); 
	cout << "Working days: ";
	cin >> num;
	cin.ignore();
	while (num < 0)
	{
		cout << "Try another value: ";
		cin >> num;
		cin.ignore();
	}
	setWorkingDays(num);
	cout << "Role: ";
	getline(cin, str);
	setRole(str);
}

void Employee::setName(string str)
{
	this->name = str;
}

string Employee::getName()
{
	return this->name;
}

void Employee::setID(string str)
{
	this->id = str;
}

string Employee::getID()
{
	return this->id;
}

void Employee::setStartYear(int year)
{
	this->startYear = year;
}

int Employee::getStartYear()
{
	return this->startYear;
}

void Employee::setDateOfBirth(Date bd)
{
	this->dateOfBirth = bd;
}

Date Employee::getDateOfBirth()
{
	return this->dateOfBirth;
}

void Employee::setHourlyWage(int h)
{
	this->hourlyWage = h;
}

int Employee::getHourlyWage()
{
	return this->hourlyWage;
}

void Employee::setWorkingHours(int h)
{
	this->workingHours = h;
}

int Employee::getWorkingHours()
{
	return this->workingHours;
}

void Employee::setWorkingDays(int d)
{
	this->workingDays = d;
}

int Employee::getWorkingDays()
{
	return this->workingDays;
}

void Employee::setRole(string str)
{
	this->role = str;
}

string Employee::getRole()
{
	return this->role;
}

long long Employee::getSalary()
{
	return 1LL * hourlyWage * workingHours * workingDays;
}

int Employee::countEmployee()
{
	return 1;
}

/*string Employee::getPosition()
{
	return "";
}*/

HR* Employee::maxSalary()
{
	return this;
}

HR* Employee::findHR(string str)
{
	if (this->name == str || this->id == str)
	{
		return this;
	}
	return nullptr;
}

void Employee::printHRInfo(string tab)
{
	cout << tab << "Empolyee:\n";
	cout << tab << "- Name: " << name << '\n';
	cout << tab << "- ID: " << id << '\n';
	cout << tab << "- Starting year: " << startYear << '\n';
	cout << tab << "- DOB: "; dateOfBirth.printDate(); cout << '\n';
	cout << tab << "- Hourly wage: " << hourlyWage << '\n';
	cout << tab << "- Working hours: " << workingHours << '\n';
	cout << tab << "- Working days: " << workingDays << '\n';
	cout << tab << "- Salary: " << getSalary() << '\n';
	cout << tab << "- Role: " << role << '\n';
}