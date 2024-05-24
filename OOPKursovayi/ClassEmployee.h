#pragma once
#include <iostream>
#include <vector>
#include "DBconn.h"
class ClassEmployee
{
public:
	vector<int> ids;
	string name;
	int position;
	int salary;
	string address;
	string phone;

public:
	int Get_id()

	{
		setlocale(LC_ALL, "ru");

		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int id_empl;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT id,FullName FROM employees; ");
		result = pstmt->executeQuery();
		this->ids.clear();
		cout << endl << "Cписок  Работников" << endl;
		cout << "==================" << endl;
		cout << "№\tName" << endl;
		cout << "-------------------" << endl;

		int num = 1;

		while (result->next()) {
			int id = result->getInt("id");
			string name = result->getString("FullName").c_str();
			this->ids.push_back(id);
			cout << num << "\t" << name << endl;
			cout << "-------------------" << endl;
			num++;
		}

		delete pstmt;
		delete con;
		delete result;

		cout << "Выберите номер  Работников: ";
		cin >> id_empl;
		if (id_empl - 1 >= 0 && (id_empl - 1) < ids.size()) {
			int chosenId = ids[id_empl - 1];



			return chosenId;
		}
		else {



			cout << "Invalid choice." << endl;
			return -1;
		}
	}
	void UpdateName(int id)
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;

		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE employees SET FullName = ? WHERE id = ?");
		pstmt->setString(1, this->name);
		pstmt->setInt(2, id);
		pstmt->execute();
		system("cls");

		cout << "\033[32m" << "Name Updated" << "\033[0m" << endl;
		delete pstmt;
		delete con;

	}
	void UpdatePosition(int id)
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;

		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE employees SET Position_id = ? WHERE id = ?");
		pstmt->setInt(1, this->position);
		pstmt->setInt(2, id);
		pstmt->execute();
		system("cls");

		cout << "\033[32m" << "Position Updated" << "\033[0m" << endl;
		delete pstmt;
		delete con;
	}
	void UpdateSalary(int id)
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;

		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE employees SET Salary = ? WHERE id = ?");
		pstmt->setInt(1, this->salary);
		pstmt->setInt(2, id);
		pstmt->execute();
		system("cls");

		cout << "\033[32m" << "Position Updated" << "\033[0m" << endl;
		delete pstmt;
		delete con;
	}
	void UpdateAddress(int id)
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;

		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE employees SET Address = ? WHERE id = ?");
		pstmt->setString(1, this->address);
		pstmt->setInt(2, id);
		pstmt->execute();
		system("cls");

		cout << "\033[32m" << "Position Updated" << "\033[0m" << endl;
		delete pstmt;
		delete con;
	}
	void UpdatePhone(int id)
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;

		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE employees SET PhoneNumber = ? WHERE id = ?");
		pstmt->setString(1, this->phone);
		pstmt->setInt(2, id);
		pstmt->execute();
		system("cls");

		cout << "\033[32m" << "Position Updated" << "\033[0m" << endl;
		delete pstmt;
		delete con;
	}

	void UpdateAll(int id)
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;

		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE employees SET FullName= ?,Position_id=?,Salary = ?,Address = ?,PhoneNumber = ? WHERE id = ?");
		pstmt->setString(1, this->name);
		pstmt->setInt(2, this->position);
		pstmt->setInt(3, this->salary);
		pstmt->setString(4, this->address);
		pstmt->setString(5, this->phone);
		pstmt->setInt(6, id);
		pstmt->execute();
		system("cls");
		cout << "\033[32m" << "Updated" << "\033[0m" << endl;
		delete pstmt;
		delete con;


	}
	void Insert()
	{
		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("INSERT INTO employees(FullName, Position_id, Salary, Address, PhoneNumber) \
										VALUES (?,?,?,?,?)");
			pstmt->setString(1, this->name);
			pstmt->setInt(2, this->position);
			pstmt->setInt(3, this->salary);
			pstmt->setString(4, this->address);
			pstmt->setString(5, this->phone);
			pstmt->execute();
			system("cls");
			cout << "\033[32m" << "Saved" << "\033[0m" << endl;
			delete pstmt;
			delete con;
		}
		catch (sql::SQLException e)
		{
			cout << "\033[31m" << "Could not Saved. Error message: " << e.what() << "\033[0m" << endl;

			system("pause");
		}
	}
	void Delete(int id)
	{

		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("Delete from employees Where id=?");
			pstmt->setInt(1, id);
			pstmt->execute();
			system("cls");

			cout << "\033[32m" << "Deleted" << "\033[0m" << endl;
			delete pstmt;
			delete con;
		}
		catch (sql::SQLException e)
		{
			cout << "\033[31m" << "Could not Deleted. Error message: " << e.what() << "\033[0m" << endl;

			system("pause");
		}
	}
	int Check()
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int res = 0;
		con = ConectDB();
		pstmt = con->prepareStatement("select EXISTS(SELECT * FROM employees) as chck ");
		result = pstmt->executeQuery();
		if (result->next()) {
			res = result->getInt(1);
			delete pstmt;
			delete con;
			delete result;
			return res;
		}
	}
	void Print()
	{
		setlocale(LC_ALL, "ru");

		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int id_prod;
		int id, salary;;
		this->ids.clear();
		string name;
		string surname;
		string address, phone, position;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT employees.id, FullName, positions.name as position, Salary, Address, PhoneNumber \
                                    FROM employees \
                                    INNER JOIN positions on positions.id = employees.Position_id");
		result = pstmt->executeQuery();

		cout << endl << "Список Сотрудников" << endl;
		cout << "==============================================================================" << endl;
		cout << "№\tName\t\tPosition\t\Salary\tAddress\t\tPhone Number" << endl;
		cout << "------------------------------------------------------------------------------" << endl;

		int num = 1;
		while (result->next()) {
			id = result->getInt("id");
			name = result->getString("FullName").c_str();
			size_t space_pos = name.find_last_of(" "); // Находим последнее вхождение пробела
			if (space_pos != string::npos) {
				surname = name.substr(space_pos + 1); // Получаем фамилию
				name = name.substr(0, space_pos); // Получаем имя
			}
			else {
				surname = "";
			}
			position = result->getString("position");
			salary = result->getInt("Salary");
			address = result->getString("Address").c_str();
			phone = result->getString("PhoneNumber").c_str();
			this->ids.push_back(id);

			cout << num << "\t" << name << "\n\t" << surname << "\t" << position << "\t\t" << salary << "\t" << address << "\t\t" << phone << endl;
			cout << "------------------------------------------------------------------------------" << endl;

			num++;
		}

		delete pstmt;
		delete con;
		delete result;
	}
};

