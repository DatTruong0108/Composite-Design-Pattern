#include"Company.h"
#include"Department.h"
#include"Employee.h"
#include"Section.h"

int main()
{
	Company* company = new Company("US Company");
	company->setProduct("Thu Nhoi Bong");

	Employee* ceo = new Employee("Dat Truong", "CEO", 5000, "CEO", 2.5);
	ceo->setDaysWorking(27);
	ceo->setYearStarted(2010);
	ceo->setBonus(1000);
	company->addStaff(ceo);
	Department* sales = new Department("Sales department", "SA");
	company->addDepartment(sales);
	Department* production = new Department("Production department", "PD");
	company->addDepartment(production);
	Department* backOffice = new Department("Back office department", "BO");
	company->addDepartment(backOffice);

	Employee* salesManager = new Employee("Pndy", "SA_MNG", 2000, "Sales Director", 2);
	salesManager->setDaysWorking(27);
	salesManager->setYearStarted(2011);
	sales->addStaff(salesManager);
	Section* marketing = new Section("Maketing section", "SA_MT");
	sales->addSection(marketing);
	Section* customerService = new Section("Customer service section", "SA_CS");
	sales->addSection(customerService);

	Employee* productionManager = new Employee("Hieu Bang Vang", "PD_MNG", 2000, "Production Director", 2);
	productionManager->setDaysWorking(27);
	productionManager->setYearStarted(2010);
	production->addStaff(productionManager);
	Section* purchasing = new Section("Purchasing section", "PD_PC");
	production->addSection(purchasing);
	Section* manufacturing = new Section("Manufacturing section", "PD_MF");
	production->addSection(manufacturing);

	Employee* backOfficeManager = new Employee("Buh sboi", "BO_MNG", 2000, "Back Office Director", 2);
	backOfficeManager->setDaysWorking(26);
	backOfficeManager->setYearStarted(2012);
	backOffice->addStaff(backOfficeManager);
	Section* humanResources = new Section("Human resources section", "BO_HR");
	backOffice->addSection(humanResources);
	Section* finance = new Section("Finance section", "BO_FN");
	backOffice->addSection(finance);

	Employee* emp1 = new Employee("Nguyen 1", "SA_MT_01", 800, "Manager", 1.5);
	emp1->setDaysWorking(27);
	emp1->setYearStarted(2014);
	marketing->addStaff(emp1);
	Employee* emp2 = new Employee("Tran 2", "SA_MT_02", 700, "Staff", 1);
	emp2->setDaysWorking(23);
	emp2->setYearStarted(2015);
	marketing->addStaff(emp2);
	Employee* emp3 = new Employee("Duong 3", "SA_CS_01", 840, "Manager", 1.5);
	emp3->setDaysWorking(25);
	emp3->setYearStarted(2017);
	customerService->addStaff(emp3);
	Employee* emp4 = new Employee("Pham 4", "SA_CS_02", 800, "Staff", 1);
	emp4->setDaysWorking(26);
	emp4->setYearStarted(2019);
	customerService->addStaff(emp4);
	Employee* emp5 = new Employee("Truong 5", "PD_PC_01", 820, "Manager", 1.5);
	emp5->setDaysWorking(27);
	emp5->setYearStarted(2012);
	purchasing->addStaff(emp5);
	Employee* emp6 = new Employee("Ngo 6", "PD_PC_02", 780, "Staff", 1);
	emp6->setDaysWorking(23);
	emp6->setYearStarted(2019);
	purchasing->addStaff(emp6);
	Employee* emp7 = new Employee("Thai 7", "PD_MF_01", 820, "Manager", 1.5);
	emp7->setDaysWorking(27);
	emp7->setYearStarted(2022);
	manufacturing->addStaff(emp7);
	Employee* emp8 = new Employee("Vo 8", "PD_MF_02", 690, "Staff", 1);
	emp8->setDaysWorking(24);
	emp8->setYearStarted(2014);
	manufacturing->addStaff(emp8);
	Employee* emp9 = new Employee("Hoang 9", "BO_HR_01", 830, "Manager", 1.5);
	emp9->setDaysWorking(27);
	emp9->setYearStarted(2015);
	humanResources->addStaff(emp9);
	Employee* emp10 = new Employee("Huynh 10", "BO_HR_02", 780, "Staff", 1);
	emp10->setDaysWorking(25);
	emp10->setYearStarted(2016);
	humanResources->addStaff(emp10);
	Employee* emp11 = new Employee("Phung 11", "BO_FN_01", 890, "Manager", 1.5);
	emp11->setDaysWorking(26);
	emp11->setYearStarted(2012);
	finance->addStaff(emp11);
	Employee* emp12 = new Employee("Luong 12", "BO_FN_02", 800, "Staff", 1);
	emp12->setDaysWorking(24);
	emp12->setYearStarted(2015);
	finance->addStaff(emp12);

	company->outputDiagram(0);

	cout << "\nTotal Salary this month: " << company->totalSalary() << " Average: " << company->averageSalary() << endl;
	cout << "Highest Salary Staff: \n";
	company->highestSalaryStaff()->outputDiagram(0);
	cout << "The result of find Department ID BO\n";
	company->findDepartment("BO")->outputDiagram(0);
	cout << "The result of find Section ID SA_MT\n";
	company->findSection("SA_MT")->outputDiagram(0);
	cout << "The result of find Employee ID PD_MF_01\n";
	company->findEmployee("PD_MF_01")->outputDiagram(0);
	delete company;

	system("pause");

	return 0;
}