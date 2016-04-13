//
// $Id$

#include <martiniquehm/pointr3.h>

namespace MartiniqueHM {

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
