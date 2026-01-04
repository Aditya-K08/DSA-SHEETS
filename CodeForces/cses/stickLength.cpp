#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long median;
    if (n & 1) {
        median = arr[n / 2];
    } else {
        median = (arr[n / 2] + arr[n / 2 - 1]) / 2;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(arr[i] - median);
    }

    cout << sum << endl;
    return 0;
}
