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

	int n, m;
	cin >> n >> m;
	vector<int> a(n), ord;
	for(int i =0; i<n; ++i) {
		cin >> a[i];
		ord.push_back(a[i]);
	}
	sort(ord.begin(), ord.end());
	ord.erase(unique(ord.begin(), ord.end()), ord.end());
	for(int & i : a) i = lower_bound(ord.begin(), ord.end(), i) - ord.begin() + 1;

	struct Q {int s, e, qi;};
	vector<Q> q;
	for(int i =0; i<m; ++i) {
		int s, e;
		cin >> s >> e;
		q.push_back({s-1, e-1, i});
	}
	sort(q.begin(), q.end(), [](auto& a, auto& b) {
		return make_pair(a.s / 320, a.e) < make_pair(b.s / 320, b.e);
	});
	vector<long long> ans(m);
	fenwick<int> fw(100005);
	int l = 0, r = -1;
	long long sum = 0;
	for(auto & [s, e, qi] : q) {
		while(l < s) {
			fw.add(a[l], -1);
			sum -= fw.sum(a[l] - 1);
			l++;
		}
		while(l > s) {
			l--;
			fw.add(a[l], 1);
			sum += fw.sum(a[l] - 1);
		}
		while(r < e) {
			r++;
			fw.add(a[r], 1);
			sum += fw.sum(100000) - fw.sum(a[r]);
		}
		while(r > e) {
			fw.add(a[r], -1);
			sum -= fw.sum(100000) - fw.sum(a[r]);
			r--;
		}
		ans[qi] = sum;
	}
	for(auto i : ans) cout << i << '\n';
}