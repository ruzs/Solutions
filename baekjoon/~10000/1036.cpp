#include <bits/stdc++.h>
using namespace std;

int n, k, d[36][52], used[36];
string s[51];
priority_queue<pair<vector<int>, int>> pq;
int b10(char c) {
	if (isdigit(c)) return c & 15;
	return c - 'A' + 10;
}
char b36(int i) {
	if (i < 10) return i + '0';
	return i + 'A' - 10;
}
string add(const string & a, const string & b) {
	if (a.size() > b.size()) return add(b, a);
	string r = b;
	int tmp, c = 0;
	for(int i =0; i<r.size(); ++i) {
		tmp = b10(r[i]) + c;
		if (i < a.size()) tmp += b10(a[i]);
		c = tmp / 36;
		tmp %= 36;
		r[i] = b36(tmp);
	}
	if (c) r += b36(c);
	return r;
}
int main() {
	cin >> n;
	for(int i =0; i<n; ++i) {
		cin >> s[i];
		reverse(s[i].begin(), s[i].end());
		for(int j =0; j<s[i].size(); ++j)
			d[b10(s[i][j])][j]++;
	}
	cin >> k;
	for(int i =0, c =0; i<35; ++i) {
		vector<int> v(52, 0);
		for(int j =0; j<=51; ++j) {
			d[i][j] *= 35 - i;
			d[i][j] += c;
			c = d[i][j] / 36;
			d[i][j] %= 36;
			v[51 - j] = d[i][j];
		}
		pq.push({ v, i });
	}
	while(pq.size() && k) {
		auto cyper = pq.top().second; pq.pop();
		if (used[cyper]) continue;
		used[cyper] = 1;
		k--;
	}
	string ans = "0";
	for(int i =0; i<n; ++i) {
		for(char & j : s[i]) if (used[b10(j)]) j = 'Z';
		ans = add(ans, s[i]);
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}
