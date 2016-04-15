//
// $Id$

// void construct
inline
STLTriangle::STLTriangle() : m_A(0,0,0), m_B(0,0,0), m_C(0,0,0), m_N(0,0,0), m_normalvalid(false)
{}

// Ordinary contructor
inline
STLTriangle::STLTriangle(const PointR3& A, const PointR3& B, const PointR3& C) : m_A(A), m_B(B), m_C(C), m_N(0,0,0), m_normalvalid(false)
{
	ComputeNormal();
}

// Copy ctor
inline
STLTriangle::STLTriangle(const STLTriangle& T) : m_A(T.m_A), m_B(T.m_B), m_C(T.m_C), m_N(T.m_N),m_normalvalid(T.m_normalvalid)
{}

// Dtor
inline
STLTriangle::~STLTriangle()
{}

// Point A, RO
inline PointR3 STLTriangle::A() const
{
	return m_A;
}

// Point A, W
inline PointR3& STLTriangle::A()
{
	return m_A;
}

// Point B, RO
inline PointR3 STLTriangle::B() const
{
	return m_B;
}

// Point B, W
inline PointR3& STLTriangle::B()
{
	return m_B;
}

// Point C, RO
inline PointR3 STLTriangle::C() const
{
	return m_C;
}

// Point C, W
inline PointR3& STLTriangle::C()
{
	return m_C;
}
// the normal
inline VectoR3 STLTriangle::N() const
{
	return m_N;
}

// reverse the normal
inline void STLTriangle::Reverse()
{
	PointR3 tt(m_B);
	m_B = m_C;
	m_C = tt;
	m_normalvalid = false;
}

// set Z for all points
inline void STLTriangle::SetZ(double z)
{
	m_A.Z() = z;
	m_B.Z() = z;
	m_C.Z() = z;
}

// write data in binary format
/*! https://en.wikipedia.org/wiki/STL_%28file_format%29
 * Because ASCII STL files can become very large, a binary version of STL exists
 * A binary STL file has an 80-character header (which is generally ignored, but
 * should never begin with "solid" because that will lead most software to assume
 * that this is an ASCII STL file[citation needed]). Following the header is a 4-byte
 * unsigned integer indicating the number of triangular facets in the file.
 * Following that is data describing each triangle in turn. The file simply ends
 * after the last triangle.
 *
 * Each triangle is described by twelve 32-bit floating-point numbers: three for
 * the normal and then three for the X/Y/Z coordinate of each vertex – just as with
 * the ASCII version of STL. After these follows a 2-byte ("short") unsigned integer
 * that is the "attribute byte count" – in the standard format, this should be zero
 * because most software does not understand anything else.
 *
 * Floating-point numbers are represented as IEEE floating-point numbers and are
 * assumed to be little-endian, although this is not stated in documentation.
 *
 * UINT8[80] – Header
 * UINT32 – Number of triangles
 *
 * foreach triangle
 *	REAL32[3] – Normal vector
 *	REAL32[3] – Vertex 1
 *	REAL32[3] – Vertex 2
 *	REAL32[3] – Vertex 3
 *	UINT16 – Attribute byte count
 * end
 */
inline void STLTriangle::write(std::ostream& s) const
{
	m_N.write(s);
	m_A.write(s);
	m_B.write(s);
	m_C.write(s);
// 	char cc[2] = {0,0};
// 	s.write(cc, 2);
	uint16_t cc = 0;
	s.write(reinterpret_cast<char*>(&cc), 2);
}

// compute normal from A, B & C
/*! var dir = Vector3.Cross(b - a, c - a);
 *  var norm = Vector3.Normalize(dir);
 */
inline void STLTriangle::ComputeNormal() const
{
	if ( ! m_normalvalid ) {
		m_N = Cross(m_B - m_A, m_C - m_A);
		m_N.Normalize();
		m_normalvalid = true;
	}
}
