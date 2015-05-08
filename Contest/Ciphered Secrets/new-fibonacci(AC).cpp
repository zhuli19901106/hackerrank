#include <cstdio>
#include <cstring>
using namespace std;

typedef long long int LL;
const LL MOD = 1000000007;

void copy(LL a[3][3], LL b[3][3])
{
	int i, j;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			b[i][j] = a[i][j];
		}
	}
}

void multiplyMatrix(LL a[3][3], LL b[3][3], LL c[3][3])
{
	int i, j, k;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j) {
			c[i][j] = 0;
			for (k = 0; k < 3; ++k) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
}

void multiplyVector(LL a[3][3], LL v1[3], LL v2[3])
{
	int i, j;

	for (i = 0; i < 3; ++i) {
		v2[i] = 0;
		for (j = 0; j < 3; ++j) {
			v2[i] = (v2[i] + a[i][j] * v1[j]) % MOD;
		}
	}
}

void fastPow(LL a[3][3], LL b[3][3], LL x)
{
	if (x == 1) {
		copy(a, b);
		return;
	}

	LL p[3][3];
	fastPow(a, p, x >> 1);
	
	if (x & 1) {
		LL p1[3][3];

		multiplyMatrix(p, p, p1);
		multiplyMatrix(a, p1, b);
	} else {
		multiplyMatrix(p, p, b);
	}
}

int main()
{
	int t, ti;
	LL n;
	LL m[3][3] = {
		{0, 1, 0}, 
		{0, 0, 1}, 
		{0, 0, 0}
	};
	LL pm[3][3];
	LL v1[3] = {0, 1, 1};
	LL v2[3];

	scanf("%d", &t);
	for (ti = 0; ti < t; ++ti) {
		scanf("%lld%lld%lld%lld", &m[2][2], &m[2][1], &m[2][0], &n);
		if (n < 3) {
			printf("%lld\n", v1[n]);
			continue;
		}
		fastPow(m, pm, n - 2);
		multiplyVector(pm, v1, v2);
		printf("%lld\n", v2[2]);
	}

	return 0;
}