#include <bits/stdc++.h>
using namespace std;

int n, enc[1001];
map<string, int> d;
string s, ans[1001];
void solve() {
	d.clear();
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> s;
		d[s] = i;
	}
	for(int i =0; i<n; ++i) {
		cin >> s;
		enc[i] = d[s];
	}
	for(int i =0; i<n; ++i) {
		cin >> s;
		ans[enc[i]] = s;
	}
	for(int i =0; i<n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}
