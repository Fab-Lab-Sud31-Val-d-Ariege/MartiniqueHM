//
// $Id$

#include <martiniquehm/srtm_files.h>
#include <cmath>

namespace MartiniqueHM {

	// direct way, when the format is known
	void SRTMbin250m::open(const assabib::FileName& fn)
	{
		m_fn = fn;
		m_ind.open(m_fn.FullName().c_str(), ios::in | ios::binary);
		if (!m_ind) ERROPENF(m_fn.FullName().c_str())

		// skip magick, 16 bytes
		m_ind.seekg(16);

		// read header
		m_ind.read(reinterpret_cast<char*>(&m_hd), sizeof(m_hd));
		m_mapwest = m_hd.xllcorner;
		m_cellsize = m_hd.cellsize;
		m_ready = true;
	}

	// go to first byte of interest, after setting boundaries
	void SRTMbin250m::GoToStart()
	{
		// row start
		m_mapnorth = m_hd.yllcorner +  m_hd.nrows * m_hd.cellsize;
		m_ir = (m_mapnorth-m_north)/m_hd.cellsize;
		// row end
		size_t sr = (m_mapnorth-m_south)/m_hd.cellsize;
		// col start
		m_ic = fabs(m_hd.xllcorner-m_west)/m_hd.cellsize;
		// col end
		size_t ec = fabs(m_hd.xllcorner-m_east)/m_hd.cellsize;
		// Storage area size
		m_cc = ec-m_ic;
		m_rr = sr-m_ir;

		// storage buffer
		if ( m_rowbuff ) {
			delete [] m_rowbuff;
		}
		m_rowbuff = new int16_t[m_cc];

		// stride between rows
		// m_v[i * m_c + j]
		m_stride = (m_hd.ncols - ec + m_ic) * sizeof(int16_t);

		// start of ROI
		m_seekg = (m_ir * m_hd.ncols + m_ic) * sizeof(int16_t) + 16 + sizeof(m_hd);
		m_ind.seekg(m_seekg);
		m_ind.read(reinterpret_cast<char*>(m_rowbuff), m_cc*sizeof(int16_t));
		m_ready=true;
	}

// 	// direct way, when the format is known
// 	void SRTMbin90m::open(const assabib::FileName& fn)
// 	{
//
// 	}

}

