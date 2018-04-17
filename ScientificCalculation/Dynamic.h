#pragma once
#include"Rocket.h"
#include"State.h"
#include<cmath>


class Dynamic
{
public:
	Dynamic(Rocket & roc);
	~Dynamic();
public:
	State DataReserve;                             //Restore the calculated states.
	void Calculation(double t);                                    //Runge Kutta 45 numerical integral method.
private:
	Vecd _currentPos;                                      //State vector
	Vecd _currentVel;
	double _currentPhi;
	double getPhi(double t);
	double _currentMass;
	Rocket _roc;
	double _ds[NumOfState];              //Derivatives.
};

