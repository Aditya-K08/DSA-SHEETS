#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pyes cout << "YES"<< "\n";
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

ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }

ll gcd(ll a, ll b) {
  if (a == 0ll) {
    return b;
  }
  return gcd(b % a, a);
}

void concept() {
    int n;
    cin >> n;
    vector<int> arr(n);
    bool hasodd = false, haseven = false;
    ll maxodd = 0, maxeven = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            haseven = true;
            maxeven = max(maxeven, arr[i]);
        } else {
            hasodd = true;
            maxodd = max(maxodd, arr[i]);
        }
    }

    if (!haseven || !hasodd) {
        cout << "0" << endl;
    } else {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 == 0) {
                if (maxodd >= arr[i]) {
                    cnt++;
                    maxodd += arr[i];
                } else {
                    cnt += 2;
                    maxodd += maxeven;
                }
            }
        }
        cout << cnt << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        concept();
    }
    return 0;
}