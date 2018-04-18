#include "Mtrx.h"



Mtrx::Mtrx(){}
Mtrx::~Mtrx(){}


//Trans21 Mat*Vec,m must be a 3X3 matrix
Vecd  Mtrx::matTrans21(Vecd2 const & m, Vecd const & v)
{
	Vecd vt(3);
	vt[0] = m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2];
	vt[1] = m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2];
	vt[2] = m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2];
	
	return vt;
}

//3X3 matrix multiplication.(Can be easily adopted to a more general version by using the size() function)
Vecd2 Mtrx::matPrdct22(Vecd2 const & m, Vecd2 const & n)
{
	Vecd2 o(3);
	for (int i = 0; i < 3; i++)
	{
		o[0].push_back(0);
		o[1].push_back(0);
		o[2].push_back(0);
	}
	
	for (int i = 0; i < 3; i++)    //m's row number
	{
		for (int j = 0; j < 3; j++)      //n's column number
		{
			for (int k = 0; k < 3; k++)     //m's column number and n's row number
			{
				o[i][j] =o[i][j]+ m[i][k] * n[k][j];
			}
		}
	}

	return o;
}


//angle in degree.
Vecd2 Mtrx::createTmat(double angle, xyz a)
{
	double ag = angle * D2R;
	Vecd2 mat(3);
	switch (a)
	{
	case Mtrx::x:
		mat[0].push_back(1.0);
		mat[0].push_back(0.0);
		mat[0].push_back(0.0);

		mat[1].push_back(0.0);
		mat[1].push_back(cos(ag));
		mat[1].push_back(sin(ag));

		mat[2].push_back(0.0);
		mat[2].push_back(-sin(ag));
		mat[2].push_back(cos(ag));
		break;
	case Mtrx::y:
		mat[0].push_back(cos(ag));
		mat[0].push_back(0.0);
		mat[0].push_back(-sin(ag));

		mat[1].push_back(0.0);
		mat[1].push_back(1.0);
		mat[1].push_back(0.0);

		mat[2].push_back(sin(ag));
		mat[2].push_back(0.0);
		mat[2].push_back(cos(ag));
		break;
	case Mtrx::z:
		mat[0].push_back(cos(ag));
		mat[0].push_back(sin(ag));
		mat[0].push_back(0);

		mat[1].push_back(-sin(ag));
		mat[1].push_back(cos(ag));
		mat[1].push_back(0);

		mat[2].push_back(0);
		mat[2].push_back(0);
		mat[2].push_back(1);
		break;
	default:
		break;
	}
	return mat;
}
