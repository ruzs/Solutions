#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, m, a, b, c;
vector<int> g[N];
pair<int, int> range[N];
void dfs(int a, int p = 0) {
	range[a].first = ++c;
	for(int b : g[a]) {
		if (b != p) dfs(b, a);
	}
	range[a].second = c;
}
#define LEFT n<<1,l,l+r>>1
#define RGHT n<<1|1,(l+r>>1)+1,r
int tree[N<<2], lazy[N<<2];
void apply(int n, int l, int r) {
	tree[n] ^= r - l & 1 ? 0 : lazy[n];
	if (l != r) {
		lazy[n << 1] ^= lazy[n];
		lazy[n << 1 | 1] ^= lazy[n];
	}
	lazy[n] = 0;
}
void update(int n, int l, int r, int s, int e, int x) {
	if (lazy[n]) apply(n, l, r);
	if (e < l || r < s) return;
	if (s <= l && r <= e) {
		lazy[n] ^= x;
		apply(n, l, r);
		return;
	}
	update(LEFT, s, e, x);
	update(RGHT, s, e, x);
	tree[n] = tree[n << 1] ^ tree[n << 1 | 1];
}
int query(int n, int l, int r, int s, int e) {
	if (lazy[n]) apply(n, l, r);
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) return tree[n];
	return query(LEFT, s, e) ^ query(RGHT, s, e);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for(int i =1; i<n; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	for(int i =1; i<=n; ++i) {
		cin >> c;
		update(1, 1, n, range[i].first, range[i].first, c);
	}
	for(int i =0; i<m; ++i) {
		cin >> a;
		if (a == 1) {
			cin >> b;
			cout << query(1, 1, n, range[b].first, range[b].second) << '\n';
		} else {
			cin >> b >> c;
			update(1, 1, n, range[b].first, range[b].second, c);
		}
	}
}