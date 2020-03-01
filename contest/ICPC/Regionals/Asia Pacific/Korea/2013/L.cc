#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> pre(n), idx(n + 1);
		for(int i =0; i<n; ++i) cin >> pre[i];
		for(int i =0; i<n; ++i) {
			int in;
			cin >> in;
			idx[in] = i;
		}
		auto post = [&](auto& rec, int ps, int pe, int is, int ie) {
			if (ps > pe || is > ie) return;
			rec(rec, ps + 1, ps + idx[pre[ps]] - is, is, idx[pre[ps]] - 1);
			rec(rec, ps + idx[pre[ps]] - is + 1, pe, idx[pre[ps]] + 1, ie);
			cout << pre[ps] << ' ';
		};
		post(post, 0, n - 1, 0, n - 1);
		cout << '\n';
	}
}