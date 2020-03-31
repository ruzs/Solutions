#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	vector<int> pi(s.size());
	long long sum = 0;
	for(int i =1, j =0; i<s.size(); ++i) {
		while(j && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) pi[i] = ++j;
		if (pi[i]) {
			function<int(int)> find = [&](int k) {
				if (!pi[k - 1]) return k;
				return pi[k - 1] = find(pi[k - 1]);
			};
			sum += i - find(pi[i]) + 1;
		}
	}
	cout << sum;
}