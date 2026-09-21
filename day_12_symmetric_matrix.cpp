#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int matrix[100][100];

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // A symmetric matrix must be square
    if (m != n) {
        cout << "Not a Symmetric Matrix" << endl;
        return 0;
    }

    bool symmetric = true;

    // Compare matrix[i][j] with matrix[j][i]
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = false;
                break;
            }
        }

        if (!symmetric)
            break;
    }

    if (symmetric)
        cout << "Symmetric Matrix" << endl;
    else
        cout << "Not a Symmetric Matrix" << endl;

    return 0;
}