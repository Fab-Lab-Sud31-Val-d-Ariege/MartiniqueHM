//
// $Id$
#ifndef MHM_STLWriter_INCLUDED_
#define MHM_STLWriter_INCLUDED_

#include <cstring>
#include <cstdint>
#include <string>
#include <fstream>
#include <assabib/framic_defs.h>
#include <assabib/FileName.h>
#include <martiniquehm/stl_triangle.h>

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
    STLWriter(const string& filename);
    //! Dtor
    virtual ~STLWriter();
    //@}

    //! \name Constructors and destructors
    //@{
	//! return the file name
	assabib::FileName  FileName() const;
	//! set the file name
	assabib::FileName& FileName();
    //@}

    //! \name I/O, display and storage
    //@{
    //! Standard info function.
    void info(ostream& s=cout, bool debug=false) const;
	//! stl header
	virtual void write_header(size_t nbt) const =0;
    //! stl data
	virtual void write_data(const STLTriangle& tr) const=0;
	//!  stl trailer, if any
	virtual void write_trailer() const =0;
    //@}

  protected :
	//! file name of the output
	assabib::FileName m_fn;
	//! stream
	mutable std::ofstream m_oud;
};

class STLWriterAscii : public STLWriter
{
public :
	//! \name Constructors and destructors
	//@{
	//! void construct
	STLWriterAscii();
	//! Ordinary contructor
	STLWriterAscii(const string& filename);
	//! Dtor
	virtual ~STLWriterAscii();
	//@}

	//! \name I/O, display and storage
	//@{
	//! Standard info function.
	void info(ostream& s=cout, bool debug=false) const;
	//! stl header
	void write_header(size_t nbt) const;
	//! stl data
	void write_data(const STLTriangle& tr) const;
	//!  stl trailer, if any
	void write_trailer() const;
	//@}
};

class STLWriterBinary : public STLWriter
{
public :
	//! \name Constructors and destructors
	//@{
	//! void construct
	STLWriterBinary();
	//! Ordinary contructor
	STLWriterBinary(const string& filename);
	//! Dtor
	virtual ~STLWriterBinary();
	//@}

	//! \name I/O, display and storage
	//@{
	//! Standard info function.
	void info(ostream& s=cout, bool debug=false) const;
	//! stl header
	void write_header(size_t nbt) const;
	//! stl data
	void write_data(const STLTriangle& tr) const;
	//!  stl trailer, if any
	void write_trailer() const;
	//@}
};

#include "stl_writer.inl"

} // namespace

#endif
