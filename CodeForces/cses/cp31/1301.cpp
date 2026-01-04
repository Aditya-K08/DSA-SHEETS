#include<bits.stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>odd(n+1,0),even(n+1,0);
    for(int i=2;i<=n;i+=2){
        odd[i-1] = odd[i-2]+arr[i-1];
    }
    for(int i=1;i<=n;i+=2){
        even[i] = even[i-2]+arr[i];
    }
    vector<int>bal(n+1);
    for(int i=0;i<n;i++){
        bal[i] = odd[i+1]-even[i+1];
        if(bal[i]==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}