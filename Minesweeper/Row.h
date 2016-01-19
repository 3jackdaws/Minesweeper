/************************************************************************
* Class: Row
*
* Purpose: This class is just a helper class for array2D.
*
* Manager functions:
Row(const Array2D<T> &, const int row);
	constructs an object that has a reference to a 2D array and knows the row
T & operator [] (int column);
	returns the data that is where the user asked for
const T & operator [] (int column) const;
	const version of the above thing
* 	
*************************************************************************/


#ifndef ROW_H
#define ROW_H
#include "Exception.h"
template <typename T> class Array2D;

template <typename T>
class Row
{
public:

    Row(const Array2D<T> &, const int row);
    T & operator [] (int column);
    const T & operator [] (int column) const;
private:
    Array2D<T> & m_array2D;
    int m_row;
};

/**********************************************************************
* Purpose: This function constructs a Row object that has a refeence to the original array2D.
*
* Precondition:
*     Array2D must exist
*
* Postcondition:
*      A Row object now exists
************************************************************************/
template <typename T>
Row<T>::Row(const Array2D<T> & wtf, const int row): m_array2D(const_cast<Array2D<T> &>(wtf)), m_row(row)
{
    
}

/**********************************************************************
* Purpose: This function returns the data asked for in in array2D.
*
* Precondition:
*     should be called from an array2D object
*
* Postcondition:
*      Returns the data at the spot requested
*
************************************************************************/
template <typename T>
T & Row<T>::operator[](int col)
{
    int index = (m_array2D._col) * m_row + col;
    return m_array2D.m_array[index];
}

/**********************************************************************
* Purpose: This function returns the data asked for in in array2D only const.
*
* Precondition:
*     should be called from an array2D object
*
* Postcondition:
*      Returns the data at the spot requested in const 
*
************************************************************************/

template <typename T>
const T & Row<T>::operator[](int col) const
{
    int index = (m_array2D._col) * m_row + col;
    return m_array2D.m_array[index];
}

#endif