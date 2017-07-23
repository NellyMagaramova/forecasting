#pragma once

#include <ctime>//для того чтобы ряд X привести к календарному виду
#include <cmath>
#include <iomanip>//для определения манипулятора
#include "Data.h"

using namespace std;

class AdditiveModel:public Data
{
protected:


private:

	vector<double>Vx;
	vector<double>Vy;
	int count_row;

	vector<double>T;
	
	vector<int>month;
	vector<int>year;
	
	vector<double>tga;
	double STgA;
	double A;
	double B;
	double SumVy;
	double SumVx;
	int countS;
	vector<double>St;
	vector<double>MovAvg;
	vector<double>E;
	vector<double>y;





public:

	//AdditiveModel(int count_row,double Vx,double Vy);
	AdditiveModel(const Data&);
	/*void operator()(const Data &obj) {
		this->newVx = obj.Vx;
		this->newVy = obj.Vy;
		this->newcount_row = obj.count_row;
	}*/
	~AdditiveModel(void);



	


	void tgA();
	void sumXY();
	void Bmst();
	void Amst();
	void Tt();
	void MovingAverage();
	void S();
	void Err(void);
	void Y(void);
	void PrintData(void);



};