#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<vector<int>> tree(4 * MAXN, vector<int>(26, 0));
string s;

void build(int node, int start, int end) {
    if (start == end) {
        tree[node][s[start] - 'a'] = 1;
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        for (int i = 0; i < 26; i++) {
            tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }
}

void update(int node, int start, int end, int idx, char old_char, char new_char) {
    if (start == end) {
        tree[node][old_char - 'a']--;
        tree[node][new_char - 'a']++;
        s[idx] = new_char;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, old_char, new_char);
        } else {
            update(2 * node + 1, mid + 1, end, idx, old_char, new_char);
        }
        for (int i = 0; i < 26; i++) {
            tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
        }
    }
}

vector<int> query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return vector<int>(26, 0);
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    vector<int> left = query(2 * node, start, mid, l, r);
    vector<int> right = query(2 * node + 1, mid + 1, end, l, r);
    vector<int> result(26, 0);
    for (int i = 0; i < 26; i++) {
        result[i] = left[i] + right[i];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    int n = s.size();
    build(1, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            pos--; 
            update(1, 0, n - 1, pos, s[pos], c);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            vector<int> freq = query(1, 0, n - 1, l, r);
            int count = 0;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) count++;
            }
            cout << count << '\n';
        }
    }
}
