#include <bits/stdc++.h>

using namespace std;

struct point { int x, y; };

double dist(point& a, point& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
double d[1 << 16][16];
bool ready[1 << 16][16];
double dp(int msk, int a, int n, double g[][16]) {
	if (msk + 1 == 1 << n) return g[a][0];
	double& ref = d[msk][a];
	if (ready[msk][a]) return ref;
	ready[msk][a] = 1;
	ref = 1e9;
	for(int i =0; i<n; ++i) {
		if (msk & (1 << i)) continue;
		ref = min(ref, dp(msk | (1 << i), i, n, g) + g[a][i]);
	}
	return ref;
}
int main() {
	int n;
	point p[16];
	double g[16][16];
	
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> p[i].x >> p[i].y;
		for(int j =0; j<i; ++j)
			g[i][j] = g[j][i] = dist(p[i], p[j]);
	}
	cout << setprecision(20) << dp(1, 0, n, g);
}