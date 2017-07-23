#pragma once
// additivModel.cpp: определяет точку входа для консольного приложения.

#include <fstream>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>




using namespace std;

class AdditiveModel;



class Data
{
private:


	vector<time_t>d;
	int  count_col1;
	vector<double> v;
public:
	Data(void);
	Data(const Data& toModel); //копирующий
	~Data(void);

protected:
	vector<double>Vx1;
	vector<double>Vy1;
	int count_row1;

public:
	friend AdditiveModel;

	void readFile(void);

	

	void PrintData(void);

};









