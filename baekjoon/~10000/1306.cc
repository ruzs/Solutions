#include <bits/stdc++.h>

using namespace std;

template <class T, class Comp = less<T>> struct rmq {
	vector<T> a;
	int n;
	rmq(const vector<T>& _a) {
		n = 1 << 32 - __builtin_clz(_a.size());
		a.resize(n << 1);
		copy(_a.begin(), _a.end(), a.begin() + n);
		for (int i = n - 1; i; --i)
			a[i] = min(a[i << 1], a[i << 1 | 1], Comp());
	}
	void update(int p, T x) {
		a[p += n] = x;
		while (p >>= 1) a[p] = min(a[p << 1], a[p << 1 | 1], Comp());
	}
	T query(int s, int e) {
		T r = min(a[s += n], a[e += n], Comp());
		while (s <= e) {
			if (s & 1)
				r = min(r, a[s++], Comp());
			if (!(e & 1))
				r = min(r, a[e--], Comp());
			s >>= 1;
			e >>= 1;
		}
		return r;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	rmq<int, greater<int>> rm(a);
	for (int i = m; i + m - 1 <= n; ++i) {
		cout << rm.query(i - m + 1, i + m - 1) << ' ';
	}
}