// additivModel.cpp: ���������� ����� ����� ��� ����������� ����������.

#include "Data.h"


using namespace std;

Data::Data(void) :Vy1(0), Vx1(0), count_row1(0) {}

Data::Data(const Data& toModel) { *this = toModel; }

Data::~Data(void) {}

void Data::readFile(void)
{
		vector<double>Vi;
		vector<double>Vj;
		std::ifstream stream("C:\\Users\\nmaga\\Desktop\\����� �����\\dollar.txt");
		vector<double> v;


		int count_digit = 0; //���������� ����� � �����
		if (stream.is_open()) {
			double bufDownloadVector;
			while (!stream.eof()) {

				//������� ������� ���� ���� � ����������� ����� ����� ��� ����� �����.

				//������ ����� ����� � �������

				stream >> bufDownloadVector; //��� ������ �� ������������ ����� ��������� � �����
				count_digit++;//����������� ������� ����� �����
				v.push_back(bufDownloadVector);
			}
			count_digit = count_digit - 1;



			int count_col;
			count_col = 2;//������������ ����� �������� (�� ������� ������ ����� ��������)
			int count_row;
			count_row = count_digit / count_col; //������������ ���������� �����


			double **massiv;

			massiv = new double*[count_row];

			for (int i = 0; i < count_row; i++)
			{
				massiv[i] = new double[count_col];
			}

			//��������� ������� �� �����
			for (int i = 0; i < count_row; i++)
			{
				for (int j = 0; j < count_col; j++)
				{
					massiv[i][j] = v.at(i*count_col + j);
				}
			}

			for (int i = 0; i < count_row; i++)
			{
				Vi.push_back(massiv[i][0]);

				Vj.push_back(massiv[i][1]);


			}

			this->count_row1 = count_row;
			this->count_col1 = count_col;
			this->v = v;
			this->Vx1 = Vi;
			this->Vy1 = Vj;



			stream.close();

			for (int i = 0; i < count_row; i++)
			{
				delete[] massiv[i];
			}
			delete[] massiv;

		}
		else {
			cout << "���� �� ��������" << endl;
		}



	}


void Data::PrintData(void){


		std::cout << "Vy:"; for (auto &it : Vy1) { std::cout << it << " "; }
		std::cout << "\nVx:"; for (auto &it : Vx1) { std::cout << it << " "; }
		

	}
















