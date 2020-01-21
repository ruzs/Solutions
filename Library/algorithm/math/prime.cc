const int N = 1e7+5;

bool np[N>>1];

auto primeList(int max_n) {
	vector<int> r = {2};
	for(int i =3; i<=max_n; i+=2) {
		if (np[i>>1]) continue;
		r.push_back(i);
		for(int j =i*3; j<=max_n; j+=i+i)
			np[j>>1] = 1;
	}
	return r;
}

bool isPrime(int x) {
	if (x % 2 == 0) return x == 2;
	for(int i =3; i*i<=x; i+=2) {
		if (x % i == 0) return 0;
	}
	return 1;
}