#include "Company.h"

Company::Company(string name, string id, string product, int year, Date date) {
	this->name = name;
	this->id = id;
	this->product = product;
	this->startYear = year;
	this->date = date;
}

Company::~Company() {
	for (int i = 0; i < cpnList.size(); i++) {
		delete cpnList[i];
		cpnList[i] = nullptr;
	}
}

void Company::add(HR* addHR)
{
	this->cpnList.push_back(addHR);
}

void Company::add(HR* addingHR, string deptID)
{
	if (this->id == deptID)
	{
		add(addingHR);
	}
	else
	{
		for (int i = 0; i < (int)cpnList.size(); ++i)
		{
			cpnList[i]->add(addingHR, deptID);
		}
	}
}

void Company::remove(string removeID)
{
	for (int i = 0; i < (int)this->cpnList.size(); ++i)
	{
		if (cpnList[i]->isLeaf())
		{
			if (cpnList[i]->getID() == removeID)
			{
				cpnList.erase(cpnList.begin() + i);
			}
		}
		else
		{
			cpnList[i]->remove(removeID);
		}
	}
}

long long Company::getSalary()
{
	long long sumSalary = 0;
	for (int i = 0; i < (int)cpnList.size(); ++i)
	{
		sumSalary += cpnList[i]->getSalary();
	}
	return sumSalary;
}

int Company::countEmployee()
{
	int cnt = 0;
	for (int i = 0; i < (int)this->cpnList.size(); ++i)
	{
		cnt += cpnList[i]->countEmployee();
	}
	return cnt;
}

double Company::avgSalary()
{
	return 1.0 * this->getSalary() / this->countEmployee();
}

HR* Company::maxSalary()
{
	HR* maxS = new Employee;
	for (int i = 0; i < (int)this->cpnList.size(); ++i)
	{
		HR* curMax = cpnList[i]->maxSalary();
		if ((*maxS).getSalary() < (*curMax).getSalary())
		{
			maxS = curMax;
		}
	}
	return maxS;
}

HR* Company::findHR(string str)
{
	HR* strHR = new Employee;
	for (int i = 0; i < (int)this->cpnList.size(); ++i)
	{
		strHR = cpnList[i]->findHR(str);
		if (strHR != nullptr)
		{
			return strHR;
		}
	}
	return nullptr;
}

void Company::printHRInfo(string tab)
{
	if (tab != "")
	{
		cout << tab << "Subdepartment:\n";
	}
	cout << tab << "Dep. Name: " << name << '\n';
	cout << tab << "Dep. ID: " << id << '\n';
	cout << tab << "Dep. Product: " << product << '\n';
	cout << tab << "Dep. Starting year: " << startYear << '\n';
	cout << tab << "Establishment Day: "; date.printDate(); cout << '\n';
	if (!cpnList.empty())
	{
		cout << tab << "Include:\n";
	}
	tab += '|\t';
	for (int i = 0; i < (int)cpnList.size(); ++i)
	{
		cpnList[i]->printHRInfo(tab);
	}
}

void Company::createCompany() {
	HR* CEO = new Employee("Mr. Ly To Vuong", "CEO001", 2000, Date(31, 3, 1980), 200000, 8, 24, "CEO");
	add(CEO);
	//--------------------------------------------------------------------
	HR* BusinessDepartment = new Office("Business Dept", "DPM001", 2000, Date(1, 1, 2000));
	HR* BusinessManager = new Employee("Mrs. Tieu Huan Nhi", "MNG001", 2015, Date(28, 7, 1990), 150000, 10, 24, "BusinessManager");
	HR* MarketingRoom = new Office("Marketing Room", "ROM001", 2000, Date(1, 1, 2000));
	HR* E1 = new Employee("Mr. Ngo Hao", "E001", 2016, Date(12, 6, 1992), 100000, 9, 25, "MarketingManager");
	HR* E2 = new Employee("Mrs. Thanh Thanh", "E002", 2018, Date(7, 2, 1994), 80000, 9, 25, "Employee");
	HR* CustomerCareRoom = new Office("Customer Care Room", "ROM002", 2000, Date(1, 1, 2000));
	HR* E3 = new Employee("Mr. Lam Tu Nhai", "E003", 2017, Date(14, 1, 1996), 90000, 8, 25, "CustomerCareManager");
	HR* E4 = new Employee("Mrs. Thien Tu Tuyet", "E004", 2019, Date(14, 7, 1999), 75000, 8, 25, "Employee");
	MarketingRoom->add(E1);
	MarketingRoom->add(E2);
	BusinessDepartment->add(BusinessManager);
	BusinessDepartment->add(MarketingRoom);
	BusinessDepartment->add(CustomerCareRoom);
	CustomerCareRoom->add(E3);
	CustomerCareRoom->add(E4);
	add(BusinessDepartment);
	//--------------------------------------------------------------------
	HR* ProductionDepartment = new Office("Production Dept", "DPM002", 2000, Date(1, 1, 2000));
	HR* ProductionManager = new Employee("Mr. Duong Hao", "MNG002", 2015, Date(18, 3, 1989), 160000, 10, 24, "ProductionManager");
	HR* PurchasingRoom = new Office("Purchasing Room", "ROM003", 2001, Date(15, 2, 2001));
	HR* E5 = new Employee("Mrs. Tran Nguyet Nhien", "E005", 2013, Date(11, 11, 1985), 120000, 9, 25, "PurchasingManager");
	HR* E6 = new Employee("Mrs. Ly Han Y", "E006", 2018, Date(7, 2, 1994), 80000, 9, 25, "Employee");
	HR* ProductionRoom = new Office("Production Room", "ROM004", 2000, Date(1, 1, 2000));
	HR* E7 = new Employee("Mr. Truong Dong Quan", "E007", 2018, Date(14, 12, 1996), 95000, 8, 25, "ProductionManager");
	HR* E8 = new Employee("Mrs. Hoang Thien Nghi", "E008", 2020, Date(16, 2, 2000), 70000, 8, 25, "Employee");
	add(ProductionDepartment);
	ProductionDepartment->add(ProductionManager);
	ProductionDepartment->add(PurchasingRoom);
	ProductionDepartment->add(ProductionRoom);
	PurchasingRoom->add(E5);
	PurchasingRoom->add(E6);
	ProductionRoom->add(E7);
	ProductionRoom->add(E8);
	//--------------------------------------------------------------------
	HR* BackOfficeDepartment = new Office("BackOffice Dept", "DPM003", 2002, Date(1, 1, 2002));
	HR* BackOfficeManager = new Employee("Mr. Tran Tam", "MNG003", 2010, Date(18, 3, 1985), 170000, 10, 24, "BackOfficeManager");
	HR* FinancialRoom = new Office("Financial Room", "ROM005", 2001, Date(15, 2, 2001));
	HR* E9 = new Employee("Mrs. Chu Truc Thanh", "E009", 2014, Date(17, 5, 1990), 90000, 9, 25, "FinancialManager");
	HR* HRRoom = new Office("HR Room", "ROM006", 2000, Date(1, 1, 2000));
	HR* E10 = new Employee("Mr. Doi Moc Bach", "E010", 2017, Date(14, 12, 1995), 100000, 8, 25, "HRManager");
	add(BackOfficeDepartment);
	BackOfficeDepartment->add(BackOfficeManager);
	BackOfficeDepartment->add(FinancialRoom);
	BackOfficeDepartment->add(HRRoom);
	FinancialRoom->add(E9);
	HRRoom->add(E10);
}

void Company::greeting()						
{
	cout << "	|1. Print Company;\n";
	cout << "	|2. Add;\n";
	cout << "	|3. Remove;\n";
	cout << "	|4. Sum all salary;\n";
	cout << "	|5. Highest-salary Employee\n";
	cout << "	|6. AVG salary\n";
	cout << "	|7. Find employee\n";
	cout << "	|8. Exit\n";
}

void Company::part01()
{
	printHRInfo("");
}

void Company::part02()
{
	cout << "Choose one number:\n";
	cout << "\t1. Default Adding (Add New employee to the whole company)\n";
	cout << "\t2. Specific Adding (Add New employee to a specific department)\n";
	cout << "Input a number: ";
	int c;
	cin >> c;
	while (c < 1 || c > 2)
	{
		cout << "Reinput: ";
		cin >> c;
	}
	cin.ignore();
	HR* newE = new Employee;
	newE->setEmployee();
	if (c == 1)
	{
		add(newE);
	}
	else
	{
		cout << "Dept'ID to add to: ";
		string deptID;
		cin >> deptID;
		add(newE, deptID);
	}
	cout << "Adding successfull.\n";
}

void Company::part03()
{
	cout << "Employee or Department's ID to remove: ";
	string removeID;
	getline(cin, removeID);
	remove(removeID);
	cout << "Removing successful.\n";
}

void Company::part04()
{
	cout << "Sum salary of all employees is " << getSalary() << '\n';
}

void Company::part05()
{
	cout << "Highest-salary Employee is:\n";
	maxSalary()->printHRInfo("");
}

void Company::part06()
{
	double avg = avgSalary();
	cout << "AVG salary is " << fixed << setprecision(3) << avgSalary() << '\n';
}

void Company::part07()
{
	cout << "Employee's ID to find: ";
	string findID;
	getline(cin, findID);
	HR* E = findHR(findID);
	if (!E)
	{
		cout << "There's no employee " << findID << '\n';
	}
	else
	{
		cout << findID << " employee is:\n";
		E->printHRInfo("");
	}
}


void Company::menu(int t, char& next)		//Chua menu va lap lai menu
{
	if (t >= 1 && t <= 8)
		system("cls");
	switch (t)
	{
	case 1:
		part01();
		break;
	case 2:
		part02();
		break;
	case 3:
		part03();
		break;
	case 4:
		part04();
		break;
	case 5:
		part05();
		break;
	case 6:
		part06();
		break;
	case 7:
		part07();
		break;
	case 8:
		cout << "Exit.\n";
		next = 'n';
		break;
	default:
		cout << "Reinput: ";
		cin >> t;
		menu(t, next);
		break;
	}

}

void Company::workOnCompany()
{
	createCompany();
	cout << "Default Company created.\n";
	char next;
	int t = -1;
	do
	{
		next = '0';
		if (t != -1)
			system("cls");
		greeting();
		cout << "Input a number (1 - 8): ";
		cin >> t;
		cin.ignore();
		menu(t, next);
		if (next == '0')
		{
			cout << "Continue? (Y: Yes/Others: No): ";
			cin >> next;
		}
	} while (next == 'y' || next == 'Y');
	system("pause");
}
