#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    int bestSum = arr[left] + arr[right];
    int bestA = arr[left];
    int bestB = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(bestSum)) {
            bestSum = sum;
            bestA = arr[left];
            bestB = arr[right];
        }

        if (sum < 0) {
            left++;
        }
        else if (sum > 0) {
            right--;
        }
        else {
            bestA = arr[left];
            bestB = arr[right];
            break;
        }
    }

    cout << bestA << " " << bestB;

    return 0;
}