#include<bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<bool>& visited, vector<vector<int>>& edges, int& cnt, vector<int>& parent) {
	visited[curr] = true;
	parent[curr] = cnt;

	for (int e : edges[curr]) {
		if (!visited[e]) {
			dfs(e, visited, edges, cnt, parent);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(n+1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	vector<bool> visited(n + 1, false);
	vector<int> parent(n + 1);
	vector<int> comp;
	int cnt = 0;

	for(int i = 1; i <= n; i++) {
		if (!visited[i]) {
			comp.push_back(i);
			dfs(i, visited, edges, cnt, parent);
			cnt++;
		}
	}

	cout << comp.size() - 1 << endl;
	for (int i = 1; i < comp.size(); i++) {
		cout << comp[i - 1] << " " << comp[i] << endl;
	}

	return 0;
}
