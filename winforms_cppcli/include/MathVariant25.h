#pragma once
// Obshhie formuly variant 25 (dlya konsol'nyh i WinForms modulej)
#include <cmath>

inline double Lab3_f1(double x) { return 1.0 / tan(x * x * x) + 1.0; }
inline double Lab3_f2(double x) {
    double t = sin(x) + 1.0;
    if (t <= 1e-12) return 0.0;
    double lx = log(t);
    return lx * lx;
}
inline double Lab3_f3(double x) { return 2.0 * x * x + x * x * x * x + 1.0; }
inline double Lab3_y(double x, double a) {
    if (x <= 0.0) return Lab3_f1(x);
    if (x <= a) return Lab3_f2(x);
    return Lab3_f3(x);
}

inline double Lab4_f1(double x) { return x / tan(x); }
inline double Lab4_f2(double x) { return log(x * x + 1.0); }
inline double Lab4_f3(double x) { return exp(-2.0 * x) - 3.0 * x + 1.0; }
inline double Lab4_y(double x) {
    if (x <= 0.0) return Lab4_f1(x);
    if (x <= 5.0) return Lab4_f2(x);
    return Lab4_f3(x);
}

inline double Lab8_f1(double x) { return x * x + sin(7.0 * x) - 1.0; }
inline double Lab8_f2(double x) { return x * x * x + 10.0 * x; }
inline double Lab8_f3(double x) { return 2.0 * x * x + x * x * x * x + 1.0; }
inline double Lab8_y(double x, double a) {
    if (x <= 0.0) return Lab8_f1(x);
    if (x <= a) return Lab8_f2(x);
    return Lab8_f3(x);
}
