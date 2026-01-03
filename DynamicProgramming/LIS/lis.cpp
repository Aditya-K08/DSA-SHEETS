#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,st,n) for(int i=st;i<n;++i)
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pb push_back
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr)
const int MOD = 1000000007;

int main() {
    fastio();
    int n;
    cin >> n;
    vi arr(n);
    rep(i,0,n) cin >> arr[i];

    vi dp(n,1);
    vi path(n,-1);
    int end = 0, maxi = 1;

    rep(i,0,n){
        rep(j,0,i){
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                path[i] = j;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            end = i;
        }
    }

    cout << maxi << "\n";
    vi lis;
    while(end != -1){
        lis.pb(arr[end]);
        end = path[end];
    }
    reverse(all(lis));

    for(int x : lis) cout << x << " ";
    cout << "\n";

    return 0;
}
