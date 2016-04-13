//
// $Id$
#ifndef STLTRIANGLE_INCLUDED_
#define STLTRIANGLE_INCLUDED_

#include <string>
#include <martiniquehm/pointr3.h>

namespace MartiniqueHM {

//*********************************************************
//
//           CLASS STLTriangle<T> :
//
//*********************************************************

//! Brief

/*! Long
*/

class STLTriangle : public NamedObject
{
  public :
    //! \name Constructors and destructors
    //@{
    //! void construct
    STLTriangle();
    //! Ordinary contructor
	STLTriangle(const PointR3& A, const PointR3& B, const PointR3& C);
    //! Copy ctor
    STLTriangle(const STLTriangle&);
    //! Dtor
    virtual ~STLTriangle();
    //@}

	//! \name acces to fields
	//@{
	//! Point A, RO
	PointR3 A() const;
	//! Point A, W
	PointR3& A();
	//! Point B, RO
	PointR3 B() const;
	//! Point B, W
	PointR3& B();
	//! Point C, RO
	PointR3 C() const;
	//! Point C, W
	PointR3& C();
	//! the normal
	PointR3 N() const;
	//! reverse the normal
	void Reverse();
	//! set Z for all points
	void SetZ(double z);
	//@}

    //! \name I/O, display and storage (file STLTriangle_IO.cpp)
    //@{
    //! Standard info function.
	void info(std::ostream& s= std::cout, bool debug=false) const;
    //! Serialisation try, ascii output
	friend std::ostream& operator<< (std::ostream& s, const STLTriangle& fs);
    //! write data in binary format
    void write(std::ostream& s) const;
    //@}

  private :
	//! Point A
	PointR3 m_A;
	//! Point B
	PointR3 m_B;
	//! Point C
	PointR3 m_C;
	//! Normal vector
	PointR3 m_normal;
	//! flag, is the normal valid ?
	bool m_normalvalid;

	//! compute normal from A, B & C
	void ComputeNormal();

};

#include "stl_triangle.inl"

} // namespace

#endif
