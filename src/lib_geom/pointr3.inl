//
// $Id$

    // void construct
    inline
    PointR3::PointR3(float x, float y, float z)
	{
		m_c[0]=x;
		m_c[1]=y;
		m_c[2]=z;
	}

    // Copy ctor
    inline
    PointR3::PointR3(const PointR3& ROp)
	{
		m_c[0] = ROp.m_c[0];
		m_c[1] = ROp.m_c[1];
		m_c[2] = ROp.m_c[2];
	}

    // Destructor
    inline
	PointR3::~PointR3()
	{}

	// Assign another PointR3
	inline PointR3&
	PointR3::operator = (const PointR3& ROp)
	{
		if(this != &ROp) {
			m_c[0] = ROp.m_c[0];
			m_c[1] = ROp.m_c[1];
			m_c[2] = ROp.m_c[2];
		}
		return *this;
	}

    // first component, RW
	inline float&
	PointR3::X()
	{
		return m_c[0];
	}

    // second component, RW
	inline float&
	PointR3::Y()
	{
		return m_c[1];
	}

	// third component, RW
	inline float&
	PointR3::Z()
	{
		return m_c[2];
	}

	// first component, RO
	inline float
	PointR3::X() const
	{
		return m_c[0];
	}

	// second component, RO
	inline float
	PointR3::Y() const
	{
		return m_c[1];
	}

	// third component, RO
	inline float
	PointR3::Z() const
	{
		return m_c[2];
	}

	// Serialisation try, binary output
	inline void
	PointR3::write(std::ostream& s) const
	{
		s.write(reinterpret_cast<const char*>(m_c), 3*sizeof(float));
	}
