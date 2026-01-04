#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    set<int> kids;
    for (int i = 1; i <= n; i++) kids.insert(i);
    k=k%n;
    auto it = kids.begin();

    while (!kids.empty()) {
        for (int i = 1; i <= k; i++) {
            ++it;
            if (it == kids.end()) it = kids.begin();
        }

        cout << *it << " ";
        auto toErase = it++;
        if (it == kids.end()) it = kids.begin();
        kids.erase(toErase);
    }

    return 0;
}
