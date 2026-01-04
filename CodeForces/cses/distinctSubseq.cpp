#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    unordered_map<long long, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    long long ans = 1;
    for (auto &[val, f] : freq) {
        ans = (ans * (f + 1)) % MOD;
    }

    ans = (ans - 1 + MOD) % MOD; // exclude empty subsequence
    cout << ans << "\n";
}
