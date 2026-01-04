#include <iostream>
#include <vector>
using namespace std;

// Build the segment tree
void build(vector<int> &arr, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(arr, tree, 2 * node, start, mid);
        build(arr, tree, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

// Query range sum [l, r]
int query(vector<int> &tree, int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0; // no overlap
    if (l <= start && end <= r) return tree[node]; // total overlap

    int mid = (start + end) / 2;
    int left = query(tree, 2 * node, start, mid, l, r);
    int right = query(tree, 2 * node + 1, mid + 1, end, l, r);
    return left + right;
}

// Update a value at index idx
void update(vector<int> &arr, vector<int> &tree, int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(arr, tree, 2 * node, start, mid, idx, val);
        else
            update(arr, tree, 2 * node + 1, mid + 1, end, idx, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}
int main() {
    int n = 6;
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    vector<int> tree(4 * n); // segment tree size

    build(arr, tree, 1, 0, n - 1);

    cout << query(tree, 1, 0, n - 1, 1, 3) << endl; // 3 + 5 + 7 = 15

    update(arr, tree, 1, 0, n - 1, 1, 10); // arr[1] = 10

    cout << query(tree, 1, 0, n - 1, 1, 3) << endl; // 10 + 5 + 7 = 22

    return 0;
}


//
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}