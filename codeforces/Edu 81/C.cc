#include <bits/stdc++.h>

using namespace std;

int d[100001][26];
string a, b;
int dp(int i, int ab) {
	if (i == a.size()) return -2;
	int & ref = d[i][ab];
	if (ref != -1) return ref;
	if (a[i] == ab + 'a') {
		dp(i + 1, ab);
		return ref = i;
	}
	return ref = dp(i + 1, ab);
}
void solve() {
	memset(d, -1, sizeof d);
	cin >> a >> b;
	
	int i =-1, cnt = 1;
	for(char c : b) {
		i = dp(i + 1, c - 'a');
		if (i < 0) {
			cnt++, i =dp(0, c - 'a');
			if (i < 0) {
				cout << "-1\n";
				return;
			}
		}
	}
	cout << cnt << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T; cin >> T;
	while(T--) solve();
}