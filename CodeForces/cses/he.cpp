#include <bits/stdc++.h>
using namespace std;

void build(vector<int> &arr, vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(arr, tree, 2 * node, start, mid);
        build(arr, tree, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
    }
}
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

        tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
    }
}

int query(vector<int> &tree, int node, int start, int end, int l, int r) {
    if (r < start || end < l) return INT_MAX;
    if (l <= start && end <= r) return tree[node]; 

    int mid = (start + end) / 2;
    int left = query(tree, 2 * node, start, mid, l, r);
    int right = query(tree, 2 * node + 1, mid + 1, end, l, r);
    return min(left,right);
}
int main() {
	int n,t;
	cin>>n>>t;
	vector<int>arr(n);
	vector<int>tree(4*n);
	for(int i=0;i<n;i++) cin>>arr[i];
	build(arr,tree,1,0,n-1);
	for(int i=0;i<n;i++){
		char s;
		int l,r;
		cin>>s>>l>>r;
		if(s=='u') update(arr,tree,1,0,n-1,l,r);
		else if(s=='q') cout<<query(tree,1,0,n-1,--l,--r)<<endl;
	}
}