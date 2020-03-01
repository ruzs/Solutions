#include <bits/stdc++.h>
using namespace std;

int n, m, l, k, c, d1[101][101], d2[101][101];
string t, s, e;
map<string, int> city, traf = {
	{"Mugunghwa", 0},{"ITX-Saemaeul", 1},{"ITX-Cheongchun", 2},
	{"S-Train", 3},{"V-Train", 4},{"Airplane", 5},{"KTX", 6},
	{"Taxi", 7},{"Bus", 8},{"Subway", 9}
};
vector<int> route;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i =0; i<n; ++i) {
		cin >> t;
		city[t] = i;
	}
	cin >> m;
	for(int i =0; i<m; ++i) {
		cin >> t;
		route.push_back(city[t]);
	}
	for(int i =0; i<n; ++i) {
		for(int j =0; j<n; ++j) {
			if (i != j) d1[i][j] = d2[i][j] = 1e9;
		}
	}
	cin >> l;
	while(l--) {
		cin >> t >> s >> e >> c;
		int tt = traf[t], cs = city[s], ce = city[e];
		d1[cs][ce] = d1[ce][cs] = min(d1[cs][ce], c);
		if (tt < 3) d2[cs][ce] = d2[ce][cs] = 0;
		else if (tt < 5) d2[cs][ce] = d2[ce][cs] = min(d2[cs][ce], c / 2);
		else d2[cs][ce] = d2[ce][cs] = min(d2[cs][ce], c);
	}
	for(int h =0; h<n; ++h) {
		for(int i =0; i<n; ++i) {
			for(int j =0; j<n; ++j) {
				d1[i][j] = min(d1[i][j], d1[i][h] + d1[h][j]);
				d2[i][j] = min(d2[i][j], d2[i][h] + d2[h][j]);
			}
		}
	}
	int sum1 =0, sum2 =0;
	for(int i =1; i<m; ++i) {
		sum1 += d1[route[i - 1]][route[i]];
		sum2 += d2[route[i - 1]][route[i]];
	}
	if (sum1 > sum2 + k) cout << "Yes";
	else cout << "No";
}
