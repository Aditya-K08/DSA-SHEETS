#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

int main() {
    int r, g;
    cin >> r >> g;

    int h = 0;
    while ((h + 1) * (h + 2) / 2 <= r + g) {
        h++;
    }

    vector<vector<int>> dp(h + 1, vector<int>(r + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= h; i++) {
        for (int j = 0; j <= r; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % MOD;
            }
        }
    }

    int total = h * (h + 1) / 2;
    int ans = 0;

    for (int j = 0; j <= r; j++) {
        int green_used = total - j;
        if (green_used <= g) {
            ans = (ans + dp[h][j]) % MOD;
        }
    }

    cout << ans << "\n";
    return 0;
}
