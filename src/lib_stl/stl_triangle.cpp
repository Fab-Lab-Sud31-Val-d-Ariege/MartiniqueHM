//
// $Id$

#include <martiniquehm/stl_triangle.h>

namespace MartiniqueHM {

// Standard info function.
void info(std::ostream& s, bool debug) const
{
	s<<"[STLTriangle]\n\tPoint A : "; m_A.info(s);
	s<<"\tPoint B : "; m_B.info(s);
	s<<"\tPoint C : "; m_C.info(s);
	s<<"\tNormal  : "; m_C.info(s);
}

// Serialisation try, ascii output
friend std::ostream& operator<< (std::ostream& s, const STLTriangle& fs)
{
	s<<"  facet normal "<<m_N<<'\n';
	s<<"    outer loop\n";
	s<<"      vertex "<<m_A<<"\n";
	s<<"      vertex "<<m_B<<"\n";
	s<<"      vertex "<<m_C<<"\n";
	s<<"    endloop\n";
	s<<"  endfacet\n";
}

} // namespace
