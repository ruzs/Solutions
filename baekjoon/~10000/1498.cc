#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int> pi(s.size());
	for(int i =1, j =0; i<s.size(); ++i) {
		while(j && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) pi[i] = ++j;
		if (pi[i]) {
			int k = i + 1 - pi[i];
			if (k && (i + 1) % k == 0) cout << i + 1 << ' ' << (i + 1) / k << '\n';
		}
	}
}