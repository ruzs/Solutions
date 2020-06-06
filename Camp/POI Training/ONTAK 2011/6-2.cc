#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	struct Q { int s, e, qi; };
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
	vector<int> cnt(1000005);
	int l = 0, r = -1;
	long long sum = 0;
	auto ins = [&](int x) {
		int y = a[x];
		sum -= (long long)cnt[y] * cnt[y] * y;
		cnt[y]++;
		sum += (long long)cnt[y] * cnt[y] * y;
	};
	auto del = [&](int x) {
		int y = a[x];
		sum -= (long long)cnt[y] * cnt[y] * y;
		cnt[y]--;
		sum += (long long)cnt[y] * cnt[y] * y;
	};
	for(auto & [s, e, qi] : q) {
		while(l < s) del(l++);
		while(l > s) ins(--l);
		while(r < e) ins(++r);
		while(r > e) del(r--);
		ans[qi] = sum;
	}
	for(auto i : ans) cout << i << '\n';
}