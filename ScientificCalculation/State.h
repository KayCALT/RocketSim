#pragma once
//State variable container class.
//Restore the process states.
//Also some general constants and functions.
#include<vector>
using std::vector;
typedef vector<double> Vecd;
typedef vector<vector<double>> Vecd2;

const int NumOfState = 7;
const double PI = 3.14159265;
const double D2R = PI / 180;
const double G= 6.672e-11;
const double M= 5.965e24;

class State
{
public:
	State();
	~State();
	void writeState(Vecd const & vp,Vecd const & vv,double const & mass,double const & t);

public:
	Vecd2 statPos;
	Vecd2 statVel;
	Vecd statMass;
	Vecd statTspan;
};

//Some general functions.(Maybe run against the spirit of OOP?)
double norm2(Vecd const & vec);
Vecd operator+(Vecd const & a,Vecd const & b);
Vecd operator*(double k, Vecd const & v);