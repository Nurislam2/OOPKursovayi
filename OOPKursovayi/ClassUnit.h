#pragma once
#include<iostream>
#include <vector>

#include"DBconn.h"
class ClassUnit
{
private:
	vector<int> ids;
public:
	int Get_id()
	{
		setlocale(LC_ALL, "ru");

		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int id_unit;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT id,name FROM unit_of_measurements; ");
		result = pstmt->executeQuery();
		this->ids.clear();
		cout << endl << "Cписок  Unit" << endl;
		int num = 1;
		while (result->next()) {
			int id = result->getInt("id");
			string name = result->getString("name").c_str();
			this->ids.push_back(id);
			std::cout << "№ " << num << ", Name: " << name << std::endl;
			num++;
		}


		cout << "Выберите номер  Unit: ";
		cin >> id_unit;
		if (id_unit - 1 >= 0 && (id_unit - 1) < ids.size()) {
			int chosenId = ids[id_unit - 1];


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
	int Check()
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int res = 0;
		con = ConectDB();
		pstmt = con->prepareStatement("select EXISTS(SELECT * FROM unit_of_measurements) as chck ");
		result = pstmt->executeQuery();
		if (result->next()) {
			res = result->getInt(1);
			delete pstmt;
			delete con;
			delete result;
			return res;
		}
	}

};

