#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    long long maxi = arr[0];
    long long curr = arr[0];
    for(int i=1;i<n;i++){
        curr=max(arr[i],curr+arr[i]);
        maxi=max(curr,maxi);
    }
    cout<<maxi<<endl;
    return 0;
}
