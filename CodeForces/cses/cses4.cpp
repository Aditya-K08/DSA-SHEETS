#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, vector<int>& arr) {
    int MOD = 1e9+7;
    vector<int> dp(k + 1, 0);
    dp[0] = 1; 

    for (int i = 0; i < n; i++) {
        for (int j = arr[i] ; j <= k ; j++) {
                dp[i] = (dp[i] + dp[i - arr[j]]) % MOD; 
        }
    }

    cout << dp[k] << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    solve(n, k, arr);
    return 0;
}
