#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> a(n);
	for(auto& i : a) cin >> i;
	int k;
	cin >> k;

	auto KMP = [](const string & s, const string & t) {
		int n = s.size();
		vector<int> pi(n), r;
		for(int i =1, j =0; i<n; ++i) {
			while(j && s[i] != s[j]) j = pi[j - 1];
			if (s[i] == s[j]) pi[i] = ++j;
		}
		for(int i =0, j =0; i + 1<t.size(); ++i) {
			while(j && t[i] != s[j]) j = pi[j - 1];
			if (t[i] == s[j]) if (++j == s.size()) r.push_back(i - s.size() + 1);
		}
		return r;
	};
	vector<int> b(n);
	iota(b.begin(), b.end(), 0);
	int ans = 0;
	do {
		string s = "";
		for(int i : b) s += a[i];
		auto kmp = KMP(s, s + s);
		if (kmp.size() == k) ans++;
	} while(next_permutation(b.begin(), b.end()));
	cout << ans;
}