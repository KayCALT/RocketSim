#include "Rocket.h"





Rocket::Rocket(double mass, double propulsion, double dm,double cx,double cy,double s,double to)
	:_mass(mass),_propulsion(propulsion),_dm(dm),_position{0,0,0},_velocity{0,0,0},_phi{0},_cx{cx},_cy{cy},_alp{-3*D2R},_tOff{to},_s{s}
{
	double pdg = _propulsion / (_mass*9.8);
	_t1 = sqrt(40 / (pdg - 1));
}



Rocket::~Rocket()
{
}

//void Rocket::stateRefresh(State const & dy)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		_position[i] = dy.statPos[i].back();
//		_velocity[i] = dy.statVel[i].back();
//	}
//	_phi = dy.statPhi.back();
//	_mass = dy.statMass.back();
//}



