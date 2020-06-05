#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct fenwick {
	vector<T> a;
	fenwick(int n) { a.resize(n); }

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

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int & i : a) cin >> i;
	for(int & i : b) cin >> i;
	int m;
	cin >> m;
	struct Q {int s, e, k, qi;};
	vector<Q> q;
	vector<long long> ans(m);
	for(int i =0; i<m; ++i) {
		int s, e, k;
		cin >> s >> e >> k;
		q.push_back({s - 1, e - 1, k, i});
	}
	sort(q.begin(), q.end(), [](auto& a, auto& b) {
		return make_pair(a.s / 320, a.e) < make_pair(b.s / 320, b.e);
	});

	fenwick<int> fa(100005), fb(100005);
	auto ins = [&](int x) {
		fa.add(a[x], 1);
		fb.add(b[x], 1);
	};
	auto del = [&](int x) {
		fa.add(a[x], -1);
		fb.add(b[x], -1);
	};
	int l = 0, r = -1;
	for(auto & [s, e, k, qi] : q) {
		while(l < s) del(l++);
		while(l > s) ins(--l);
		while(r < e) ins(++r);
		while(r > e) del(r--);
		long long sum = 0, sqr = sqrt(k);
		for(int i =1; i<=sqr; ++i) {
			sum += (long long)(fa.sum(k / i) - fa.sum(sqr)) * (fb.sum(i) - fb.sum(i - 1));
			sum += (long long)fb.sum(k / i) * (fa.sum(i) - fa.sum(i - 1));
		}
		ans[qi] = sum;
	}
	for(long long i : ans) cout << i << '\n';
}