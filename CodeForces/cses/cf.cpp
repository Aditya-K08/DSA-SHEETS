#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n;i>=0;i--){
        cout<<i<<" ";
    } 
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}