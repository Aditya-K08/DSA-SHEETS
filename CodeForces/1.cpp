#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MOD 1000000007
typedef long long ll;

void concept08() {
    ll n, k, x;
    cin >> n >> k >> x;
    
    vector<ll> arr(n + 1);
    vector<ll> prefix(n + 1, 0);
    
    ll t = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
        t += arr[i];
    }

    ll maxi = k * t - x;
    ll ans = 0;
    
    if (maxi < 0) {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (prefix[i] > maxi) continue;
        
        ll c = (maxi - prefix[i]) / t;
        ans += min((long long)k, c + 1);  
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        concept08();
    }
    return 0;
}
