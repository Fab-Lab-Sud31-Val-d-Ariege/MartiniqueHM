//
// $Id$


// void construct
inline
VectoR3::VectoR3(float x, float y, float z)
{
	m_c[0] = x;
	m_c[1] = y;
	m_c[2] = z;
}

// void construct
inline
VectoR3::VectoR3(const PointR3& A, const PointR3& B)
{
	m_c[0] = A.X() - B.X();
	m_c[1] = A.Y() - B.Y();
	m_c[2] = A.Z() - B.Z();
}

// Copy ctor
inline
VectoR3::VectoR3(const VectoR3& A)
{
	m_c[0] = A.X();
	m_c[1] = A.Y();
	m_c[2] = A.Z();
}

// Destructor
inline
VectoR3::~VectoR3()
{}
