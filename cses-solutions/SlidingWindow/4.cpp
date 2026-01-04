#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<ll> arr(n);
    arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    vector<int> bit_count(32,0);
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int b=0;b<32;b++){
            if(arr[i] & (1<<b)) bit_count[b]++;
        }
        if(i >= k){
            for(int b=0;b<32;b++){
                if(arr[i-k] & (1<<b)) bit_count[b]--;
            }
        }
        if(i >= k-1){
            int window_or = 0;
            for(int b=0;b<32;b++){
                if(bit_count[b] > 0) window_or |= (1<<b);
            }
            ans ^= window_or; 
        }
    }
    cout << ans << "\n";
    return 0;
}
