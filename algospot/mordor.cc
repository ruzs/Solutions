#include <bits/stdc++.h>

using namespace std;

template<class T, class Comp = less<T>>
struct RMQ {
	T a[1<<18];
	int n;
	RMQ(int _n, T *_a) {
		n = 1 << 32 - __builtin_clz(_n);
		for(int i =0; i<_n; ++i) a[i + n] = _a[i];
		for(int i =n -1; i; --i) a[i] = min(a[i<<1], a[i<<1|1], Comp());
	}
	void update(int p, int x) {
		a[p += n] = x;
		while(p >>= 1) a[p] = min(a[p<<1], a[p<<1|1]);
	}
	auto query(int s, int e) {
		int r = min(a[s += n], a[e += n], Comp());
		while(s <= e) {
			if (s % 2 == 1) r = min(r, a[s++], Comp());
			if (e % 2 == 0) r = min(r, a[e--], Comp());
			s >>= 1; e >>= 1;
		}
		return r;
	}
};
int n, q, a[100005], b, c;
void solve() {
	cin >> n >> q;
	for(int i =0; i<n; ++i) cin >> a[i];
	RMQ<int> rmn(n, a);
	RMQ<int, greater<int>> rmx(n, a);
	while(q--) {
		cin >> b >> c;
		cout << rmx.query(b, c) - rmn.query(b, c) << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}