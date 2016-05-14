//
// $Id$

#include <common.h>
#include <martiniquehm/stl_triangle.h>
#include <martiniquehm/stl_writer.h>

using namespace MartiniqueHM;

int main (int argc, char* argv[])
{
    COPYRIGHT("test tststlwriter", "0.1");

	// create a set of triangle for a tetraheron
	PointR3 A( 1,  0, -0.70711);
	PointR3 B( 0,  1,  0.70711);
	PointR3 C(-1,  0, -0.70711);
	PointR3 D( 0, -1,  0.70711);

	// The 4 triangles
	STLTriangle T0 (A, B, D);
	STLTriangle T1 (B, C, D);
	STLTriangle T2 (A, C, B);
	STLTriangle T3 (A, D, C);

	// Writing in ascii
	STLWriterAscii swa("tetra-ascii.stl");
	swa.write_header(4);
	swa.write_data(T0);
	swa.write_data(T1);
	swa.write_data(T2);
	swa.write_data(T3);
	swa.write_trailer();

	// writing in binary
	STLWriterBinary swb("tetra-binary.stl");
	swb.write_header(4);
	swb.write_data(T0);
	swb.write_data(T1);
	swb.write_data(T2);
	swb.write_data(T3);
	swb.write_trailer();

    return 0;
}
