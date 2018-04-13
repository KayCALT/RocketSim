#include "Dynamic.h"



Dynamic::Dynamic(Rocket & roc)
	:_roc(roc),
	currentPos{roc._position[0],roc._position[1],roc._position[2]},
	currentVel{roc._velocity[0],roc._velocity[1],roc._velocity[2]},
	currentPhi{roc._phi},
	currentMass{roc._mass}
{}


Dynamic::~Dynamic()
{
}
