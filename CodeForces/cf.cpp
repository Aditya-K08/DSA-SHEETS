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
    cout << cnt;
}

bool prime(ll n){
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

ll getNum(int n, int x, int y) {
    if (n == 1) {
        if (x == 1 && y == 1) return 1;
        if (x == 2 && y == 2) return 2;
        if (x == 2 && y == 1) return 3;
        return 4;
    }
    ll h = 1LL << (n - 1);
    ll b = 1LL << (2 * (n - 1));
    if (x <= h && y <= h) return getNum(n - 1, x, y);
    if (x > h && y > h) return b + getNum(n - 1, x - h, y - h);
    if (x > h && y <= h) return 2 * b + getNum(n - 1, x - h, y);
    return 3 * b + getNum(n - 1, x, y - h);
}

pair<int, int> getPos(int n, ll d) {
    if (n == 1) {
        if (d == 1) return {1, 1};
        if (d == 2) return {2, 2};
        if (d == 3) return {2, 1};
        return {1, 2};
    }
    ll h = 1 << (n - 1);
    ll b = 1LL << (2 * (n - 1));
    if (d <= b) return getPos(n - 1, d);
    if (d <= 2 * b) {
        auto p = getPos(n - 1, d - b);
        return {p.first + h, p.second + h};
    }
    if (d <= 3 * b) {
        auto p = getPos(n - 1, d - 2 * b);
        return {p.first + h, p.second};
    }
    auto p = getPos(n - 1, d - 3 * b);
    return {p.first, p.second + h};
}

void solve() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        string type;
        cin >> type;
        if (type == "->") {
            int x, y;
            cin >> x >> y;
            cout << getNum(n, x, y) << "\n";
        } else {
            ll d;
            cin >> d;
            auto [x, y] = getPos(n, d);
            cout << x << " " << y << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << "\n";
    }
    return 0;
}
