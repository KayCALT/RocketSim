// ScientificCalculation.cpp
//Version 1.0.0
#include"State.h"
#include"Mtrx.h"
#include"Dynamic.h"
#include<iostream>
#include<fstream>
using std::cout;
using std::endl;

//改进方向:
//1.代码效率,积分那里的结构
//2.valarray类
//3.更复杂的情况
int main()
{
	Rocket roca;
	Dynamic dyn(roca);
	double tlength = 500;
	double step = 0.1;
	double t = 0;
	do
	{
		dyn.rk45(t, step);
		t += step;
	} while ((t<tlength)&&(dyn.dataReserve.statPos[1].back()>0));          //积分时间内，碰地前停止

	State sout = dyn.dataReserve;

	//输出到文件
	std::ofstream foutp;
	foutp.open(".//output//position.txt");
	foutp << std::fixed;
	foutp.precision(4);
	std::ofstream foutv;
	foutv.open(".//output//velocity.txt");
	foutv << std::fixed;
	foutv.precision(4);
	std::ofstream foutm;
	foutm.open(".//output//mass.txt");
	foutm << std::fixed;
	foutm.precision(4);
	std::ofstream tout;
	tout.open(".//output//tspan.txt");
	tout << std::fixed;
	tout.precision(4);
	for (int i = 0; i < sout.statPos.size(); i++)
	{
		for (int j = 0; j < sout.statPos[i].size(); j++)
		{
			foutp << sout.statPos[i][j] << "  ";
		}
		foutp << endl;
	}
	for (int i = 0; i < sout.statVel.size(); i++)
	{
		for (int j = 0; j < sout.statVel[i].size(); j++)
		{
			foutv << sout.statVel[i][j] << "  ";
		}
		foutv << endl;
	}
	for (int i = 0; i < sout.statMass.size(); i++)
	{
		foutm << sout.statMass[i] << "  ";
	}
	foutm << endl;
	for (int i = 0; i < sout.statTspan.size(); i++)
	{
		tout << sout.statTspan[i] << "  ";
	}
	tout << endl;




	return 0;
}


/*Test codes*/

//State di;
//Vecd ui{ 1,2,3 };
//Mtrx op;
//Vecd2	b = op.createTmat(30, Mtrx::x);
//Vecd2	c = op.createTmat(30, Mtrx::x);
//Vecd tvec = op.matTrans21(b, ui);
//Vecd2 tmat = op.matPrdct22(b, c);
////op.transpose(b);
//for (int i = 0; i < 3; i++)
//{
//	std::cout << tvec[i] << std::endl;
//}
//for (int i = 0; i < 3; i++)
//{
//	for (int j = 0; j < 3; j++)
//	{
//		std::cout << b[i][j] << "  ";
//	}
//	std::cout << std::endl;
//}