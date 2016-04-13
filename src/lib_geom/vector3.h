//
// $Id$
#ifndef POINTR3_INCLUDED_
#define POINTR3_INCLUDED_

#include <iostream>
#include <ostream>
#include <martiniquehm/pointr3.h>

namespace MartiniqueHM {

//*********************************************************
//
//           CLASS VectoR3 : a vector in R3
//
//*********************************************************
//! This hold a triplet of double. Mainly a storage class with write facilities

/*! A vector of R3 vectoriel space.
*/
class VectoR3 : public PointR3
{
public :
	//! \name Constructors and destructors
	//@{
	//! void construct
	VectoR3(double x=0., double y=0., double z=0.);
	//! void construct
	VectoR3(const pointR3& A, const PointR3& B);
	//! Copy ctor
	VectoR3(const VectoR3&);
	//! Destructor
	~VectoR3();
	//@}

	//! set vector length to 1
	void Normalize();

	//! \name I/O, display and storage
	//@{
	//! Standard info function.
	void info(std::ostream& s=std::cout, bool debug=false) const;
	//@}
	};


#include "vector3.inl"

} // namespace

#endif
