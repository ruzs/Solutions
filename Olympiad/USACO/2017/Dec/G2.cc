#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5, M = 1e9+7;
bool F[] = { ios::sync_with_stdio(0), cin.tie(0) };

int n, k, a, b, c[N], d[N][4];
vector<int> g[N];

int dp(int a, int pc, int p) {
	int & ref = d[a][pc];
	if (~ref) return ref;

	if (c[a]) {
		if (c[a] == pc) return ref = 0;
		ref = 1;
		for(int b : g[a]) {
			if (b == p) continue;
			ref = (1ll * ref * dp(b, c[a], a)) % M;
		}
	}
	else {
		ref = 0;
		for(int i =1; i<=3; ++i) {
			if (i == pc) continue;
			long long tmp = 1;
			for(int b : g[a]) {
				if (b == p) continue;
				tmp = (tmp * dp(b, i, a)) % M;
			}
			ref = (ref + tmp) % M;
		}
	}
	return ref;
}
int main() {
	cin >> n >> k;
	while(--n) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(d, -1, sizeof d);
	while(k--) {
		cin >> a >> b;
		c[a] = b;
	}
	cout << dp(1, 0, 0);
}