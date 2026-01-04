#include<bits/stdc++.h>
using namespace std;

void solve(int n, int k, vector<int>& arr) {
    vector<int> dp(k+1, INT_MAX);
    dp[0] = 0;
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            if (j - arr[i] >= 0 && dp[j - arr[i]] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - arr[i]] + 1);
            }
        }
    }
    if (dp[k] == INT_MAX) cout << "-1" << endl;
    else cout << dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    solve(n, k, arr);
    return 0;
}
