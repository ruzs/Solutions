#include <bits/stdc++.h>

using namespace std;

struct customer {
	int t, l, h;
} a[101];

int n, m;
bool go(int i, int m) {
	if (a[i].l > m || a[i].h < m) return 0;
	if (i == n) return 1;
	int d = a[i + 1].t - a[i].t;
	if (go(i + 1, m + d)) 
	return 0;
}
void solve() {
	cin >> n >> m;
	for(int i =1; i<=n; ++i) cin >> a[i].t >> a[i].l >> a[i].h;
	
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}