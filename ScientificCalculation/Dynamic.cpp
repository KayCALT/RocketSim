#include "Dynamic.h"



Dynamic::Dynamic(Rocket & roc)
	:_roc(roc),
	_currentPos{roc._position[0],roc._position[1],roc._position[2]},
	_currentVel{roc._velocity[0],roc._velocity[1],roc._velocity[2]},
	_currentPhi{roc._phi},
	_currentMass{roc._mass},
	_ds(NumOfState)
{}


Dynamic::~Dynamic()
{
}

//Calculation.

void Dynamic::rk45(double t,double h)
{
	func(t, _currentPos, _currentVel, _currentMass);
	Vecd k1 = h * _ds;
	_currentPos[0] +=0.5* k1[0];
	_currentPos[1] += 0.5*k1[1];
	_currentPos[2] += 0.5*k1[2];
	_currentVel[0] += 0.5*k1[3];
	_currentVel[1] += 0.5*k1[4];
	_currentVel[2] += 0.5*k1[5];
	_currentMass += 0.5*k1[6];
	func(t, _currentPos, _currentVel, _currentMass);
	Vecd k2 = h * _ds;
	_currentPos[0] += 0.5* k2[0];
	_currentPos[1] += 0.5*k2[1];
	_currentPos[2] += 0.5*k2[2];
	_currentVel[0] += 0.5*k2[3];
	_currentVel[1] += 0.5*k2[4];
	_currentVel[2] += 0.5*k2[5];
	_currentMass += 0.5*k2[6];
	func(t, _currentPos, _currentVel, _currentMass);
	Vecd k3 = h * _ds;
	_currentPos[0] +=  k3[0];
	_currentPos[1] += k3[1];
	_currentPos[2] += k3[2];
	_currentVel[0] += k3[3];
	_currentVel[1] += k3[4];
	_currentVel[2] += k3[5];
	_currentMass += k3[6];
	func(t, _currentPos, _currentVel, _currentMass);
	Vecd k4 = h * _ds;

	Vecd ka =_op.vecNumpro(1.0/6.0,k1 + 2*k2 + 2*k3 + k4);
	_currentPos[0] += ka[0];
	_currentPos[1] += ka[1];
	_currentPos[2] += ka[2];
	_currentVel[0] += ka[3];
	_currentVel[1] += ka[4];
	_currentVel[2] += ka[5];
	_currentMass += ka[6];

	dataReserve.writeState(_currentPos, _currentVel, _currentMass,t);

}

//r is currentPos, v is currentVel, m is currentMass.
void Dynamic::func(double t,Vecd const & r, Vecd const & v, double const & m)
{
	_currentPhi = getPhi(t);
	double Thrust = (_currentMass > _roc._tOff)*_roc._propulsion;      //推力值
	double q = 0.5*1.226*exp(-0.1378*r[1] / 1000.0)*norm2(v);   //动压
	Vecd R{ -_roc._cx *q*_roc._s,_roc._cy*q*_roc._alp*_roc._s,0 };    //气动力
	Vecd P{ Thrust,0,0 };
	Vecd R0{ 0,6378140,0 };
	Vecd e = (1 / sqrt(norm2(R0 + r)))*( R0 + r);
	//转移矩阵和坐标系下的力
	Vecd2	Bg = _op.createTmat(_currentPhi, Mtrx::z);
	_op.transpose(Bg);
	Vecd2 Bv = _op.createTmat(_roc._alp, Mtrx::z);
	P = _op.matTrans21(Bg, P);
	R = _op.matTrans21(_op.matPrdct22(Bg, Bv), R);         //相关力转移到地惯系下
	Vecd g = (-G * M / (norm2(R0 + r)))* e;
	Vecd F = P + R + g;
	Vecd a = (1.0 / m)* F;
	double dm = (t < _roc._tOff)*_roc._dm;

	//动态导数
	_ds[0] = _currentVel[0];
	_ds[1] = _currentVel[1];
	_ds[2] = _currentVel[2];
	_ds[3] = a[0];
	_ds[4] = a[1];
	_ds[5] = a[2];
	_ds[6] = dm;

	return ;
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
