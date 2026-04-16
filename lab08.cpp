// Laboratornaya 8 — matematicheskaja chast' (v metodichke eshho TabControl, menju, Chart)
// Variant 25, tablitsa 8.1: f1 = x^2+sin(7x)-1; f2 = x^3+10x; f3 = 2x^2+x^4+1; parametр a = 7

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double f1(double x) {
    return x * x + sin(7.0 * x) - 1.0;
}

double f2(double x) {
    return x * x * x + 10.0 * x;
}

double f3(double x) {
    return 2.0 * x * x + x * x * x * x + 1.0;
}

double y_fun(double x, double a) {
    if (x <= 0.0)
        return f1(x);
    if (x <= a)
        return f2(x);
    return f3(x);
}

int main() {
    double a = 7.0;
    double xn = -7.4, xk = 8.5, xh = 0.11;

    cout << fixed << setprecision(4);
    cout << "Tabuljacija (dlja vkladok v WinForms — tablitsa i grafik):" << endl;
    double ymin = y_fun(xn, a), ymax = ymin;

    for (double x = xn; x <= xk + 1e-9; x += xh) {
        double y = y_fun(x, a);
        cout << x << "\t" << y << endl;
        if (y < ymin) ymin = y;
        if (y > ymax) ymax = y;
    }
    cout << "min y: " << ymin << ", max y: " << ymax << endl;
    return 0;
}
