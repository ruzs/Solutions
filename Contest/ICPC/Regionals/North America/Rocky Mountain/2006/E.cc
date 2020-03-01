#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct fenwick {
	vector<T> a;
	int n;
	fenwick(int _n) : n(_n) {
		a.resize(n);
	}
	void add(int p, T x) {
		while(p < n) {
			a[p] += x;
			p += p & -p;
		}
	}
	T sum(int p) {
		T r{};
		while(p) {
			r += a[p];
			p -= p & -p;
		}
		return r;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	fenwick<int> fw(n + 1);
	for(int i =1; i<=n; ++i) fw.add(i, 1);
	for(int i =0; i<n; ++i) {
		int x;
		cin >> x;
		int ans = 0, j = n;
		while (j /= 2) {
			while(ans + j <= n && fw.sum(ans + j) - 1 < x) ans += j;
		}
		fw.add(ans + 1, -1);
		a[ans + 1] = i + 1;
	}
	for(int i =1; i<=n; ++i) cout << a[i] << '\n';
}