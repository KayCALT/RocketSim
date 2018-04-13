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


