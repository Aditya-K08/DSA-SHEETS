#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        long long A, B;
        cin >> N >> A >> B;
        cout << "Case #" << tc << ":";
        int total = 2 * N;
        for (int i = 1; i < total; ++i) cout << " 1";
        cout << " " << B << "\n";
    }
    return 0;
}
