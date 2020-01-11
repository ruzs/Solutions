#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for(auto & i : a) cin >> i;

	sort(a.begin(), a.end());
	int cnt = 0;
	while(m--) {
		string s; cin >> s;
		if (lower_bound(a.begin(), a.end(), s)->substr(0, s.size()) == s) cnt++;
	}
	cout << cnt;
}
