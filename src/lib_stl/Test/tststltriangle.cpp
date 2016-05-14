//
// $Id$

#include <common.h>
#include <martiniquehm/stl_triangle.h>

using namespace MartiniqueHM;

int main (int argc, char* argv[])
{
    COPYRIGHT("test STLTriangle", "0.1");

	WATCH(sizeof(float));
	WATCH(sizeof(double));

	STLTriangle T0;
	T0.info();

	// a non-void triangle
	PointR3 A(5, 1, 1);
	PointR3 B(11, 6, 2);
	PointR3 C(4, 7, 3);
	STLTriangle T1 (A, B, C);
	cout<<T1<<endl;

	return 0;
}
