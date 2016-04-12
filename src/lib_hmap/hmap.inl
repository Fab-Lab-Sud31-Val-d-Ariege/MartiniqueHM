//
// $Id: HMap.inl 1599 2010-08-19 11:38:29Z micheli $

//******* HMap class **********************************************
HMap::HMap() : m_size(0), m_r(0), m_c(0), m_sqsize(0), m_na(0), m_bottom(0)
{
  TRACE("HMap::Constructeur vide");
  m_name = "unnamed";
}

HMap::HMap(const string& str, size_t rr, size_t cc)
{
  TRACE("HMap::Constructeur dimensionné");
    m_name = str;
    m_size = rr * cc;
    m_v.resize(m_size);
    m_r = rr;
	m_c = cc;
	m_sqsize = 1;
	m_na = -9999;
	m_bottom = -5;
}

// copy constructor
HMap::HMap(const HMap &ROp)
{
  TRACE("HMap::Constructeur de copie");
    m_name = ROp.m_name;
    m_v = ROp.m_v;
    m_size = ROp.m_size;
    m_r = ROp.m_r;
	m_c = ROp.m_c;
	m_sqsize = ROp.m_sqsize;
	m_na = ROp.m_na;
	m_bottom = ROp.m_bottom;
}

HMap::~HMap(void)
{
    TRACE("HMap::Destructeur");
}

HMap&
HMap::operator = (const T& val)
{
    TRACE("HMap::Affectation d'un double");
    m_v = val;
    return *this;
}

inline size_t
HMap::R() const
{
    return m_r;
}

inline size_t
HMap::C() const
{
    return m_c;
}

inline string
HMap::name(void) const
{
    return m_name;
}

inline void
HMap::NameIt(string newname)
{
    m_name = newname;
}

// Opérateur d'accès classique en matrice bidimensionnelle
inline double&
HMap::operator() ( size_t i, size_t j )
{
#ifndef NO_CHECKING
    if( i >= m_r || j >= m_c ) {
        cout <<m_name<<" : index out of range : "<<i<<" & "<<j<<endl;
        exit(ERROR);
    }
#endif
    return m_v[i * m_c + j];
}

// Opérateur d'accès classique en matrice bidimensionnelle
inline double
HMap::operator() ( size_t i, size_t j ) const
{
#ifndef NO_CHECKING
    if( i >= m_r || j >= m_c ) {
        cout <<m_name<<" : index out of range : "<<i<<" & "<<j<<endl;
        exit(ERROR);
    }
#endif
    return m_v[i * m_c + j];
}

inline void
operator*= (double scalar) {
	m_v *= scalar;
}
