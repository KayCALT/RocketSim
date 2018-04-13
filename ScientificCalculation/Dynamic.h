#pragma once
#include"Rocket.h"
#include"State.h"



class Dynamic
{
public:
	Dynamic(Rocket & roc);
	~Dynamic();
public:
	Vecd currentPos;                                      //State vector, i.e., [pos,vel,phi,m]
	Vecd currentVel;
	double currentPhi;
	double currentMass;
private:
	Rocket _roc;
	double _ds[NumOfState];              //Derivatives.
};

