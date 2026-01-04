#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define br cout << "\n";
#define ff first
#define sc second
#define pb push_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll ceil_div(ll a, ll b) {
	return a % b == 0 ? a / b : a / b + 1;
}

ll gcd(ll a, ll b) {
	if (a == 0ll) {
		return b;
	}
	return gcd(b % a, a);
}
const int N = 1e5; 
int tree[4 * N];   
int arr[N];  
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

// Query the sum in range [l, r]
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;          // no overlap
    if (l <= start && end <= r) return tree[node]; // total overlap

    // partial overlap
    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

// Update index idx to value val
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

void concept() {
   
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		concept();
		cout<<endl;
	}
	return 0;
}