#include <bits/stdc++.h>

using namespace std;

int st[1 << 23];
void update(int p, int x) {
	st[p += 1 << 22] += x;
	while(p >>= 1) st[p] = st[p << 1] + st[p << 1 | 1];
}
int kth(int k, int i = 1, int l = 0, int r = (1 << 22) - 1) {
	if (st[i] < k) return -1;
	if (l == r) return l;
	int m = l + r >> 1;
	if (st[i << 1] >= k) return kth(k, i << 1, l, m);
	else return kth(k - st[i << 1], i << 1 | 1, m + 1, r);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), sc = {1, 2, 5}, ps(3000005);
	for(int i =0; i<3; ++i) {
		for(int j =0; j<n; ++j) {
			int x; cin >> x;
			ps[a[j]] += sc[i];
			ps[a[j] += x] -= sc[i];
		}
	}
	for(int i =0; i<3000005; ++i) {
		if (i) ps[i] += ps[i - 1];
		st[i + (1 << 22)] = 1;
	}
	for(int i =(1 << 22) - 1; i; --i) {
		st[i] = st[i << 1] + st[i << 1 | 1];
	}
	int m;
	cin >> m;
	bitset<3000005> v;
	while(m--) {
		int k;
		cin >> k;
		int f = min(3000000, kth(k));
		if (!v[f]) {
			v[f] = 1;
			cout << ps[f] << '\n';
			update(f, -1);
		} else {
			cout << 0 << '\n';
		}
	}
}