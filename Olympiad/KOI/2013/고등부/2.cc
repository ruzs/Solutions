#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l;
	cin >> n >> l;
	vector<array<int, 2>> a(n);
	vector<int> t, d;
	for(auto & i : a) {
		cin >> i[0] >> i[1];
		t.push_back(i[0]);
		d.push_back(i[1]);
	}
	sort(a.begin(), a.end());
	sort(t.begin(), t.end());
	sort(d.begin(), d.end());
	t.erase(unique(t.begin(), t.end()), t.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	vector<long long> td(t.size()), dd(d.size());
	long long ans = 0;
	for(auto & i : a) {
		int ti = lower_bound(t.begin(), t.end(), i[0]) - t.begin();
		int di = lower_bound(d.begin(), d.end(), i[1]) - d.begin();
		long long len = l + abs(i[0] - i[1]);
		tie(td[ti], dd[di]) = make_pair(max(td[ti], dd[di] + len), max(dd[di], td[ti] + len));
		ans = max({ans, td[ti], dd[di]});
	}
	cout << ans;
}