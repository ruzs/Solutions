#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<long long> b = {1, 2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870};
	vector<string> anss = {"", "*2", "*2*3", "*2*3*5", "*2*3*5*7", "*2*3*5*7*11", "*2*3*5*7*11*13",
						"*2*3*5*7*11*13*17", "*2*3*5*7*11*13*17*19", "*2*3*5*7*11*13*17*19*23"};
	int n;
	while(cin >> n) {
		if (!n) break;
		cout << n << " = ";
		vector<string> ans;
		while(n) {
			int base = prev(upper_bound(b.begin(), b.end(), n)) - b.begin();
			ans.push_back(to_string(n / b[base]) + anss[base]);
			n %= b[base];
		}
		for(int i =ans.size() - 1; i>0; --i) cout << ans[i] << " + ";
		cout << ans[0] + '\n';
	}
}