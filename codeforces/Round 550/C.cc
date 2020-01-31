#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a;
	map<int, int> mp;
	vector<int> u, v;
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> a;
		if (++mp[a] > 2) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	for(auto& i : mp) {
		u.push_back(i.first);
		i.second--;
	}
	for(auto& i : mp) {
		if (i.second) v.push_back(i.first);
	}
	cout << u.size() << '\n';
	for(int i : u) cout << i << ' ';
	cout << '\n' << v.size() << '\n';
	for(int i =v.size() - 1; i>=0; --i) cout << v[i] << ' ';
	cout << '\n';
}