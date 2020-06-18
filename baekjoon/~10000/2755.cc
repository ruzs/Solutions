#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	double sum = 0, tot = 0;
	map<string, double> mp = {
		{"A+", 4.3}, {"A0", 4.0}, {"A-", 3.7},
		{"B+", 3.3}, {"B0", 3.0}, {"B-", 2.7},
		{"C+", 2.3}, {"C0", 2.0}, {"C-", 1.7},
		{"D+", 1.3}, {"D0", 1.0}, {"D-", 0.7},
		{"F", 0.0}
	};
	while(n--) {
		string s;
		double c;
		cin >> s >> c >> s;
		tot += c;
		sum += c * mp[s];
	}
	cout.precision(2);
	cout << fixed << sum / tot + 1e-9;
}