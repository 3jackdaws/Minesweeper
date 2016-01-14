//
//  Array2D.h
//  2DArray_A3
//
//  Created by Ian Murphy on 1/9/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//
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

template <typename T>
Array2D<T>::Array2D() : _col(0), _row(0)
{
    m_array.setLength(0);
}

template <typename T>
Array2D<T>::Array2D(int row, int col) : _col(col), _row(row)
{
    m_array.setLength(row*col);
}

template <typename T>
Array2D<T>::Array2D(const Array2D<T> & cp) : _col(cp._col), _row(cp._row), m_array(cp.m_array)
{
    
}

template <typename T>
Array2D<T>::~Array2D()
{
}


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

template <typename T>
const Row<T> Array2D<T>::operator[](int index) const
{
    return Row<T> (*this, index);
}

template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
    return Row<T> (*this, index);
}


template <typename T>
int Array2D<T>::getRow() const
{
    return _row;
}

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

template <typename T>
int Array2D<T>::getColumn() const
{
    return _col;
}

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

template <typename T>
T & Array2D<T>::Select(int row, int col)
{
    return m_array[row*_col+col];
}

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


