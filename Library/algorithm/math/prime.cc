const int N = 1e7+5;

bool np[N>>1];

auto primeList(int max_n) {
	vector<int> r={2};
	long long i=1, j, k;
	while(i+=2 <= max_n) {
		if (np[i>>1]) continue;
		r.push_back(i);
		for(j=i*i, k=i+i; j<=max_n; j+=k)
			np[j>>1] = 1;
	}
	return r;
}

bool isPrime(int x) {
	if (x % 2 == 0) return x == 2;
	for(int i=3; i*i<=x; i+=2) {
		if (x % i == 0) return 0;
	}
	return 1;
}