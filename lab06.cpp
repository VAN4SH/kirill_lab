// Laboratornaya 6, variant 25 (tablitsa 6.5)
// a) maks. po modulju element i nomer stroki i stolbtsa
// b) raznost' max i min na glavnoj diagonali
// v) A(6x6): (nechetnye vo 2-m stolbtse, indeks 1) * (polozhitel'nye v 3-j stroke, indeks 2)

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int r, c;
    cout << "Chislo strok: ";
    cin >> r;
    cout << "Chislo stolbtsov: ";
    cin >> c;
    if (r < 1 || c < 1) {
        cout << "Nekorrektnyj razmer" << endl;
        return 1;
    }

    int** a = new int*[r];
    for (int i = 0; i < r; i++) {
        a[i] = new int[c];
        for (int j = 0; j < c; j++)
            a[i][j] = -20 + rand() % 41;
    }

    cout << "Matritsa A:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }

    int bi = 0, bj = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (abs(a[i][j]) > abs(a[bi][bj])) {
                bi = i;
                bj = j;
            }
    cout << "a) max |a[i,j]| = " << a[bi][bj] << " v stroke " << bi << ", stolbtsa " << bj << endl;

    if (r == c) {
        int dmin = a[0][0], dmax = a[0][0];
        for (int i = 0; i < r; i++) {
            if (a[i][i] < dmin) dmin = a[i][i];
            if (a[i][i] > dmax) dmax = a[i][i];
        }
        cout << "b) max-min na glavnoj diagonali: " << (dmax - dmin) << endl;
    } else
        cout << "b) ne kvadratnaja matritsa" << endl;

    if (r >= 6 && c >= 6) {
        int cnt_odd_col2 = 0;
        for (int i = 0; i < 6; i++)
            if (abs(a[i][1]) % 2 == 1)
                cnt_odd_col2++;
        int cnt_pos_row3 = 0;
        for (int j = 0; j < 6; j++)
            if (a[2][j] > 0)
                cnt_pos_row3++;
        cout << "v) (nechetnye v stolbtse 2) * (polozh. v stroke 3): "
             << cnt_odd_col2 * cnt_pos_row3 << endl;
    } else
        cout << "v) nuzhno ne menee 6 strok i 6 stolbtsov" << endl;

    for (int i = 0; i < r; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
