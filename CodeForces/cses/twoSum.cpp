#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    map<int, int> mp;  // safer than unordered_map
    for (int i = 0; i < n; i++) {
        int tar = t - arr[i];
        if (mp.count(tar)) {
            cout << i + 1 << " " << mp[tar] + 1 << "\n";
            return 0;
        }
        mp[arr[i]] = i;
    }

    cout << "IMPOSSIBLE\n";
}
