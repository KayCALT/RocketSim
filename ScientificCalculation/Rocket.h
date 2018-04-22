#pragma once
#include"State.h"



class Rocket
{
public:
	Rocket(double mass = 3000, double propulsion = 74000, double dm=-8,double cx=0.3,double cy=0.03,double s=0.785,double to=25);
	~Rocket();
	//Refresh state from Dynamic.
	//void stateRefresh(State const & dyn);
	//dfas
	friend class Dynamic;
private:
	
	double _propulsion;        //In Newton.
	double _dm;                    //Comsuming speed of fuel.
	double _cx;
	double _cy;
	double _t1;                      //The stop time of .
	double _s;
	double _tOff;
	double _alp;                    //1st version will adopt a const AOA.
	//States
	Vecd  _position;          //In m.
	Vecd  _velocity;		    //In m/s.
	double _phi;                //Pitch angle.
	double _mass;             //In kg.

};

