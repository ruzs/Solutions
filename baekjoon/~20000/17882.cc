#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p, d;
	cin >> n >> p >> d;
	string s;
	cin >> s;
	s += s;
	vector<int> P = {0};
	for(char c : s) {
		P.push_back(P.back() + (c == 'Z'));
	}
	int ans = 0;
	for(int i =0; i<n; ++i) {
		ans += (P[i + p] - P[i] < d);
	}
	cout << ans;
}