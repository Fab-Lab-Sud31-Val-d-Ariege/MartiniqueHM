//
// $Id$
#ifndef SRTMFiles_INCLUDED_
#define SRTMFiles_INCLUDED_

#include <string>
#include <fstream>
#include <cstdint>
#include <common.h>
#include <assabib/FileName.h>

// to be sure double are 64 bits long
#ifndef __STDC_IEC_559__
#error "Requires IEEE 754 floating point!"
#endif


namespace MartiniqueHM {

	//*********************************************************
	//
	//           CLASS SRTMFiles
	//
	//*********************************************************
	//! Knows the format of srtm file ; get and gives values from a rectangle from one of them
	/*!
	*/

	class SRTMFiles
	{
	public :
		//! \name Constructors and destructors
		//@{
		//! default construct
		SRTMFiles();
		//! Dtor
		virtual ~SRTMFiles();
		//@}

		//! \name Acces to the values
		//@{
		//! normal way to open a data file. The format is automatically guessed.
		static SRTMFiles* GuessAndOpen(const assabib::FileName& fn);
		//! direct way, when the format is known ; mainly for debug
		virtual void open(const assabib::FileName& fn) =0;
		//! set the rectangle boundary
		void SetLimits(double east, double north, double west, double south);
		//! give current value in the rectangle
		virtual int16_t ZCur() const =0;
		//! go to next value in the rectangle
		virtual bool Next() =0;
		//! return number of rows in ROI
		size_t Rows() const;
		//! return number of columns in ROI
		size_t Cols() const;
		//! return X pos in degree (longitude)
		double XLon() const;
		//! return Y pos in degree (latitude)
		double YLat() const;
		//! return cell size (assumed cells are square)
		double CellSize() const;
		//! return true if next point is not NA
		virtual bool IsValid() const =0;
		//@}

		//! \name I/O, display and storage (file SRTMFiles_IO.cpp)
		//@{
		//! Standard info function.
		void info(ostream& s=cout, bool debug=false) const;
		//@}

	protected :
		//! file name
		assabib::FileName m_fn;
		//! stream
		ifstream m_ind;
		//! is the read pointer ready
		bool m_ready;
		//! seekg pointer
		streampos m_seekg;
		//! map west limit
		double m_mapwest;
		//! map north limit
		double m_mapnorth;
		//! ROI east limit
		double m_east;
		//! ROI north limit
		double m_north;
		//! ROI west limit
		double m_west;
		//! ROI south limit
		double m_south;
		//! nb of rows in rectangle ROI
		size_t m_rr;
		//! nb of columns in rectangle ROI
		size_t m_cc;
		//! index of current row in ROI
		size_t m_ir;
		//! index of current column in ROI
		size_t m_ic;
		//! index of first ROI row in whole map
		size_t m_irmap;
		//! index of first ROI column in whole map
		size_t m_icmap;
		//! cell size (square)
		double m_cellsize;

		//! go to first byte of interest, after setting boundaries
		virtual void GoToStart() = 0;
	};

	class SRTMbin250m : public SRTMFiles
	{
	public:
		//! \name Constructors and destructors
		//@{
		//! default construct
		SRTMbin250m();
		//! Dtor
		virtual ~SRTMbin250m();
		//@}

		//! \name Acces to the values
		//@{
		//! direct way, when the format is known ; mainly for debug
		void open(const assabib::FileName& fn);
		//! give current value in the rectangle
		int16_t ZCur() const;
		//! go to next value in the rectangle
		bool Next();
		//! return true if next point is not NA
		bool IsValid() const;
		//@}

		//! \name I/O, display and storage (file SRTMbin250m_IO.cpp)
		//@{
		//! Standard info function.
		void info(ostream& s=cout, bool debug=false) const;
		//@}

	private:
		//! header structure
		struct headertype {
			int64_t ncols;
			int64_t nrows;
			double  xllcorner;
			double  yllcorner;
			double  cellsize;
			int16_t na;
		} m_hd;

		//! amount of byte to skip to go to next row
		size_t m_stride;
		//! buffer of size = nb cols
		int16_t* m_rowbuff;

		//! go to first byte of interest, after setting boundaries
		void GoToStart();
	};

// 	class SRTMbin90m : public SRTMFiles
// 	{
// 	public:
// 		//! \name Constructors and destructors
// 		//@{
// 		//! default construct
// 		SRTMbin90m();
// 		//! Dtor
// 		virtual ~SRTMbin90m();
// 		//@}
//
// 		//! \name Acces to the values
// 		//@{
// 		//! direct way, when the format is known ; mainly for debug
// 		void open(const assabib::FileName& fn);
// 		//! give next value in the rectangle
// 		int16_t Next();
// 		//@}
//
// 		//! \name I/O, display and storage (file SRTMbin90m_IO.cpp)
// 		//@{
// 		//! Standard info function.
// 		void info(ostream& s=cout, bool debug=false) const;
// 		//@}
// private:
// 	//! go to first byte of interest, after setting boundaries
// 	void GoToStart();
// 	}

	#include "srtm_files.inl"

} // namespace

#endif
