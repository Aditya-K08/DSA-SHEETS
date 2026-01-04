#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<ll>arr(n);
    arr[0]=x;
    for(int i=1;i<n;i++){
        ll e = (a*arr[i-1]+b)%c;
        arr[i]=e;
    }
    
    vector<ll>ans;
    ll window = 0;
    for(int i=0;i<k;i++){
        window^=arr[i];
    }
    ans.push_back(window);
    for(int i=k;i<n;i++){
        window^=arr[i]^arr[i-k];
        ans.push_back(window);
    }    
    ll res = 0;
    for(int i=0;i<ans.size();i++){
        res^=ans[i];
    }
    cout<<res<<endl;
    return 0;
}