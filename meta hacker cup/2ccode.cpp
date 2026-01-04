#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define all(x) (x).begin(), (x).end()
#define pb push_back

struct Appear {
    int route;
    int pos;
};

struct DSU {
    vector<int> p;
    DSU() {}
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    int first(int x) {
        return find(x);
    }
    void erase(int x) {
        p[x] = find(x + 1);
    }
};

void solve(int tc){
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> adj;
    adj.reserve(m);
    vector<DSU> dsu;
    dsu.reserve(m);
    vector<vector<Appear>> at(n + 1);

    rep(r,0,m){
        int L;
        cin >> L;
        adj.emplace_back();
        adj.back().reserve(L);
        rep(j,0,L){
            int x;
            cin >> x;
            adj.back().pb(x);
        }
        int idxRoute = (int)adj.size() - 1;
        rep(j,0,L){
            int node = adj[idxRoute][j];
            at[node].push_back({idxRoute, j});
        }
        dsu.emplace_back(L + 1);
    }

    const ll INF = (ll)4e18;
    vector<ll> dist(n + 1, INF);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ll du = dist[u];

        for (auto &a : at[u]) {
            int r = a.route;
            int p = a.pos;
            int L = (int)adj[r].size();

            int left = p + 1;
            if (left >= L) continue;
            int right = p + k;
            if (right >= L) right = L - 1;

            auto &D = dsu[r];
            int idx = D.first(left);
            while (idx <= right) {
                int v = adj[r][idx];

                if (dist[v] == INF) {
                    dist[v] = du + 1;
                    q.push(v);
                }

                D.erase(idx);
                idx = D.first(idx);
            }
        }
    }

    long long ans = 0;
    rep(i,1,n+1){
        ll d = (dist[i] == INF ? -1 : dist[i]);
        ans += 1LL * i * d;
    }

    cout << "Case #" << tc << ": " << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    rep(tc,1,T+1){
        solve(tc);
    }
    return 0;
}
