#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, x;
	priority_queue<int> A, B;
	cin >> n >> a >> b;
	while(a--) {
		cin >> x;
		A.push(x);
	}
	while(b--) {
		cin >> x;
		B.push(x);
	}
	while(n > 1) {
		int t = A.top(); A.pop();
		a = A.top(); A.pop();
		b = B.top(); B.pop();
		if (a < b) {
			A.push(a);
			A.push(t);
		}
	}
}