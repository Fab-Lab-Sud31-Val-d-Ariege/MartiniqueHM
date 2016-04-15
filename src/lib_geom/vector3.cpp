//
// $Id$

#include <cmath>
#include <martiniquehm/vector3.h>

namespace MartiniqueHM {

	// set vector length to 1
	void VectoR3::Normalize()
	{
		float ll = sqrt(m_c[0]*m_c[0] + m_c[1]*m_c[1] + m_c[2]*m_c[2]);
		if ( ll != 0. ) {
			m_c[0] /= ll;
			m_c[1] /= ll;
			m_c[2] /= ll;
		}
	}

	// cross product
	// 	cx = aybz − azby
	// 	cy = azbx − axbz
	// 	cz = axby − aybx

	VectoR3 Cross(const VectoR3& A, const VectoR3& B)
	{
		float x = A.Y()*B.Z() - A.Z()*B.Y();
		float y = A.Z()*B.X() - A.X()*B.Z();
		float z = A.X()*B.Y() - A.Y()*B.X();
		return VectoR3(x, y, z);
	}

	// Standard info function.
	void VectoR3::info(std::ostream& s, bool debug) const
	{
		s<<"VectoR3 : ["<<m_c[0]<<' '<<m_c[1]<<' '<<m_c[2]<<"]\n";
	}
} // namespace
