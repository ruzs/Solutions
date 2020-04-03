#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());;
	int i = 0, j = 0, cnt = 0;
	while (i<a.size() && j<b.size()) {
		while (i<a.size() && a[i] < b[j]) cnt++, i++;
		while (j<b.size() && a[i] > b[j]) cnt++, j++;
		if (i<a.size() && j<b.size() && a[i] == b[j]) i++, j++;
	}
	cout << cnt + a.size() - i + b.size() - j;
}