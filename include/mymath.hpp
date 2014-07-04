#ifndef OOP1_MATH_HPP
#define OOP1_MATH_HPP

#include <cmath>

const double INF = 1e9;
const double EPS = 1e-6;

inline double sqr(double x) {
    return x * x;
}

inline bool eq(double x, double y) {
    return (x + EPS > y) && (x - EPS < y);
}

inline bool lt(double x, double y) {
    return x + EPS < y;
}

inline bool le(double x, double y) {
    return x - EPS < y;
}

inline bool gt(double x, double y) {
    return x - EPS > y;
}

inline bool ge(double x, double y) {
    return x + EPS > y;
}

#endif