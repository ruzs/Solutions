#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<char, char> T = {
		{'.', '.'},
		{'O', 'O'},
		{'-', '|'},
		{'|', '-'},
		{'/', '\\'},
		{'\\', '/'},
		{'^', '<'},
		{'<', 'v'},
		{'v', '>'},
		{'>', '^'}
	};
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(string & i : s) cin >> i;
	for(int j =m - 1; j>=0; --j) {
		for(int i =0; i<n; ++i) cout << T[s[i][j]];
		cout << '\n';
	}
}