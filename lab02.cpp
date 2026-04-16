// Лабораторная работа 2, вариант 25
// Кусочно заданная функция: y = f1(x) при x<=0; f2(x) при 0<x<=a; f3(x) при x>a

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double x, a, y;

    cout << "Vvedite a: ";
    cin >> a;
    cout << "Vvedite x: ";
    cin >> x;

    if (x <= 0.0) {
        // f1(x) = sin^2(x) + cos^4(x)
        double sx = sin(x);
        double cx = cos(x);
        y = sx * sx + cx * cx * cx * cx;
    } else if (x <= a) {
        // f2(x) = (ln x)^2 + x  — нужен x > 0; при 0 < x <= a это выполняется
        y = log(x) * log(x) + x;
    } else {
        // f3(x) = tg^2(x) + x
        y = tan(x) * tan(x) + x;
    }

    cout << "y = " << y << endl;
    return 0;
}
