#pragma once
//State variable container class.

#include<vector>
using std::vector;
typedef vector<double> Vecd;
typedef vector<vector<double>> Vecd2;

const int NumOfState = 8;

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

