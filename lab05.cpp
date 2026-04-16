// Laboratornaya 5, variant 25. Zadanija a), b), v) iz tablicy 5.1:
// a) summa otritsatel'nyh elementov
// b) summa elementov s indeksom, kratnym 3 (indeksy 0,3,6,...)
// v) proizvedenie modulej naibol'shego i naimen'shego elementa

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Razmer massiva n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Oshibka: n dolzhno byt' > 0" << endl;
        return 1;
    }

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = -50 + rand() % 121;

    cout << "Massiv:" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    long long sum_neg = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            sum_neg += a[i];

    long long sum_idx3 = 0;
    for (int i = 0; i < n; i++)
        if (i % 3 == 0)
            sum_idx3 += a[i];

    int mn = a[0], mx = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < mn) mn = a[i];
        if (a[i] > mx) mx = a[i];
    }
    long long prod_mod = 1LL * llabs(mn) * llabs(mx);

    cout << "a) summa otritsatel'nyh: " << sum_neg << endl;
    cout << "b) summa s indeksom kratnym 3: " << sum_idx3 << endl;
    cout << "v) |min|*|max|: " << prod_mod << endl;

    delete[] a;
    return 0;
}
