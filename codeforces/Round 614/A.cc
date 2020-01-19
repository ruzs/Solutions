#include <bits/stdc++.h>
using namespace std;

int n, s, k;
set<int> S;
void solve() {
	S.clear();
	cin >> n >> s >> k;
	while(k--) {
		int x; cin >> x;
		S.insert(x);
	}
	for(int i =0; i<2000; ++i) {
		if (s + i <= n && !S.count(s + i) || s - i >= 1 && !S.count(s - i)) {
			cout << i << '\n';
			return;
		}
	}
}
int main() {
	int T; cin >> T;
	while(T--) solve();
}