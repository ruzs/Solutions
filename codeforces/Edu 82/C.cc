#include <bits/stdc++.h>

using namespace std;

bool v[26];
set<int> g[26];
string ans;
void dfs(int a) {
	v[a] = 1;
	ans += a + 'a';
	for(int b : g[a]) {
		if (!v[b]) dfs(b);
	}
}
void solve() {
	for(int i =0; i<26; ++i) {
		v[i] = 0;
		g[i].clear();
	}
	string s;
	cin >> s;
	for(int i =1; i<s.size(); ++i) {
		g[s[i] - 'a'].insert(s[i - 1] - 'a');
		g[s[i - 1] - 'a'].insert(s[i] - 'a');
	}
	for(int i =0; i<26; ++i) {
		if (g[i].size() > 2) {
			cout << "NO\n";
			return;
		}
	}
	ans = "";
	for(int i =0; i<26; ++i) if (!v[i] && g[i].size() < 2) dfs(i);
	if (ans.size() < 26) cout << "NO\n";
	else cout << "YES\n" << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}