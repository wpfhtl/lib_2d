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
 * \file    calc.h
 * \author  Martin Buck
 * \date    January 2015
 * \version 1.0
 * \brief   contains basic calculation functions which are necessary for this lib
 */

#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

#include "Point.h"
#include "Path.h"

namespace lib_2d {

    unsigned long long int faculty(unsigned int number) {
        unsigned long long int f = 1;
        for(unsigned int i =1; i <= number; ++i)
            f *= i;
        return f;
    }

//------------------------------------------------------------------------------

    template <typename T>
    T binomial_coeff(unsigned int n, unsigned int k) {
        return faculty(n) / ( faculty(k) * faculty(n-k) );
    }

//------------------------------------------------------------------------------

    template <typename T>
    T bernstein_polynomal(unsigned int n, unsigned int i, T t) {
        return binomial_coeff<T>(n,i) * pow(t,i) * pow(1.0-t, n-i);
    }

//------------------------------------------------------------------------------

    template <typename T>
    T distance_point_line(Point<T> p, Point<T> l1, Point<T> l2) {
        T a1 = l1.x;
        T a2 = l1.y;

        T b1 = l2.x;
        T b2 = l2.y;

        T c1 = p.x;
        T c2 = p.y;

        T x = (a1*a1*c1 - a1*a2*b2 + a1*a2*c2 - 2*a1*b1*c1 + a1*b2*b2 - a1*b2*c2 + a2*a2*b1 - a2*b1*b2 - a2*b1*c2 + b1*b1*c1 + b1*b2*c2)
              /(a1*a1 - 2*a1*b1 + a2*a2 - 2*a2*b2 + b1*b1 + b2*b2);

        T y = ((a2 - b2) * x + a1*b2 - a2*b1) / (a1 - b1);

        return sqrt(  pow(x-p.x,2) + pow(y-p.y,2)  );
    }

//------------------------------------------------------------------------------

    template <typename T>
    bool is_equal(const Point<T> &a, const Point<T> b) {
        return a.equal_to(b);
    }

    template <typename T>
    bool is_equal(const Path<T> &a, const Path<T> b) {
        return a.equal_to(b);
    }

//------------------------------------------------------------------------------

    template <typename T>
    bool is_similar(const Point<T> &a, const Point<T> b, T maxDistance) {
        return a.similar_to(b, maxDistance);
    }

    template <typename T>
    bool is_similar(const Path<T> &a, const Path<T> b, T maxDistance) {
        return a.similar_to(b, maxDistance);
    }

} //lib_2d

#endif // CALC_H_INCLUDED
