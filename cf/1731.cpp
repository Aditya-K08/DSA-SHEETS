#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> dp(n, vector<int>(n, 1e9));

    for(int i = 0; i < n; i++) dp[i][i] = 1;

    for(int len = 2; len <= n; len++){
        for(int l = 0; l + len - 1 < n; l++){
            int r = l + len - 1;
            dp[l][r] = 1 + dp[l + 1][r];
            for(int k = l + 1; k <= r; k++){
                if(s[l] == s[k]){
                    dp[l][r] = min(dp[l][r],
                                   (k == l + 1 ? 0 : dp[l + 1][k - 1]) + dp[k][r]);
                }
            }
        }
    }

    cout << dp[0][n - 1] << '\n';
}


int main(){
    int t;
    //cin>>t;
    t==1;
    while(t--){
        solve();
    }
    return 0;
}