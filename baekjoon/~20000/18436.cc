#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct fenwick {
	vector<T> a;
	fenwick(int n) { a.resize(n + 1); }

	void add(int p, T x) {
		do a[p] += x;
		while ((p += p & -p) < a.size());
	}
	T sum(int p) {
		T r{};
		do r += a[p];
		while (p -= p & -p);
		return r;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n + 1);
	fenwick<int> even(n + 1), odd(n + 1);
	for(int i =1; i<=n; ++i) {
		cin >> a[i];
		if (a[i] & 1) odd.add(i, 1);
		else even.add(i, 1);
	}
	int m; cin >> m;
	for(int i =0; i<m; ++i) {
		int o, l, r;
		cin >> o >> l >> r;
		if (o == 1) {
			if (a[l] & 1) odd.add(l, -1);
			else even.add(l, -1);
			a[l] = r;
			if (r & 1) odd.add(l, 1);
			else even.add(l, 1);
		} else if (o == 2) {
			cout << even.sum(r) - even.sum(l - 1) << '\n';
		} else if (o == 3) {
			cout << odd.sum(r) - odd.sum(l - 1) << '\n';
		}
	}

}