#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF64 = (ll)4e18;

struct Item {
    int len;
    ll val;
    long double ratio;
    int idx;
};

int N;
ll M;
vector<ll> A;
vector<ll> V;

vector<Item> items;
vector<long double> sufMaxRatio;
ll bestCost;
vector<ll> bestCnt;
vector<ll> curCnt;

void dfs(int pos, ll remVal, ll curCost) {
    if (remVal <= 0) {
        if (curCost < bestCost) {
            bestCost = curCost;
            bestCnt = curCnt;
        }
        return;
    }
    if (pos == (int)items.size()) return;

    long double r = sufMaxRatio[pos];
    ll lbExtra = (ll)ceill((long double)remVal / r);
    if (curCost + lbExtra >= bestCost) return;

    const Item &it = items[pos];
    int Ci = it.len;
    ll Vi = it.val;
    int idx = it.idx;

    ll maxK = (bestCost - curCost) / Ci;

    for (ll k = maxK; k >= 0; --k) {
        ll newCost = curCost + k * Ci;
        if (newCost >= bestCost) continue;

        ll newRem = remVal - k * Vi;
        if (newRem > 0) {
            if (pos + 1 >= (int)items.size()) continue;
            long double r2 = sufMaxRatio[pos + 1];
            ll lb2 = (ll)ceill((long double)newRem / r2);
            if (newCost + lb2 >= bestCost) continue;
        }

        curCnt[idx] += k;
        dfs(pos + 1, newRem, newCost);
        curCnt[idx] -= k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;

    for (int tc = 1; tc <= T; ++tc) {
        cin >> N >> M;
        A.assign(N + 1, 0);
        for (int i = 1; i <= N; ++i) cin >> A[i];

        V.assign(N + 1, 0);
        for (int i = 1; i <= N; ++i) V[i] = V[i - 1] + A[i];

        items.clear();
        for (int i = 1; i <= N; ++i) {
            Item it;
            it.len = i;
            it.val = V[i];
            it.ratio = (long double)V[i] / (long double)i;
            it.idx = i;
            items.push_back(it);
        }

        sort(items.begin(), items.end(),
             [](const Item &a, const Item &b) {
                 if (fabsl(a.ratio - b.ratio) > 1e-18)
                     return a.ratio > b.ratio;
                 return a.len < b.len;
             });

        int K = items.size();
        sufMaxRatio.assign(K + 1, 0.0L);
        for (int i = K - 1; i >= 0; --i)
            sufMaxRatio[i] = max(sufMaxRatio[i + 1], items[i].ratio);

        const Item &bestItem = items[0];
        ll bestLen = bestItem.len;
        ll bestVal = bestItem.val;
        ll t = (M + bestVal - 1) / bestVal;
        bestCost = t * bestLen;

        bestCnt.assign(N + 1, 0);
        bestCnt[bestItem.idx] = t;
        curCnt.assign(N + 1, 0);

        dfs(0, M, 0);

        vector<ll> x(N + 1, 0);
        x[N] = bestCnt[N];
        for (int i = N - 1; i >= 1; --i)
            x[i] = bestCnt[i] + x[i + 1];

        cout << "Case #" << tc << ": " << bestCost << "\n";
        for (int i = 1; i <= N; ++i)
            cout << x[i] << (i + 1 <= N ? ' ' : '\n');
    }
    return 0;
}
