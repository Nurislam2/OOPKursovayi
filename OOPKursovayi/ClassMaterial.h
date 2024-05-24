#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "DBconn.h"
class ClassMaterial
{
public:
	vector<int> ids;
	
public:
	virtual int Get_id(){
		return 0;
	}
	virtual void Update(int id, string name){}
	virtual void Update(int id, int id_unit){}
	virtual void Insert(string name, int id_unit){}
	virtual void Delete(int id){}
	virtual int Check() {
		return 0;

	}
	virtual void Print(){}

};
