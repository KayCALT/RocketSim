#include "Rocket.h"





Rocket::Rocket(double mass, double propulsion, double dm,double cx,double cy)
	:_mass(mass),_propulsion(propulsion),_dm(dm),_position{0,0,0},_velocity{0,0,0},_phi{0},_cx{cx},_cy{cy}
{
}



Rocket::~Rocket()
{
}

void Rocket::stateRefresh(State const & dy)
{
}



