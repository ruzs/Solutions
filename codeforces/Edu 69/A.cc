#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int & i : a) cin >> i;
	sort(a.begin(), a.end());
	cout << min(a[a.size() - 2] - 1, n - 2) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}