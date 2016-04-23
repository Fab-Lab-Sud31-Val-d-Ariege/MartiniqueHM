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
		m_ready = true;
	}

	// go to first byte of interest, after setting boundaries
	void SRTMbin250m::GoToStart()
	{
		// row start
		double NN = m_hd.yllcorner +  m_hd.nrows * m_hd.cellsize;
		size_t nr = (NN-m_north)/m_hd.cellsize;
		WATCH(nr);
		// row end
		// size_t sr = (NN-m_south)/m_hd.cellsize;
		// col start
		double WW = m_hd.xllcorner;
		size_t wc = fabs(WW-m_west)/m_hd.cellsize;
		WATCH(wc);
		// col end
		size_t ec = fabs(WW-m_east)/m_hd.cellsize;
		WATCH(ec);
		// Storage area size
		m_cc = ec-wc;
		WATCH(m_cc)
		// size_t rr = sr-nr;
		// m_v[i * m_c + j]

		// storage buffer
		if ( m_rowbuff ) {
			delete [] m_rowbuff;
		}
		m_rowbuff = new int16_t[m_cc];

		// stride between rows
		m_stride = (m_hd.ncols - ec + wc) * sizeof(int16_t);

		// start of ROI
		m_start = (nr * m_hd.ncols + wc) * sizeof(int16_t) + 16 + sizeof(m_hd);
		m_ind.seekg(m_start);
		m_ind.read(reinterpret_cast<char*>(m_rowbuff), m_cc*sizeof(int16_t));
		m_ready=true;
	}

// 	// direct way, when the format is known
// 	void SRTMbin90m::open(const assabib::FileName& fn)
// 	{
//
// 	}

}

