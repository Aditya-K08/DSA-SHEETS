#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;
        vector<ull> A(N + 1);
        for (int i = 1; i <= N; ++i) cin >> A[i];

        unordered_map<ull, ll> cnt;

        ull px = 0;
        cnt[px]++;
        for (int i = 1; i <= N; ++i) {
            px ^= A[i];
            cnt[px]++;
        }

        __int128 t = (__int128)N * (N + 1) * (N + 2);
        ll totalTriplets = (ll)(t / 6);

        __int128 subtract = 0;
        for (auto &pr : cnt) {
            ll c = pr.second;
            if (c >= 2) subtract += (__int128)c * (c - 1) / 2;
            if (c >= 3) subtract += (__int128)c * (c - 1) * (c - 2) / 6;
        }

        __int128 result = (__int128)totalTriplets - subtract;
        ll answer = (ll)result;

        cout << "Case #" << tc << ": " << answer << "\n";
    }
    return 0;
}





913669539   +   910238130   +   860114890   -   813829899   -   6149048   -   26582657   -   36124499   +   43993239
913669539   +   910238130   +   860114890   -   813829899   -   6149048   -   26582657   -   36124499   +   43993239
913669539   -   910238130   +   860114890   +   813829899   -   6149048   -   26582657   -   36124499   +   43993239