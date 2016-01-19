/************************************************************************
* Class: Array2D
*
* Purpose: This class creates a dynamic two-dimensional array that can't be started at any base because that's dumb.
*
* Manager functions:
* 	Array2D ( )
* 		Default size is zero
*	Array2D (int row, int col)
*		Creates an appropriate sized array with dimentions passed
*	Array (const Array & copy)
		copies 
*	operator = (const Array & copy)
		does what an op = should do
*	~Array()
*
* Methods:
*	operator [ ] (int index)
		returns a Row object so that array[][] works
	getRow()
		returns the row size
	setRow
		sets the row size
	getCol()
		gets the col size
	setCol
		sets the column size
	Select()
		selects a specific element
*		...
*************************************************************************/
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include "Row.h"
#include "Array.h"
#include "Exception.h"
template <typename T>
class Array2D
{
public:
    friend class Row<T>;
    Array2D();
    Array2D(int row, int col);
    Array2D(const Array2D<T> & cp);
    ~Array2D();
    
    Array2D & operator = (const Array2D & rhs);
    Row<T> operator [] (int index);
    const Row<T> operator [] (int index) const;
    int getRow() const;
    void setRow(int rows);
    int getColumn() const;
    void setColumn(int col);
    T & Select(int row, int col);
    
private:
    Array<T> m_array;
    int _row;
    int _col;
    
    void Alter(int rows, int cols);
};

/**********************************************************************
* Purpose: This is a default ctor.
*
* Precondition:
*     none
*
* Postcondition:
*      instantiates a basic Array2D that shouldn't have undefined behaviour
*
************************************************************************/
template <typename T>
Array2D<T>::Array2D() : _col(0), _row(0)
{
    m_array.setLength(0);
}

/**********************************************************************
* Purpose: This is a ctor.
*
* Precondition:
*     none
*
* Postcondition:
*      instantiates a basic Array2D that is the dimentions set
*
************************************************************************/
template <typename T>
Array2D<T>::Array2D(int row, int col) : _col(col), _row(row)
{
    m_array.setLength(row*col);
}

/**********************************************************************
* Purpose: This is a copy ctor.
*
* Precondition:
*     cp must be an object
*
* Postcondition:
*      instantiates an Array2D object that is a duplicate of the passed in object
*
************************************************************************/
template <typename T>
Array2D<T>::Array2D(const Array2D<T> & cp) : _col(cp._col), _row(cp._row), m_array(cp.m_array)
{
    
}

/**********************************************************************
* Purpose: This is a d'tor.
*
* Precondition:
*     must be object
*
* Postcondition:
*      Things are destructed 
*
************************************************************************/
template <typename T>
Array2D<T>::~Array2D()
{
}

/**********************************************************************
* Purpose: This is a op = overload
*
* Precondition:
*     both objects involved must be instantiated
*
* Postcondition:
*      kinda like a copy ctor only on non-new objects
*
************************************************************************/
template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D<T> &rhs)
{
    if(this != &rhs)
    {
        _row = rhs._row;
        _col = rhs._col;
        m_array = rhs.m_array;
    }
    return *this;
}

/**********************************************************************
* Purpose: Allows Array2D to be accessed like a normal array i.e. array[1][1] = 5
*
* Precondition:
*     array must be of some size greater than 0
*
* Postcondition:
*      returns a Row helper object that knows the row being accessed
*
************************************************************************/
template <typename T>
const Row<T> Array2D<T>::operator[](int index) const
{
    return Row<T> (*this, index);
}

/**********************************************************************
* Purpose: Allows Array2D to be accessed like a normal array i.e. array[1][1] = 5
*
* Precondition:
*     array must be of some size greater than 0
*
* Postcondition:
*      returns a const Row helper object that knows the row being accessed
*
************************************************************************/
template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
    return Row<T> (*this, index);
}

/**********************************************************************
* Purpose: returns the row size
*
* Precondition:
*     object must be instantiated
*
* Postcondition:
*      returns _row
*
************************************************************************/
template <typename T>
int Array2D<T>::getRow() const
{
    return _row;
}

/**********************************************************************
* Purpose: sets the row size
*
* Precondition:
*     object must be instantiated
*
* Postcondition:
*      remakes the whole array so that data does not change locations
*
************************************************************************/
template <typename T>
void Array2D<T>::setRow(int rows)
{
    if(rows == _row)
    {
        
    }
    else if(rows > 0)
    {
        Alter(rows, _col);
//        _row = rows;
    }
    else{
        throw Exception("InvalidRowNumberException");
    }
}

/**********************************************************************
* Purpose: returns the col size
*
* Precondition:
*     object must be instantiated
*
* Postcondition:
*      returns _col
*
************************************************************************/
template <typename T>
int Array2D<T>::getColumn() const
{
    return _col;
}

/**********************************************************************
* Purpose: sets the col size
*
* Precondition:
*     object must be instantiated
*
* Postcondition:
*      remakes the whole array so that data does not change locations
*
************************************************************************/
template <typename T>
void Array2D<T>::setColumn(int col)
{
    if(col == _col)
    {
        
    }
    else if(col > 0)
    {
        Alter(_row, col);
//        _col = col;
    }
    else{
        throw Exception("InvalidColumnNumberException");
    }
}

/**********************************************************************
* Purpose: selects a specific elemetn and returns it
*
* Precondition:
*     object must be instantiated
*
* Postcondition:
*      returns the data at location row, col
*
************************************************************************/
template <typename T>
T & Array2D<T>::Select(int row, int col)
{
    return m_array[row*_col+col];
}

/**********************************************************************
* Purpose: Helper function that makes a new array with data in the correct spots
*
* Precondition:
*     object must be instantiated
*
* Postcondition:
*      makes a new array of size row * col that has data in the correct positions
*
************************************************************************/
template <typename T>
void Array2D<T>::Alter(int rows, int cols)
{
    int l_rows = rows;
    int l_cols = cols;
    
    if(rows > _row)
        l_rows = _row;
    if(cols > _col)
        l_cols = _col;
    
    Array2D<T> newArray(rows, cols);
    for (int row = 0; row<l_rows; row++)
    {
        for (int col = 0; col<l_cols; col++)
        {
            newArray[row][col] = (*this)[row][col];
        }
    }
    m_array = newArray.m_array;
    _row = newArray._row;
    _col = newArray._col;
}

#endif


