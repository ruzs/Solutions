#include <bits/stdc++.h>

using namespace std;

auto fio = ios::sync_with_stdio(0);

int main() {
	int n, a[500005];
	vector<pair<int, int>> v;
	cin >> n;
	for(int i =1; i<=n; ++i) cin >> a[i];
	for(int i =1; i<=n; ++i)
		if (a[i] < a[i - 1] && a[i] < a[i + 1]) v.push_back({i, a[i]});
	sort()

}