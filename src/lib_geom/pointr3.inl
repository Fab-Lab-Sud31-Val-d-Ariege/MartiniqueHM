//
// $Id$

    // void construct
    inline
    PointR3::PointR3(double x, double y, double z)
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
	inline double&
	PointR3::X()
	{
		return m_c[0];
	}

    // second component, RW
	inline double&
	PointR3::Y()
	{
		return m_c[1];
	}

	// third component, RW
	inline double&
	PointR3::Z()
	{
		return m_c[2];
	}

	// first component, RO
	inline double
	PointR3::X() const
	{
		return m_c[0];
	}

	// second component, RO
	inline double
	PointR3::Y() const
	{
		return m_c[1];
	}

	// third component, RO
	inline double
	PointR3::Z() const
	{
		return m_c[2];
	}

	// Serialisation try, binary output
	inline void
	PointR3::write(std::ostream& s)
	{
		s.write(reinterpret_cast<char*>(m_c), 3*sizeof(double));
	}
