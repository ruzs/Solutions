#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	map<set<string>, int> mp;
	while(n--) {
		string a, b, c;
		cin >> a >> b >> c;
		mp[{a, b, c}]++;
	}
	int ans = 0;
	for(auto & i : mp) ans = max(ans, i.second);
	cout << ans;
}