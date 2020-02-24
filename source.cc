#include <bits/stdc++.h>

using namespace std;

auto fio = ios::sync_with_stdio(0);
template <class T, class Comp = less<T>>
struct range_min {
	vector<vector<T>> a;
	range_min(const vector<T>& _a) {
		int d = 32 - __builtin_clz(_a.size());
		a.resize(d, vector<T>(1 << d));
		copy(_a.begin(), _a.end(), a[0].begin());
		for (int i = 0; i < d - 1; ++i)
			for (int j = 0; j < (int)_a.size(); ++j)
				a[i + 1][j] = min(a[i][j], a[i][min((int)_a.size() - 1, j + (1 << i))], Comp());
	}
	T query(int s, int e) {
		int d = 31 - __builtin_clz(e - s + 1);
		return min(a[d][s], a[d][e - (1 << d) + 1], Comp());
	}
};
int main() {
	int n;
	long long m;
	cin >> n >> m;
	vector<int> a(n), b(n);
	for(int i =0; i<n; ++i) cin >> a[i] >> b[i];
	range_min<int, greater<int>> rmq(b);

	long long ps = 0;
	int ans = 1e9;
	for(int i =0, j =0; i<n; ++i) {
		ps += a[i];
		while (ps >= m) {
			ans = min(ans, rmq.query(j, i));
			ps -= a[j++];
		}
	}
	cout << ans;
}