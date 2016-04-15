//
// $Id$

#include <martiniquehm/pointr3.h>
#include <martiniquehm/vector3.h>

namespace MartiniqueHM {

	// create a vector from 2 points, V = AB = B-A
	VectoR3 operator- (const PointR3& B, const PointR3& A)
	{
		return VectoR3 (B.X()-A.X(), B.Y()-A.Y(), B.Z()-A.Z());
	}

	// Standard info function.
	void PointR3::info(std::ostream& s, bool debug) const
	{
		s<<"PointR3 : ["<<m_c[0]<<' '<<m_c[1]<<' '<<m_c[2]<<"]\n";
	}

	// Serialisation try, ascii output
	std::ostream& operator<< (std::ostream& s, const PointR3& Pt)
	{
		s<<Pt.X()<<' '<<Pt.Y()<<' '<<Pt.Z();
		return s;
	}

} // namespace
