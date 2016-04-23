//
// $Id$

// default construct
inline SRTMFiles::SRTMFiles() : m_ready(false), m_seekg(0), m_east(0.0), m_north(0.0), m_west(0.0), m_south(0.0)
{}

// Dtor
inline SRTMFiles::~SRTMFiles()
{}

// set the rectangle boundary
inline void SRTMFiles::SetLimits(double east, double north, double west, double south)
{
	m_east = east;
	m_north = north;
	m_west = west;
	m_south = south;
	m_ready = false;
	GoToStart();
}

// Standard info function.
inline void SRTMFiles::info(ostream& s, bool debug) const
{
	s<<"[SRTMFiles]\n";
	if (m_ind) {
		s<<"Opened on = "<<m_fn.FullName()<<'\n';
		s<<"seekg pointer at = "<<m_seekg<<'\n';
		s<<"seekg pointer ready = "<<m_ready<<'\n';
	} else {
		s<<"Not opened\n";
	}
	s<<"east  limit = "<<m_east<<'\n';
	s<<"north limit = "<<m_north<<'\n';
	s<<"west  limit = "<<m_west<<'\n';
	s<<"south limit = "<<m_south<<'\n';
}

// default construct
inline SRTMbin250m::SRTMbin250m() : SRTMFiles(), m_start(0), m_stride(0), m_rowbuff(NULL), m_cc(0), m_ii(0)
{}

// Dtor
inline SRTMbin250m::~SRTMbin250m()
{
	delete [] m_rowbuff;
}

// give next value in the rectangle
inline int16_t SRTMbin250m::Next()
{
	// do we need to read another line
	if ( m_ii+1 >= m_cc ) {
		m_ii = 0;
		m_ind.seekg(m_stride, m_ind.cur);
		m_ind.read(reinterpret_cast<char*>(&m_rowbuff), m_cc*sizeof(int16_t));
	}
	return m_rowbuff[m_ii++];
}

// Standard info function.
inline void SRTMbin250m::info(ostream& s, bool debug) const
{
	SRTMFiles::info(s, debug);
	s<<"[SRTMbin250m]\n";
	s<<"ncols = "<<m_hd.ncols<<'\n';
	s<<"nrows = "<<m_hd.nrows<<'\n';
	s<<"xllcorner = "<<m_hd.xllcorner<<'\n';
	s<<"yllcorner = "<<m_hd.yllcorner<<'\n';
	s<<"cellsize = "<<m_hd.cellsize<<'\n';
	s<<"na = "<<m_hd.na<<'\n';
	s<<"start of ROI (bytes)= "<<m_start<<'\n';
	s<<"length of a row ="<<m_cc<<'\n';
	s<<"current pos in row ="<<m_ii<<'\n';
	s<<"byte to skip to next row ="<<m_stride<<'\n';
}

// // default construct
// inline SRTMbin90m::SRTMbin90m() : SRTMFiles()
// {}
//
// // Dtor
// inline SRTMbin90m::~SRTMbin90m()
// {}
//
// // give next value in the rectangle
// inline int16_t SRTMbin90m::Next()
// {
//
// }
//
// // Standard info function.
// inline void SRTMbin90m::info(ostream& s, bool debug) const
// {
// 	SRTMFiles::info(s, debug);
// 	s<<"[SRTMbin90m]\n";
// }
