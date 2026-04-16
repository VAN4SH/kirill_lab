// Laboratornaya 4, variant 25. Tri grafika na odnom cherte (v WinForms — Chart)
// Zdes' — tablitsa tochek; granitsy kusochka: x<=0, 0<x<=5, x>5 (kak v metodichke 4.3)

#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

double f1(double x) {
    return x / tan(x);
}

double f2(double x) {
    return log(x * x + 1.0);
}

double f3(double x) {
    return exp(-2.0 * x) - 3.0 * x + 1.0;
}

double y_piece(double x) {
    if (x <= 0.0)
        return f1(x);
    if (x <= 5.0)
        return f2(x);
    return f3(x);
}

int main() {
    double xn = -3.8, xk = 17.1, xh = 0.65;
    ofstream out("lab04_graph.txt");

    cout << fixed << setprecision(4);
    cout << "x\t\ty (dlja Chart — tri serii raznym cvetom po chastyam)" << endl;

    for (double x = xn; x <= xk + 1e-9; x += xh) {
        double y = y_piece(x);
        cout << x << "\t" << y << endl;
        out << x << " " << y << endl;
    }
    out.close();
    cout << "Dannye takzhe zapisany v lab04_graph.txt" << endl;
    return 0;
}
