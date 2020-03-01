#include <bits/stdc++.h>

using namespace std;

int n, m, a[10][10];
long long ans = -1;
set<long long> v;
bool valid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
int main() {
	for(long long i =0; i<40000; ++i) v.insert(i*i);
	scanf("%d%d", &n, &m);
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}
	for(int i =0; i<n; ++i) {
		for(int j =0; j<m; ++j) {
			if (v.count(a[i][j])) ans = max(ans, (long long)a[i][j]);
			for(int id =-n+1; id<n; ++id) {
				for(int jd =-m+1; jd<m; ++jd) {
					if (!id && !jd) continue;
					int ic =i, jc =j;
					long long x = a[ic][jc];
					while(valid(ic + id, jc + jd)) {
						x = x * 10 + a[ic += id][jc += jd];
						if (v.count(x)) ans = max(ans, x);
					}
				}
			}
		}
	}
	printf("%lld", ans);
}
