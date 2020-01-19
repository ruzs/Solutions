#include <bits/stdc++.h>
using namespace std;

int n, m;
string t;
int main() {
	cin >> n >> m >> t;
	string s = "I";
	while(n--) s += "OI";

	auto getPi = [&](string& p) {
		vector<int> pi(p.size());
		for (int i = 1, j = 0; i < p.size(); ++i) {
			while (j && p[i] != p[j]) j = pi[j - 1];
			if (p[i] == p[j]) pi[i] = ++j;
		}
		return pi;
	};
	auto KMP = [&](string& t, string& p) {
		vector<int> ans, pi = getPi(p);
		for (int i = 0, j = 0; i < t.size(); ++i) {
			while (j && t[i] != p[j]) j = pi[j - 1];
			if (t[i] == p[j]) {
				if (j == p.size() - 1) {
					ans.push_back(i - p.size() + 1);
					j = pi[j];
				} else
					j++;
			}
		}
		return ans;
	};

	cout << KMP(t, s).size();
}
