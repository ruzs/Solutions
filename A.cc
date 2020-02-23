#include <bits/stdc++.h>

using namespace std;

void solve() {
<<<<<<< HEAD
	int n, m, a, s = 0;
	cin >> n >> m >> a;
	s += a;
	for(int i =1; i<n; ++i) {
		cin >> a;
		int x = min(m, a * i) / i;
		s += x;
		m -= x * i;
	}
	cout << s << '\n';
=======
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	if ((y - x) % (b + a) == 0) {
		cout << (y - x) / (b + a) << '\n';
	}
	else cout << "-1\n";
>>>>>>> ef72632469cae9f198d75202044b6e0cfa8dcd9e
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, t =0; cin >> T;
	while(++t <= T) solve();
}