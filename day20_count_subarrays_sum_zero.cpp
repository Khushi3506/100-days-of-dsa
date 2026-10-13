
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<long long, int> prefixCount;
    long long prefixSum = 0;
    long long count = 0;

    // Empty prefix
    prefixCount[0] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Same prefix sum means subarray sum is zero
        if (prefixCount.find(prefixSum) != prefixCount.end()) {
            count += prefixCount[prefixSum];
        }

        prefixCount[prefixSum]++;
    }

    cout << count << endl;

    return 0;
}
