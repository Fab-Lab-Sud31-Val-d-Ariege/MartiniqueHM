//
// $Id$

#include <common.h>
#include <martiniquehm/vector3.h>

using namespace MartiniqueHM;

int main (int argc, char* argv[])
{
    COPYRIGHT("test pointR3", "0.1");

	VectoR3 U(100, 10, 1);
	U.info();

	PointR3 A(0, 0, 0);
	A.info();
	PointR3 B(5, 0, 0);
	B.info();
	VectoR3 U2 = B - A;
	U2.info();

	VectoR3 I(2, 0, 0);
	VectoR3 J(0, 10, 0);
	VectoR3 K = Cross(I, J);
	K.info();
	K.Normalize();
	K.info();
	return 0;
}

