#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	long long sum = 0;
	for(int i =0; i<s.size(); ++i) {
		for(int j =n - i - 1; j>=0; --j) {
			sum += (long long)(s[i] - 'a') * pow(26, j);
		}
	}
	cout << sum + s.size();
}