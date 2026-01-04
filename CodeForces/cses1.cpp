#include<bits/stdc++.h>
using namespace std;


void solve(int n){
    int m = 1e9+7;
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=6;j++)
            if(i-j>=0) dp[i] = (dp[i] + dp[i-j]) % m;
    }
    cout<<dp[n];
}
int main(){
    int n;
    cin>>n;
    solve(n);
    return 0;
}