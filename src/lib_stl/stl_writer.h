//
// $Id$
#ifndef MHM_STLWriter_INCLUDED_
#define MHM_STLWriter_INCLUDED_

#include <string>
#include <framic_defs.h>
#include <assabib/FileName.h>

namespace MartiniqueHM {

//*********************************************************
//
//           CLASS STLWriter :
//
//*********************************************************

//! This class writes triangles in STL format, either ascii or binary

/*!
*/

class STLWriter
{
  public :
    //! \name Constructors and destructors
    //@{
    //! void construct
    STLWriter();
    //! Ordinary contructor
    STLWriter(const string& filename, bool ascii=false);
    //! Dtor
    virtual ~STLWriter();
    //@}

    //! \name Constructors and destructors
    //@{
	//! return the file name
	string  FileName() const;
	//! set the file name
	string& FileName();
	//! read the binary flag
	bool  BinaryFlag() const;
	//! set "binary" flag
	bool& BinaryFlag();
    //@}

    //! \name I/O, display and storage (file STLWriter_IO.cpp)
    //@{
    //! Standard info function.
    void info(ostream& s=cout, bool debug=false) const;
	//! stl header
	void write_header() const;
    //! stl data
    void write_data(const STLTriangle& tr) const;
	//!  stl trailer, if any
	void write_trailer() const;

    //@}

  private :
	//! file name of the output
	assabib::FileName m_fn;
	//! flag, binary output
  	bool m_binary;
	//! stream
	ofstream m_oud;
};

#include "STLWriter.inl"
#include "STLWriter.cpp"
#include "STLWriter_IO.cpp"

#include "STLWriter_fct.h"
#include "STLWriter_fct.cpp"

} // namespace

#endif
