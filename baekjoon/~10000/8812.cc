#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> g(2), p(n + 1, vector<int>(17));
		vector<int> d(n + 1, 0);
		d[1] = 1;
		int Jas = 1;
		while(n--) {
			char opt;
			int x;
			cin >> opt >> x;
			if (opt == 'D') {
				int l = g.size();
				g[x].push_back(l);
				d[l] = d[x] + 1;
				p[l][0] = x;
				for(int j =1; j<17; ++j) 
					p[l][j] = p[p[l][j - 1]][j - 1];
				g.push_back(vector<int>());
			}
			else {
				auto lca = [&](int a, int b) {
					if (d[a] > d[b]) swap(a, b);
					for(int j =16; ~j; --j)
						if (d[a] <= d[p[b][j]]) b = p[b][j];
					if (a == b) return a;
					for(int j =16; ~j; --j)
						if (p[a][j] != p[b][j]) {
							a = p[a][j];
							b = p[b][j];
						}
					return p[a][0];
				}(Jas, x);
				if (lca == Jas) {
					Jas = [&] {
						for(int j =16; ~j; --j)
							if (d[Jas] < d[p[x][j]]) x = p[x][j];
						return x;
					}();
				}
				else Jas = p[Jas][0];
				cout << Jas << '\n';
			}
		}
	}
}