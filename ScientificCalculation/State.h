#pragma once
//State variable container class.
//Restore the process states.
#include<vector>
using std::vector;
typedef vector<double> Vecd;
typedef vector<vector<double>> Vecd2;

const int NumOfState = 8;
const double PI = 3.14159265;
const double D2R = PI / 180;
const double G= 6.672e-11;
const double M= 5.965e24;

class State
{
public:
	State();
	~State();
	void writeState(Vecd const & vp,Vecd const & vv,double const & phi,double const & mass);

public:
	Vecd2 statPos;
	Vecd2 statVel;
	Vecd statPhi;
	Vecd statMass;

};

double norm2(Vecd vec);
