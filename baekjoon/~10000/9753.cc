#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> np(200005 + 1);
	for(int i = 2; i <= 200005; ++i) {
		for(int j = i + i; j <= 200005; j += i) np[j]++;
	}
	vector<int> v;
	for(int i =6; i<200005; ++i)
		if (np[i] == 2) v.push_back(i);
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		cout << *lower_bound(v.begin(), v.end(), x) << '\n';
	}
}