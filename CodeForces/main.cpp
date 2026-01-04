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

bool compare(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second;
}


long long StrHash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void concept() {
    string s, s2;
    cin >> s >> s2;
    int k;
    cin >> k;
    set<char> set;
    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == '1') set.insert('a' + i);
    }

    int n = s.length();
    vector<ll> arr(n + 1, 0);

    for (int i = 0; i < n; i++) {
        if (set.find(s[i]) != set.end()) arr[i + 1] = arr[i] + 1;
        else arr[i + 1] = arr[i];
    }

    ll cnt = 0;
    int p = 31;
    int m = 1e9 + 9;
    vector<long long> power(n);

    power[0] = 1;
    for (int i = 1; i < n; i++) {
        power[i] = (power[i - 1] * p) % m;
    }

    vector<long long> hash(n + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * power[i]) % m;
    }

    for (int len = 1; len <= n; len++) {
        unordered_set<long long> hash_set;
        for (int j = 0; j <= n - len; j++) {
            long long curr_hash = (hash[j + len] - hash[j] + m) % m;
            curr_hash = (curr_hash * power[n - j - 1]) % m;
            if (len - (arr[j + len] - arr[j]) <= k) hash_set.insert(curr_hash);
        }
        cnt += hash_set.size();
    }
    cout << cnt <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int s2;
    s2= StrHash(s);
    cout<<s2;
    return 0;
}
