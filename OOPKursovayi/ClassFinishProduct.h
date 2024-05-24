#pragma once
#include <iostream>
#include <vector>
#include "DBconn.h"
#include"ClassMaterial.h"
class ClassFinishProduct:public ClassMaterial
{

public:
	int Get_id()
	{
		setlocale(LC_ALL, "ru");

		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int id_prod;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT id,name FROM finished_products; ");
		result = pstmt->executeQuery();
		this->ids.clear();
		cout << endl << "Cписок  Продуктов" << endl;
		int num = 1;
		while (result->next()) {
			int id = result->getInt("id");
			string name = result->getString("name").c_str();
			this->ids.push_back(id);
			std::cout << "№ " << num << ", Name: " << name << std::endl;
			num++;
		}


		cout << "Выберите номер  Продукта: ";
		cin >> id_prod;
		if (id_prod - 1 >= 0 && (id_prod - 1) < ids.size()) {
			int chosenId = ids[id_prod - 1];


			delete pstmt;
			delete con;
			delete result;
			return chosenId;
		}
		else {

			delete pstmt;
			delete con;
			delete result;

			cout << "Invalid choice." << endl;
			return -1;
		}
	}
	void Update(int id, string name)
	{

		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("UPDATE finished_products SET name = ? WHERE id = ?");
			pstmt->setString(1, name);
			pstmt->setInt(2, id);
			pstmt->execute();
			system("cls");

			cout << "\033[32m" << "Name Updated" << "\033[0m" << endl;
			delete pstmt;
			delete con;
		}
		catch (sql::SQLException e)
		{
			system("cls");
			cout << "\033[31m" << "Could not Updated. Error message: " << e.what() << "\033[0m" << endl;

			system("pause");
		}

	}
	void Update(int id, int id_unit)
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;

		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE finished_products SET unit_of_measurement_id = ? WHERE id = ?");
		pstmt->setInt(1, id_unit);
		pstmt->setInt(2, id);
		pstmt->execute();
		system("cls");
		cout << "\033[32m" << "Unit Updated" << "\033[0m" << endl;
		delete pstmt;
		delete con;

	}
	void Insert(string name, int id_unit)
	{

		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("INSERT INTO finished_products (name,unit_of_measurement_id) VALUES(?,?)");
			pstmt->setString(1, name);
			pstmt->setInt(2, id_unit);
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
			pstmt = con->prepareStatement("Delete from finished_products Where id=?");
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
		pstmt = con->prepareStatement("select EXISTS(SELECT * FROM finished_products) as chck ");
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
		int id;
		this->ids.clear();
		string name, unit;
		float quantity, amount;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT finished_products.id, finished_products.name, unit_of_measurements.name as unit , quantity, amount \
                                    FROM finished_products \
                                    INNER JOIN unit_of_measurements on unit_of_measurements.id = unit_of_measurement_id");
		result = pstmt->executeQuery();

		cout << endl << "Cписок Продуктов" << endl;
		cout << "==============================================================================" << endl;
		cout << "№\tName\t\tUnit\t\tQuantity\tAmount" << endl;
		cout << "------------------------------------------------------------------------------" << endl;

		int num = 1;
		while (result->next()) {
			id = result->getInt("id");
			name = result->getString("name").c_str();
			quantity = result->getDouble("quantity");
			amount = result->getDouble("amount");
			unit = result->getString("unit").c_str();
			this->ids.push_back(id);

			cout << num << "\t" << name << "\t" << unit << "\t" << quantity << "\t\t" << amount << endl;
			cout << "------------------------------------------------------------------------------" << endl;

			num++;
		}
		delete pstmt;
		delete con;
		delete result;
	}
};

