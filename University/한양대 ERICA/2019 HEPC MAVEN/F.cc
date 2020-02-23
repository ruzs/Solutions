#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unordered_map<string, string> mp;
	string site, pw;
	int n, m;
	cin >> n >> m;
	while(n--) {
		cin >> site >> pw;
		mp[site] = pw;
	}
	while(m--) {
		cin >> site;
		cout << mp[site] << '\n';
	}
}