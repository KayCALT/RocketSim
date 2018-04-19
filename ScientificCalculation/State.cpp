#include "State.h"



State::State()
	:statPos(3),statVel(3)
{
}


State::~State()
{
}

void State::writeState(Vecd const & vp, Vecd const & vv, double const & phi, double const & mass)
{
	for (int i = 0; i < 3; i++)
	{
		statPos[i].push_back(vp[i]);
		statVel[i].push_back(vv[i]);
	}
	statPhi.push_back(phi);
	statMass.push_back(mass);
}
//vec is supposed to be 3X1(for now)
double norm2(Vecd vec)
{
	double rslt;
	rslt = pow(vec[0] ,2 )+ pow(vec[1] , 2 )+ pow(vec[2] ,2);

	return rslt ;
}

//I assume the size of a and b are equal here.Or it will return an empty vector.
Vecd operator+(Vecd const & a, Vecd const & b)
{
	Vecd vec;
	if (a.size()==b.size())
	{
		for (int i = 0; i < int(a.size()); i++)
		{
			vec.push_back(a[i] + b[i]);
		}
	}
	return vec;
}
