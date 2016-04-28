//
// $Id$

// default construct
inline SRTMFiles::SRTMFiles() : m_ready(false), m_seekg(0),	m_mapwest(0.0), m_mapnorth(0.0), m_east(0.0), m_north(0.0), m_west(0.0), m_south(0.0), m_rr(0), m_cc(0), m_ir(0), m_ic(0), m_irmap(0), m_icmap(0), m_cellsize(0.0)
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

// return number of rows in ROI
inline size_t SRTMFiles::Rows() const
{
	return m_rr;
}

// return number of columns in ROI
inline size_t SRTMFiles::Cols() const
{
	return m_cc;
}

// return X pos in degree (longitude), correct when used _after_ Next()
inline double SRTMFiles::XLon() const
{
	return (m_icmap + m_ic) * m_cellsize + m_mapwest;
}

// return Y pos in degree (latitude), correct when used _after_ Next()
inline double SRTMFiles::YLat() const
{
	return m_mapnorth - (m_irmap+m_ir) * m_cellsize;
}

// return cell size (assumed cells are square)
inline double SRTMFiles::CellSize() const
{
	return m_cellsize;
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
	s<<"Map east limit = "<<m_mapwest<<'\n';
	s<<"Map north limit = "<<m_mapnorth<<'\n';
	s<<"ROI east  limit = "<<m_east<<'\n';
	s<<"ROI north limit = "<<m_north<<'\n';
	s<<"ROI west  limit = "<<m_west<<'\n';
	s<<"ROI south limit = "<<m_south<<'\n';
	s<<"Nb of rows in ROI = "<<m_rr<<'\n';
	s<<"Nb of cols in ROI = "<<m_cc<<'\n';
	s<<"Row Index of current point in ROI = "<<m_ir<<'\n';
	s<<"Col Index of current point in ROI = "<<m_ic<<'\n';
	s<<"Index of first ROI row in whole map = "<<m_irmap<<'\n';
	s<<"index of first ROI column in whole map = "<<m_icmap<<'\n';
	s<<"Cell size = "<<m_cellsize<<'\n';
}

// default construct
inline SRTMbin250m::SRTMbin250m() : SRTMFiles(), m_stride(0), m_rowbuff(NULL)
{}

// Dtor
inline SRTMbin250m::~SRTMbin250m()
{
	delete [] m_rowbuff;
}

// give current value in the rectangle
inline int16_t SRTMbin250m::ZCur() const
{
	return m_rowbuff[m_ic];
}

// return true if next point is not NA
inline bool SRTMbin250m::IsValid() const
{
	return (m_rowbuff[m_ic] != m_hd.na);
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
	s<<"byte to skip to next row = "<<m_stride<<'\n';
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
