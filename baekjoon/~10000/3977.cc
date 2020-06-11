#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> g(n), tg(n);
		for(int i =0; i<m; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			tg[v].push_back(u);
		}
		int sccn = 0;
		vector<int> visited(n), st, scc(n);
		function<void(int)> dfs = [&](int u) {
			visited[u] = 1;
			for(int v : g[u]) if (!visited[v]) dfs(v);
			st.push_back(u);
		};
		function<void(int)> tdfs = [&](int u) {
			visited[u] = 0;
			scc[u] = sccn;
			for(int v : tg[u]) if (visited[v]) tdfs(v);
		};
		for(int v =0; v<n; ++v) {
			if (!visited[v]) dfs(v);
		}
		for(int i =n-1; ~i; --i) {
			if (visited[st[i]]) {
				tdfs(st[i]);
				sccn++;
			}
		}
		vector<int> indegree(sccn);
		for(int u =0; u<n; ++u) {
			for(int v : g[u]) {
				if (scc[u] != scc[v]) indegree[scc[v]]++;
			}
		}
		if (count(indegree.begin(), indegree.end(), 0) > 1)
			cout << "Confused\n\n";
		else {
			set<int> ans;
			for(int i =0; i<n; ++i) {
				if (indegree[scc[i]] == 0)
					ans.insert(i);
			}
			for(int i : ans) cout << i << '\n';
			cout << '\n';
		}
	}
}