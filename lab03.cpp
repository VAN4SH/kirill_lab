// Laboratornaya 3, variant 25. Tabulirovanie i poisk jekstremumov (cikl while)

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// f1 = ctg(x^3) + 1
double f1(double x) {
    return 1.0 / tan(x * x * x) + 1.0;
}

// f2 = (ln(sin(x)+1))^2 — v metodichke zapis' ln(sin x + 1)^2
double f2(double x) {
    double t = sin(x) + 1.0;
    if (t <= 1e-12)
        return 0.0;
    double lx = log(t);
    return lx * lx;
}

// f3 = 2x^2 + x^4 + 1
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
    double xn = -7.4, xk = 0.6, xh = 0.16;
    double a = 7.0;

    double x = xn;
    double ymin = y_fun(xn, a);
    double ymax = ymin;

    cout << fixed << setprecision(5);
    cout << "x\t\ty" << endl;

    while (x <= xk + 1e-9) {
        double y = y_fun(x, a);
        cout << x << "\t" << y << endl;
        if (y < ymin) ymin = y;
        if (y > ymax) ymax = y;
        x += xh;
    }

    cout << "min y na otrezke: " << ymin << endl;
    cout << "max y na otrezke: " << ymax << endl;
    return 0;
}
