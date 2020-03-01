#include <bits/stdc++.h>

using namespace std;

auto fio = ios::sync_with_stdio(0);

template<class T, class Comp = less<T>>
struct rmq {
	T a[1<<18];
	int n;
	void init(int _n, T *_a) {
		n = 1 << 32 - __builtin_clz(_n);
		for(int i =0; i<_n; ++i) a[i + n] = _a[i];
		for(int i =n -1; i; --i) a[i] = min(a[i<<1], a[i<<1|1], Comp());
	}
	T query(int s, int e) {
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
	int n, a[100005], b[100005];
	long long m;
	rmq<int, greater<int>> rm;

	cin >> n >> m;
	for(int i =0; i<n; ++i) cin >> a[i] >> b[i];
	rm.init(n, b);

	long long ps = 0;
	int ans = 1e9;
	for(int i =0, j =0; i<n; ++i) {
		ps += a[i];
		while (ps >= m) {
			ans = min(ans, rm.query(j, i));
			ps -= a[j++];
		}
	}
	cout << ans;
}