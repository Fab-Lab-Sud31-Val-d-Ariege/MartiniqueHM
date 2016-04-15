//
// $Id$

#include <martiniquehm/stl_triangle.h>

namespace MartiniqueHM {

	// Standard info function.
	void STLTriangle::info(std::ostream& s, bool debug) const
	{
		if ( !m_normalvalid ) ComputeNormal();
		s<<"[STLTriangle]\n\tPoint A : "; m_A.info(s);
		s<<"\tPoint B : "; m_B.info(s);
		s<<"\tPoint C : "; m_C.info(s);
		s<<"\tNormal  : "; m_N.info(s);
	}

	// Serialisation try, ascii output
	std::ostream& operator<< (std::ostream& s, const STLTriangle& fs)
	{
		if ( !fs.m_normalvalid ) fs.ComputeNormal();
		s<<"  facet normal "<<fs.m_N<<'\n';
		s<<"    outer loop\n";
		s<<"      vertex "<<fs.m_A<<"\n";
		s<<"      vertex "<<fs.m_B<<"\n";
		s<<"      vertex "<<fs.m_C<<"\n";
		s<<"    endloop\n";
		s<<"  endfacet\n";
		return s;
	}

} // namespace
