#include <bits/stdc++.h>

using namespace std;

vector<int> tree[1<<17];
int n, m, a[1<<16], b, c;

#define LEFT n<<1,l,l+r>>1
#define RIGHT n<<1|1,(l+r>>1)+1,r
void init(int n, int l, int r) {
	if (l == r) return tree[n].push_back(a[l]), void();
	init(LEFT);
	init(RIGHT);
	int i =0, j =0;
	vector<int>& le = tree[n<<1];
	vector<int>& ri = tree[n<<1|1];
	while(i < le.size() && j < ri.size()) {
		tree[n].push_back(le[i] < ri[j] ? le[i++] : ri[j++]);
	}
	while(i < le.size()) tree[n].push_back(le[i++]);
	while(j < ri.size()) tree[n].push_back(ri[j++]);
}
int cntquery(int n, int l, int r, int s, int e, int k) {
	if (r < s || e < l) return 0;
	if (s <= l && r <= e) return tree[n].end() - upper_bound(tree[n].begin(), tree[n].end(), k);
	return cntquery(LEFT, s, e, k) + cntquery(RIGHT, s, e, k);
}
void solve() {
	for(int i =0; i<1<<17; ++i) tree[i].clear();
	cin >> n;
	for(int i =0; i<n; ++i) cin >> a[i];
	init(1, 0, n - 1);
	long long ans = 0;
	for(int i =1; i<n; ++i) ans += cntquery(1, 0, n - 1, 0, i - 1, a[i]);
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t =0, T;
	cin >> T;
	while(++t <= T) solve();
}