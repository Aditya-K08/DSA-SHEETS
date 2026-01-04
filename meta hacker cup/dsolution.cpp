#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct KData {
    bool ready = false;
    int K;
    vector<int> safe_len;
    int safe_total;
    vector<unordered_map<uint32_t,int>> dp;
};

KData KD[26];

inline uint32_t rotate_and_add(uint32_t mask, int t, int K) {
    if (t == 0) return mask | 1u;
    uint32_t full = (1u << K) - 1u;
    uint32_t r = ((mask >> t) | ((mask << (K - t)) & full)) & full;
    return r | 1u;
}

int solve_rec(KData &kd, int rem, uint32_t mask) {
    if (rem == 0) return 1;
    int used = __builtin_popcount(mask);
    if (used + rem > kd.K) return 0;
    auto &mp = kd.dp[rem];
    auto it = mp.find(mask);
    if (it != mp.end()) return it->second;
    long long ans = 0;
    int K = kd.K;
    for (int d = 0; d <= 9; ++d) {
        int t = d % K;
        if (mask & (1u << t)) continue;
        uint32_t nm = rotate_and_add(mask, t, K);
        ans += solve_rec(kd, rem - 1, nm);
        if (ans >= MOD) ans -= MOD;
    }
    int res = ans;
    mp[mask] = res;
    return res;
}

void ensure_K_precomputed(int K) {
    if (KD[K].ready) return;
    KData &kd = KD[K];
    kd.ready = true;
    kd.K = K;
    kd.safe_len.assign(K, 0);
    kd.dp.assign(K, {});
    uint32_t M0 = 1u;
    for (int len = 1; len < K; ++len) {
        long long total = 0;
        for (int d = 1; d <= 9; ++d) {
            int t = d % K;
            if (M0 & (1u << t)) continue;
            uint32_t M1 = rotate_and_add(M0, t, K);
            total += solve_rec(kd, len - 1, M1);
            if (total >= MOD) total -= MOD;
        }
        kd.safe_len[len] = total;
    }
    long long s = 0;
    for (int len = 1; len < K; ++len) {
        s += kd.safe_len[len];
        if (s >= MOD) s -= MOD;
    }
    kd.safe_total = s;
}

int mod_of_str(const string &s) {
    long long v = 0;
    for (char c : s) v = (v * 10 + (c - '0')) % MOD;
    return v;
}

string dec_str(string s) {
    if (s == "0") return "0";
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '0') {
        s[i] = '9';
        i--;
    }
    if (i >= 0) s[i]--;
    int p = 0;
    while (p + 1 < s.size() && s[p] == '0') p++;
    s.erase(0, p);
    if (s.empty()) s = "0";
    return s;
}

int safe_up_to(const string &X, int K) {
    if (X == "0") return 0;
    ensure_K_precomputed(K);
    KData &kd = KD[K];
    int n = X.size();
    if (n >= K) return kd.safe_total;

    long long res = 0;
    for (int len = 1; len < n; ++len) {
        res += kd.safe_len[len];
        if (res >= MOD) res -= MOD;
    }

    vector<int> digits(n);
    for (int i = 0; i < n; ++i) digits[i] = X[i] - '0';

    uint32_t M = 1u;

    int fb = digits[0];
    for (int d = 1; d < fb; ++d) {
        int t = d % K;
        if (M & (1u << t)) continue;
        uint32_t M1 = rotate_and_add(M, t, K);
        int rem = n - 1;
        res += solve_rec(kd, rem, M1);
        if (res >= MOD) res -= MOD;
    }
    int t0 = fb % K;
    if (M & (1u << t0)) return res;
    M = rotate_and_add(M, t0, K);

    for (int i = 1; i < n; i++) {
        int limit = digits[i];
        for (int d = 0; d < limit; d++) {
            int t = d % K;
            if (M & (1u << t)) continue;
            uint32_t M1 = rotate_and_add(M, t, K);
            int rem = n - 1 - i;
            res += solve_rec(kd, rem, M1);
            if (res >= MOD) res -= MOD;
        }
        int t = limit % K;
        if (M & (1u << t)) return res;
        M = rotate_and_add(M, t, K);
    }

    res++;
    if (res >= MOD) res -= MOD;
    return res;
}

int kweak_up_to(const string &X, int K) {
    if (X == "0") return 0;
    int total = mod_of_str(X);
    int safe = safe_up_to(X, K);
    int ans = total - safe;
    if (ans < 0) ans += MOD;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        string L, R;
        int K;
        cin >> L >> R >> K;
        string Lm1 = dec_str(L);
        int a = kweak_up_to(R, K);
        int b = kweak_up_to(Lm1, K);
        int ans = a - b;
        if (ans < 0) ans += MOD;
        cout << "Case #" << tc << ": " << ans << "\n";
    }
}
