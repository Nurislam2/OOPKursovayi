#include<iostream>
#include "ClassFinishProduct.h"
#include"ClassRawMaterial.h"
#include"ClassEmployee.h"
#include"ClassBudget.h"
#include"ClassIngredient.h"
#include"ClassPosition.h"
#include"ClassProduction.h"
#include"ClassPurchase.h"
#include"ClassSale.h"
#include"ClassUnit.h"
#include<vector>
#include <sstream>
#include <string>

using namespace std;

void finishproduct() {
	setlocale(LC_ALL, "ru");

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	ClassFinishProduct FP;
	ClassUnit unit;
	string ans,name,command,pole;
	float quantity,amount;
	int id_unit,id_FP,num=0;

	while (command!="Exit")
	{

		FP.Print();
		cout << "Add Finish Product --> Add" << endl;
		cout << "Delete Finish product --> Delete [№]" << endl;
		cout << "Edit Finish product --> Edit [№] [Name;Unit]" << endl;
		getline(cin, ans);
		istringstream iss(ans);
		iss >> command >> num>>pole;
		if (command=="Add")
		{
			cout << "Get a Name of New Finish Product" << endl;
			cout << "Name:" << endl;
			getline(cin, name);
			id_unit = unit.Get_id();
			FP.Insert(name, id_unit);
		}
		else if(command=="Delete")
		{
			if (num - 1 >= 0 && (num - 1) < FP.ids.size())
			{
				id_FP = FP.ids[num - 1];
				FP.Delete(id_FP);
			}
			else
			{
				system("cls");
				cout << "Id invalid" << endl;
			}
			
		}
		else if(command=="Edit")
		{

			if (num - 1 >= 0 && (num - 1) < FP.ids.size())
			{
				id_FP = FP.ids[num - 1];
				if (pole == "Name") {
					cout << "Get a New Name for Finish Product" << endl;
					cout << "Name:" << endl;
					getline(cin, name);
					FP.Update(id_FP, name);

				}
				else if (pole == "Unit")
				{
					id_unit = unit.Get_id();
					FP.Update(id_FP, id_unit);
				}
				else
				{
					system("cls");

					cout << "Invalid Command" << endl;
				}
			}else
			{
				system("cls");

				cout << "Id invalid" << endl;
			}
		}
		else
		{
			system("cls");

			cout << "Invalide Command" << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


	}
}

void employees(){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	ClassEmployee empoloyee;
	ClassPosition position;
	string ans, command, pole;
	int id_empl, num = 0;

	while (command != "Exit")
	{

		empoloyee.Print();
		cout << "Add Employees --> Add" << endl;
		cout << "Delete Employees --> Delete [№]" << endl;
		cout << "Edit Employees --> Edit [№] [Name;Position,Salary,Address,Phone,All]" << endl;

		getline(cin, ans);
		istringstream iss(ans);
		iss >> command >> num >> pole;
		if (command == "Add")
		{
			cout << "Get a Name of Employees" << endl;
			cout << "Name:" << endl;
			getline(cin, empoloyee.name);
			empoloyee.position = position.Get_id();
			cout << "Get a Salary of Employees" << endl;
			cout << "Salary:" << endl;
			cin >> empoloyee.salary;
			cout << "Get a Addsess of Employees" << endl;
			cout << "Address:" << endl;
			cin >> empoloyee.address;
			cout << "Get a Phone of Employees" << endl;
			cout << "Phone:" << endl;
			cin >> empoloyee.phone;
			empoloyee.Insert();
		}
		else if (command == "Delete")
		{
			if (num - 1 >= 0 && (num - 1) < empoloyee.ids.size())
			{
				id_empl = empoloyee.ids[num - 1];
				empoloyee.Delete(id_empl);
			}
			else
			{
				system("cls");
				cout << "Id invalid" << endl;
			}


		}
		else if (command == "Edit")
		{

			if (num - 1 >= 0 && (num - 1) < empoloyee.ids.size())
			{
				id_empl = empoloyee.ids[num - 1];
				if (pole == "Name") {
					cout << "Get a New Name for Finish Product" << endl;
					cout << "Name:" << endl;
					getline(cin, empoloyee.name);
					empoloyee.UpdateName(id_empl);

				}
				else if (pole == "Position")
				{
					empoloyee.position = position.Get_id();
					empoloyee.UpdatePosition(id_empl);
				}
				else if (pole == "Address")
				{

					cout << "Get a New Address" << endl;
					cout << "Address:" << endl;
					cin>> empoloyee.address;
					empoloyee.UpdateAddress(id_empl);
				}
				else if (pole == "Phone")
				{
					cout << "Get a New Phone" << endl;
					cout << "Phone Number:" << endl;
					cin >> empoloyee.phone;
					empoloyee.UpdatePhone(id_empl);
				}
				else if (pole == "Salary")
				{
					cout << "Get a New Salary" << endl;
					cout << "Salary:" << endl;
					cin >> empoloyee.salary;
					empoloyee.UpdateSalary(id_empl);
				}
				else if (pole == "All")
				{
					cout << "Get a New Name for Employee" << endl;
					cout << "Name:" << endl;
					getline(cin, empoloyee.name);
					empoloyee.position = position.Get_id();
					cout << "Salary:" << endl;
					cin >> empoloyee.salary;
					cout << "Address:" << endl;
					cin >> empoloyee.address;
					cout << "Phone Number:" << endl;
					cin >> empoloyee.phone;
					empoloyee.UpdateAll(id_empl);
				}
				else
				{
					system("cls");

					cout << "Invalid Command" << endl;
				}


			}
			else
			{
				system("cls");

				cout << "Id invalid" << endl;
			}
		}
		else
		{
			system("cls");

			cout << "Invalide Command" << endl;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
}

void rawmaterial() {
	setlocale(LC_ALL, "ru");

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	ClassRawMaterial RM;
	ClassUnit unit;
	string ans, name, command, pole;
	float quantity, amount;
	int id_unit, id_FP, num = 0;

	while (command != "Exit")
	{

		RM.Print();
		cout << "Add Raw material --> Add" << endl;
		cout << "Delete Raw material --> Delete [№]" << endl;
		cout << "Edit Raw material --> Edit [№] [Name;Unit]" << endl;
		getline(cin, ans);
		istringstream iss(ans);
		iss >> command >> num >> pole;
		if (command == "Add")
		{
			cout << "Get a Name of New Finish Product" << endl;
			cout << "Name:" << endl;
			getline(cin, name);
			id_unit = unit.Get_id();
			RM.Insert(name, id_unit);
		}
		else if (command == "Delete")
		{
			if (num - 1 >= 0 && (num - 1) < RM.ids.size())
			{
				id_FP = RM.ids[num - 1];
				RM.Delete(id_FP);
			}
			else
			{
				system("cls");
				cout << "Id invalid" << endl;
			}

		}
		else if (command == "Edit")
		{

			if (num - 1 >= 0 && (num - 1) < RM.ids.size())
			{
				id_FP = RM.ids[num - 1];
				if (pole == "Name") {
					cout << "Get a New Name for Finish Product" << endl;
					cout << "Name:" << endl;
					getline(cin, name);
					RM.Update(id_FP, name);

				}
				else if (pole == "Unit")
				{
					id_unit = unit.Get_id();
					RM.Update(id_FP, id_unit);
				}
				else
				{
					system("cls");

					cout << "Invalid Command" << endl;
				}
			}
			else
			{
				system("cls");

				cout << "Id invalid" << endl;
			}
		}
		else
		{
			system("cls");

			cout << "Invalide Command" << endl;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');


	}
}

void sale() {
	setlocale(LC_ALL, "ru");

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	ClassSale sale;
	ClassEmployee employee;
	ClassFinishProduct product;
	string ans, date;
	float quantity, amount;
	int id_emp, id_FP;
	while (ans != "Exit")
	{
		sale.Print();
		cout << "Add Sale --> Add" << endl;
		cin>> ans;
	
		if (ans == "Add") {

			id_FP = product.Get_id();
			cout << "Quantity:";
			cin >> quantity;
			if ( sale.Chek(id_FP, quantity)) {
				cout << "Amount:";
				amount = sale.calAmount(id_FP, quantity);
				cout << amount << endl;
				id_emp = employee.Get_id();
				cout << "Date:";
				cin >> date;
				sale.Insert(id_FP, quantity, amount, id_emp, date);

			}
			else {
				cout << "The quantity exceeds the product quantity limit.";
			}
		}
		else
		{
			system("cls");

			cout << "Invalide Command" << endl;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
}

void purchase() {
	setlocale(LC_ALL, "ru");

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	ClassPurchase purchase;
	ClassEmployee employee;
	ClassRawMaterial raw;
	string ans, date;
	float quantity, amount;
	int id_emp, id_FP;
	while (ans != "Exit")
	{
		purchase.Print();
		cout << "Add Sale --> Add" << endl;
		cin >> ans;

		if (ans == "Add") {

			id_FP = raw.Get_id();
			cout << "Quantity:";
			cin >> quantity;
			if (purchase.Chek(quantity)) {
				id_emp = employee.Get_id();
				cout << "Date:";
				cin >> date;
				purchase.Insert(id_FP, quantity, id_emp, date);

			}
			else {
				cout << "No Money";
			}
		}
		else
		{
			system("cls");

			cout << "Invalide Command" << endl;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
}

void production() {
	setlocale(LC_ALL, "ru");

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	ClassProduction production;
	ClassEmployee employee;
	ClassFinishProduct product;
	string ans, date;
	float quantity;
	int id_emp, id_FP;
	while (ans != "Exit")
	{
		production.Print();
		cout << "Add production --> Add" << endl;
		cin >> ans;

		if (ans == "Add") {

			id_FP = product.Get_id();
			cout << "Quantity:";
			cin >> quantity;
			if (production.Chek(id_FP, quantity)) {
				id_emp = employee.Get_id();
				cout << "Date:";
				cin >> date;
				production.Insert(id_FP, quantity, id_emp, date);

			}
			else {
				cout << "The quantity exceeds the product quantity limit.";
			}
		}
		else
		{
			system("cls");

			cout << "Invalide Command" << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


	}
}

void budget() {
	setlocale(LC_ALL, "ru");

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	ClassBudget budget;

	string ans;
	while (ans != "Exit")
	{
		budget.Print();
		cout << "Update Budget --> Add" << endl;
		cin >> ans;

		if (ans == "Add") {
			cout << "Amount: ";
			cin >> budget.amount;
			cout << "Percent: ";
			cin >> budget.percent;
			cout << "Bonus: ";
			cin >> budget.bonus;
			budget.Update();
		}
		else
		{
			system("cls");

			cout << "Invalide Command" << endl;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	}
}

void ingredients() {
	setlocale(LC_ALL, "ru");

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	ClassIngredient ingredient;
	ClassFinishProduct FP;
	ClassRawMaterial RM;
	string ans, command, pole;
	float quantity;
	int id_IG, id_RM, num = 0;

	while (command != "Exit")
	{

		FP.Print();
		cout << "Add Ingredient --> Add" << endl;
		cout << "Delete Ingredient --> Delete [№]" << endl;
		cout << "Edit Ingredient --> Edit [№] [RM;Quantity]" << endl;
		getline(cin, ans);
		istringstream iss(ans);
		iss >> command >> num >> pole;
		if (command == "Add")
		{
			ingredient.product = FP.Get_id();
			ingredient.rawMaterial= RM.Get_id();
			cout << "Quantity: ";
			cin >> ingredient.quantity;
			ingredient.Insert();
		}
		else if (command == "Delete")
		{
			if (num - 1 >= 0 && (num - 1) < ingredient.ids.size())
			{
				id_IG = ingredient.ids[num - 1];
				FP.Delete(id_IG);
			}
			else
			{
				system("cls");
				cout << "Id invalid" << endl;
			}

		}
		else if (command == "Edit")
		{

			if (num - 1 >= 0 && (num - 1) < FP.ids.size())
			{
				id_IG = ingredient.ids[num - 1];
				if (pole == "RM") {
					ingredient.rawMaterial = RM.Get_id();
					ingredient.UpdateRawMaterial(id_IG);

				}
				else if (pole == "Quantity")
				{
					cout << "Quantity: ";
					cin >> ingredient.quantity;
					ingredient.UpdateRawMaterial(id_IG);
				}
				else
				{
					system("cls");

					cout << "Invalid Command" << endl;
				}
			}
			else
			{
				system("cls");

				cout << "Id invalid" << endl;
			}
		}
		else
		{
			system("cls");

			cout << "Invalide Command" << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


	}
}

int main() {
	int ans=100;

	while (ans!=0)
	{
		cout << "\tEmployees --> 1"<<endl;
		cout << "\tIngredient --> 2"<<endl;
		cout << "\tRaw Material --> 3" << endl;
		cout << "\tFinished Products --> 4" << endl;
		cout << "\tPurchase --> 5" << endl;
		cout << "\tSale --> 6"<<endl;
		cout << "\tProduction --> 7" << endl;
		cout << "\Budget --> 8" << endl;
		cout << "Exit --> 0" << endl;
		cin >> ans;
		switch (ans)
		{
		case(1):
			employees();
			break;
		case(2):
			ingredients();
			break;
		case(3):
			rawmaterial();
			break;
		case(4):
			finishproduct();
			break;
		case(5):
			purchase();
			break;
		case(6):
			sale();
			break;
		case(7):
			production();
			break;
		case(8):
			budget();
			break;
		default:
			break;
		}
	}
	
	
	std::cout << "\033[32m" << "Этот текст зеленого цвета!" << "\033[0m" << std::endl;
}