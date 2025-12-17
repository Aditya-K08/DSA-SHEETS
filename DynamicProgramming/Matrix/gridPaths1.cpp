#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,st,n) for(int i=st;i<n;++i)
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define fastio() ios::sync_with_stdio(false);cin.tie(nullptr)
const int MOD = 1000000007;
 
int main(){
    int n;
    cin>>n;
    char matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
 
    if (matrix[0][0] == '*' || matrix[n-1][n-1]=='*') {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
 
    vector<int>dx{1,0};
    vector<int>dy{0,1};
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (matrix[i][j] == '*') continue;
            for(int k=0;k<2;k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<n && ny<n && matrix[nx][ny]!='#'){
                    dp[nx][ny] = (dp[nx][ny] + dp[i][j]) % MOD;
                }
            }
        }
    }
 
    cout<<dp[n-1][n-1]<<endl;
}
