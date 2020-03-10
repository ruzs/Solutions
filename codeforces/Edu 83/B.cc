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
		vector<int> a(n);
		for(int & i : a) cin >> i;
		sort(a.rbegin(), a.rend());
		for(int i : a) cout << i << ' ';
		cout << '\n';
	}
}