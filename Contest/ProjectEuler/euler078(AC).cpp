//https://www.hackerrank.com/contests/projecteuler/challenges/euler078
/*
	Background knowledge:
	http://en.wikipedia.org/wiki/Partition_%28number_theory%29
	http://en.wikipedia.org/wiki/Pentagonal_number
*/
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const LL MOD = 1000000007;
const int N = 60000;

LL pen[1000];
LL a[N + 1];

int main()
{
	int i, j;
	
	memset(pen, 0, sizeof(pen));
	i = 1;
	j = 1;
	while (true) {
		pen[j++] = i * (3 * i - 1) / 2;
		pen[j] = i * (3 * i + 1) / 2;
		if (pen[j] > N) {
			break;
		}
		++i;
		++j;
	}
	
	memset(a, 0, sizeof(a));
	a[0] = 1;
	for (i = 1; i <= N; ++i) {
		a[i] = 0;
		j = 0;
		while (pen[j + 1] <= i) {
			if ((j & 3) < 2) {
				a[i] = (a[i] + a[i - pen[j + 1]]) % MOD;
			} else {
				a[i] = (a[i] + MOD - a[i - pen[j + 1]]) % MOD;
			}
			++j;
		}
	}
	
	int t, ti;
	int n;
	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%d", &n);
		printf("%lld\n", a[n]);
	}
	
	return 0;
}