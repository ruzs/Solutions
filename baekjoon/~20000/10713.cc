#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> p(n + 1);
	int l; cin >> l;
	for(int i =1; i<m; ++i) {
		int x; cin >> x;
		if (l < x) {
			p[l - 1]++;
			p[x - 1]--;
		} else {
			p[x - 1]++;
			p[l - 1]--;
		}
		l = x;
	}
	partial_sum(p.begin(), p.end(), p.begin());
	long long sum = 0;
	for(int i =0; i+1<n; ++i) {
		long long a, b, c;
		cin >> a >> b >> c;
		sum += min(a * p[i], b * p[i] + c);
	}
	cout << sum;
}