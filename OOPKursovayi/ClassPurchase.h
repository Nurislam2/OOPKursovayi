#pragma once
#include <iostream>
#include <vector>
#include "DBconn.h"

class ClassPurchase
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
		pstmt = con->prepareStatement("SELECT purchase_of_raw_materials.id,raw_materials.name,purchase_of_raw_materials.quantity,\
		purchase_of_raw_materials.amount,purchase_of_raw_materials.date,employees.FullName\
		FROM purchase_of_raw_materials \
		INNER JOIN raw_materials ON purchase_of_raw_materials.raw_material_id = raw_materials.id\
		INNER JOIN employees ON productions.employee_id = employees.id;");
		result = pstmt->executeQuery();

		cout << endl << "Список Закупок" << endl;
		cout << "================================================================================================" << endl;
		cout << "№\Raw material\t\Quantity\tAmount\t\tDate\t\tFullName" << endl;
		cout << "--------------------------------------------------------------------------------------------------" << endl;
		int num = 1;
		while (result->next()) {
			//id = result->getInt("id");
			namePro = result->getString("name").c_str();
			quantity = result->getDouble("quantity");
			amount = result->getDouble("amount");
			date = result->getString("date").c_str();
			empl = result->getString("FullName").c_str();
			//this->ids.push_back(id);

			cout << num << "\t" << namePro << "\t" << quantity << "\t" << amount << "\t\t" << date << "\t" << empl << endl;
			cout << "----------------------------------------------------------------------------------------------------" << endl;

			num++;
		}

		delete pstmt;
		delete con;
		delete result;
	}
	bool Chek(float amount)
	{

		setlocale(LC_ALL, "ru");
		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			sql::ResultSet* result;
			bool rs;
			con = ConectDB();
			pstmt = con->prepareStatement("CALL SP_ch_amount(?)  ");
			pstmt->setDouble(1, amount);
			result = pstmt->executeQuery();
			if (result->next()) {
				rs = result->getInt(1);
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
	void Insert(int id_prod, float quantity, int id_emp, string date)
	{
		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("CALL SP_insert_pur(?,?,?,?)");
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

