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
	void calculation(double t);                                    //Runge Kutta 45 numerical integral method.
private:
	Vecd _currentPos;                                      //State vector
	Vecd _currentVel;
	double _currentPhi;
	double getPhi(double t);
	double _currentMass;
	Rocket _roc;
	double _ds[NumOfState];              //Derivatives.

	Mtrx _op;
};

