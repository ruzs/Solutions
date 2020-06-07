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
	vector<int> ans(m);
	vector<int> cnt(200005);
	vector<int> mx(100005);
	mx[0] = 200005;
	int l = 0, r = -1, ret = 0;
	auto ins = [&](int x) {
		int y = a[x] + 100000;
		mx[cnt[y]]--;
		cnt[y]++;
		mx[cnt[y]]++;
		ret = max(ret, cnt[y]);
	};
	auto del = [&](int x) {
		int y = a[x] + 100000;
		mx[cnt[y]]--;
		cnt[y]--;
		mx[cnt[y]]++;
		if (!mx[ret]) ret--;
	};
	for(auto & [s, e, qi] : q) {
		while(l > s) ins(--l);
		while(r < e) ins(++r);
		while(l < s) del(l++);
		while(r > e) del(r--);
		ans[qi] = ret;
	}
	for(auto i : ans) cout << i << '\n';
}