#include <bits/stdc++.h>

using namespace std;

template<class T, class Comp = less<T>>
struct rmq {
	T a[1<<18];
	int n;
	void init(int _n, T *_a) {
		n = 1 << 32 - __builtin_clz(_n);
		for(int i =0; i<_n; ++i) a[i + n] = _a[i];
		for(int i =n -1; i; --i) a[i] = min(a[i<<1], a[i<<1|1], Comp());
	}
	void update(int p, T x) {
		a[p += n] = x;
		while(p >>= 1) a[p] = min(a[p<<1], a[p<<1|1], Comp());
	}
	T query(int s, int e) {
		if (s > e) return {0, 0};
		T r = min(a[s += n], a[e += n], Comp());
		while(s <= e) {
			if (s % 2 == 1) r = min(r, a[s++], Comp());
			if (e % 2 == 0) r = min(r, a[e--], Comp());
			s >>= 1; e >>= 1;
		}
		return r;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	rmq<pair<int, int>, greater<pair<int, int>>> rm;

	int n, a, b, c;
	cin >> n;
	pair<int, int> arr[100005];
	for(int i =1; i<=n; ++i) cin >> arr[i].first, arr[i].second = i;

	rm.init(n + 1, arr);
	cin >> n;
	while(n--) {
		cin >> a >> b >> c;
		if (a == 1) rm.update(b, {c, b});
		else {
			auto r = rm.query(b, c);
			cout << r.first + max(rm.query(b, r.second - 1), rm.query(r.second + 1, c)).first << '\n';
		}
	}
}