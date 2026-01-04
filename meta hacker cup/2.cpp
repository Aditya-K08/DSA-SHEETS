#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool validate(const vector<ll> &A, ll h) {
    int n = A.size();
    vector<bool> visited(n, false);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (A[i] <= h) {
            visited[i] = true;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int i = q.front(); q.pop();
        if (i > 0 && !visited[i-1] && abs(A[i-1]-A[i]) <= h) {
            visited[i-1] = true;
            q.push(i-1);
        }
        if (i < n-1 && !visited[i+1] && abs(A[i+1]-A[i]) <= h) {
            visited[i+1] = true;
            q.push(i+1);
        }
    }
    
    for (bool v : visited)
        if (!v) return false;
    return true;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;
        vector<ll> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        if (N == 1) {
            cout << "Case #" << tc << ": " << A[0] << "\n";
            continue;
        }

        ll lo = 0, hi = *max_element(A.begin(), A.end()), ans = hi;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            if (validate(A, mid)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }
}
