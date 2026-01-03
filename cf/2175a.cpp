#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        set<int>s(arr.begin(),arr.end());
        if(n==1){
            cout<<arr[0]<<endl;
            continue;
        }
        sort(arr.begin(),arr.end());
        auto it  = lower_bound(arr.begin(),arr.end(),s.size())-arr.begin();
        int sec = *it;
        cout<<sec<<endl;
    }
}