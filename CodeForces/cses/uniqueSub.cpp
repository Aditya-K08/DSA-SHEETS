#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define concept08 

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#define isOn(S, j) (S & (1<<j))
#define setBit(S, j) (S |= (1<<j))
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1<<n)-1)

#define modulo(S, N) ((S) & (N-1))   
#define isPowerOfTwo(S) (!(S & (S-1)))
#define nearestPowerOfTwo(S) (1<<lround(log2(S)))
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define turnOffLastConsecutiveBits(S) ((S) & (S+1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S-1))


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef __int128 ell;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

ll gcd(ll a, ll b) {
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<ll> sieve(int n) {
    int* arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    }
    delete[] arr;
    return vect;
}

template <typename T>
class SegmentTree {
    vector<T> tree;
    int n;
    T IDENTITY; 

    function<T(T,T)> merge; 

public:
    SegmentTree(vector<T>& arr, T identity, function<T(T,T)> mergeFn) {
        n = arr.size();
        tree.resize(4*n);
        IDENTITY = identity;
        merge = mergeFn;
        build(arr, 0, 0, n-1);
    }

    void build(vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node+1, start, mid);
            build(arr, 2*node+2, mid+1, end);
            tree[node] = merge(tree[2*node+1], tree[2*node+2]);
        }
    }

    T query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) return IDENTITY; // no overlap
        if (L <= start && end <= R) return tree[node]; // total overlap
        int mid = (start + end) / 2;
        T left = query(2*node+1, start, mid, L, R);
        T right = query(2*node+2, mid+1, end, L, R);
        return merge(left, right);
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2*node+1, start, mid, idx, val);
            else
                update(2*node+2, mid+1, end, idx, val);
            tree[node] = merge(tree[2*node+1], tree[2*node+2]);
        }
    }

    T query(int L, int R) {
        return query(0, 0, n-1, L, R);
    }

    void update(int idx, T val) {
        update(0, 0, n-1, idx, val);
    }

    int getMaxi(int mask, int node, int start, int end, int bit) {
        if (tree[node] == 0) return -1;
        if (start == end) return start;
        int mid = (start + end) / 2;
        int leftNode = 2*node+1, rightNode = 2*node+2;
        int mbit = (mask >> bit) & 1;
        if (mbit == 1) {
            if (tree[leftNode] > 0) return getMaxi(mask, leftNode, start, mid, bit-1);
            return -1;
        } else {
            if (tree[rightNode] > 0) return getMaxi(mask, rightNode, mid+1, end, bit-1);
            if (tree[leftNode] > 0) return getMaxi(mask, leftNode, start, mid, bit-1);
            return -1;
        }
    }

    int getMaxi(int mask, int max_bit) {
        return getMaxi(mask, 0, 0, n-1, max_bit);
    }
};

template <typename T>
using ordered_multiset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int upperLimit = 17;
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = 0, j = 0;
    unordered_map<ll, int> map;
    ll cnt = 0;

    while (j < n) {
        while (map.count(arr[j])) {
            map[arr[i]]--;
            if (map[arr[i]] == 0) map.erase(arr[i]);
            i++;
        }
        map[arr[j]]++;
        cnt += j - i + 1;
        j++;
    }

    cout << cnt << "\n";
}




int main() {
#ifdef concept08
    freopen("Error.txt", "w", stderr);
#endif

    fastio();
    auto start1 = high_resolution_clock::now();

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve(); 
    // }
    solve(); 
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);

#ifdef concept08
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
#endif

    return 0;
}
