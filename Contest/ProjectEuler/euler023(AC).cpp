//https://www.hackerrank.com/contests/projecteuler/challenges/euler023
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int N = 100000;
char b[N + 1];
set<int> s;
int p[20000];
int pc;

void sieve()
{
	int i, j;
	
	memset(b, 0, sizeof(b));
	b[0] = b[1] = 1;
	for (i = 2; i <= N / i; ++i) {
		if (b[i]) {
			continue;
		}
		for (j = i; j <= N / i; ++j) {
			b[i * j] = 1;
		}
	}
	pc = 0;
	for (i = 0; i <= N; ++i) {
		if (b[i]) {
			continue;
		}
		p[pc++] = i;
	}
}

int fast_pow(int p, int c)
{
	if (c == 0) {
		return 1;
	}
	if (c == 1) {
		return p;
	}
	int s = fast_pow(p, c >> 1);
	if (c & 1) {
		return s * s * p;
	} else {
		return s * s;
	}
}

int fast_poly(int p, int c)
{
	if (c == 0) {
		return 1;
	}
	if (c & 1) {
		int s = fast_poly(p, c >> 1);
		return s + s * fast_pow(p, (c + 1) >> 1);
	} else {
		return fast_poly(p, c - 1) * p + 1;
	}
}

int divisor_sum(int n)
{
	if (n == 1) {
		return 1;
	}
	
	int i = 0;
	int sum = 1;
	int c;
	
	while (p[i] <= n / p[i]) {
		if (n % p[i]) {
			++i;
			continue;
		}
		c = 0;
		while (n % p[i] == 0) {
			n /= p[i];
			++c;
		}
		sum *= fast_poly(p[i], c);
		++i;
	}
	if (n > 1) {
		sum *= (n + 1);
	}
	return sum;
}

int main()
{
	sieve();
	
	int i;
	for (i = 1; i <= N; ++i) {
		if (divisor_sum(i) - i > i) {
			s.insert(i);
		}
	}
	
	int t, ti;
	int n;
	set<int>::iterator it;

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &n);
		for (it = s.begin(); it != s.end(); ++it) {
			if (s.find(n - *it) != s.end()) {
				break;
			}
		}
		printf(it != s.end() ? "YES\n" : "NO\n");
	}
	s.clear();
	
	return 0;
}