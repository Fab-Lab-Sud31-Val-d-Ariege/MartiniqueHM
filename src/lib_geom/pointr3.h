//
// $Id$
#ifndef POINTR3_INCLUDED_
#define POINTR3_INCLUDED_

#include <iostream>
#include <ostream>
//#include <martiniquehm/vector3.h>

namespace MartiniqueHM {

class VectoR3;

//*********************************************************
//
//           CLASSE PointR3 : a point in R3
//
//*********************************************************
//! This hold a triplet of float. Mainly a storage class with write facilities
/*! A point in R3 vectoriel space has 3 coordinates [ x, y, z].
*/
class PointR3
{
  public :
    //! \name Constructors and destructors
	//@{
    //! void construct
    PointR3(float x=0., float y=0., float z=0.);
    //! Copy ctor
    PointR3(const PointR3&);
    //! Destructor
    virtual ~PointR3();
	//@}

    //! \name Acces to the values
	//@{
    //! Assign another PointR3
    PointR3& operator = (const PointR3&);
    //! first component, W
    float& X();
    //! second component, W
    float& Y();
    //! third component, W
    float& Z();
    //! first component, RO
    float X() const;
    //! second component, RO
    float Y() const;
    //! third component, RO
    float Z() const;
	//@}

	//! create a vector from 2 points, V = AB = B-A
	friend VectoR3 operator- (const PointR3& B, const PointR3& A);

    //! \name I/O, display and storage
	//@{
    //! Standard info function.
    void info(std::ostream& s=std::cout, bool debug=false) const;
	//! Serialisation try, ascii output
	friend std::ostream& operator<< (std::ostream& s, const PointR3& Pt);
	//! Serialisation try, binary output
	void write(std::ostream& s) const;
	//@}

  protected :
    float m_c[3];
};

#include "pointr3.inl"

} // namespace

#endif
