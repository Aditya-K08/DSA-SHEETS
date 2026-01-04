#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);

    for(int i = 2; i < n; i++){
        for(int j=i;j<i+k;j++){
            
        }
    }

    cout << dp[n-1] << endl;
    return 0;
}
