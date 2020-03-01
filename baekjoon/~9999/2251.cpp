#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

int A, B, C;
set<int> s;
set<tuple<int, int, int>> d;
void rec(int a, int b, int c) {
	if (d.find({a,b,c}) != d.end()) return;
	d.insert({a,b,c});
	if (!a) s.insert(c);
	rec(a + min(A - a, c), b, c - min(A - a, c));
	rec(a, b + min(B - b, c), c - min(B - b, c));
	rec(a + min(A - a, b), b - min(A - a, b), c);
	rec(a, b - min(C - c, b), c + min(C - c, b));
	rec(a - min(B - b, a), b + min(B - b, a), c);
	rec(a - min(C - c, a), b, c + min(C - c, a));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;
	rec(0, 0, C);
	for(int i : s) cout << i << ' ';
}
