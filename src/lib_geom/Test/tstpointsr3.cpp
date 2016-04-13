//
// $Id$

#include <assabib/framic_defs.h>
#include <martiniquehm/pointr3.h>

using namespace MartiniqueHM;

int main (int argc, char* argv[])
{
    COPYRIGHT("test pointR3", "0.1");

	PointR3 A;
	A.info();
	PointR3 B(1, 2, 3);
	cout<<B<<endl;

	A = B;
	A.info();

	return 0;
}


//./tst -f totofile.dat --outDir=~/Data/ -e essai.ini -q file1.dat file2.dat
