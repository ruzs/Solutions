#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l;
	cin >> n >> l;
	int ss = 0, ff = 0, sf = 0, fs = 0;
	set<string> st;
	for(int i =0; i<n; ++i) {
		string a;
		cin >> a;
		if (all_of(a.begin(), a.end(), [](char c){return c == '4' || c == '7';}) && !st.count(a)) {
			st.insert(a);
			if (a.front() == '4') {
				if (a.back() == '4') ff++;
				else fs++;
			} else {
				if (a.back() == '4') sf++;
				else ss++;
			}
		}
	}
	vector<vector<long long>> r = {{1, 0},{0, 1}}, a = {{ss, fs},{sf, ff}};
	auto mul = [](auto & a, auto & b) {
		vector<vector<long long>> r(2, vector<long long>(2));
		for(int i =0; i<2; ++i) for(int j =0; j<2; ++j) for(int k =0; k<2; ++k) {
			r[i][j] += a[i][k] * b[k][j];
			r[i][j] %= 1234567891;
		}
		return r;
	};
	while(l) {
		if (l & 1) r = mul(r, a);
		a = mul(a, a);
		l >>= 1;
	}
	cout << (r[0][0] + r[0][1] + r[1][0] + r[1][1]) % 1234567891;
}