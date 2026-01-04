#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pyes cout << "YES\n";
#define pno cout << "NO\n";
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

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

ll gcd(ll a, ll b) {
  if (a == 0ll) {
    return b;
  }
  return gcd(b % a, a);
}

void concept(){
    ll n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int>dp(n+1,0);

    dp[0]=1;

    
     
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcase;
    cin>>testcase;
    while(testcase--){
        concept();
    }
    return 0;
}