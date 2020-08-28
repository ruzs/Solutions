#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	vector<int> p = {0};
	for(char c : s)
		p.push_back(p.back() + (c & 15));
	int ans = 0;
	for(int i =0; i<=s.size(); ++i) {
		for(int j =i + 2; j<=s.size(); j += 2) {
			int k = i + j >> 1;
			if (p[k] - p[i] == p[j] - p[k])
				ans = max(ans, j - i);
		}
	}
	cout << ans;
}