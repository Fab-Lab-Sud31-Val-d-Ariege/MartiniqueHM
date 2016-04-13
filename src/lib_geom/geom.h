//
// $Id$
#ifndef ???_INCLUDED_
#define ???_INCLUDED_

#include <string>
#include <framic_defs.h>
#include <assabib/SDate.h>
# include <>

namespace assabib {

//*********************************************************
//
//           CLASS ???<T> : 
//
//*********************************************************

//! Brief

/*! Long
*/

template <class T>
class ??? : public NamedObject
{
  public :
    //! \name Constructors and destructors
    //@{
    //! void construct
    ???();
    //! Ordinary contructor
    ???(const string& name, size_t size);
    //! each element is initialized with val
    ???(const string& name, const T& val, size_t size);
    //! the element at position I is initialized with p[I]
    ???(const string& name, const T* ptr, size_t size);
    //! Ctor from valarray<T>
    ???(const string& name, const valarray<T>& vec);
    //! Copy ctor
    ???(const ???&);
    //! Dtor
    virtual ~???();
    //@}

    //! \name Acces to the values
    //@{
    //! Assign another ???.
    ???<T>& operator=(const ???<T>& right);
    //! Assign a valarray
    ???<T>& operator=(const valarray<T>& right);
    //! Assign a scalar to each value
    ???<T>& operator=(const T& val);
    //! Get only the values
    valarray<T> GetValarray();
    //! get te size
    size_t size() const;
    //@}

    //! \name 4 operation
    //@{
    //! Addition membre à membre de deux ???<T>s.
    friend ???<T> operator+ <> (const ???<T> &LOp, const ???<T> &ROp);
    //! Addition d'un scalaire à un ???<T>.
    friend ???<T> operator+ <> (double scalar, const ???<T> &ROp);
    //! Addition d'un scalaire à un ???<T>.
    friend ???<T> operator+ <> (const ???<T> &ROp, double scalar);

    //! Soustraction membre à membre de deux ???<T>s.
    friend ???<T> operator- <> (const ???<T> &LOp, const ???<T> &ROp);
    //! Soustraction d'un scalaire à un ???<T>.
    friend ???<T> operator- <> (double scalar, const ???<T> &ROp);
    //! Soustraction d'un scalaire à un ???<T>.
    friend ???<T> operator- <> (const ???<T> &ROp, double scalar);
    //! change le signe des valeur du ???<T> ; moins unaire.
    friend ???<T> operator- <> (const ???<T> &ROp);

    //! Multiplication membre à membre de deux ???<T>s.
    friend ???<T> operator* <> (const ???<T> &LOp, const ???<T> &ROp);
    //! Multiplication d'un ???<T> par un scalaire.
    friend ???<T> operator* <> (double scalar, const ???<T> &ROp);
    //! Multiplication d'un ???<T> par un scalaire.
    friend ???<T> operator* <> (const ???<T> &ROp, double scalar);

    //! Division membre à membre de deux ???<T>s.
    friend ???<T> operator/ <> (const ???<T> &LOp, const ???<T> &ROp);
    //! Division d'un ???<T> par un scalaire.
    friend ???<T> operator/ <> (const ???<T> &ROp, double scalar);
    //! Division d'un scalaire par un ???<T>.
    friend ???<T> operator/ <> (double scalar, const ???<T> &ROp);

    //! Addition en place d'un ???<T> à un autre
    void operator+= (const ???<T> &ROp);
    //! Accumulation en place avec un scalaire.
    void operator+= (double scalar);
    //! Produit en place de deux ???<T>.
    void operator*= (const ???<T> &ROp);
    //! Produit en place d'un ???<T> par un scalaire.
    void operator*= (double scalar);
    //@}

    // ===============================================================
    //! make a copy then apply a function to each value
    ???<T> apply(T func(T)) const;
    //! apply a function to each value of the ???
    void apply(T func(T));
        
    //! \name I/O, display and storage (file ???_IO.cpp)
    //@{
    //! Standard info function.
    void info(ostream& s=cout, bool debug=false) const;
    //! Serialisation try, ascii output
    friend ostream& operator<< <> (ostream& s, const ???<T>& fs);
    //! Serialisation try, ascii input
    friend istream& operator>> <> (istream& s, ???<T>& fs);
    //! write data in XSIL format
    void write(ostream& out) const;
    //! write header of XSIL format
    void writeXSIL_Head(ostream& out) const;
    //! write data in XSIL format (section Table)
    void writeXSIL_Data(ostream& out) const;
    //! write footer of XSIL format
    void writeXSIL_Foot(ostream& out) const;
    //@}

  protected :
    //! Exécute la copie des attributs
    void DoCopy(const ???<T> &ROp);

  private :
    //! initialisation des attributs
    void ClearMembers();
    //! allocation des tableaux
    void AllocTables();
};

#include "???.inl"
#include "???.cpp"
#include "???_IO.cpp"

#include "???_fct.h"
#include "???_fct.cpp"

} // namespace

#endif
