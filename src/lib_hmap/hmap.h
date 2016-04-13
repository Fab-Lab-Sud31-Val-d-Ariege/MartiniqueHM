//
// $Id$
#ifndef HMAP_INCLUDED_
#define HMAP_INCLUDED_

#include <assabib/framic_defs.h>
#include <string>
#include <vector>
#include <valarray>

namespace MartiniqueHM {

//*********************************************************
//
//           CLASS HMap :
//
//*********************************************************

//! This class hold an height map based on a matrix
/*! Typically the values comes from Nasa's SRTM measurements. They
 * are on a regular grid with sqare aspect ratio. The square size
 * is typically 250m or 90m.
 */

class HMap
{
  public :
    //! \name Constructors and destructors
    //@{
    //! void construct
    HMap();
    //! Ordinary contructor
    HMap(const string& name, size_t rows, size_t cols);
    //! Copy ctor
    HMap(const HMap& ROp);
    //! Dtor
    virtual ~HMap();
    //@}

    //! \name Acces to the values
    //@{
	//! Read the name
	const string& name() const;
	//! number of rows
	size_t R() const;
	//! number of columns
	size_t C() const;
	//! scale, size of the square on Earth
	double& sqsize();
	//! ref value for NA data
	double& NA();
	//! value of the bottom for a manifole STL
	double& bottom();

	//! 2d access, indexes start at 0
	double& operator() ( size_t i, size_t j );
	//! 2d access, indexes start at 0
	double  operator() ( size_t i, size_t j ) const;
    //@}

    //! \name operation
    //@{
    //! Assign a scalar to each value
    HMap& operator=(const double& val);
    //! in place scaling (Z co-ordinate only)
    void operator*= (double scalar);
    //@}

	//! \name input
	//@{
	//! read data from a binary version of SRTM data
	bool FillFrom(const FileName& fn, );
	//@}

    // ===============================================================
    //! \name I/O, display and storage (file HMap_IO.cpp)
    //@{
	//! read the name
	string name() const;
	//! assign the name
	string& name();
	//! Standard info function.
    void info(ostream& s=cout, bool debug=false) const;
// 	//! write data in XML format ; parameters only, not the map!
//     void write(ostream& out) const;
//     //! write header of XSIL format
//     void writeXML_Head(ostream& out) const;
//     //! write data in XSIL format (section doubleable)
//     void writeXML_Data(ostream& out) const;
//     //! write footer of XSIL format
//     void writeXML_Foot(ostream& out) const;
    //@}

  private :
	//! name of the map
	string m_name;
	//! storage area
	valarray<double> m_v;
	//! full size
	size_t m_size;
	//! nb of rows
	size_t m_r;
	//! nb of columns
	size_t m_c;
	//! size of the square on earth
	double m_sqsize;
	//! ref value for NA data
	double m_na;
	//! altitude of the bottom of a manifold STL
	double m_bottom;

	//! border of the map
	vector< pair<size_t, size_t> > m_border;

	//! find the border of the valid data, from outside the map only
	void FindBorder();
};

#include "hmap.inl"

} // namespace

#endif
