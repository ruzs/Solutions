#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	
	int d = abs(a - b);
	if (d & 1) {
		cout << -1;
		return 0;
	}
	bitset<20> bs;
	for(int i =0; d >>= 1; ++i) {
		bs[i] = d & 1;
	}
	set<pair<int, int>> v = {minmax(a, b)}, nv;
	for(int k =0; k<18; ++k) {
		nv.clear();
		for(auto & [a, b] : v) {
			int na, nb;
			if (bs[k]) {
				na = a + (1<<k), nb = b - (1<<k);
				if (na == nb) {
					cout << k + 1;
					return 0;
				}
				nv.insert(minmax(na, nb));
			} else {
				if (a - (1<<k) >= 1) {
					na = a - (1<<k), nb = b - (1<<k);
					nv.insert(minmax(na, nb));
				}
				if (b + (1<<k) <= n) {
					na = a + (1<<k), nb = b + (1<<k);
					nv.insert(minmax(na, nb));
				}
			}
		}
		swap(v, nv);
	}
	cout << -1;
}