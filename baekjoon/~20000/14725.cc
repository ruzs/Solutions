#include <bits/stdc++.h>

using namespace std;

map<char, int> tr[325 * 1000];
int ti, ext[325 * 1000];
void insert(string & s) {
	int i = 0;
	for(char c : s) {
		i = tr[i].count(c) ? tr[i][c] : tr[i][c] = ++ti;
	}
	ext[i] = 1;
}
void print(int x, int y) {
	if (ext[x]) cout << '\n';
	for(auto & [c, i] : tr[x]) {
		if (c == ' ') {
			cout << '\n';
			for(auto & [d, j] : tr[i]) {
				for(int k =0; k<y; ++k) cout << "--";
				cout << d;
				print(j, y + 1);
			}
		} else {
			cout << c;
			print(i, y);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i =0; i<n; ++i) {
		int k; string s;
		cin >> k;
		cin.ignore();
		getline(cin, s);
		insert(s);
	}
	print(0, 1);
}