#include <bits/stdc++.h>

using namespace std;

string sub(string & a, string & b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	string r(a);
	for(int i =0; i<(int)b.size(); ++i) {
		if (r[i] < b[i]) {
			r[i] += 26;
			r[i + 1]--;
		}
		r[i] -= b[i] - 'a';
	}
	return r;
}
string add(string & a, string & b) {
	string r;
	for(int i =0; i<(int)a.size(); ++i) {
		if (i < b.size()) r[i] += b[i];
		if (r[i] > 'z') {
			r[i] -= 26;
			r[i + 1]++;
		}
	}
	return r;
}
int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;

}