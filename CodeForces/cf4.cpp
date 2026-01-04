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
ll lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
ll mod_exp(ll base, ll exp, ll mod) {
	ll result = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return result;
}

void concept() {
	int n,m;
	cin>>n>>m;

	cout<<lcm(n,m)<<endl;
		
}

int main() {
    int t;
    cin>>t;
    while(t--)
	concept();
	return 0;
}