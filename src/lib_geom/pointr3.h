//
// $Id$
#ifndef POINTR3_INCLUDED_
#define POINTR3_INCLUDED_

#include <iostream>
#include <ostream>

namespace MartiniqueHM {

class VectoR3;
//*********************************************************
//
//           CLASSE PointR3 : a point in R3
//
//*********************************************************
//! This hold a triplet of double. Mainly a storage class with write facilities

/*! A point in R3 vectoriel space has 3 coordinates [ x, y, z].
*/
class PointR3
{
  public :
    //! \name Constructors and destructors
	//@{
    //! void construct
    PointR3(double x=0., double y=0., double z=0.);
    //! Copy ctor
    PointR3(const PointR3&);
    //! Destructor
    ~PointR3();
	//@}

    //! \name Acces to the values
	//@{
    //! Assign another PointR3
    PointR3& operator = (const PointR3&);
    //! first component, W
    double& X();
    //! second component, W
    double& Y();
    //! third component, W
    double& Z();
    //! first component, RO
    double X() const;
    //! second component, RO
    double Y() const;
    //! third component, RO
    double Z() const;
	//@}

	//! create a vector from 2 points, V = AB = B-A
	friend VectoR3 operator-(const pointR3& B, const PointR3& A)

    //! \name I/O, display and storage
	//@{
    //! Standard info function.
    void info(std::ostream& s=std::cout, bool debug=false) const;
	//! Serialisation try, ascii output
	friend std::ostream& operator<< (std::ostream& s, const PointR3& Pt);
	//! Serialisation try, binary output
	void write(std::ostream& s);
	//@}

  protected :
    double m_c[3];
};

#include "pointr3.inl"

} // namespace

#endif
