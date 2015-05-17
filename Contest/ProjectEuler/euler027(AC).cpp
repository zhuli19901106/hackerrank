//https://www.hackerrank.com/contests/projecteuler/challenges/euler027
// A good problem, looks easy enough. But you won't get the answer so easily.
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5000000;
const int M = 2000;
char b[N + 1];
int p[N / 10];
int pc;
int plen[M + 1];
int pa[M + 1];
int pb[M + 1];


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
		b[i] = !b[i];
		if (b[i]) {
			p[pc++] = i;
		}
	}
}

int count_prime(int na, int nb)
{
	int cc = 1;
	int i = 1;
	int sum;
	while (true) {
		sum = i * (i + na) + nb;
		if (sum < 0 || !b[sum]) {
			return cc;
		}
		i += 1;
		cc += 1;
	}
}

int main()
{
	sieve();
	
	memset(plen, -1, sizeof(plen));
	memset(pa, -1, sizeof(pa));
	memset(pb, -1, sizeof(pb));
	int i, j;
	int cc;
	for (i = 0; p[i] <= M; ++i) {
		for (j = 1; j < p[i]; ++j) {
			cc = count_prime(-j, p[i]);
			if (plen[p[i]] < cc) {
				plen[p[i]] = cc;
				pa[p[i]] = -j;
				pb[p[i]] = p[i];
			}
			cc = count_prime(j, p[i]);
			if (plen[p[i]] < cc) {
				plen[p[i]] = cc;
				pa[p[i]] = j;
				pb[p[i]] = p[i];
			}
		}
	}
	
	for (i = 1; i <= M; ++i) {
		if (plen[i] < plen[i - 1]) {
			plen[i] = plen[i - 1];
			pa[i] = pa[i - 1];
			pb[i] = pb[i - 1];
		}
	}
	
	int n;
	while (scanf("%d", &n) == 1) {
		printf("%d %d\n", pa[n], pb[n]);
	}
	
	return 0;
}