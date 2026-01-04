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

void concept() {
// Function implementation goes here
    int n;
    cin>>n;

    string s;
    cin>>s;

    int len = s.length();
    unordered_map<int,int>map;

    for(int i=0;i<len;i++){
        if(s[i]=='?') continue;
        else map[s[i]]++;
    }

    int ans =0 ;
    for(auto it:map){
        if(it.second > n) ans += n;
        else ans += it.second;
    }

    cout<<ans;
}

int main() {
    int t;
    cin >> t;
    
    
    while (t--) {
        concept();
        cout<<endl;
    }
    return 0;
}