// Laboratornaya 7, variant 25 — figura (a) iz tablicy 7.1
// Tipichno (a) — verhnjaja poluokruzhnost' radiusa R=100 v kvadrate [-100;100]x[-100;100]
// Ploschad' tochno: S = pi*R^2/2

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

bool vnutri_figury(double x, double y) {
    const double R = 100.0;
    return (y >= 0.0) && (x * x + y * y <= R * R);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    long long N;
    cout << "Chislo tochek N (Monte-Karlo): ";
    cin >> N;
    if (N <= 0) {
        cout << "N dolzhno byt' > 0" << endl;
        return 1;
    }

    const double R = 100.0;
    const double S_kv = (2.0 * R) * (2.0 * R);
    const double PI = acos(-1.0);
    const double S_tochno = PI * R * R / 2.0;

    long long n = 0;
    for (long long k = 0; k < N; k++) {
        double x = -R + (2.0 * R) * rand() / (1.0 + RAND_MAX);
        double y = -R + (2.0 * R) * rand() / (1.0 + RAND_MAX);
        if (vnutri_figury(x, y))
            n++;
    }

    double S_fig = S_kv * (static_cast<double>(n) / static_cast<double>(N));
    double err = fabs(S_tochno - S_fig) / S_tochno * 100.0;

    cout << "Ploschad' (Monte-Karlo): " << S_fig << endl;
    cout << "Ploschad' analiticheski: " << S_tochno << endl;
    cout << "Otnositel'naja pogreshnost', %: " << err << endl;
    return 0;
}
