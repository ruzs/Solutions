//eratosthenes's sieve
const int N = 1e7+5;

vector<long long> prime = {2};
bool np[N>>1];
void primeList(int max_n) {
	long long i =1, j, k;
	while((i+=2) <= max_n) {
		if (np[i>>1]) continue;
		prime.push_back(i);
		for(j=i*i, k=i+i; j<=max_n; j+=k) np[j>>1] = 1;
	}
}
bool isPrime(int x) {
	if (x % 2 == 0) return x == 2;
	return !np[x>>1];
}

//sqrt(x) decision function
bool isPrime(int x) {
	if (x % 2 == 0) return x == 2;
	for(int i=3; i*i<=x; i+=2) {
		if (x % i == 0) return 0;
	}
	return 1;
}

//prime factorization
auto getFactors(int x) {
	map<int, int> factors;
	for(int i =2; i*i<=x; ++i) {
		int c =0;
		while(x % i == 0) c++, x /= i;
		factors[i] = c;
	}
	if (x > 1) factors[x] = 1;
	return factors;
}

//divisors
auto getDivisors(int x) {
	set<int> divisors;
	for(int i =2; i*i<=x; ++i) {
		if (x % i == 0) {
			divisors.insert(i);
			divisors.insert(x / i);
		}
	}
	return divisors;
}

//Euler phi function, phi(x) = x보다 작은 서로소의 개수
int getEulerPhi(int x) {
	int phi = x;
	for(int i =2; i*i<=x; ++i) {
		if (x % i == 0) phi /= i, phi *= i - 1;
		while(x % i == 0) x /= i;
	}
	return phi;
}