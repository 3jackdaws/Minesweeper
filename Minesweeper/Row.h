//
//  Row.h
//  2DArray_A3
//
//  Created by Ian Murphy on 1/9/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

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

template <typename T>
Row<T>::Row(const Array2D<T> & wtf, const int row): m_array2D(const_cast<Array2D<T> &>(wtf)), m_row(row)
{
    
}

template <typename T>
T & Row<T>::operator[](int col)
{
    int index = (m_array2D._col) * m_row + col;
    return m_array2D.m_array[index];
}

template <typename T>
const T & Row<T>::operator[](int col) const
{
    int index = (m_array2D._col) * m_row + col;
    return m_array2D.m_array[index];
}

#endif