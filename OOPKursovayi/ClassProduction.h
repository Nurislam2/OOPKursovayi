#pragma once
#include "DBconn.h"
#include <iostream>
#include <vector>
class ClassProduction
{

public:
	void Print()
	{
		setlocale(LC_ALL, "ru");

		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int id_prod;
		int id, salary;
		float quantity, amount;
		string namePro, empl;
		string date;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT productions.id,finished_products.name,productions.quantity,\
		productions.date,employees.FullName\
		FROM productions \
		INNER JOIN finished_products ON productions.finished_product_id = finished_products.id\
		INNER JOIN employees ON productions.employee_id = employees.id;");
		result = pstmt->executeQuery();

		cout << endl << "Список Продаж" << endl;
		cout << "================================================================================================" << endl;
		cout << "№\tName Product\t\Quantity\t\tDate\t\tFullName" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		int num = 1;
		while (result->next()) {
			//id = result->getInt("id");
			namePro = result->getString("name").c_str();
			quantity = result->getDouble("quantity");
			date = result->getString("date").c_str();
			empl = result->getString("FullName").c_str();
			//this->ids.push_back(id);

			cout << num << "\t" << namePro << "\t" << quantity << "\t\t" << date << "\t" << empl << endl;
			cout << "----------------------------------------------------------------------------------------------------" << endl;

			num++;
		}

		delete pstmt;
		delete con;
		delete result;
	}
	bool Chek(int id_prod, float quantity)
	{

		setlocale(LC_ALL, "ru");
		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			sql::ResultSet* result;
			bool rs;
			con = ConectDB();
			pstmt = con->prepareStatement("CALL SP_Production(?,?)  ");
			pstmt->setInt(1, id_prod);
			pstmt->setDouble(2, quantity);
			result = pstmt->executeQuery();
			if (result->next()) {
				rs = result->getInt("SP_Production");
				delete pstmt;
				delete con;
				delete result;
				return rs;
			}
		}
		catch (sql::SQLException e)
		{
			cout << "\033[31m" << " Error message: " << e.what() << "\033[0m" << endl;

			system("pause");
		}

	}
	void Insert(int id_prod, float quantity,  int id_emp, string date)
	{
		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("CALL SP_Insert_Production(?,?,?,?)");
			pstmt->setInt(1, id_prod);
			pstmt->setDouble(2, quantity);
			pstmt->setString(3, date);

			pstmt->setInt(4, id_emp);
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
};

