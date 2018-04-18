#pragma once
#include"State.h"
#include<cmath>
//Operation class Mtrx
//Mainly used for matrix-relating calculation.

class Mtrx
{
public:
	Mtrx();
	~Mtrx();
	enum xyz {
		x,y,z
	};
	Vecd  matTrans21(Vecd2 const & m, Vecd const & v);    //Trans21 Mat*Vec,m must be a 3X3 matrix.(for now)
	Vecd2 matPrdct22(Vecd2 const & m, Vecd2 const & n);   //Matrix multiply.m and n must both be 3X3 matrixs.(for now)
	Vecd2  createTmat(double angle,xyz a);                    //Creat a transformation matrix by specifying the rotation axis.
	
};

