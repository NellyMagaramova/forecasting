#include "Data.h"
#include "Additive.h"

int main()
{
	Data a;
	
	a.readFile();

	AdditiveModel b(a);
	
	b.tgA();
	b.sumXY();
	b.Bmst();
	b.Amst();
	b.Tt();

	b.MovingAverage();
	b.S();
	b.Err();
	b.Y();
	b.PrintData();




	system("pause");
	return 0;
}