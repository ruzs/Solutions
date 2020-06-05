#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	struct E { int x, y, i; };
	vector<E> a;
	for(int i =0; i<n; ++i) {
		int s, e, h;
		cin >> s >> h >> e;
		a.push_back({s, h, i});
		a.push_back({e, h, i});
	}
	a.push_back({0, 0, n});
	a.push_back({2000000000, 0, n});
	sort(a.begin(), a.end(), [](auto& a, auto& b) {
		return a.x < b.x;
	});

	map<int, int> h = {{0, 1}};
	bitset<100005> bs;
	int lx = 0, ly = 0;
	for(int j =0; j<a.size(); ++j) {
		auto & [x, y, i] = a[j];
		if (bs[i]) {
			h[y]--;
			if (!h[y]) h.erase(y);
		} else {
			h[y]++;
		}
		bs[i].flip();
		if (j + 1 < a.size() && x != a[j + 1].x && ly != h.rbegin()->first) {
			lx = x;
			ly = h.rbegin()->first;
			cout << lx << ' ' << ly << ' ';
		}
	}
}