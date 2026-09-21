#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int a[100][100], b[100][100];

    // First matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Second matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    // Addition and output
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] + b[i][j];

            if (j < n - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}