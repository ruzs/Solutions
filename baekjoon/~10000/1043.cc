#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k, x, a[51]{}, g[50][50]{};
	vector<int> in[51];
	cin >> n >> m >> k;
	while(k--) {
		cin >> x;
		a[x] = 1;
	}
	for(int i =0; i<m; ++i) {
		cin >> k;
		while(k--) {
			cin >> x;
			in[x].push_back(i);
			for(int j : in[x]) g[i][j] = g[j][i] = 1;
		}
	}
	for(int i =0; i<m; ++i)
		for(int j =0; j<m; ++j)
			for(int k =0; k<m; ++k)
				if (g[j][i] && g[i][k]) g[j][k] = 1;
	bitset<51> bs;
	for(int i =1; i<=n; ++i) {
		if (a[i]) {
			for(int j : in[i]) {
				for(int k =0; k<m; ++k) if (g[j][k]) bs[k] = 1;
			}
		}
	}
	cout << m - bs.count();
}