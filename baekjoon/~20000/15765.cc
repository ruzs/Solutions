#include <bits/stdc++.h>

using namespace std;

map<string, string> mp;
bool ismother(string a, string b) {
	string prt = b + " is the ";
	if (mp[a] == b) {
		cout << prt << "mother of " + a;
		return 1;
	}
	if (!mp.count(a) || !mp.count(mp[a])) return 0;
	auto t = mp[mp[a]];
	while(t != b) {
		if (!mp.count(t)) return 0;
		t = mp[t];
		prt += "great-";
	}
	cout << prt << "grand-mother of " + a;
	return 1;
}
bool isaunt(string a, string b) {
	if (!mp.count(b)) return 0;
	string prt = b + " is the ";
	b = mp[b];
	if (!mp.count(a) || !mp.count(mp[a])) return 0;
	string t = mp[mp[a]];
	while(t != b) {
		if (!mp.count(t)) return 0;
		t = mp[t];
		prt += "great-";
	}
	cout << prt << "aunt of " + a;
	return 1;
}
bool related(string a, string b) {
	while(1) {
		string t = b;
		while(1) {
			if (a == t) return 1;
			if (!mp.count(t)) break;
			t = mp[t];
		}
		if (!mp.count(a)) break;
		a = mp[a];
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s, e;
	cin >> n >> s >> e;
	while(n--) {
		string a, b;
		cin >> a >> b;
		mp[b] = a;
	}
	if (mp[s] == mp[e]) cout << "SIBLINGS";
	else if (ismother(s, e));
	else if (ismother(e, s));
	else if (isaunt(s, e));
	else if (isaunt(e, s));
	else if (related(s, e)) cout << "COUSINS";
	else cout << "NOT RELATED";
}