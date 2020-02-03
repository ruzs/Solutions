#include <bits/stdc++.h>
using namespace std;

int main() {
	int A[100000], N, K;
	scanf("%d%d", &N, &K);
	for(int i=0; i<N; i++) scanf("%d", A+i);
	for(int i=N; --i;) A[i]-=A[i-1];
	auto f=[&](int m) {
		trace(m);
		pair<long, int> a{}, b{};
		for(int i=1; i<N; i++)
			trace(a.first, A[i], m, a.second),
			tie(a, b)=make_pair(min(a, b), make_pair(a.first+A[i]-m, a.second+1));
		return min(a, b);
	};
	int l=0, r=1e9;
	while(l<r) {
		int m=l+r+1>>1;
		if(f(m).second<=K) l=m;
		else r=m-1;
	}
	printf("%d", f(r).first+1L*r*K);
}