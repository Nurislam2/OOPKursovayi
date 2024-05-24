#pragma once
#include <iostream>
#include <vector>
#include "DBconn.h"
#include"ClassMaterial.h"
class ClassBudget:public ClassMaterial
{
public:
	float amount;
	float percent;
	float bonus;
public:
	void Update()
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;

		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE budgets SET BudgetAmount = ?, Percent=?,Bonus=? WHERE id = 1");
		pstmt->setDouble(1, this->amount);
		pstmt->setDouble(2, this->percent);
		pstmt->setDouble(3, this->bonus);
		pstmt->execute();
		system("cls");
		cout << "\033[32m" << " Updated" << "\033[0m" << endl;
		delete pstmt;
		delete con;

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
		float percent,bonus, amount;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT * FROM `budgets`");
		result = pstmt->executeQuery();

		cout << endl << "Áþäæåò" << endl;
		cout << "==============================================================================" << endl;
		cout << "¹\t Amount\t Percent \t Bonus" << endl;
		cout << "------------------------------------------------------------------------------" << endl;

		int num = 1;
		while (result->next()) {
			id = result->getDouble("id");
			amount = result->getDouble("BudgetAmount");
			percent = result->getDouble("Percent");
			bonus = result->getDouble("Bonus");
			this->ids.push_back(id);

			cout << num << "\t" << amount << "\t" << percent << "\t" << bonus << endl;
			cout << "------------------------------------------------------------------------------" << endl;

			num++;
		}
		delete pstmt;
		delete con;
		delete result;
	}
};