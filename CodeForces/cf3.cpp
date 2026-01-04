#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sol() {
    ll n;
    ll maxodd = 0;
    ll maxeven = 0;
    bool hasodd = false;
    bool haseven = false;
    cin >> n;
    vector<ll> arr(n);
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
    sort(arr.begin(), arr.end());

    ll ans = 0;

    if (hasodd && haseven) {
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 == 0) {
                if (maxodd >= arr[i]) {
                    maxodd += arr[i];
                    ++ans;
                } else {
                    maxodd += maxeven;
                    ans += 2;
                }
            }
        }
        cout << ans << '\n';
    } else {
        cout << "0\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
