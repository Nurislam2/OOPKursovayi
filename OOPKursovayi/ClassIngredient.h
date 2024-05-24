#pragma once
#include <iostream>
#include <vector>
#include "DBconn.h"
class ClassIngredient
{
public:
	vector<int> ids;
	int product;
	int rawMaterial;
	float quantity;
public:
	int Get_id()

	{
		setlocale(LC_ALL, "ru");

		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int id_prod;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT finished_products.name AS product, ingredients.id, raw_materials.name AS raw, ingredients.quantity,\
		unit_of_measurements.name AS unit_of_measurements\
		FROM ingredients\
		INNER JOIN raw_materials ON ingredients.raw_material_id = raw_materials.id\
		INNER JOIN unit_of_measurements ON raw_materials.unit_of_measurement_id = unit_of_measurements.id\
		INNER JOIN finished_products ON ingredients.finished_product_id = finished_products.id\
		ORDER BY finished_products.name;");
		result = pstmt->executeQuery();
		this->ids.clear();
		cout << endl << "Cписок  Ингредиентов" << endl;
		int num = 1;
		while (result->next()) {
			int id = result->getInt("id");
			string name = result->getString("product").c_str();
			string prod = result->getString("raw").c_str();
			float quantity = result->getDouble("quantity");
			string unit = result->getString("unit_of_measurements").c_str();
			this->ids.push_back(id);
			std::cout << "№ " << num << ", Product: " << name << ", Raw mat: " << name << ", Quantity: " << name << ", unit_of_measurements: " << name << std::endl;
			num++;
		}


		cout << "Выберите номер  Ингредиента: ";
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
	void UpdateRawMaterial(int id) {
		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("UPDATE ingredients SET raw_material_id = ? WHERE id = ?");
			pstmt->setInt(1, this->rawMaterial);
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
	void UpdateQunatity(int id) {
		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("UPDATE ingredients SET qunatity = ? WHERE id = ?");
			pstmt->setInt(1, this->quantity);
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
	void Insert() {
		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("INSERT INTO `ingredients`(`finished_product_id`, `raw_material_id`, `quantity`) VALUES (?,?,?)");
			pstmt->setInt(1, this->product);
			pstmt->setInt(2, this->rawMaterial);
			pstmt->setDouble(3, this->quantity);
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
	void Delete(int id) {
		try
		{
			sql::PreparedStatement* pstmt;
			sql::Connection* con;
			con = ConectDB();
			pstmt = con->prepareStatement("Delete from ingredients Where id=?");
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
	void Print() {
		setlocale(LC_ALL, "ru");

		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int id_prod;
		con = ConectDB();
		pstmt = con->prepareStatement("SELECT finished_products.name AS product, ingredients.id, raw_materials.name AS raw, ingredients.quantity,\
		unit_of_measurements.name AS unit_of_measurements\
		FROM ingredients\
		INNER JOIN raw_materials ON ingredients.raw_material_id = raw_materials.id\
		INNER JOIN unit_of_measurements ON raw_materials.unit_of_measurement_id = unit_of_measurements.id\
		INNER JOIN finished_products ON ingredients.finished_product_id = finished_products.id\
		ORDER BY finished_products.name;");
		result = pstmt->executeQuery();
		this->ids.clear();
		cout << endl << "Cписок  Ингредиентов" << endl;
		int num = 1;
		while (result->next()) {
			int id = result->getInt("id");
			string name = result->getString("product").c_str();
			string prod = result->getString("raw").c_str();
			float quantity = result->getDouble("quantity");
			string unit = result->getString("unit_of_measurements").c_str();
			this->ids.push_back(id);
			std::cout << "№ " << num << ", Product: " << name << ", Raw mat: " << name << ", Quantity: " << name << ", unit_of_measurements: " << name << std::endl;
			num++;
		}
	}
};

