#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int n, ans;
pair<int, int> p[100005];
struct fenwick {
	int f[N];
	void update(int p, int x) {
		while(p < N) f[p] += x, p += p & -p;
	}
	int query(int p) {
		int r = f[p];
		while(p -= p & -p) r += f[p];
		return r;
	}
} col, row;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> p[i].first >> p[i].second;
	}
	p[n] = p[0];
	for(int i =1; i<=n; ++i) {
		if (p[i].first == p[i - 1].first){
			row.update(min(p[i].second, p[i - 1].second) + 500001, 1);
			row.update(max(p[i].second, p[i - 1].second) + 500001, -1);
		}
		else{
			col.update(min(p[i].first, p[i - 1].first) + 500001, 1);
			col.update(max(p[i].first, p[i - 1].first) + 500001, -1);
		}
	}
	for(int i =1; i<=1000000; ++i) {
		ans = max(ans, row.query(i));
		ans = max(ans, col.query(i));
	}
	printf("%d", ans);
}
