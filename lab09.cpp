// Laboratornaya 9 — obrabotka matritsy, variant 25
// Neparnyj variant — podschet PO STROKAM: B[i] = (max v stroke i) + (min v stroke i)
// Sortirovka massiva B metodom vstavki (tablitsa 9.4)

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

void sort_vstavka(double* b, int n) {
    for (int i = 1; i < n; i++) {
        double key = b[i];
        int j = i - 1;
        while (j >= 0 && b[j] > key) {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int r, c;
    cout << "Strok r: ";
    cin >> r;
    cout << "Stolbtsov c: ";
    cin >> c;
    if (r < 1 || c < 1)
        return 1;

    double** a = new double*[r];
    for (int i = 0; i < r; i++) {
        a[i] = new double[c];
        for (int j = 0; j < c; j++)
            a[i][j] = -10.0 + (20.0 * rand() / RAND_MAX);
    }

    cout << fixed << setprecision(2);
    cout << "Matritsa A:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << setw(8) << a[i][j];
        cout << endl;
    }

    double* b = new double[r];
    for (int i = 0; i < r; i++) {
        double rmin = a[i][0], rmax = a[i][0];
        for (int j = 1; j < c; j++) {
            if (a[i][j] < rmin) rmin = a[i][j];
            if (a[i][j] > rmax) rmax = a[i][j];
        }
        b[i] = rmax + rmin;
    }

    cout << "Massiv B (do sortirovki):" << endl;
    for (int i = 0; i < r; i++)
        cout << "B[" << i << "] = " << b[i] << endl;

    sort_vstavka(b, r);

    cout << "Massiv B (posle sortirovki vstavkami):" << endl;
    for (int i = 0; i < r; i++)
        cout << "B[" << i << "] = " << b[i] << endl;

    for (int i = 0; i < r; i++)
        delete[] a[i];
    delete[] a;
    delete[] b;
    return 0;
}
