// ScientificCalculation.cpp
//
#include"State.h"
#include"Mtrx.h"
#include<iostream>

int main()
{
	State di;
	Vecd ui{ 1,2,3 };
	Mtrx op;
	Vecd2	b = op.createTmat(30, Mtrx::x);
	Vecd2	c = op.createTmat(30, Mtrx::x);
	Vecd tvec = op.matTrans21(b, ui);
	Vecd2 tmat = op.matPrdct22(b, c);
	//op.transpose(b);
	for (int i = 0; i < 3; i++)
	{
		std::cout << tvec[i] << std::endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << b[i][j] << "  ";
		}
		std::cout << std::endl;
	}

	return 0;
}

