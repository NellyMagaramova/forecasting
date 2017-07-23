#include "Additive.h"
//AdditiveModel::AdditiveModel(int count_row,double  Vx,double  Vy): Vy(0), Vx(0), count_row(0) {}
AdditiveModel::AdditiveModel(const Data& toModel) :Data(toModel) {
	this->Vx = toModel.Vx1;
	this->Vy = toModel.Vy1;
	this->count_row = toModel.count_row1;
}
AdditiveModel::~AdditiveModel(void) {}
void AdditiveModel::tgA()
 {
		vector<double>tg;
		struct tm *timeinfo;
		vector<int>m;//month
		vector<int>y;//year

		int month, month1;
		int year, year1;
		double D;
		double g;
		double SumTgA;
		double Vy1P;
		double VyP;
		int i;
		int n;
		double tga1; //тангенс


		n = this->count_row;

		D = Vx.at(0);

		//в переменные задаю значение первого месяца и года
		month1 = (int)(modf(D, &g) * 100);
		year1 = (int)g;

		//добавляем в вектора первое значение года и месяца
		y.push_back(year1);

		if (month1 != NULL) {
			m.push_back(month1);
		}

		Vy1P = Vy.at(0);//переменную инициализирую нулевым элементом из вектора


		/*подсчитываю  разность между двумя соседними элементами.
		создаю временную переменную  в которой храню сначало нулевой элемент, а потом каждый раз в цикле присваиваю ему
		новое значение;
		в массив Vy передаю значение текущего элемента. аналогично с month и year*/
		for (i = 1; i < n; i++) {
			timeinfo = new tm;
			VyP = Vy.at(i);



			D = Vx.at(i);

			month = (int)(modf(D, &g) * 100);
			year = (int)g;
			//	timeinfo->tm_year = year;
			timeinfo->tm_mon = month;
			timeinfo->tm_year = year;


			//если во временном ряде только данные по году, то по  месяцу не анализируем
			if (month == NULL) {
				tga1 = double((VyP - Vy1P)) / (abs(timeinfo->tm_year - year1));
				tg.push_back(tga1);
				year1 = timeinfo->tm_year;
				y.push_back(year1);

			}
			else {
				tga1 = double((VyP - Vy1P)) / (abs(timeinfo->tm_mon - month1));
				tg.push_back(tga1);

				month1 = timeinfo->tm_mon;
				m.push_back(month1);
			}

			Vy1P = VyP;
			this->month = m;
			this->year = y;



			delete timeinfo;
		}
		this->tga = tg;
		SumTgA = 0;
		for (auto it = tg.begin(); it != tg.end(); it++) {
			SumTgA = SumTgA + *it;

		}
		this->STgA = SumTgA;



	}
//
void AdditiveModel::sumXY() {
		//необходимо подсчитать сумму всех элементов по ряду условные единиц(vewVy)
		//и по временному ряду. 
		double SumY;
		int SumX;


		SumY = 0;
		SumX = 0;
		for (int i = 0; i<count_row; i++)
		{
			SumX = SumX + 1;

		}

		for (auto it = Vy.begin(); it != Vy.end(); it++)
		{
			SumY = SumY + *it;

		}
		this->SumVy = SumY;
		this->SumVx = SumX;
	}
//
void AdditiveModel::Bmst() {
		double k;
		double b;
		

		k = ((count_row - 1)*count_row) / 2;
		b = STgA / k;

		this->B = b;
	}
void AdditiveModel::Amst() {
		double a;

		a = (SumVy - SumVx) / count_row;
		this->A = a;
	}
//
void AdditiveModel::Tt() {
		vector<double>T2;
		double t;

		for (int i = 0; i<count_row; i++)
		{
			t = A + B*i;
			T2.push_back(t);
		}
		this->T = T2;
	}

void AdditiveModel::MovingAverage() {

	vector<double>Mavg;
	vector<double>M;
	int n;

	n = 4;
	int m;
	m = count_row - n;

	std::vector<std::vector<double>> y;
	int row(0);


	for (size_t i = 0; i < Vy.size() - (n + 1); i++)
	{

		y.push_back(std::vector<double>());


		y.at(row).push_back(Vy.at(i) / 2);



		for (int k = i + 1; k != (i + n - 1); k++) {
			y.at(row).push_back(Vy.at(k));

		}

		y.at(row).push_back(Vy.at(i + n - 1) / 2);
		++row;
	}
	double Sum;

	for (size_t it = 0; it <y.size(); it++)
	{
		Sum = 0;
		for (size_t j = 0; j < y.at(it).size(); j++) {
			Sum = Sum + y.at(it).at(j);

		}
		double sumResult;
		sumResult = Sum / n;
		Mavg.push_back(sumResult);
	}
	this->countS = Mavg.size();
	this->MovAvg = Mavg;



}
void AdditiveModel::S() {
	vector<double>s1;
	for (int i = 0; i < countS; i++) {
		s1.push_back(Vy[i] - MovAvg[i]);
	}
	this->St = s1;
}

void AdditiveModel::Err(void) {
	vector<double>e;
	for (size_t i = 0; i < St.size(); i++) {
		e.push_back(Vy[i] - (T[i] + St[i]));
	}
	this->E = e;
}

void AdditiveModel::Y(void) {

	vector<double>yy;
	for (size_t i = 0; i < E.size(); i++)
	{
		yy.push_back(T[i] + E[i] + St[i]);

	}
	this->y = yy;
}



void AdditiveModel::PrintData(void) {


	int m;
	int j;

	std::cout << "Vy:"; for (auto &it : Vy) { std::cout << it << " "; }
	std::cout << "\nT:"; for (auto &it : T) { std::cout << it << " "; }
	std::cout << "\nSi:"; for (auto &it : St) { std::cout << it << " "; }
	std::cout << "\nE:"; for (auto &it : E) { std::cout << it << " "; }

	cout << "\n \n \n Additive model\n\n";
	cout << "Year\t" << "Month \t" << "Value";


	j = 0;
	std::cout << "\n ";


	for (auto &it : year) {
		//resultFile << it<<"\t";
		for (auto &i : y)

		{

			m = month.at(j);
			//resultFile<<month[q]<<"\t"<<year[q]<<"\t"<< y[q]<<"\n";
			cout << it << "\t" << m << "\t" << i << "\n";
			j = j + 1;
		}


		//y.clear();
	

	}



}







