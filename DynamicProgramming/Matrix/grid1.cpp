#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main(){
    int m,n;
    cin>>m>>n;
    char matrix[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    if (matrix[0][0] == '#') {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));

    vector<int>dx{1,0};
    vector<int>dy{0,1};
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (matrix[i][j] == '#') continue;
            for(int k=0;k<2;k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx<m && ny<n && matrix[nx][ny]!='#'){
                    dp[nx][ny] = (dp[nx][ny] + dp[i][j]) % MOD;
                }
            }
        }
    }

    cout<<dp[m-1][n-1]<<endl;
}