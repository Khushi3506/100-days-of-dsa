#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int matrix[20][20];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    bool isIdentity = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = false;
                    break;
                }
            } else {
                if (matrix[i][j] != 0) {
                    isIdentity = false;
                    break;
                }
            }
        }

        if (!isIdentity)
            break;
    }

    if (isIdentity)
        cout << "Identity Matrix";
    else
        cout << "Not an Identity Matrix";

    return 0;
}