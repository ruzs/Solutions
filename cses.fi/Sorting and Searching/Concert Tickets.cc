#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, a;
	multiset<int> s;
	cin >> n >> m;
	for(int i =0; i<n; ++i) cin >> a, s.insert(-a);
	while(m--) {
		cin >> a;
		auto lb = s.lower_bound(-a);
		if (lb == s.end()) cout << "-1\n";
		else {
			cout << -*lb << '\n';
			s.erase(lb);
		}
	}
}