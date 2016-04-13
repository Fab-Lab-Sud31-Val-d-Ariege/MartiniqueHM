//
// $Id$

// void construct
STLTriangle() m_A(0,0,0); m_B(0,0,0), m_C(0,0,0), m_N(0,0,0),m_normalvalid(false);
{

}

// Ordinary contructor
STLTriangle(const PointR3& A, const PointR3& B, const PointR3& C) m_A(A); m_B(B), m_C(C), m_N(0,0,0),m_normalvalid(false);
{
	ComputeNormal();
}

// Copy ctor
STLTriangle(const STLTriangle& T) m_A(T.m_A); m_B(T.m_B), m_C(T.m_C), m_N(T.m_N),m_normalvalid(T.m_normalvalid);
{

}

// Dtor
virtual ~STLTriangle()
{

}

// Point A, RO
PointR3 A() const
{
	return m_A;
}

// Point A, W
PointR3& A()
{
	return m_A;
}

// Point B, RO
PointR3 B() const
{
	return m_B;
}

// Point B, W
PointR3& B()
{
	return m_B;
}

// Point C, RO
PointR3 C() const
{
	return m_C;
}

// Point C, W
PointR3& C()
{
	return m_C;
}
// the normal
PointR3 N() const
{
	return m_N;
}

// reverse the normal
void Reverse()
{
	PointR3 tt(m_B);
	m_B = m_C;
	m_C = tt;
	m_normalvalid = false;
}

// set Z for all points
void SetZ(double z)
{
	m_A.Z() = z;
	m_B.Z() = z;
	m_C.Z() = z;
}

// write data in binary format
void write(std::ostream& s) const
{

}

// compute normal from A, B & C
/*! var dir = Vector3.Cross(b - a, c - a);
 * var norm = Vector3.Normalize(dir);
 */
void ComputeNormal()
{

}
