#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define br cout << "\n";
#define ff first
#define sc second
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll ceil_div(ll a, ll b) {
	return a % b == 0 ? a / b : a / b + 1;
}

ll gcd(ll a, ll b) {
	if (a == 0ll) {
		return b;
	}
	return gcd(b % a, a);
}

int findPosition(vector<ll>& prefix, ll req) {
    int left = 0, right = prefix.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (prefix[mid] >= req) right = mid;  
        else left = mid + 1;
    }
    return left;
}

void solve(){
        int n; 
        ll k, x; 
        cin >> n >> k >> x; 
 
        vector<ll> arr(n); 
        for (int i = 0; i < n; i++) cin >> arr[i]; 
 
        vector<ll> prefix(n + 1, 0);
        int sum = 0; 
        for (int i = 0; i < n; i++) {
            sum+=arr[i];
            prefix[i + 1] = prefix[i] + arr[i];
        } 
        vector<ll> Larr(n, 0); 
 
        for (int i = 0; i < n; i++) { 
            ll rem = prefix[n] - prefix[i]; 
 
            if (rem >= x) { 
                int j = findPosition(prefix, x + prefix[i]);  
                Larr[i] = j - i;
            }
            else { 
                ll needed = x - rem; 
                ll cycles = (needed + sum - 1) / sum; 
                ll base = (n - i) + (cycles - 1) * (ll)n; 
                ll req = x - ((prefix[n] - prefix[i]) + (cycles - 1) * sum); 
                int j = findPosition(prefix, req);  
                Larr[i] = base + j; 
            } 
        } 
 
        ll ans = 0; 
        for (int i = 0; i < n; i++) { 
            ll L = Larr[i]; 
            ll maxVal = k * (ll)n - i - L; 
            if (maxVal < 0) continue; 
            ll maxJ = maxVal / n; 
            if (maxJ >= k) maxJ = k - 1; 
            ans += (maxJ + 1); 
        } 
         
        cout << ans << "\n";
}

int main() { 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
 
    int t; 
    cin >> t; 
     
    while (t--) { 
         solve();
    } 
 
    return 0; 
}