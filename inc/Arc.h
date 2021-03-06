/*
    Copyright (c) 2014 - 2015 Martin Buck
    Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
    OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/**
 * \file    Arc.h
 * \author  Martin Buck
 * \date    November 2014
 * \version 1.0
 * \brief   contains the class Arc which represents an arc in 2d space
 *          derived from Path
 */

#ifndef ARC_H_INCLUDED
#define ARC_H_INCLUDED

#include "constants.h"
#include "PointCloud.h"
#include "Point.h"


namespace lib_2d {

template <typename T>
class Arc : public PointCloud<T> {
    using PointCloud<T>::emplace_back;

private:
    T diameter;
    Point<T> m_center;

public:

    Arc(T diameter,
        unsigned int nPoints,
        bool closePath = true,
        T radiansStart = 0,
        T radiansEnd = LIB_2D_2PI,
        Point<T> m_center = Point<T>{}) :
            PointCloud<T>(nPoints),
            diameter(diameter),
            m_center(m_center) {

        T pDistance;
        unsigned int endIndex(nPoints);

        if(closePath) {
            pDistance = fabs(radiansEnd - radiansStart) / (T)(nPoints - 2);
            endIndex--;
        }

        else
            pDistance = fabs(radiansEnd - radiansStart) / (T)(nPoints - 1);


        for(unsigned int i=0; i<endIndex; ++i) {
            T radians = radiansStart + i * pDistance;
            T x = m_center.x + diameter/2.0 * cos(radians);
            T y = m_center.y + diameter/2.0 * sin(radians);
            emplace_back(x, y);
        }

        if(closePath) {
            T x = m_center.x + diameter/2.0 * cos(radiansStart);
            T y = m_center.y + diameter/2.0 * sin(radiansStart);
            emplace_back(x, y);
        }
    }

//------------------------------------------------------------------------------

    T get_diameter() const {
        return diameter;
    }

//------------------------------------------------------------------------------

    Point<T> center() const {
        return m_center;
    }

//------------------------------------------------------------------------------

    Arc& move_by(T x, T y) {
        PointCloud<T>::move_by(x, y);
        m_center.move_by(x, y);
        return *this;
    }

    Arc& move_by(Point<T> other) {
        PointCloud<T>::move_by(other);
        m_center.move_by(other);
        return *this;
    }

//------------------------------------------------------------------------------

    Arc& mirror_vertically(T xValue = 0) {
        PointCloud<T>::mirror_vertically(xValue);
        m_center.mirror_vertically(xValue);
        return *this;
    }

    Arc& mirror_vertically(Point<T> other) {
        PointCloud<T>::mirror_vertically(other);
        m_center.mirror_vertically(other);
        return *this;
    }

    Arc& mirror_horizontally(T yValue = 0) {
        PointCloud<T>::mirror_horizontally(yValue);
        m_center.mirror_horizontally(yValue);
        return *this;
    }

    Arc& mirror_horizontally(Point<T> other) {
        PointCloud<T>::mirror_horizontally(other);
        m_center.mirror_horizontally(other);
        return *this;
    }

    Arc& mirror_point(Point<T> other) {
        PointCloud<T>::mirror_point(other);
        m_center.mirror_point(other);
        return *this;
    }

    Arc& mirror_point(T xValue = 0, T yValue = 0) {
        PointCloud<T>::mirror_point(xValue, yValue);
        m_center.mirror_point(xValue, yValue);
        return *this;
    }

//------------------------------------------------------------------------------

    Arc& rotate(T radians, Point<T> m_center = Point<T>{}) {
        PointCloud<T>::rotate(radians, m_center);
        this->m_center.rotate(radians, m_center);
        return *this;
    }

    Arc& rotate(T radians, T centerX, T centerY) {
        PointCloud<T>::rotate(radians, centerX, centerY);
        this->m_center.rotate(radians, centerX, centerY);
        return *this;
    }
};

} //lib_2d

#endif // ARC_H_INCLUDED
