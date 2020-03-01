#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	vector<int> r(a.size() + b.size() + 1, 0);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int i =0; i<a.size(); ++i) {
		for(int j =0; j<b.size(); ++j) {
			r[i + j] += (a[i] == '1') * (b[j] == '1');
		}
	}
	for(int i =0; i+1<r.size(); ++i) {
		r[i + 1] += r[i] / 2;
		r[i] %= 2;
	}
	while(r.size() && !r.back()) r.pop_back();
	reverse(r.begin(), r.end());
	for(int i : r) cout << i;
}