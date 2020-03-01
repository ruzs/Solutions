#include <bits/stdc++.h>

using namespace std;

auto getPi(string& p) {
	vector<int> r(p.size());
	for (int i = 1, j = 0; i < p.size(); ++i) {
		while (j && p[i] != p[j]) j = r[j - 1];
		if (p[i] == p[j]) r[i] = ++j;
	}
	return r;
}
auto KMP(string& h, string& t) {
	vector<int> r, pi = getPi(t);
	for (int i = 0, j = 0; i < h.size(); ++i) {
		while (j && h[i] != t[j]) j = pi[j - 1];
		if (h[i] == t[j]) {
			if (j == t.size() - 1) {
				r.push_back(i - t.size() + 1);
				j = pi[j];
			}
			else j++;
		}
	}
	return r;
}
int main() {
	int n, tc = 0;
	string s, a[27] = {"0", "1"};
	for(int i =2; i<27; ++i)
		a[i] = a[i - 1] + a[i - 2];
	while(cin >> n >> s) {
		unsigned long long d[101]{};
		for(int i =0; i<=min(26, n); ++i) {
			d[i] = KMP(a[i], s).size();
		}
		for(int i =27; i<=n; ++i) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 2] - d[i - 3] - d[i - 4];
		}
		cout << "Case " << ++tc << ": " << d[n] << '\n';
	}
}