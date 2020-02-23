#include <bits/stdc++.h>

using namespace std;

auto fio = ios::sync_with_stdio(0);

int n, a[5];
long long r;
map<vector<int>, int> mp;
vector<int> v;
void subset(int l = -1) {
	if (v.size()) r += (v.size() & 1 ? 1ll : -1ll) * mp[v]++;
	for(int i =l + 1; i < 5; ++i) {
		v.push_back(a[i]);
		subset(i);
		v.pop_back();
	}
}
int main() {
	cin >> n;
	for(int j = 0; j<n; ++j) {
		for(int i =0; i<5; ++i) {
			cin >> a[i];
		}
		sort(a, a + 5);
		vector<int> v;
		subset();
	}
	cout << 1ll * n * (n - 1) / 2 - r;
}