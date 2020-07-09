#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int d[1050];
		memset(d, -1, sizeof d);
		string ans = to_string(a / b) + '.';
		do {
			d[a % b] = ans.size();
			a %= b;
			if (a % b == 0) {
				ans += "(0)";
				break;
			}
			a *= 10;
			ans += to_string(a / b);
			if (~d[a % b]) {
				ans.insert(ans.begin() + d[a % b], '(');
				ans += ')';
				break;
			}
		} while(a);
		cout << ans << '\n';
	}
}