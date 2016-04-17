//
// $Id$
#ifndef SRTMFiles_INCLUDED_
#define SRTMFiles_INCLUDED_

#include <assabib/framic_defs.h>
#include <string>
#include <fstream>
#include <cinttypes>


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
		//! give next value in the rectangle
		virtual int16_t Next() const =0;
		//@}

		//! \name I/O, display and storage (file SRTMFiles_IO.cpp)
		//@{
		//! Standard info function.
		void info(ostream& s=cout, bool debug=false) const;
		//@}

	protected :
		//! file name
		assabib::Filename m_fn;
		//! stream
		ifstream m_ind;
		//! is the read pointer ready
		bool m_ready;
	};

	class SRTMbin250m : public SRTMFiles
	{

	};

	class SRTMbin90m : public SRTMFiles
	{

	}

	#include "SRTMFiles.inl"

} // namespace

#endif
