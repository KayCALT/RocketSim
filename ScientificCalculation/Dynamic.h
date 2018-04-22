#pragma once
#include"Rocket.h"
#include"State.h"
#include"Mtrx.h"
#include<cmath>


class Dynamic
{
public:
	Dynamic(Rocket & roc);
	~Dynamic();
public:
	State dataReserve;                             //Restore the calculated states.
    //Runge Kutta 45 numerical integral method.
	void rk45(double t, double h);
private:
	Vecd _currentPos;                                      //State vector
	Vecd _currentVel;
	double _currentPhi;
	double _currentMass;
	Rocket _roc;
	Vecd _ds;            //Derivatives.
	Mtrx _op;

	double getPhi(double t);
	
	void func(double t,Vecd const & r,Vecd const & v,double const & m);
};

