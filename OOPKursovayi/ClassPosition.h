#pragma once
#include<iostream>
#include <vector>

#include"DBconn.h"
class ClassPosition
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
		int id_pos;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT id,name FROM positions; ");
		result = pstmt->executeQuery();
		this->ids.clear();
		cout << endl << "Cписок  Должностей" << endl;
		int num = 1;
		while (result->next()) {
			int id = result->getInt("id");
			string name = result->getString("name").c_str();
			this->ids.push_back(id);
			std::cout << "№ " << num << ", Name: " << name << std::endl;
			num++;
		}


		cout << "Выберите номер  Должность: ";
		cin >> id_pos;
		if (id_pos - 1 >= 0 && (id_pos - 1) < ids.size()) {
			int chosenId = ids[id_pos - 1];


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
		pstmt = con->prepareStatement("select EXISTS(SELECT * FROM positions) as chck ");
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

