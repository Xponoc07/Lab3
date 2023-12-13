#include <iostream>
using namespace std;

int main() {

    int number, n, m, max = INT_MIN;

    cin >> n >> m;

    int matrix[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> number;
            matrix[i][j] = number;

            if (number > max)
                max = number;
        }
    }

    // Это можешь удалить, если хочешь
    cout << "Before replace max" << "\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    //---------------------------------

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == max)
                matrix[i][j] = 0;
        }
    }

    cout << "After replace max" << "\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
