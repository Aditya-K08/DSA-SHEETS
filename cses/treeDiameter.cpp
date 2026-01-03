#include <bits/stdc++.h>
using namespace std;

int maxi = 0;

void dfs(int u, int parent, vector<vector<int>>& adj, int depth) {
    maxi = max(maxi, depth);
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u, adj, depth + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1, adj, 0);
    cout << maxi << endl;
}
#include <bits/stdc++.h>
using namespace std;

struct Flow {
    int gA, lA, gB, lB;
};

struct Endpoint {
    int g;
    int spine;
    int k;
    int port;
};

struct Circuit {
    int m;
    Endpoint a, b; // a.g < b.g
};

static std::mt19937 rng(712367);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, L;
    cin >> N >> S >> L;
    int M, K, P;
    cin >> M >> K >> P;

    int SP = S / P;
    int MP = M / P;
    int R = N * SP * K;

    auto plane_of_oxc = [&](int m) -> int { return m / MP; };

    auto decode_port = [&](int m, int idx) -> Endpoint {
        int p = plane_of_oxc(m);
        int block = SP * K;
        int g = idx / block;
        int rem = idx % block;
        int local_s = rem / K;
        int k = rem % K;
        int spine = p * SP + local_s;
        return Endpoint{g, spine, k, idx};
    };

    vector<vector<int>> conn(M, vector<int>(R, -1)); // persistent across queries

    int QNUM = 5;
    for (int qi = 0; qi < QNUM; qi++) {
        int Q;
        cin >> Q;
        vector<Flow> flows(Q);
        vector<vector<int>> D(N, vector<int>(N, 0));
        for (int i = 0; i < Q; i++) {
            cin >> flows[i].gA >> flows[i].lA >> flows[i].gB >> flows[i].lB;
            D[flows[i].gA][flows[i].gB]++;
        }

        long long totalLS = 1LL * N * L * S;
        long long totalSO = 1LL * N * S * MP * K;
        long long LBLS = (2LL * Q + totalLS - 1) / totalLS;
        long long LBSO = (2LL * Q + totalSO - 1) / totalSO;
        long long T = max(1LL, max(LBLS, LBSO));

        vector<vector<int>> need(N, vector<int>(N, 0));
        auto recompute_need = [&]() {
            for (int i = 0; i < N; i++)
                for (int j = i + 1; j < N; j++)
                    need[i][j] = (D[i][j] == 0 ? 0 : (int)((D[i][j] + T - 1) / T));
        };

        auto feasible = [&]() -> bool {
            long long U = 1LL * S * MP * K;
            for (int g = 0; g < N; g++) {
                long long deg = 0;
                for (int h = 0; h < N; h++) {
                    if (g < h) deg += need[g][h];
                    else if (h < g) deg += need[h][g];
                }
                if (deg > U) return false;
            }
            return true;
        };

        while (true) {
            recompute_need();
            if (feasible()) break;
            T++;
        }

        vector<vector<int>> needRemain = need;

        for (int m = 0; m < M; m++) {
            for (int u = 0; u < R; u++) {
                int v = conn[m][u];
                if (v == -1 || u > v) continue;
                Endpoint eu = decode_port(m, u);
                Endpoint ev = decode_port(m, v);
                if (eu.g == ev.g) {
                    conn[m][u] = conn[m][v] = -1;
                    continue;
                }
                int a = min(eu.g, ev.g);
                int b = max(eu.g, ev.g);
                if (needRemain[a][b] > 0) {
                    needRemain[a][b]--;
                } else {
                    conn[m][u] = conn[m][v] = -1;
                }
            }
        }

        vector<vector<vector<int>>> freePorts(M, vector<vector<int>>(N));
        for (int m = 0; m < M; m++) {
            for (int g = 0; g < N; g++) {
                int start = g * SP * K;
                int len = SP * K;
                auto &fp = freePorts[m][g];
                fp.clear();
                fp.reserve(len);
                for (int t = 0; t < len; t++) {
                    int idx = start + t;
                    if (conn[m][idx] == -1) fp.push_back(idx);
                }
                shuffle(fp.begin(), fp.end(), rng);
            }
        }

        vector<tuple<int,int,int>> pairs;
        pairs.reserve(N * N);
        for (int g = 0; g < N; g++)
            for (int h = g + 1; h < N; h++)
                if (needRemain[g][h] > 0)
                    pairs.emplace_back(-D[g][h], g, h);
        sort(pairs.begin(), pairs.end());

        for (auto [negD, g, h] : pairs) {
            int c = needRemain[g][h];
            for (int it = 0; it < c; it++) {
                int bestM = -1;
                int bestScore = -1;
                for (int m = 0; m < M; m++) {
                    int sg = (int)freePorts[m][g].size();
                    int sh = (int)freePorts[m][h].size();
                    int score = min(sg, sh);
                    if (score > bestScore) {
                        bestScore = score;
                        bestM = m;
                    }
                }
                if (bestM == -1 || bestScore == 0) break;

                int u = freePorts[bestM][g].back(); freePorts[bestM][g].pop_back();
                int v = freePorts[bestM][h].back(); freePorts[bestM][h].pop_back();
                conn[bestM][u] = v;
                conn[bestM][v] = u;
            }
        }

        vector<vector<vector<int>>> circuitsIdx(N, vector<vector<int>>(N));
        vector<Circuit> circuits;
        circuits.reserve(M * (R / 2));

        for (int m = 0; m < M; m++) {
            for (int u = 0; u < R; u++) {
                int v = conn[m][u];
                if (v == -1 || u > v) continue;
                Endpoint eu = decode_port(m, u);
                Endpoint ev = decode_port(m, v);
                if (eu.g == ev.g) continue;
                Circuit c;
                c.m = m;
                if (eu.g < ev.g) { c.a = eu; c.b = ev; }
                else { c.a = ev; c.b = eu; }
                int id = (int)circuits.size();
                circuits.push_back(c);
                circuitsIdx[c.a.g][c.b.g].push_back(id);
            }
        }

        vector<vector<vector<int>>> loadLS(N, vector<vector<int>>(L, vector<int>(S, 0)));
        vector<vector<vector<array<int,2>>>> loadSO(N, vector<vector<array<int,2>>>(S, vector<array<int,2>>(M)));
        for (int g = 0; g < N; g++)
            for (int s = 0; s < S; s++)
                for (int m = 0; m < M; m++)
                    loadSO[g][s][m] = {0, 0};
        vector<vector<int>> loadPort(M, vector<int>(R, 0));

        auto eval_choice = [&](const Circuit &c, const Flow &f) -> int {
            int m = c.m;
            int sA, kA, pA;
            int sB, kB, pB;

            if (c.a.g == f.gA) {
                sA = c.a.spine; kA = c.a.k; pA = c.a.port;
                sB = c.b.spine; kB = c.b.k; pB = c.b.port;
            } else {
                sA = c.b.spine; kA = c.b.k; pA = c.b.port;
                sB = c.a.spine; kB = c.a.k; pB = c.a.port;
            }

            int t1 = loadLS[f.gA][f.lA][sA] + 1;
            int t2 = loadSO[f.gA][sA][m][kA] + 1;
            int t3 = max(loadPort[m][pA], loadPort[m][pB]) + 1;
            int t4 = loadSO[f.gB][sB][m][kB] + 1;
            int t5 = loadLS[f.gB][f.lB][sB] + 1;
            return max({t1, t2, t3, t4, t5});
        };

        vector<array<int,5>> routes(Q);

        for (int i = 0; i < Q; i++) {
            const Flow &f = flows[i];
            auto &lst = circuitsIdx[f.gA][f.gB];
            if (lst.empty()) {
                routes[i] = {0, 0, 0, 0, 0};
                continue;
            }

            int tries = min<int>(4, (int)lst.size());
            int bestId = lst[0];
            int bestVal = INT_MAX;

            if ((int)lst.size() <= tries) {
                for (int id : lst) {
                    int val = eval_choice(circuits[id], f);
                    if (val < bestVal) { bestVal = val; bestId = id; }
                }
            } else {
                uniform_int_distribution<int> dist(0, (int)lst.size() - 1);
                for (int t = 0; t < tries; t++) {
                    int id = lst[dist(rng)];
                    int val = eval_choice(circuits[id], f);
                    if (val < bestVal) { bestVal = val; bestId = id; }
                }
            }

            const Circuit &c = circuits[bestId];
            int m = c.m;
            int sA, kA, pA;
            int sB, kB, pB;

            if (c.a.g == f.gA) {
                sA = c.a.spine; kA = c.a.k; pA = c.a.port;
                sB = c.b.spine; kB = c.b.k; pB = c.b.port;
            } else {
                sA = c.b.spine; kA = c.b.k; pA = c.b.port;
                sB = c.a.spine; kB = c.a.k; pB = c.a.port;
            }

            loadLS[f.gA][f.lA][sA]++;
            loadSO[f.gA][sA][m][kA]++;
            loadPort[m][pA]++; loadPort[m][pB]++;
            loadSO[f.gB][sB][m][kB]++;
            loadLS[f.gB][f.lB][sB]++;

            routes[i] = {sA, kA, m, sB, kB};
        }

        for (int m = 0; m < M; m++) {
            for (int j = 0; j < R; j++) {
                cout << conn[m][j] << (j + 1 == R ? '\n' : ' ');
            }
        }
        for (int i = 0; i < Q; i++) {
            auto &r = routes[i];
            cout << r[0] << ' ' << r[1] << ' ' << r[2] << ' ' << r[3] << ' ' << r[4] << "\n";
        }
    }

    return 0;
}
