#include <bits/stdc++.h>

using namespace std;

#define int long long

tuple<int, int, int> gcd(int a, int b) {
    if (a == 0)
        return make_tuple(b, 0, 1);
        
    auto [g, x, y] = gcd(b % a, a);
    return make_tuple(g, y - (b / a) * x, x);
}
int any_solution(int a, int b, int c, int & g, int & x0, int & y0) {
    if (a == 0 && b == 0)
        return c ? 0 : -1;
        
    tie(g, x0, y0) = gcd(abs(a), abs(b));
    
    if (c % g) return 0;
    
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return 1;
}
int all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int g, x, y;
    int sol = any_solution(a, b, c, g, x, y);
    if (sol == 0) return 0;
	if (sol == -1) return (maxx - minx + 1) * (maxy - miny + 1);
    a /= g;
    b /= g;

    auto shift = [&](int k) {
        x += k * b;
        y -= k * a;
    };
    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift((minx - x) / b);
    if (x < minx)
        shift(sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;

    shift((maxx - x) / b);
    if (x > maxx)
        shift(-sign_b);
    int rx1 = x;

    shift(-(miny - y) / a);
    if (y < miny)
        shift(-sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift(-(maxy - y) / a);
    if (y > maxy)
        shift(sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

signed main() {
	int a, b, c, mnx, mxx, mny, mxy;
	cin >> a >> b >> c >> mnx >> mxx >> mny >> mxy;
	cout << all_solutions(a, b, -c, mnx, mxx, mny, mxy);
}