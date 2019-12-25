#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int t, n, m, i, j, k, a[N];
struct RMQ {
	int t[1 << 18], ts, mx;
	RMQ(int _mx) : mx(_mx) {}
	void init(int n) {
		memset(t, mx ? 0 : 64, sizeof t);
		ts = n - 1;
		for(int i =1; i<=16; i<<=1) ts |= ts >> i;
		ts++;
	}
	void update(int p, int x) {
		t[p += ts] = x;
		while(p >>= 1) t[p] = mx ? max(t[p << 1], t[p << 1 | 1]) : min(t[p << 1], t[p << 1 | 1]);
	}
	int query(int s, int e) {
		s += ts; e += ts;
		int r = mx ? 0 : 1e9;
		while(s <= e) {
			if (s % 2 == 1) r = mx ? max(r, t[s++]) : min(r, t[s++]);
			if (e % 2 == 0) r = mx ? max(r, t[e--]) : min(r, t[e--]);
			s /= 2; e /= 2;
		}
		return r;
	}
} mx(1), mn(0);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n >> m;
		mn.init(n);
		mx.init(n);
		for(int i =1; i<=n; ++i) {
			mx.update(i, i);
			mn.update(i, i);
			a[i] = i;
		}
		while(m--){
			cin >> i >> j >> k;
			j++; k++;
			if (i) {
				if (mx.query(j, k) == k && mn.query(j, k) == j) cout << "YES\n";
				else cout << "NO\n";
			} else {
				mx.update(j, a[k]);
				mx.update(k, a[j]);
				mn.update(j, a[k]);
				mn.update(k, a[j]);
				swap(a[j], a[k]);
			}
		}
	}
}
