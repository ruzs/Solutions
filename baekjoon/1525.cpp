#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

using lint = long long;
lint s, e;
vector<int> w[10] = {{1,3},{0,2,4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7},{4,6,8},{5,7}};
lint swap(lint mask, int i, int j) {
	lint res = mask;
	res &= ~((15LL << (i << 2)) | (15LL << (j << 2)));
	res |= (15LL & (mask >> (j << 2))) << (i << 2);
	res |= (15LL & (mask >> (i << 2))) << (j << 2);
	return res;
}
int zeroidx(lint mask) {
	int i =0;
	while(mask & (15LL << (i << 2))) i++;
	return i;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i =0, x; i<9; ++i) {
		cin >> x;
		s <<= 4;
		s |= x;
	}
	for(int i =1; i<9; ++i) {
		e |= i;
		e <<= 4;
	}

	queue<lint> q;
	map<lint, int> d;
	q.push(s);
	d[s] = 0;
	while(q.size()) {
		lint a = q.front(); q.pop();
		int c = d[a];
		if (a == e) {
			cout << c;
			return 0;
		}
		int zi = zeroidx(a);
		for(int i : w[zi]) {
			lint b = swap(a, zi, i);
			if (d.find(b) == d.end()) {
				d[b] = c + 1;
				q.push(b);
			}
		}
	}
	cout << -1;
}
