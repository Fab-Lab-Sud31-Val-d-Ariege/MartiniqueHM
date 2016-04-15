//
// $Id$
#ifndef VECTOR3_INCLUDED_
#define VECTOR3_INCLUDED_

#include <iostream>
#include <ostream>
#include <martiniquehm/pointr3.h>

namespace MartiniqueHM {

//*********************************************************
//
//           CLASS VectoR3 : a vector in R3
//
//*********************************************************
//! This hold a triplet of float. Mainly a storage class with write facilities

/*! A vector of R3 vectoriel space.
*/
class VectoR3 : public PointR3
{
public :
	//! \name Constructors and destructors
	//@{
	//! void construct
	VectoR3(float x=0., float y=0., float z=0.);
	//! void construct
	VectoR3(const PointR3& A, const PointR3& B);
	//! Copy ctor
	VectoR3(const VectoR3&);
	//! Destructor
	virtual ~VectoR3();
	//@}

	//! \name Vector operations
	//@{
	//! set vector length to 1
	void Normalize();
	//! cross product
	friend VectoR3 Cross(const VectoR3& A, const VectoR3& B);
	//@}

	//! \name I/O, display and storage
	//@{
	//! Standard info function.
	void info(std::ostream& s=std::cout, bool debug=false) const;
	//@}
};


#include "vector3.inl"

} // namespace

#endif
