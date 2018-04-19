#include "Dynamic.h"



Dynamic::Dynamic(Rocket & roc)
	:_roc(roc),
	_currentPos{roc._position[0],roc._position[1],roc._position[2]},
	_currentVel{roc._velocity[0],roc._velocity[1],roc._velocity[2]},
	_currentPhi{roc._phi},
	_currentMass{roc._mass}
{}


Dynamic::~Dynamic()
{
}

//Calculation.
void Dynamic::calculation(double t)
{
	
	_currentPhi = getPhi(t);
	double Thrust = (_currentMass > _roc._tOff)*_roc._propulsion;      //The thrust.
	double q = 0.5*1.226*exp(-0.1378*_currentPos[1] / 1000.0)*norm2(_currentVel);   //Dynamic pressure.
	Vecd R{ -_roc._cx *q*_roc._s,_roc._cy*q*_roc._alp*_roc._s,0};    //Aerodynamic force in velocity coordinate.
	Vecd P{ Thrust,0,0 };
	Vecd R0{ 0,6378140,0 };
	Vecd e = _op.vecNumpro(1 / sqrt(norm2(R0 + _currentPos)), R0 + _currentPos);
	//要用到转置、分量式推导了,基本是计算的最后一步了。
	Vecd2	Bg = _op.createTmat(_currentPhi, Mtrx::z);
	_op.transpose(Bg);
	Vecd2 Bv = _op.createTmat(_roc._alp, Mtrx::z);
	P = _op.matTrans21(Bg, P);
	R = _op.matTrans21(_op.matPrdct22(Bg, Bv), R);         //相关力转移到地惯系下
	Vecd g = _op.vecNumpro(-G * M / (norm2(R0 + _currentPos)), e);
}


//Get schemed pitch angle.
double Dynamic::getPhi(double t)
{
	double &  t1 = _roc._t1;
	double phi;
	if (t<t1)
	{
		phi = PI / 2;
	}
	else if (t<t1 + 2)
	{
		phi = PI / 2 + _roc._alp;
	}
	else if (t<30)
	{
		phi = atan2(_currentVel[2], _currentVel[1] + 1e-20) + _roc._alp;
	}
	else
	{
		phi = atan2(_currentVel[2], _currentVel[1]);
	}
	return phi;
}
