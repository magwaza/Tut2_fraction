/ Mthandeni Magwaza
//211524036

#include "stdafx.h"
#include <iostream>
using namespace std;


class Fraction
{
private:


	int numerator;
	int denominator;

public:
	Fraction(int num = 0, int denom = 1);
	~Fraction();
	void setFract(int, int);
	Fraction getFract();
	Fraction fadd(Fraction add);
	Fraction fsubtract(Fraction subtract);
	Fraction fmultiply(Fraction multiply);
	Fraction fdivide(Fraction divide);
	void print();


};



int main()
{

	Fraction f1, f2, f3, f4, f5, f6, p;
	int a, b, c, d;

	cout << "enter first fraction:" << endl;
	cin >> a >> b;
	cout << "enter second fraction:" << endl;
	cin >> c >> d;
	p.setFract(a, b);
	f1 = p.getFract();
	p.setFract(c, d);
	f2 = p.getFract();
	cout << " adding two fractions\n" << endl;
	f3 = f1.fadd(f2); //Adds the two fractions;     
	f3.print();
	cout << " subtract two fractions\n" << endl;
	f4 = f1.fsubtract(f2); //Subtracts the two fractions    
	f4.print();
	cout << " multiplies two fractions\n" << endl;
	f5 = f1.fmultiply(f2); //Multiplies the two fractions     
	f5.print();
	cout << " divides two fractions\n" << endl;
	f6 = f1.fdivide(f2); //Divides the two fractions    
	f6.print();
	system("pause");
	return 0;
}

Fraction::~Fraction()
{

}

Fraction::Fraction(int a, int b)
{
	setFract(a, b);
}
void Fraction::setFract(int a, int b)
{
	if (b != 0)
	{
		denominator = b;
		numerator = a;
	}
	else
	{
		cout << "division by zero aint allowed" << endl;
		exit(1);
	}
}


Fraction Fraction::getFract()
{
	Fraction f;
	f.denominator = denominator;
	f.numerator = numerator;
	return  f;
}
Fraction Fraction::fadd(Fraction add)
{
	Fraction f;
	f.numerator = numerator * add.denominator + add.numerator * denominator;
	f.denominator = denominator * add.denominator;
	return f;

}
Fraction Fraction::fsubtract(Fraction subtract)
{
	Fraction f;
	f.numerator = numerator * subtract.denominator - subtract.numerator * denominator;
	f.denominator = denominator * subtract.denominator;
	return f;

}
Fraction Fraction::fmultiply(Fraction multiply)
{
	Fraction f;
	f.numerator = numerator * multiply.numerator;
	f.denominator = denominator * multiply.denominator;
	return f;
}
Fraction Fraction::fdivide(Fraction divide)
{
	Fraction f;
	f.numerator = numerator * divide.denominator;
	f.denominator = denominator * divide.numerator;
	return f;
}

void Fraction::print()
{
	{
		int gcf; // greatest common factor variable
		bool finished = false;
		if (denominator == 0)
			denominator = 1; // set denominator to 1 if 0
		if (numerator < 0 && denominator < 0) // set both to positive if both negative
		{
			numerator = -numerator;
			denominator = -denominator;
		}
		if (numerator > 0 && denominator < 0) // change negative from denominator to numerator
		{
			numerator = -numerator;
			denominator = -denominator;
		}

		if (abs(numerator) > abs(denominator)) // set gcf to larger of denominator / numerator
			gcf = abs(denominator);
		else
			gcf = abs(numerator);

		while (!finished && gcf >= 2)
		{
			if (numerator % gcf == 0 && denominator % gcf == 0) // find greatest common factor
			{
				numerator = numerator / gcf;
				denominator = denominator / gcf; // reduce by dividing by greatest common factor
				finished = true;
			}
			gcf--;
		}
	}


	cout << "The answer is:" << numerator << " / " << denominator << endl;
}



